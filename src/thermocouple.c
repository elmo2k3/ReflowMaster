
#include "ioport.h"
#include "spi_master.h"
#include "thermocouple.h"
struct spi_device spi_max31855;

float temperature_is;

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

void thermocouple_init()
{
	spi_max31855.id = 0;
	ioport_set_port_peripheral_mode(IOPORT_PIOA,PIO_PA11A_NPCS0 | PIO_PA12A_MISO | PIO_PA14A_SPCK,
									PIO_PA11A_NPCS0 | PIO_PA12A_MISO | PIO_PA14A_SPCK);

	spi_master_init(SPI);
	spi_master_setup_device(SPI, &spi_max31855,SPI_MODE_0, 1000000ul, 0);
	spi_set_bits_per_transfer(SPI,0,SPI_CSR_BITS_16_BIT);
	spi_enable(SPI);
}

void thermocouple_task()
{
	int16_t temperature_extern;
	int16_t temperature_intern;
	float f_temp_intern;
	uint16_t data;
	uint8_t uc_pcs = 0;

	spi_select_device(SPI,&spi_max31855);
	spi_write(SPI,data,0,0);
	while((spi_read_status(SPI) & SPI_SR_RDRF) == 0);
	spi_read(SPI,&data,&uc_pcs);
	temperature_extern = ((data>>2) & 0x3FFF);
	spi_write(SPI,data,0,0);
	while((spi_read_status(SPI) & SPI_SR_RDRF) == 0);
	spi_read(SPI,&data,&uc_pcs);
	spi_deselect_device(SPI,&spi_max31855);

	temperature_intern = ((data>>4) & 0xFFF);
	f_temp_intern = temperature_intern / 16.0;
	temperature_is = temperature_extern / 4.0;
}
