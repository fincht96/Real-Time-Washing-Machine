#ifndef PROGRAM_H
#define PROGRAM_H


#include "stage.h"
#include "program_state.h"

// can only hold up to 15 stages
#define STAGE_LIST_SIZE 15


class Program
{
    public:

        Program(SevenSegmentDisplay* const pSeven_seg, Motor* const pMotor, Timer* const pTimer);

		
        // PROGRAM CONTROL
        // ===============

        // function will set the state of program
        void setState(enum ProgramState state);

        // returns current state of program, i.e. either running, paused or finished
        enum ProgramState getState() const;

        // function resets program object
        void reset();

		
		
        // STAGE CONTROL
        // =============

        // increments the stage currently running, enables systemOperator to increment the stage currently running
        void incrementSelectedStage();

        // adds new item
        void addStage(enum StageType type, uint32_t duration);



    private:

        // PROGRAM MANAGEMENT
        // ==================

        // holds current program state
        ProgramState m_program_state;



        // STAGE MANAGEMENT
        // ================

				// used to index the elements in the array
				uint8_t m_array_index;
		
		
        // array holds the all stages in program
        Stage m_stage[STAGE_LIST_SIZE];


        // holds the selected stage item in m_stage_list
        uint8_t m_current_selected_stage;
		






};

#endif // PROGRAM_H
