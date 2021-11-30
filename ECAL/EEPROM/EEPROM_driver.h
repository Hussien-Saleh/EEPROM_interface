#ifndef EEPROM_DRIVER_H_
#define EEPROM_DRIVER_H_

#define ERROR 0
#define SUCCESS 1

#include "../../MCAL/I2C/i2c_driver.h"

void init_EEPROM(void);
u8 write_byte_EEPROM(u16 address,u8 data);
u8 read_byte_EEPROM(u16 address,u8 *data);
 
#endif
