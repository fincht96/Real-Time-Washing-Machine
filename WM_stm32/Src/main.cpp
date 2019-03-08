/*
* File: main.cpp
* Title: Demonstration application entry point
* Version: 0.01
* Created: 06/02/2018
*
* Author: Themba Kaonga
* Loughborough University
* Loughborough, LE11 3TU, UK
* Copyright Thomas Finch 2018*
*/

#include "washing_machine.h"



extern "C" {  // this is needed to make C++ and C work together
  #include "board_startup.h"   // you DON'T need to worry about the contents of this file
}









int main(void)
{
	board_startup();
	
	// creates an object of type WashingMachine
	WashingMachine m_wm;
	
	
	return 0;
}
