
#include "ioport.h"
#include "spi_master.h"
struct spi_device spi_max31855;

float temperature_is;
uint8_t temperature_valid;

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
	volatile int16_t temperature_extern;
	volatile int16_t temperature_intern;
	volatile float f_temp_intern;

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
