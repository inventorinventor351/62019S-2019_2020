#include "main.h"

void autonomous() 
{

    if(autonCount == 0)
        blueBigZone();

    if(autonCount == 1)
        blueSmallZone();
    
    if(autonCount == 2)
        redBigZone();

    if(autonCount == 3)
        redSmallZone();

        
        


}