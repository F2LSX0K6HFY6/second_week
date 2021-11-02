#include <ros.h>
#include <std_msgs/Int8.h>
ros::NodeHandle nh;

std_msgs::Int8 count;
ros::Publisher counter("counter", &count);
int countt=0;

#define signalA PB_12
#define signalB PB_13

void setup() {
  // put your setup code here, to run once:
 
  nh.initNode();
  nh.advertise(counter);
  pinMode(signalA,INPUT);
  pinMode(signalB,INPUT);
}

void loop() {
/// std_msgs.data = countt;
 counter.publish( &count );
  nh.spinOnce();
  delay(1000);
  // put your main code here, to run repeatedly:
  attachInterrupt(digitalPinToInterrupt(signalA),fn1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(signalB),fn2,CHANGE);
 
}
void fn1 ()
{
  if (digitalRead(signalA)!=digitalRead(signalB))
      countt=countt+1;
  else
      countt=countt-1;
  /*Serial.println("counter= ");
  Serial.println(count);*/
  }

 void fn2 ()
{
  if (digitalRead(signalA)==digitalRead(signalB))
      countt=countt+1;
  else
      countt=countt-1;
 /*Serial.println("counter= ");
 Serial.println(count);*/
  }
