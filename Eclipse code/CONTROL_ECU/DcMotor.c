/******************************************************************************
 *
 * Module: Dc_Motor
 *
 * File Name: DcMotor.c
 *
 * Description: Source file for the DC_Motor driver
 *
 * Author: karim elnekheily
 *
 **********************************************************/

#include "DcMotor.h"
#include "gpio.h"   /* To use GPIO Driver */
#include "pwm.h"    /* To use PWM Driver */
#include "avr/io.h" /* To use the IO Ports Registers */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize pin directions of the motor
 * Stop the motor at the beginning
 */
void DcMotor_Init(void)
{
	/* Configure the direction for IN1 and IN2 pins as output pins */
	GPIO_setupPinDirection(DC_Motor_IN1_PORT_ID, DC_Motor_IN1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_Motor_IN2_PORT_ID, DC_Motor_IN2_PIN_ID,PIN_OUTPUT);

	/* Motor is stop at the beginning */
	GPIO_writePin(DC_Motor_IN1_PORT_ID, DC_Motor_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(DC_Motor_IN2_PORT_ID, DC_Motor_IN2_PIN_ID, LOGIC_LOW);
}

/*
 * Description :
 * Function responsible for rotate the DC Motor CW/ or A-CW or stop
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state)
{
	/* Select DC Motor State */
	switch (state)
	{
	case CW:
		/* Rotate Motor CW at CW(1) case */
		GPIO_writePin(DC_Motor_IN1_PORT_ID, DC_Motor_IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(DC_Motor_IN2_PORT_ID, DC_Motor_IN2_PIN_ID, LOGIC_LOW);
		break;
	case A_CW:
		/* Rotate Motor A-CW  */
		GPIO_writePin(DC_Motor_IN1_PORT_ID, DC_Motor_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_Motor_IN2_PORT_ID, DC_Motor_IN2_PIN_ID, LOGIC_HIGH);
		break;
		case STOP:
		/* Stop Motor */
		GPIO_writePin(DC_Motor_IN1_PORT_ID, DC_Motor_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_Motor_IN2_PORT_ID, DC_Motor_IN2_PIN_ID, LOGIC_LOW);
		break;
	default:
		/* Stop Motor at the default case */
		GPIO_writePin(DC_Motor_IN1_PORT_ID, DC_Motor_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_Motor_IN2_PORT_ID, DC_Motor_IN2_PIN_ID, LOGIC_LOW);
	}

	/* Start motor with required speed by PWM  */
	PWM_Timer0_Start(100);

}
