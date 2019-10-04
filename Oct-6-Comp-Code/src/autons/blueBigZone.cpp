#include "main.h"

void blueBigZone() {

    
    runIntk(80);
    delay(500);
    moveBase(1100, 1100, 2000, 100);
    delay(100);
    runIntk(0);
    moveBase(-500, -500, 1000, 100);
    moveBase(200, -200, 1000, 80);
    moveBase(500, 500, 1500, 80);
    
    

    /*-----------------------------------------------------------------------------------------********************************


    runIntk(85); //run intake
    //need to somehow open up the tray and anti tip cause they passive
    moveBase(520, 520, 1000, 1000); //move forward, pick up cube
    runIntk(0); //stop intake otherwise cube might fly out of tray
    //turn -90 degrees
    runIntk(85); //start up intake again
    //move forward to pick up other cube and even go past it
    runIntk(0);
    //turn -90 degrees
    runIntk(-25); //want to let go of these three cubes
    //move backward
    //turn -90 degrees
    //move tray up, but kinda slowly
    //move forward, hopefully slowly i guess eh, barely infront of cubes
    //move forward some more, tiny bit, and pull tray down. RLY COMPLICATED!!! hopefully the 4 cube stack falls onto tray
    //move backward
    //turn 90 degrees
    //run intake inward
    //move forward, pick up those three cubes previously left behind
    //move forward up to goal zone border thing
    //push tray forward at some speed that doesnt knock the 7 cubes down
    //move backward
    
    -------------------------------------------------------------------------------------------------------*/

}