/*** 
**** Smart Elex 30d UART Packetized Serial Mode
**** @author : Harsh Chotaliya (20BEC039)
**** @Email  : 20BEC039@nirmauni.ac.in
**** @LinkedIn https://www.linkedin.com/in/harshchotaliya
***/


/*
Used Library : Serial 
*/

/*
Function for Communication with Smartelex 30d using UART Packetized protocol
*/

/* 
*   DIP Switch1   DIP Switch2   DIP Switch3  DIP Switch4  Baud Rate
*        0             0           1              1          9600
*        0             1           1              1         19200          
*        1             0           1              1         38400
*        1             1           1              1         57600
*
*/

/*
* dir1      : motor1 direction
* dir2      : motor2 direction
* motor_no1 : ON-1  OFF-0
* motor_no2 : ON-1  OFF-0
* speed1    : motor1 speed
* speed2    : motor2 speed
*/

void control_motor_speed(bool dir1,bool dir2,bool motor_no1,bool motor_no2,int speed1,int speed2)
{
    int data_send;

    // Start Frame
    Serial1.write('*');
    
    // Motor direction & ON/OFF configuration
    data_send=(8*motor_no1+2*motor_no2+dir1*4+dir2*1);
    Serial1.write(data_send);

    //Motor 1 Speed
    Serial1.write(speed1*motor_no1);

    //Motor 2 Speed
    Serial1.write(speed2*motor_no2);
  
    // End of Frame
    Serial1.write('#');
  
}
void setup() 
{

  // Select Baudrate as per your need 
  Serial1.begin(57600);

}

void loop() 
{
  control_motor_speed(0,1,1,1,20,20);
}
