#include "program_data.h"


// STAGE TYPES

// WS (wash slow)
// WH (wash high)
// RS (rinse slow)
// RH (rinse high)
// EM (empty)
// DR (dry)
// FL (fill)
// HT (heat)
// CP (complete)



// DURATION

// MS -> LS
// i.e. 56 		is 50 + 6 seconds = 56 seconds



// Up to 256 programs can be added, and each program can only have up to 15 stages, with a maximum time duration of 99 seconds




 const char* pProgramData =		{
																// program 0
																"WS,05 "
                                "WH,07 "
																"FL,12 "
																"HT,09 "
																"DR,04 "
                                "CP,00 "

                                // program 1
                                "RH,04 "
                                "WS,44 "
                                "CP,00 "

                                // program 2
                                "RH,04 "
                                "WS,03 "
                                "CP,00 "
																
																// program 3
                                "RH,04 "
                                "CP,00 "
																
	 
                               };
