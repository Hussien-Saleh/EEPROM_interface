#include "EEPROM_driver.h"

void init_EEPROM(void)
{
	init_i2c_comm();
}

u8 write_byte_EEPROM(u16 address, u8 data)
{
    start_i2c_comm();
    if (i2c_check_status() != I2C_START)
        return ERROR;
		
    i2c_write((u8)(0xA0 | ((address & 0x0700)>>7)));
    if (i2c_check_status() != I2C_MASTER_TRANSMIT_SLAVE_ADDRESS_WRITE_ACK)
        return ERROR; 
		 
    i2c_write((u8)(address));
    if (i2c_check_status() != I2C_MASTER_TRANSMIT_DATA_ACK)
        return ERROR;
		
    i2c_write(data);
    if (i2c_check_status() != I2C_MASTER_TRANSMIT_DATA_ACK)
        return ERROR;
		
    stop_i2c_comm();
	
    return SUCCESS;
}

uint8 read_byte_EEPROM(u16 address, u8 *data)
{
    start_i2c_comm();
    if (i2c_check_status() != I2C_START)
        return ERROR;
		
    i2c_write((u8)((0xA0) | ((address & 0x0700)>>7)));
    if (i2c_check_status() != I2C_MASTER_TRANSMIT_SLAVE_ADDRESS_WRITE_ACK)
        return ERROR;
		
    i2c_write((u8)(address));
    if (i2c_check_status() != I2C_MASTER_TRANSMIT_DATA_ACK)
        return ERROR;
		
    start_i2c_comm();
    if (i2c_check_status() != I2C_REPEATED_START)
        return ERROR;
		
    i2c_write((u8)((0xA0) | ((address & 0x0700)>>7) | 1));
    if (i2c_check_status() != I2C_MASTER_TRANSMIT_SLAVE_ADDRESS_READ_ACK)
        return ERROR;
		
    *data = i2c_read_NACK();
    if (i2c_check_status() != I2C_MASTER_RECEIVE_DATA_NACK)
        return ERROR;

    stop_i2c_comm();
    return SUCCESS;
}
