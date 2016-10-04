/**
 *
 * @author Alexander Kimani, Rusty Riedel
 * @email a906k620@ku.edu
 * @date 09/12/2016
 *
 * This program utilizes a timer interrupt to give the time of the day
 */

#include	"inc/hw_ints.h"
#include	"inc/hw_memmap.h"
#include	"inc/hw_types.h"
#include	"inc/hw_uart.h"

#include	<stddef.h>
#include	<stdbool.h>
#include	<stdint.h>
#include	<stdarg.h>

#include	"driverlib/sysctl.h"
#include	"driverlib/pin_map.h"
#include	"driverlib/gpio.h"

#include	"FreeRTOS.h"
#include	"task.h"
#include 	"driverlib/timer.h"
#include	"Drivers/uartstdio.h"

#include 	"semphr.h"
#include 	"Task_I2C7_Handler.h"

#include	"sensorlib/ak8975.h"
#include 	"sensorlib/mpu9150.h"


float fMagneto[3];
tMPU9150 sMPU9150;
volatile bool g_bMPU9150Done;
extern tI2CMInstance I2C7_Instance;

void MPU9150Callback(void *pvCallbackData, uint_fast8_t ui8Status) {
	//
	// See if an error occurred.s
	//
	if (ui8Status != I2CM_STATUS_SUCCESS) {
		//
		// An error occurred, so handle it here if required.
		//
		UARTprintf( ">>>>I2C7 in 9150 callback Error: %02X\n", ui8Status );
	}
	//
	// Indicate that the MPU9150 transaction has completed.
	//
	g_bMPU9150Done = true;
}

extern void Task_Magnetometer(void *pvParameters) {

	//initialize I2C master
	I2C7_Initialization();

	//Initialize the mpu9150
	uint_fast8_t stat9150;
	stat9150 = MPU9150Init(&sMPU9150, I2C7_Instance_Ref, 0x68, MPU9150Callback, 0);
	while(!g_bMPU9150Done)
	{}
	UARTprintf( ">>>>MPU9150Init; Status: %02X\n", stat9150 );

	char buf0[30];
	char buf1[30];
	char buf2[30];

	uint_fast16_t  x, y, z;

	while (1) {
		g_bMPU9150Done = false;
		MPU9150DataRead(&sMPU9150, MPU9150Callback, 0);
		while(!g_bMPU9150Done){}

		MPU9150DataMagnetoGetFloat(&sMPU9150, &fMagneto[0], &fMagneto[1], &fMagneto[2]);
		MPU9150DataMagnetoGetRaw(&sMPU9150, &x, &y, &z);


		UARTprintf("x:%d, y:%d, z:%d\n", x, y, z);
		/*
		sprintf(buf0, "%f\n", fMagneto[0]);
		sprintf(buf1, "%f\n", fMagneto[1]);
		sprintf(buf2, "%f\n", fMagneto[2]);
		UARTprintf("x:%sy:%sz:%s\n", buf0, buf1, buf2);
		*/

		vTaskDelay((10000 * configTICK_RATE_HZ) / 10000);
	}
}