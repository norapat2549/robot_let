#include <my_rp_2wd.h>
#include <Wire.h>
#include <EEPROM.h>
#define EEPROM_ADDR 0x50
#include <my_mpu6050.h>  


//------------------------->>

int wait_time = 2000;        ///----------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>> เวลาในการรอ

int _blue[]= {500,500,500,500,450};     ///----------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>  ค่า เซนเซอร์พื้นน้ำเงิน


unsigned long lasts_time = millis();


void setup()
  {    
     Serial.begin(9600);
     sensor_set();              // ค่าเริ่มต้น eeprom, bit_analogRead=>12   
      setup_mpu();
     mydisplay_background(black);
     mydisplay("MY-MAKERS", 20, 30, 2, white);
     calibration_Yak();
   
     servo(10,90);
     servo(11,5);
     servo(23,180);
 

    _sw();


    while(digitalRead(20) == 1)
    {
       String sensor_20 = String (digitalRead(20)); 
         
          mydisplay_background(black);
          mydisplay(sensor_20,  10, 45, 2, white);
    }
    bz(500);
    delay(1000);
    servo(10,120);
  

   fw_time(70,600);
   //robot_FW_blue(70,1.5);
   robot_FW_line(70,1.5);
   robot_TL(80,10);  
   robot_FW_line(70,1.5);
   robot_TL(80,10);  
   robot_FW_line(70,1.5);
   robot_TR(80,10);
   
  
robot_FW_line(50,1);
Motor(-30,-30);delay(250);
robot_FW_line(40,1);
while(1)
{
    if(mcp_f(0)>md_mcp_f(0)&&mcp_f(3)<md_mcp_f(3)) 
       {
         Motor(-5, 30);
       }
     else if(mcp_f(0)<md_mcp_f(0)&&mcp_f(3)>md_mcp_f(3)) 
       {
         Motor(30, -5);
       }
     else{}
     {
      break;
     }  
}
Motor(0,0);delay(300);
fw_green(50,6000);
FW_last_green(50,300);


robot_FW_blue(60,2);
/////////////////////////////////////////////////////////////////////////
        
  
  while(mcp_f(4)>_blue[4]-200)
      {
          errors = position_FW();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (1.5 * P) + (0.00015 * I) +(0.3* D); 
          
          Motor(60 - PID_output, 60 + PID_output); 
      }
   delay(100);
   Motor(-30, -30);delay(30);
   Motor(0, 0);delay(800);
   
    delay(wait_time);
   /////////////////////////////////////////////////////////////////////////
   
    do{Motor(70, -70);}while(mcp_f(3) > _blue[3]-200);
    do{Motor(70, -70);}while(mcp_f(2) > _blue[2]-200);
    delay(100);
    Motor(-70, 70);delay(50);
    Motor(0, 0);delay(100);
    


fw_time(70,600);
robot_FW_line(50,1);
robot_TR(80,10);

fw_time(50,9000);
robot_FW_line(50,1);
fw_time(60,1100);
servo(10,140);
delay(500);
servo(11,175);
delay(1000);
servo(10,120);
delay(500);
servo(10,90);
delay(300);
servo(11,5);
delay(500);
servo(23,10);






   

  } 

void loop() 
  {
    
    /*
       value = digitalRead(digitalPin); 
  Serial.print("value = "); 
  Serial.println(value);
   */
    /*
  value = digitalRead(digitalPin); 
  Serial.print("value = "); 
  Serial.println(value);
  if(value == 0){
    bz(500);
  }
  
  delay(100);
  */

  
        
  }
