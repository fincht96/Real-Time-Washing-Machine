

#include "program_manager.h"
#include "stage_type.h"
#include "program_data.h"
#include "stage_data.h"


ProgramManager::ProgramManager(Program* const pProgram)
	: m_pProgram(pProgram),  m_pProgramData(pProgramData)
{
		
}




// returns true if program selected is in range, if not returns false
bool ProgramManager::selectProgram(uint8_t selected_program)
{

	// initialises and assigns variable to store offset to selected program
	int16_t selected_program_offset = getProgramOffset(selected_program);
	
	
	// if offset is -1, selected prgram does not exist
	if(selected_program_offset == -1)
		return false;
	
	else
	{
		// updates the stage items in program object with selected program data
		updateProgramStages(selected_program_offset);
		
		return true;
	}
	
	
}




// NOTE FUNCTION DOES NOT WORK IF NO DATA IN THE PROGRAM DATA CHAR ARRAY

int16_t ProgramManager::getProgramOffset(uint8_t selected_program) const 
{
	// holds the number of programs in list	
	uint8_t program_count = 0;
	
	// iterator used to increment through each element in char array
	uint8_t i = 0;
	
	// temporary buffer holds characters read from program data
	char temp_buffer[3];
	
	
	
	if(selected_program == 0)
	{
			// returns first element in char array
			return 0;
	}
	
	// check if selected program exists 
	while(*(m_pProgramData+i) != '\0')
	{
		
		// reads a sequence of two characters into temp_buffer
		temp_buffer[0] = *(m_pProgramData+i);
		temp_buffer[1] = *((m_pProgramData+i)+1);
		
		// adds null character
		temp_buffer[2] = '\0';
		
		
		
		// checks if complete stage has been detected
		if( strcmp(temp_buffer, _complete) == 0)
    {
					// increments the number of programs found in program list
					++program_count;
			
					if(selected_program  == program_count)
					{
							// offset from end of one program to first chatracter of selected one
							return i+6;
					}
		}
		
		// increments iterator
		++i;
		
	}
	
	// if selected program doesn't exist
	return -1;
	
}







void ProgramManager::updateProgramStages(uint8_t program_offset) const
{
		
	// iterator to read through characters in programData char array
	uint16_t i = 0;
	
	// temporary buffer to read characters in from program data
	char temp_buffer[3];
	
	// holds temporary stage type
	enum StageType temp_type;
	
	// holds temporary stage duration
	uint16_t temp_duration;
	
	
	
	// while complete stage is not read
	while(strcmp(temp_buffer, _complete) != 0)
	{
		
		// Reads washing machine stage type
		// ====================================================
		
		
		// reads the next three chars of program data into temporary buffer
		temp_buffer[0] = *(m_pProgramData+program_offset+i);
		temp_buffer[1] = *(m_pProgramData+program_offset+i+1);
		temp_buffer[2] = *(m_pProgramData+program_offset+i+2);
		
		// overwrites ',' with NULL character
		temp_buffer[2] = '\0';
		
		
		
		// comparescharacters in temporary buffer with keywords representing stages
		// updates the stage type if match is found
		
		if(strcmp(temp_buffer, _wash_slow) == 0)
		{
				temp_type = WASH_SLOW;
		}
		
		else if (strcmp(temp_buffer, _wash_high) == 0)
		{
				temp_type = WASH_HIGH;
		}
		
		else if (strcmp(temp_buffer, _rinse_slow) == 0)
		{
				temp_type = RINSE_SLOW;
		}
		
		else if (strcmp(temp_buffer, _rinse_high) == 0)
		{
				temp_type = RINSE_HIGH;
		}
		
		else if (strcmp(temp_buffer, _empty) == 0)
		{
				temp_type = EMPTY;
		}
		
		else if (strcmp(temp_buffer, _dry) == 0)
		{
				temp_type = DRY;
		}
		
		else if (strcmp(temp_buffer, _fill) == 0)
		{
				temp_type = FILL;
		}
		
		else if (strcmp(temp_buffer, _heat) == 0)
		{
				temp_type = HEAT;
		}
		
		
		
		// Reads washing machine stage duration
		// ====================================================
		
		// increments iterator by three to point to the time duration
		i += 3;
		
		
		// reads the next three chars of program data into temporary buffer
		temp_buffer[0] = *(m_pProgramData+program_offset+i);
		temp_buffer[1] = *(m_pProgramData+program_offset+i+1);
		temp_buffer[2] = *(m_pProgramData+program_offset+i+2);
		
		
		// convert the char numbers into actual value, ascii character converted into integer type
		temp_duration = 
										(10 * (temp_buffer[0]-48))
										+
										(1 * (temp_buffer[1]-48));
										
										
		// increments iterator by three to point to the next stage type in program data
		i += 3;
		

		// Adds new stage to Program object
		// ====================================================
		
		m_pProgram->addStage(temp_type, temp_duration);
		
	}
	
	
	
	// simply adds the complete stage to the Program and leaves the function 
	m_pProgram->addStage(COMPLETE, 0);
	
	
	
}


