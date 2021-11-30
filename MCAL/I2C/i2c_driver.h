#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include "../../include/std_types.h"
#include "../../include/common_macros.h"
#include "../../include/mcu_config.h"


#define I2C_START            0x08 
#define I2C_REPEATED_START    0x10 
#define I2C_MASTER_TRANSMIT_SLAVE_ADDRESS_WRITE_ACK  0x18
#define I2C_MASTER_TRANSMIT_SLAVE_ADDRESS_READ_ACK  0x40 
#define I2C_MASTER_TRANSMIT_DATA_ACK   0x28 
#define I2C_MASTER_RECEIVE_DATA_ACK   0x50 
#define I2C_MASTER_RECEIVE_DATA_NACK  0x58 

void init_i2c_comm(void);
void start_i2c_comm(void);
void stop_i2c_comm(void);

void i2c_write(u8 data);
u8 i2c_read_ACK(void); 
u8 i2c_read_NACK(void); 
u8 i2c_check_status(void);


#endif
