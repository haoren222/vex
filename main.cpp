/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       haoren                                                    */
/*    Created:      2023/10/22 12:20:58                                       */
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
 
int main()
{
    double a,b,c;
vex::controller con1;
 c=150;///设置一个速度基准
 while (1)
 {
    a=(double)(con1.Axis3.position())/100;//读取3轴上的位置信息，并将位置转化为数字赋予a
    b=(double)(con1.Axis4.position())/100;//读取4轴上的位置信息，并将位置转化为数字赋予b
    motor1.spin(fwd,c*((a+b)),rpm);
      motor2.spin(fwd,c*((a+b)),rpm);//利用a,b中读取的摇杆所在位置控制右边两轮的速度
        motor3.spin(fwd,c*((a-b)),rpm);
          motor4.spin(fwd,c*((a-b)),rpm);//同时控制左边两轮的速度，在4轴位置大于0时，使左右轮形成差速，最后达到转弯的效果
    
 }
 

    
return 0;

}

