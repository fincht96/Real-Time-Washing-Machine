#ifndef SYSTEM_OPERATOR_H_INCLUDED
#define SYSTEM_OPERATOR_H_INCLUDED


#include "program.h"

#include "stdint.h"
#include "buzzer.h"
#include "program_manager.h"
#include "door_button.h"
#include "button_latch.h"

class SystemOperator
{
    public:
        // constructor sets up program manager object and calls "run" member function
        SystemOperator(Program* const pProgram, ProgramManager* const pProgram_manager, Timer* const pTimer,
												Button* const pAccept_button, Button* const pCancel_button, Button* const pSelect_button_1,
												Button* const pSelect_button_2, Button* const pSelect_button_3, DoorButton* const pDoor_button,								
												Buzzer* const pBuzzer, ButtonLatch* const pLatch, SevenSegmentDisplay* const pSeg);



    private:
        // member function runs entire operation
        void run();

        // function is used to select program
        bool selectProgram();

        // resets and sets latch ready to read input
        void readyLatch();

        // briefly sounds the buzzer for 2 seconds
        void soundBuzzer();


        // PROGRAM MANAGEMENT
        // ==================

        // holds a specified program
        Program* const m_pProgram;

        // contains and manages programs
        ProgramManager* const m_pProgram_manager;


        // TIME MANAGEMENT
        // ===============

        // holds an object of type timer
        Timer* const m_pTimer;



        // EXTERNAL PERIPHERALS
        // ====================

        // Input(s)
        Button* const m_pAccept_button;
        Button* const m_pCancel_button;

        Button* const m_pSelect_button_1;
        Button* const m_pSelect_button_2;
        Button* const m_pSelect_button_3;

        DoorButton* const m_pDoor_button;

        // Output(s)
        Buzzer* const m_pBuzzer;
        ButtonLatch* const m_pLatch;
				SevenSegmentDisplay* const m_pSeg;
};



#endif // SYSTEM_OPERATOR_H_INCLUDED
