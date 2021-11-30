#include "i2c_driver.h"

void init_i2c_comm(void)
{
    TWBR = 0x02;
	TWSR = 0x00;
    TWAR = 0x02;
}

void start_i2c_comm(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

void stop_i2c_comm(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void i2c_write(u8 data)
{
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

u8 i2c_read_ACK(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while(BIT_IS_CLEAR(TWCR,TWINT));
    return TWDR;
}

u8 i2c_read_NACK(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN);
    while(BIT_IS_CLEAR(TWCR,TWINT));
    return TWDR;
}

u8 i2c_check_status(void)
{
    u8 status;
    status = TWSR & 0xF8;
    return status;
}
