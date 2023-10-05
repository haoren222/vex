/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       haoren                                                    */
/*    Created:      2023/10/5 20:06:12                                        */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include"vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here


int main() {

   vex::motor motor1(0);
vex::motor motor2(9);
motor1.spin(vex::directionType::fwd,60,vex::velocityUnits::rpm);
motor2.spin(vex::directionType::rev,12,vex::velocityUnits::rpm);
this_thread::sleep_for(13334);
motor1.spin(vex::directionType::fwd,12,vex::velocityUnits::rpm);
motor2.spin(vex::directionType::rev,60,vex::velocityUnits::rpm);
this_thread::sleep_for(13334);
motor1.stop(brake);
motor2.stop(brake);
return 0;
    }

