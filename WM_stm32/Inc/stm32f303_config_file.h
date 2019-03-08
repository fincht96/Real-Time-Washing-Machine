
//********************************************************************************************************
// STM32F303 config file
//
// Holds the specific register addresses for washing machine peripherals



#ifndef STM32F303_CONFIG_FILE_H
#define STATE_CONFIG_FILE_H



// clock frequency of device 
#define FOSC 8000000


// STM32F303 port base addresses
#define PORTC_BASE_ADDR 0x40000000 + 0x08000000 + 0x00000800
#define PORTD_BASE_ADDR 0x40000000 + 0x08000000 + 0x00000C00
#define PORTE_BASE_ADDR 0x40000000 + 0x08000000 + 0x00001000


// map PORTC to GPIO[0], PORTD to GPIO[1], PORTE GPIO[2]
#define PORTC 0
#define PORTD 1
#define PORTE 2




// outputs
#define BUZZER_PIN 0x0040  						// Buzzer address PC6
#define S7A_PIN 0x0100  						// Seven segment bit A address PD8
#define S7B_PIN 0x0800   						// Seven segment bit B address PD11
#define S7C_PIN 0x0400  						// Seven segment bit C address PD10
#define S7D_PIN 0x2000  						// Seven segment bit D address PD13
#define MOTOR_CONTROL_PIN 0x1000  				// Motor Control address PD12
#define MOTOR_DIRECTION_PIN 0x8000  			// Motor Direction address PD15
#define LATCH_PIN  0x4000  						// Switch Reset address PD14


// inputs
#define PROG_SEL1_PIN  0x0100  					// Program 1 selector address PE8
#define PROG_SEL2_PIN  0x0200   				// Program 2 selector address PE11
#define	PROG_SEL3_PIN  0x0400 					// Program 3 selector address PE10
#define DOOR_PIN  0x0800  						// Door Button address PE9
#define ACCEPT_PIN 0x1000  						// Accept  Button address PE12
#define CANCEL_PIN 0x2000  						// Cancel Button address PE13



#endif


