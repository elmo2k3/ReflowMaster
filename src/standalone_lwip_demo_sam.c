/**
 * \file
 *
 * \brief Standalone lwIP example for SAM.
 *
 * Copyright (c) 2012-2013 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

/**
 *  \mainpage Standalone lwIP example
 *
 *  \section Purpose
 *  This documents data structures, functions, variables, defines, enums, and
 *  typedefs in the software for the lwIP standalone example.
 *
 *  The given example is a lwIP example using the current lwIP stack and EMAC driver.
 *
 *  \section Requirements
 *
 *  This package can be used with SAM3X-EK and SAM4E-EK.
 *
 *  \section Description
 *
 *  This example features simple lwIP web server.
 *  - Plug the Ethernet cable directly into the evaluation kit to connect to the PC.
 *  - Configuring the PC network port to local mode to setup a 'point to point' network.
 *  - Start the example.
 *  - Launch your favorite web browser.
 *  - Type the WEB server example IP address in your browser's address bar.
 *
 *  \section Usage
 *
 *  -# Build the program and download it into the evaluation board. Please
 *     refer to the
 *     <a href="http://www.atmel.com/dyn/resources/prod_documents/6421B.pdf">
 *     SAM-BA User Guide</a>, the
 *     <a href="http://www.atmel.com/dyn/resources/prod_documents/doc6310.pdf">
 *     GNU-Based Software Development</a>
 *     application note or the
 *     <a href="http://www.iar.com/website1/1.0.1.0/78/1/">
 *     IAR EWARM User and reference guides</a>,
 *     depending on the solutions that users choose.
 *  -# On the computer, open and configure a terminal application
 *     (e.g., HyperTerminal on Microsoft Windows) with these settings:
 *    - 115200 bauds
 *    - 8 bits of data
 *    - No parity
 *    - 1 stop bit
 *    - No flow control
 *  -# In the terminal window, the
 *     following text should appear (values depend on the board and the chip used):
 *     \code
 *      LwIP: DHCP StartedNetwork upIP=xxx.xxx.xxx.xxx
 *     \endcode
 *  -# The application will output converted value to hyperterminal and display
 *     a menu for users to set different modes.
 *
 */

#include "ethernet_sam.h"
#include "sysclk.h"
#include "ioport.h"
#include "stdio_serial.h"
#include "spi_master.h"
#include "ks0108/ks0108.h"
#include "buttons.h"
#include "drehgeber.h"
#include "menu.h"

volatile float f_temp_extern;
volatile int32_t temperature_set;
volatile int32_t heating;
struct spi_device spi_max31855;

volatile uint32_t usTicks;
volatile uint8_t second_gone;

#define PIN_BEEPER PIO_PA23_IDX
#define PIN_SSR PIO_PA25_IDX
#define PIN_LED_GREEN PIO_PD17_IDX

/**
 * \brief Set peripheral mode for IOPORT pins.
 * It will configure port mode and disable pin mode (but enable peripheral).
 * \param port IOPORT port to configure
 * \param masks IOPORT pin masks to configure
 * \param mode Mode masks to configure for the specified pin (\ref ioport_modes)
 */
#define ioport_set_port_peripheral_mode(port, masks, mode) \
	do {\
		ioport_set_port_mode(port, masks, mode);\
		ioport_disable_port(port, masks);\
	} while (0)
/**
 *  \brief Configure board PIOs.
 */
static void init_board(void)
{
	/* Disable the watchdog */
	WDT->WDT_MR = WDT_MR_WDDIS;

	/* Configure UART pins */
	//ioport_set_port_peripheral_mode(PINS_UART0_PORT, PINS_UART0,
	//		PINS_UART0_MASK);
	ioport_init();

	spi_max31855.id = 0;
	ioport_set_port_peripheral_mode(IOPORT_PIOA,PIO_PA11A_NPCS0 | PIO_PA12A_MISO | PIO_PA14A_SPCK,
									PIO_PA11A_NPCS0 | PIO_PA12A_MISO | PIO_PA14A_SPCK);

	spi_master_init(SPI);
	spi_master_setup_device(SPI, &spi_max31855,SPI_MODE_0, 1000000ul, 0);
	spi_set_bits_per_transfer(SPI,0,SPI_CSR_BITS_16_BIT);
	spi_enable(SPI);
	
	ioport_set_pin_dir(PIN_LED_GREEN,IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_LED_GREEN,1);

	ioport_set_pin_dir(PIN_SSR,IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_SSR,0);

	ioport_set_pin_dir(PIO_PD27_IDX,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(PIN_BEEPER,IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_BEEPER,0);
}

void SysTick_Handler(void)
{
	usTicks++;
	if(!(usTicks % 100ul)){ // 0.001s
		drehgeber_work();
	}
	if(!(usTicks % 1000ul)){ // 0.01s
		buttons_every_10_ms();
	}
	if(!(usTicks % 10000ul)){ // 0.1s
		menu_tick();
	}
	if(!(usTicks % 100000ul)){ // 1s
		ioport_toggle_pin_level(PIN_LED_GREEN);
		second_gone = 1;
	}
}

void _delay_us(uint32_t us)
{
	uint32_t curTicks = usTicks;
	while((usTicks - curTicks)<us);
}

void _delay_ms(uint32_t us)
{
	uint32_t curTicks = usTicks;
	while((usTicks - curTicks)<us*1000ul);
}

/**
 * \brief Main function: Responsible for configuring the hardware,
 * ethernet, and other services. It also maintains the lwIP timers,
 * and processes any packets that are received.
 */
int main(void)
{
	uint32_t counter = 0;
	uint16_t data;
	uint8_t uc_pcs = 0;
	volatile int16_t temperature_extern;
	volatile int16_t temperature_intern;
	volatile float f_temp_intern;
	bool level;
	char str[30];
	
	temperature_set = 20;
	
	/* Initialize the SAM system */
	sysclk_init();
	init_board();
	buttons_init();
	drehgeber_init();

	/* Configure debug uart */

	/* Bring up the ethernet interface & initializes timer0, channel0 */
	init_ethernet();
	//SysTick_Config(SystemCoreClock/10); // 100ms
	SysTick_Config(SystemCoreClock/100000); // 1us
	ks0108Init();
	menu_init();

	/* This is the main polling loop */
	while (1) {
		/* Check if any packets are available and process if they are
		 * ready. That function also manages the lwIP timers */
		ethernet_task();
		if(second_gone){
			second_gone = 0;
			if(f_temp_extern < (float)temperature_set){
				heating = 1;
				ioport_set_pin_level(PIN_SSR,1);
				ioport_set_pin_level(PIN_BEEPER,0);
				//ioport_set_pin_level(PIO_PD17_IDX,0);
			}else{
				heating = 0;
				ioport_set_pin_level(PIN_BEEPER,1);
				ioport_set_pin_level(PIN_SSR,0);
				//ioport_set_pin_level(PIO_PD18_IDX,1);
			}
		}
		spi_select_device(SPI,&spi_max31855);
		spi_write(SPI,data,0,0);
		while((spi_read_status(SPI) & SPI_SR_RDRF) == 0);
		spi_read(SPI,&data,&uc_pcs);
		temperature_extern = ((data>>2) & 0x3FFF);
		spi_write(SPI,data,0,0);
		while((spi_read_status(SPI) & SPI_SR_RDRF) == 0);
		spi_read(SPI,&data,&uc_pcs);
		temperature_intern = ((data>>4) & 0xFFF);
		f_temp_intern = temperature_intern / 16.0;
		f_temp_extern = temperature_extern / 4.0;
		spi_deselect_device(SPI,&spi_max31855);

		menu_task();
	}
}
