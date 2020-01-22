// Gabriel Martinica and Eduardo Peña
// Spring 2019 
// Robotics Competition TTU 
// This robot follows a black line on a white background
// It uses three photosensor to determine if the robot is
// centered in the black line and adjusts the DC motors accordingly

int motorPinright1 = 9;
int motorPinright2 = 6;
int motorPinleft1 = 3;
int motorPinleft2 = 5;
int sensorpincenter = A5;
int sensorpinleft = A1;
int sensorpinright = A2;
bool sensorcenterwhite;
bool sensorleftwhite;
bool sensorrightwhite;

void setup() {
  pinMode(sensorpincenter, INPUT);
  pinMode(sensorpinleft, INPUT);
  pinMode(sensorpinright, INPUT);
  pinMode(motorPinright1, OUTPUT);
  pinMode(motorPinright2, OUTPUT);
  pinMode(motorPinleft1, OUTPUT);
  pinMode(motorPinleft2, OUTPUT);
  
  
}

void loop() {

  if (analogRead(sensorpincenter) > 530) /* More than 530 is white */
  {
    sensorcenterwhite = true;
  }
  else
  {
    /* Less is black */
    sensorcenterwhite = false;
  }
  if (analogRead(sensorpinleft) > 530)
  {
    sensorleftwhite = true;
  }
  else
  {
    sensorleftwhite = false;
  }
  if (analogRead(sensorpinright) > 500)
  {
    sensorrightwhite = true;
  }
  else
  {
    sensorrightwhite = false;
  }
  
  // Uncomment the following line to read sensor value
  
  /* Serial.println(analogRead(sensorpincenter)); */

  /* if the robot is on the center and sees black of the line and the two sensors on the side see white*/


  
  if (sensorcenterwhite == false && sensorleftwhite == true && sensorrightwhite == true)
  {
    /* Make it go forward*/
    analogWrite(motorPinright1,125);
    analogWrite(motorPinright2, 0);
    analogWrite(motorPinleft1, 125);
    analogWrite(motorPinleft2, 0);
    
  }
  else if (sensorcenterwhite == true && sensorleftwhite == true && sensorrightwhite == false)
  {
    /* Make it go right */
    analogWrite(motorPinright1, 0);
    analogWrite(motorPinright2, 115);
    analogWrite(motorPinleft1,115);
    analogWrite(motorPinleft2, 0);
    
  
  }
   else if (sensorcenterwhite == false && sensorleftwhite == true && sensorrightwhite == false)
  {
    /* Make it go right a lot */
    analogWrite(motorPinright1, 0);
    analogWrite(motorPinright2, 170);
    analogWrite(motorPinleft1, 170);
    analogWrite(motorPinleft2, 0);
    
  
  }
   else if (sensorcenterwhite == false && sensorleftwhite == false && sensorrightwhite == true)
  {
    /* Make it go left a lot */
    analogWrite(motorPinright1, 225);
    analogWrite(motorPinright2, 0);
    analogWrite(motorPinleft1, 0);
    analogWrite(motorPinleft2, 235);
    
  
  }
  else if (sensorcenterwhite == true && sensorleftwhite == false && sensorrightwhite == true)
  {
    /* Make it go left */
    analogWrite(motorPinright1, 225);
    analogWrite(motorPinright2, 0);
    analogWrite(motorPinleft1, 0);
    analogWrite(motorPinleft2, 235);
    
  
  }
    
  else if (sensorcenterwhite == true && sensorleftwhite == true && sensorrightwhite == true)
  {
    /* If all the sensors see white */
    analogWrite(motorPinright1, 0);
    analogWrite(motorPinright2, 155);
    analogWrite(motorPinleft1, 110);
    analogWrite(motorPinleft2, 0);
  }
  else if (sensorcenterwhite == false && sensorleftwhite == false && sensorrightwhite == false)
  {
    /* If all the sensors see black */
     analogWrite(motorPinright1, 125);
    analogWrite(motorPinright2, 0);
    analogWrite(motorPinleft1, 0);
    analogWrite(motorPinleft2, 105);
  }
  else
  {
    analogWrite(motorPinright1, 0);
    analogWrite(motorPinright2, 0);
    analogWrite(motorPinleft1, 0);
    analogWrite(motorPinleft2, 0);
  }



  #if 0
    /* if the center sensor sees black and the right sensor sees black and the left sensor sees white */
  if (sensorcenterwhite == false && sensorleftwhite == false && sensorrightwhite == true)
  {
    
    /* Make it go left */
    analogWrite(motorPinright1, 190);
    analogWrite(motorPinright2, 0);
    analogWrite(motorPinleft1, 0);
    analogWrite(motorPinleft2, 0);
    
  }
  /* if the sensor center is black and the sensor left is white and the sensor right is black */
  if (sensorcenterwhite == false  && sensorleftwhite == true && sensorrightwhite == false)
  {
    /* Turn right */
  
    analogWrite(motorPinright1, 0);
    analogWrite(motorPinright2, 0);
    analogWrite(motorPinleft1, 190);
    analogWrite(motorPinleft2, 0);
  }
  /* if the sensor center is white and the sensor left is white and the sensor right is black */
  if (sensorcenterwhite == true && sensorleftwhite == true && sensorrightwhite == false)
  {
    /* Turn left a lot */
    analogWrite(motorPinright1, 190);
    analogWrite(motorPinright2, 0);
    analogWrite(motorPinleft1, 0);
    analogWrite(motorPinleft2, 0);
    
  }
  /* if the sensor center is white and the sensor left is black and the sensor right is white */
  if (sensorcenterwhite == true && sensorleftwhite == false && sensorrightwhite == true)
  {
    /* Turn right a lot */
    analogWrite(motorPinright1, 0);
    analogWrite(motorPinright2, 0);
    analogWrite(motorPinleft1, 190);
    analogWrite(motorPinleft2, 0);
    
  }
  else
  {
    /* Stop */
    analogWrite(motorPinright1, 0);
    analogWrite(motorPinright2, 0);
    analogWrite(motorPinleft1, 0);
    analogWrite(motorPinleft2, 0);
  }
  
 #endif


}
