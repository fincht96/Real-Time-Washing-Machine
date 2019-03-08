#ifndef PROGRAM_MANAGER_H_INCLUDED
#define PROGRAM_MANAGER_H_INCLUDED


#include "string.h"
#include "program.h"
#include "stdint.h"


// Interface through which system operator can select which program to read from string data

class ProgramManager
{
    public:
        // constructor initialises the Program* member object
        ProgramManager(Program* const pProgram);

        // sets the selected program, performs a bounds check,
        // returns true if program exists, if not, returns false
        bool selectProgram(uint8_t selected_program);


    private:


				
		
        // updates m_program based upon selected program
        Program* const m_pProgram;
	
		
		
		
				// holds a pointer to program data char array
				const char* m_pProgramData;

				// returns -1 if program does not exist, 
				// else, returns offset to start of selected program
				int16_t getProgramOffset(uint8_t selected_program) const;
		
				// updates the stages in Program object
				void updateProgramStages(uint8_t program_offset) const;


};




#endif // PROGRAM_MANAGER_H_INCLUDED
