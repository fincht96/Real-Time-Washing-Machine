

#include "system_operator.h"
#include "stage_state.h"
#include "stage_item.h"
#include "program_state.h"
#include "timer.h"

SystemOperator::SystemOperator(Program* const pProgram, ProgramManager* const pProgram_manager, Timer* const pTimer,
												Button* const pAccept_button, Button* const pCancel_button, Button* const pSelect_button_1,
												Button* const pSelect_button_2, Button* const pSelect_button_3, DoorButton* const pDoor_button,								
												Buzzer* const pBuzzer, ButtonLatch* const pLatch, SevenSegmentDisplay* const pSeg)

		: m_pProgram(pProgram), 
			m_pProgram_manager(pProgram_manager), 
			m_pTimer(pTimer), 
			m_pAccept_button(pAccept_button),
			m_pCancel_button(pCancel_button),
			m_pSelect_button_1(pSelect_button_1),
			m_pSelect_button_2(pSelect_button_2),
			m_pSelect_button_3(pSelect_button_3),
			m_pDoor_button(pDoor_button),
			m_pBuzzer(pBuzzer),
			m_pLatch(pLatch),
			m_pSeg(pSeg)
		
{
    // calls run operation
    run();
}



void SystemOperator::run()
{

    // ready's latch for input
		readyLatch();
	
	
    while(1)
    {
			
			
        //============================================================================================
        // SELECT PROGRAM


        // if accept button has been pressed, cancel button is not pressed,
        // door button is not pressed, and no program is currently running
        if(
            m_pAccept_button->getButtonStatus() == PRESSED &&
            m_pCancel_button->getButtonStatus() != PRESSED &&
            m_pDoor_button->getButtonStatus() != PRESSED &&
            m_pProgram->getState() == PROGRAM_NOT_RUNNING
           )

        {
		
            // calls select program sub function which takes user input and updates program data
            // selectProgram will also set the status of the program to "RUNNING"
            if(selectProgram() == true)
            {
                // sets program state to running which will run program routine
                m_pProgram->setState(PROGRAM_RUNNING);
									
						}

            // if program selected was not available, then program is not selected and program status is not
            // set running
						
						// ready's latch for next input
            readyLatch();
						

        }


				//============================================================================================
        // CLEARS LATCH
				
				// if cancel button has been pressed, and no program is running, clears the latches
				

				else if(
            m_pCancel_button->getButtonStatus() == PRESSED &&
            m_pProgram->getState() == PROGRAM_NOT_RUNNING
          )
					{
							// ready's latch for next input
							readyLatch();
					}
				
				

        //============================================================================================
        // RUNS SELECTED PROGRAM


        // if accept button it not pressed, cancel button is not pressed,
        // door button is not pressed, and program is currently running
        else if(
                 m_pAccept_button->getButtonStatus() != PRESSED &&
                 m_pCancel_button->getButtonStatus() != PRESSED &&
                 m_pDoor_button->getButtonStatus() != PRESSED &&
                 m_pProgram->getState() == PROGRAM_RUNNING

                )
        {

            // sets program state to running which will run program routine
            m_pProgram->setState(PROGRAM_RUNNING);


        }
				
				

        //============================================================================================
        // INCREMENTS STAGE OF SELECTED PROGRAM


        // if accept button is pressed, cancel button is not pressed,
        // door button is not pressed, and program is currently running
        else if(
                 m_pAccept_button->getButtonStatus() == PRESSED &&
                 m_pCancel_button->getButtonStatus() != PRESSED &&
                 m_pDoor_button->getButtonStatus() != PRESSED &&
                 m_pProgram->getState() == PROGRAM_RUNNING

                )
        {
            // ready's latch for next input
            readyLatch();

            // increments current stage selected in program routine
            m_pProgram->incrementSelectedStage();
					
        }



        //============================================================================================
        // PAUSES SELECTED PROGRAM


        // if accept button is not pressed, cancel button is pressed,
        // door button is not pressed, and program is currently running
        else if(
                 m_pAccept_button->getButtonStatus() != PRESSED &&
                 m_pCancel_button->getButtonStatus() == PRESSED &&
                 m_pDoor_button->getButtonStatus() != PRESSED &&
                 m_pProgram->getState() == PROGRAM_RUNNING

                )
        {
            // ready's latch for next input
            readyLatch();
						
            // pauses the selected program
            m_pProgram->setState(PROGRAM_PAUSED);
        }



        //============================================================================================
        // RESUMES SELECTED PROGRAM FROM PAUSED STATE


        // if accept button is pressed, cancel button is not pressed,
        // door button is not pressed, and program is currently paused
        else if(
                 m_pAccept_button->getButtonStatus() == PRESSED &&
                 m_pCancel_button->getButtonStatus() != PRESSED &&
                 m_pDoor_button->getButtonStatus() != PRESSED &&
                 m_pProgram->getState() == PROGRAM_PAUSED
                )
        {

            // ready's latch for next input
            readyLatch();

            // sets program state to running which will run program routine
            m_pProgram->setState(PROGRAM_RUNNING);
        }


        //============================================================================================
        // RESETS THE MACHINE


        // if accept button is not pressed, cancel button is pressed,
        // door button is not pressed, and program is currently paused, suspended or finished
        else if(
                 m_pAccept_button->getButtonStatus() == NOT_PRESSED &&
                 m_pCancel_button->getButtonStatus() == PRESSED &&
                 (m_pProgram->getState() == PROGRAM_PAUSED || m_pProgram->getState() == PROGRAM_SUSPENDED || m_pProgram->getState() == PROGRAM_NOT_RUNNING)          
                )

        {
					
					  // ready's latch for next input
            readyLatch();
					
            // resets the program
            m_pProgram->reset();
					
						// clears seven seg display
						m_pSeg->writeValue(0);

        }



        //============================================================================================
        // TURNS BUZZER ON BRIEFLY AND SUSPENDS RUNNING PROGRAM


        // if accept button is not pressed, cancel button is not pressed,
        // door button is pressed, and program is running
        else if(
                 m_pAccept_button->getButtonStatus() != PRESSED &&
                 m_pCancel_button->getButtonStatus() != PRESSED &&
                 m_pDoor_button->getButtonStatus() == PRESSED &&
                 m_pProgram->getState() == PROGRAM_RUNNING
                )
        {


            // ready's latch for next input
            readyLatch();

            // sets program to suspended
            m_pProgram->setState(PROGRAM_SUSPENDED);

            // briefly sounds the buzzer
            soundBuzzer();

        }



      //============================================================================================
      // RESUMES SELECTED PROGRAM FROM SUSPENSION


        // if accept button is not pressed, cancel button is pressed,
        // door button is not pressed, and program is currently paused, suspended or finished
        else if(
                 m_pAccept_button->getButtonStatus() != PRESSED &&
                 m_pCancel_button->getButtonStatus() != PRESSED &&
                 m_pDoor_button->getButtonStatus() != PRESSED &&
                 m_pProgram->getState() == PROGRAM_SUSPENDED

                )

        {

            // ready's latch for next input
            readyLatch();

            // resumes the program running
            m_pProgram->setState(PROGRAM_RUNNING);

        }

			

        //============================================================================================
        // SOUNDS BUZZER IF DOOR IS OPEN AND ACCEPT IS PRESSED


            // if accept button is pressed, cancel button is not pressed,
            // door button is pressed, and program is currently suspended
            // state of Program object doesn't matter
            else if(
                    m_pAccept_button->getButtonStatus() == PRESSED &&
                    m_pCancel_button->getButtonStatus() != PRESSED &&
                    m_pDoor_button->getButtonStatus() == PRESSED 
                    )

            {

                // ready's latch for next input
                readyLatch();

                // briefly sounds the buzzer
                soundBuzzer();

            }


    }

}


bool SystemOperator::selectProgram()
{

    // temporary variable holds the selected program
    uint8_t selected_program;


    // reads the state of the program selectors

    if(m_pSelect_button_1->getButtonStatus() == NOT_PRESSED && 
			 m_pSelect_button_2->getButtonStatus() == NOT_PRESSED && 
			 m_pSelect_button_1->getButtonStatus() == NOT_PRESSED)
            selected_program = 0;


    else if(m_pSelect_button_1->getButtonStatus() == PRESSED && 
						m_pSelect_button_2->getButtonStatus() == NOT_PRESSED && 
						m_pSelect_button_3->getButtonStatus() == NOT_PRESSED)
            selected_program = 1;


    else if(m_pSelect_button_1->getButtonStatus() == NOT_PRESSED && 
						m_pSelect_button_2->getButtonStatus() == PRESSED && 
						m_pSelect_button_3->getButtonStatus() == NOT_PRESSED)
            selected_program = 2;


    else if(m_pSelect_button_1->getButtonStatus() == PRESSED && 
						m_pSelect_button_2->getButtonStatus() == PRESSED && 
						m_pSelect_button_3->getButtonStatus() == NOT_PRESSED)
            selected_program = 3;

		
		
    else if(m_pSelect_button_1->getButtonStatus() == NOT_PRESSED && 
						m_pSelect_button_2->getButtonStatus() == NOT_PRESSED && 
						m_pSelect_button_3->getButtonStatus() == PRESSED)
            selected_program = 4;

		
    else if(m_pSelect_button_1->getButtonStatus() == PRESSED && 
						m_pSelect_button_2->getButtonStatus() == NOT_PRESSED && 
						m_pSelect_button_3->getButtonStatus() == PRESSED)
            selected_program = 5;


    else if(m_pSelect_button_1->getButtonStatus() == NOT_PRESSED && 
						m_pSelect_button_2->getButtonStatus() == PRESSED && 
						m_pSelect_button_3->getButtonStatus() == PRESSED)
            selected_program = 6;


    else if(m_pSelect_button_1->getButtonStatus() == PRESSED && 
						m_pSelect_button_2->getButtonStatus() == PRESSED && 
						m_pSelect_button_3->getButtonStatus() == PRESSED)
            selected_program = 7;

		
    // selects and updates program, based on input
    if(m_pProgram_manager->selectProgram(selected_program) == true)
		{
				// if program exists then function returns true
				return true;
		}
		
	
		// if program doesn't exist, returns false
		return false;


}


void SystemOperator::readyLatch()
{
    // clears the latch
    m_pLatch->resetLatch();

	  // sets timer of 200 mS
    m_pTimer->setTimer(200);
	
	
	  // waits until timer has finished
    while(m_pTimer->checkTimer() != true)
    {
        // does nothing
    }
	
	
    // ready's latch for input
    m_pLatch->setLatch();

}


void SystemOperator::soundBuzzer()
{
        // turns buzzer on briefly
        m_pBuzzer->toggleOn();

        // sets timer of 2000 mS
        m_pTimer->setTimer(500);

        // waits until timer has finished
        while(m_pTimer->checkTimer() != true)
        {
            // does nothing
        }

        // toggles buzzer off
        m_pBuzzer->toggleOff();
}
