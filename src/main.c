#include "../ECAL/EEPROM/EEPROM_driver.h"

int main(void)
{
	u8 value= 0;
	
	DDRD  = 0xFF;
	PORTD = 0x00;

	init_EEPROM();
	write_byte_EEPROM(0x0311, 0x0F); 
	_delay_ms(10);
	read_byte_EEPROM(0x0311, &value); 
	
	while(1)
	{
		PORTD = value;
	}
	return 0;
}
