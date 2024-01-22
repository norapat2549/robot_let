float position_FW()
  {
    float position_L = map(mcp_f(1),max_mcp_f(1), min_mcp_f(1), 0, 30);
    float position_R = map(mcp_f(2), max_mcp_f(2), min_mcp_f(2), 0, 30);
    return position_L - position_R;
  }
  float position_03()
  {
    float position_L = map(mcp_f(0),max_mcp_f(0), min_mcp_f(0), 0, 30);
    float position_R = map(mcp_f(3), max_mcp_f(3), min_mcp_f(3), 0, 30);
    return position_L - position_R;
  }
void FW_last_green(int sp, int tm)   /////////////////////////////-------------->>>คำสั่งเดินหน้า
  {

      
          lasts_time = millis();
        while(millis() - lasts_time < tm)
      {
          errors = position_03();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (1.5 * P) + (0.00015 * I) +(0.3* D); 
          
          Motor(sp - PID_output, sp + PID_output); 
      }

    Motor(0, 0);delay(100);
  }
void fw_green(int sp, float tm)
{
 Motor(0,0); delay(500);
       calibration_Yak();
       delay(200);
       calibration_Yak();
          lasts_time = millis();
        while(millis() - lasts_time < tm)
      {
          errors = error_Yaw_float(); //position_FW();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (5 * P) + (0.00015 * I) +(0.3* D); 
          
          Motor(sp - PID_output, (sp+5) + PID_output); 
      }
      Motor(0,0);delay(200);   
}
void fw_time(int sp, float tm)
{
          lasts_time = millis();
        while(millis() - lasts_time < tm)
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
          
          Motor(sp - PID_output, sp + PID_output); 
      }
      Motor(0,0);delay(100);
}
void robot_FW_blue(int sp, float kp)   /////////////////////////////-------------->>>คำสั่งเดินหน้า
  {


    while(1)
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
          PID_output = (kp * P) + (0.00015 * I) +(0.3* D); 
          
          Motor(sp - PID_output, sp + PID_output); 
          if(mcp_f(0)< _blue[0]-100&& mcp_f(3)< _blue[3]-100)
            {
              break;
            }
      }
    Motor(0, 0);delay(100);
  }
void robot_FW_line(int sp, float kp)   /////////////////////////////-------------->>>คำสั่งเดินหน้า
  {

      
    while(1)
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
          PID_output = (kp * P) + (0.00015 * I) +(0.3* D); 
          
          Motor(sp - PID_output, sp + PID_output); 
          if(mcp_f(0)< md_mcp_f(0)-100&& mcp_f(3)< md_mcp_f(3)-100)
            {
              break;
            }
      }
    Motor(0, 0);delay(100);
  }

      
  
