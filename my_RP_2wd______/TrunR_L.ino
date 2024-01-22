void robot_TR_BLUE(int sp, int offset)
  {
    Motor(50, 50);delay(100);
        lasts_time = millis();
        while(millis() - lasts_time < 500)
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
          
          Motor(70 - PID_output, 70 + PID_output); 
      }

        Motor(0, 0);delay(100);
    do{Motor(sp, -50);}while(mcp_f(3)> _blue[3]-100);
    do{Motor(sp, -50);}while(mcp_f(2)> _blue[2]-100);
    do{Motor(sp, -50);}while(mcp_f(2)< _blue[2]-100);delay(100);
    Motor(-70, sp);delay(offset);
    Motor(0, 0);delay(100);
    
           

      
         
  }
void robot_TR(int sp, int offset)
  {
    while(mcp_f(4)>md_mcp_f(4))
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
          
          Motor(70 - PID_output, 70 + PID_output); 
      }

    Motor(0, 0);delay(100);
    do{Motor(sp, -sp);}while(mcp_f(3)< md_mcp_f(3));delay(100);
    do{Motor(sp, -sp);}while(mcp_f(3)> md_mcp_f(3));
    do{Motor(sp, -sp);}while(mcp_f(2)> md_mcp_f(2));
    do{Motor(sp, -sp);}while(mcp_f(2)< md_mcp_f(2));
    Motor(-sp, sp);delay(offset);
    Motor(0, 0);delay(100);
  }
void robot_TL(int sp, int offset)
  {
   Motor(50, 50);delay(100);
        lasts_time = millis();
        while(mcp_f(4)>md_mcp_f(4))
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
          
          Motor(70 - PID_output, 70 + PID_output); 
      }
    Motor(0, 0);delay(100);
    do{Motor(-sp, sp);}while(mcp_f(0)< md_mcp_f(0));delay(100);
    do{Motor(-sp, sp);}while(mcp_f(0)> md_mcp_f(0));
    do{Motor(-sp, sp);}while(mcp_f(1)> md_mcp_f(1));
    do{Motor(-sp, sp);}while(mcp_f(1)< md_mcp_f(1));
    Motor(sp, -sp);delay(offset);
    Motor(0, 0);delay(100);
  }
