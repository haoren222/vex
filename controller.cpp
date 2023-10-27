#include "vex.h"

using namespace vex;


vex::brain       Brain;



vex::motor motord1(16,true);
 vex::motor motord2(17,true);
 vex::motor motord3(18);
 vex::motor motord4(19);//底盘

 vex::motor motor5(0);
  vex::motor motor6(9,true);
vex::motor_group motorG1(motor5,motor6);//吸吐装置

vex::motor motor7(1,true);
vex::motor motor8(8);
vex::motor_group motorG2(motor7,motor8);//弹射装置

vex::motor motor9(10);
vex::motor motor10(11,true);
vex::motor_group motorG3(motor9,motor10);//爬杆装置

 vex::controller con1; //控制器

int f1=0;
int f2=0;
int f3=0;
int v1;
int vu;
void xi()
{
if(f1==1)
{
f1=0;
v1=0;
}
else{
  f1=1;
  v1=150;
  }
}
void ti()
{
 if(f3==0)f3==1;
}
void pi()
{
  if(f2==0)f2==1;
}


int main()
{
    double a,b,c;
    
  

 c=100;///设置一个速度基准
 while (1)
 {
    a=(double)(con1.Axis3.position())/100;//读取3轴上的位置信息，并将位置转化为数字赋予a
    b=(double)(con1.Axis4.position())/100;//读取4轴上的位置信息，并将位置转化为数字赋予b
    if(a<0)
    {
        b=-b;
    }//使向左后或右后的转向和轴的旋转相同
    motord1.spin(fwd,c*((a+b/2)),rpm);
      motord2.spin(fwd,c*((a+b/2)),rpm);//利用a,b中读取的摇杆所在位置控制右边两轮的速度
        motord3.spin(fwd,c*((a-b/2)),rpm);
         motord4.spin(fwd,c*((a-b/2)),rpm);//同时控制左边两轮的速度，在4轴位置大于0时，使左右轮形成差速，最后达到转弯的效果
if(con1.ButtonDown.pressing() == true)
{vu=-20;}



else if(con1.ButtonUp.pressing() == true)
{ vu=20;}
else 
{
vu=0;
}
 motor9.spin(fwd,vu,rpm);
motor10.spin(fwd,vu,rpm);
con1.ButtonA.pressed(xi);
if(con1.ButtonB.pressing()==true)
{
  motor5.spin(fwd,-v1,rpm);
   motor6.spin(fwd,-v1,rpm);
}
else
{
motor5.spin(fwd,v1,rpm);
 motor6.spin(fwd,v1,rpm);
}

if(con1.ButtonR1.pressing()==true)
{
  motor7.spin(fwd,50,rpm);
   motor8.spin(fwd,50,rpm);
}
else
{
   motor7.spin(fwd,0,rpm);
   motor8.spin(fwd,0,rpm);
     motor7.stop(hold);
   motor8.stop(hold);
}
 }
  
    
return 0;

}