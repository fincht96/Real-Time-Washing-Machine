#ifndef STAGEITEM_H_INCLUDED
#define STAGEITEM_H_INCLUDED

#include "stage_type.h"
#include "stdint.h"

class StageItem
{
	public:
			StageItem();
	
			// sets the type of stage
			void setType(enum StageType type);
	
			// returns the type of stage
			enum StageType getType();
	
			// returns the stage number corresponding to type
			uint8_t getStageNumber();
	
			// sets the time duration
			void setTimeDuration(uint32_t time_duration);
			
			// returns the time duration
			uint32_t getTimerDuration();
	
	
	
	private:
			// holds the type of stage
			StageType m_type;
	
			// holds the corresponding stage number
			uint8_t m_stage_number;
	
			// holds the time duration of stage
			uint32_t m_time_duration;
	
			// automatically updated when new StageType is set
			void setStageNumber(uint8_t stage_number);
};



#endif // STAGEITEM_H_INCLUDED
