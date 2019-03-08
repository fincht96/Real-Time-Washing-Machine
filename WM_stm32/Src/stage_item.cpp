

#include "stage_item.h"


StageItem::StageItem()
{
		m_type = HEAT;
		setStageNumber(3);
	
}






void StageItem::setType(enum StageType type)
{
		// assigns type to config
		m_type = type;
	
		// holds a temporary value
		uint8_t temp_val;
	
		switch(type)
		{
			case EMPTY:
				temp_val = 1;
			
			case WASH_SLOW:
				temp_val = 4;
			
			case WASH_HIGH:
				temp_val = 4;
			
			case RINSE_SLOW:
				temp_val = 5;
			
			case RINSE_HIGH:
				temp_val = 5;
			
			case DRY:
				temp_val = 7;
			
			case FILL:
				temp_val = 2;
			
			case HEAT:
				temp_val = 3;
			
			case COMPLETE:
				temp_val = 8;
			
			
		}
		
	
		setStageNumber(temp_val);
	
}




StageType StageItem::getType()
{
	return m_type;
}



uint8_t StageItem::getStageNumber()
{
	return m_stage_number;
}



void StageItem::setTimeDuration(uint32_t time_duration)
{
	
	
}



uint32_t StageItem::getTimerDuration()
{
		return m_time_duration;
}




void StageItem::setStageNumber(uint8_t stage_number)
{
		m_stage_number = stage_number;
}


