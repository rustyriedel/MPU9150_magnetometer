/*
 * Magnetometer.c
 *
 *  Created on: Sep 22, 2016
 *      Author: Alex Kimani, Rusty Riedel
 */
#include	<stddef.h>
#include	<stdbool.h>
#include	<stdint.h>
#include	<stdarg.h>

#include	"Tasks/Task_ReportData.h"

#include	"FreeRTOS.h"
#include	"task.h"
#include 	"Magnetometer.h"

extern void Init_Magnetometer()
{
	//***************************************************
	// Set up I2C
	//***************************************************
	// The I2C master driver instance data.
	tI2CMInstance g_sI2CMSimpleInst;

	// A boolean that is set when an I2C transaction is completed.
	volatile bool g_bI2CMSimpleDone = true;

	// The interrupt handler for the I2C module.
	void I2CMSimpleIntHandler(void)
	{
		// Call the I2C master driver interrupt handler.
		I2CMIntHandler(&g_sI2CMSimpleInst);
	}

	// The function that is provided by this example as a callback when I2C
	// transactions have completed.
	void I2CMSimpleCallback(void* pvData, uint_fast8_t ui8Status)
	{
		// See if an error occurred.
		if(ui8Status != I2CM_STATUS_SUCCESS)
		{
			// An error occurred, so handle it here if required.
		}

		// Indicate that the I2C transaction has completed.
		g_bI2CMSimpleDone = true;
	}

	// The simple I2C master driver example.
	void I2CMSimpleExample(void)
	{
		uint8_t pui8Data[4];

		// Initialize the I2C master driver.  It is assumed that the I2C module has
		// already been enabled and the I2C pins have been configured.
		I2CMInit(&g_sI2CMSimpleInst, I2C0_BASE, INT_I2C0, 0xff, 0xff, 80000000);

		// Write two bytes of data to the I2C device at address 0x22.
		g_bI2CMSimpleDone = false;
		I2CMWrite(&g_sI2CMSimpleInst, 0x22, pui8Data, 2, I2CMSimpleCallback, 0);

		while(!g_bI2CMSimpleDone)
		{
		}

		// Read four bytes of data from the I2C device at address 0x31.
		g_bI2CMSimpleDone = false;
		I2CMRead(&g_sI2CMSimpleInst, 0x31, pui8Data, 1, pui8Data, 4,
		I2CMSimpleCallback, 0);

		while(!g_bI2CMSimpleDone)
		{
		}
	}
	//***************************************************
}

extern void Task_Magnetometer( void *pvParameters ){
	//init if necessary
	Init_Magnetometer();

	//freeRTOS task loop
	while(true){

		//read the data from the magnetometer
		MPU9150DataRead(&sMPU9150, MPU9150Callback, 0);

		UARTprintf("inside mag task\n");

		//xQueueSend(  ReportData_Queue, &theTimeReport, 0 );

		//delay the task
		vTaskDelay( 1 * configTICK_RATE_HZ );

	}//end freeRTOS task loop
}//end magnetometer task

extern void Magnetometer_ISR_Handler(){

}
