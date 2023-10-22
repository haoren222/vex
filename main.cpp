/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       haoren                                                    */
/*    Created:      2023/10/19 20:43:31                                       */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here
vex::motor motor1(16,true);
 vex::motor motor2(17,true);
 vex::motor motor3(18);
 vex::motor motor4(19);
 int a,b,c;
int main()
{
vex::controller con1;
int c=150;
 while (1)
 {
    a=con1.Axis3.position(pct);
    b=con1.Axis4.position(pct);
    motor1.spin(fwd,c*((a+b)/100),rpm);
      motor2.spin(fwd,c*((a+b)/100),rpm);
        motor3.spin(fwd,c*((a-b)/100),rpm);
          motor4.spin(fwd,c*((a-b)/100),rpm);
    
 }
 

    
return 0;
}
