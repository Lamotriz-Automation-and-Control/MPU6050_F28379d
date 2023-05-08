
//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "Wire.h"
#include "stdlib.h"
#include "string.h"

// Declaring variables
uint16_t Available_I2C[20];
uint16_t status;
uint16_t data[6];
uint16_t *k = data;
//uint16_t Available_I2C[20];
uint16_t *devices=Available_I2C;
//uint16_t status;

int16_t xAccl,yAccl,zAccl;
float Ax, Ay, Az, Gx, Gy, Gz;


int16_t Gyro_X_RAW = 0;
int16_t Gyro_Y_RAW = 0;
int16_t Gyro_Z_RAW = 0;


#define pi 3.14159265

#define MPU6050_ADDR 0x68

#define SMPLRT_DIV_REG 0x19
#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_XOUT_H_REG 0x43
#define PWR_MGMT_1_REG 0x6B
#define WHO_AM_I_REG 0x75
//
// Main
//
Wire wire;



void main(void)
{
    Device_init();
    Interrupt_initModule(); // I took this from interrupt.h
    Interrupt_initVectorTable();
    Board_init();
    ESTOP0;

        // power management register 0X6B we should write all 0's to wake the sensor up
        wire.beginTransmission(MPU6050_ADDR); //Start the data transmission to the MPU
        wire.write(PWR_MGMT_1_REG); // Send the adress on wich we will write a zero
        wire.write(0); //Send the awake 0
        wire.endTransmission();


        // Configure the gyro to the desired ranges
         /*
           Wire.write(0b00000000); // range of  +/-250°/s
           Wire.write(0b00001000); // range of +/-500°/s
           Wire.write(0b00010000); // range of +/-1000°/s
           Wire.write(0b00011000); // range of +/-2000°/s
         */

        wire.beginTransmission(MPU6050_ADDR);
        wire.write(0x1B);
        wire.write(0b00011000);  // Change that command to set a diferent range of measures from the gyro
        wire.endTransmission();

        // Configure the accelerometer to the desired ranges
          /*
              Wire.write(0b00000000); // range of  +/-2g
              Wire.write(0b00001000); //range of  +/-4g
              Wire.write(0b00010000); //range of  +/-8g
              Wire.write(0b00011000); //range of  +/-16g
          */
          wire.beginTransmission(MPU6050_ADDR);
          wire.write(0x1C);
          wire.write(0b00000000);  // Change that command to set a diferent range of measures from the accelerometer
          wire.endTransmission();


    ESTOP0;

    while(1){



             wire.requestFrom(MPU6050_ADDR,ACCEL_XOUT_H_REG,6);
             wire.read(k,6);

               xAccl = ((((int16_t)data[0]) << 8) | (int16_t)data[1]);
                       //
                       //
               yAccl = ((((int16_t)data[2]) << 8) | (int16_t)data[3]);
                       //
                       //
               zAccl = ((((int16_t)data[4]) << 8) | (int16_t)data[5]);

               Ax=__divf32(xAccl,16384.0);
               Ay=__divf32(yAccl,16384.0);
               Az =__divf32(zAccl,16384.0);

              DEVICE_DELAY_US(10000);


               /*
                *

               wire.requestFrom(MPU6050_ADDR,GYRO_XOUT_H_REG,6);
               wire.read(k,6);


                   Gyro_X_RAW = (int16_t)(data[0] << 8 | data [1]);
                   Gyro_Y_RAW = (int16_t)(data[2] << 8 | data [3]);
                   Gyro_Z_RAW = (int16_t)(data[4] << 8 | data [5]);

                       // convert the RAW values into dps ( /s)
                       // we have to divide according to the Full scale value set in FS_SEL
                       // I have configured FS_SEL = 0. So I am dividing by 131.0
                       // for more details check GYRO_CONFIG Register

                   Gx = (Gyro_X_RAW/131.0)*(pi/180);
                   Gy = (Gyro_Y_RAW/131.0)*(pi/180);
                   Gz = (Gyro_Z_RAW/131.0)*(pi/180);
                   DEVICE_DELAY_US(200000);

                    *
                    */
    }



}




//
// End of File
//


