void sw_start()
  {
    bz(100);
    bz(100);
     while(digitalRead(9)==1)
        { 
          String sen_0 = String (mcp_f(0));
          String sen_1 = String (mcp_f(1));
          String sen_2 = String (mcp_f(2));
          String sen_3 = String (mcp_f(3));
          String sen_4 = String (mcp_f(4));
          String sen_5 = String (mcp_f(5));
          String sen_6 = String (mcp_f(6));
          String sen_7 = String (mcp_f(7));  
          String mpu = String (error_Yaw_float()); 
         
          mydisplay_background(black);
          mydisplay(sen_0 +" "+ sen_1+" "+ sen_2, 10, 5, 2, white);
          mydisplay(sen_3 +" "+ sen_4+" "+ sen_5, 10, 30, 2, white);
          mydisplay(sen_6 +" "+ sen_7+" "+ mpu, 10, 45, 2, white);
          
        } 
     bz(300);
  }
void _sw()
  {
    bz(100);
    bz(100);
    

    while(digitalRead(9)==1 )
      {
        if(analogRead(29) > 4000)
           {
            cal_censor(0, 0);
           }
      String sen_0 = String (mcp_f(0));
          String sen_1 = String (mcp_f(1));
          String sen_2 = String (mcp_f(2));
          String sen_3 = String (mcp_f(3));
          String sen_4 = String (mcp_f(4));
          String sen_5 = String (mcp_f(5));
          String sen_6 = String (mcp_f(6));
          String sen_7 = String (mcp_f(7));  
          String mpu = String (error_Yaw_float()); 
         
          mydisplay_background(black);
          mydisplay(sen_0 +" "+ sen_1+" "+ sen_2, 10, 5, 2, white);
          mydisplay(sen_3 +" "+ sen_4+" "+ sen_5, 10, 30, 2, white);
          mydisplay(sen_6 +" "+ sen_7+" "+ mpu, 10, 45, 2, white);
          
        for(int i = 0; i<6; i++)
          {
            Serial.print(mcp_f(i));
            Serial.print("  ");
            delay(10);
          }
        Serial.println(" ");
      }
    mydisplay_background(black);
    mydisplay("End", 5, 10 ,2, white);

    bz(500);
  }
  /*
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
  delay(200);
       calibration_Yak();
       
          lasts_time = millis();
        while(millis() - lasts_time < tm)
      {
          errors = error_Yaw(); //position_FW();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (2 * P) + (0.00015 * I) +(0.3* D); 
          
          Motor(sp - PID_output, sp + PID_output); 
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
void robot_TR(int sp, int offset)
  {
    Motor(50, 50);delay(100);
        lasts_time = millis();
        while(millis() - lasts_time < 600)
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
        while(millis() - lasts_time < 600)
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
  /*
void fww(int spl, int spr) //////เจอเส้นหยุด
 {
     while(1)
     {
      
      if(( mcp_f(1)>md_mcp_f(1)) && (mcp_f(2)>md_mcp_f(2)) ) 
        {
          Motor(spl,spr);
        }
        
     else if((mcp_f(1) < md_mcp_f(1)) && (mcp_f(2)>md_mcp_f(2)) )   
        {
          Motor(0,spr);
        }
     else if((mcp_f(1) > md_mcp_f(1)) && (mcp_f(2)< md_mcp_f(2)) )   
        {
          Motor(spl,0);
        }
     else if((mcp_f(1)< md_mcp_f(1)) && (mcp_f(1)< md_mcp_f(2)) )   
        {
          break;
        }
        
        
     else if((mcp_f(1)< md_mcp_f(1)) && (mcp_f(2)< md_mcp_f(2)) )   
        {
          break;
        }        
     }
     
     Motor(0,0);
     
  }
/*
void boxb(int spl , int spr)  /////ออกจากบล็อกฟ้า
{
  while(1)
  {
    if((mcp_f(0)>=150)&&(mcp_f(1)>=150))
    {
       Motor(spl,spr);
    }
   else if((mcp_f(0)<=100)&&(mcp_f(1)>=250))
   {
      Motor(0,spr);
   }
   else if((mcp_f(0)>=150)&&(mcp_f(1)<150))
   {
       Motor(0,spr);
   }
   else if((mcp_f(0)<150) && (mcp_f(1)<150) )   
   {
      break;
   }
    else if((mcp_f(0)<150) && (mcp_f(1)<150) )   
   {
      break;
   }
  }
   Motor(0,0);
}
*/
/*
void fl(int spl , int spr)
{
    while(1)
  {
    if((mcp_f(0)>=200)&&(mcp_f(1)>=150))
    {
       Motor(spl,spr);
    }
   else if((mcp_f(0)<=200)&&(mcp_f(1)>=200)||( mcp_f(2)<500) && (mcp_f(3)>500)||(mcp_f(0)<=100)&&(mcp_f(1)>=250))
   {
      Motor(0,spr);
   }
   else if((mcp_f(0)>=200)&&(mcp_f(1)<200)||( mcp_f(2)>500) && (mcp_f(3)<500)||(mcp_f(0)>=150)&&(mcp_f(1)<150))
   {
       Motor(0,spr);
   }
   else if((mcp_f(0)<200) && (mcp_f(1)<200) )   
   {
      break;
   }
    else if((mcp_f(0)<2200) && (mcp_f(1)<200) )   
   {
      break;
   }
  }
   Motor(40,40);delay(100);Motor(0,0);delay(50);
   Motor(0,40);delay(700);Motor(0,0);
}
void fr(int spl , int spr)
{
    while(1)
  {
    if((mcp_f(0)>=150)&&(mcp_f(1)>=150))
    {
       Motor(spl,spr);
    }
   else if((mcp_f(0)<=200)&&(mcp_f(1)>=200)||(mcp_f(2)<=100)&&(mcp_f(3)>=250))
   {
      Motor(0,spr);
   }
   else if((mcp_f(0)>=200)&&(mcp_f(1)<200)||(mcp_f(2)<=100)&&(mcp_f(3)>=250))
   {
       Motor(0,spr);
   }
   else if((mcp_f(0)<150) && (mcp_f(1)<150) )   
   {
      break;
   }
    else if((mcp_f(0)>200) && (mcp_f(1)>200) )   
   {
      break;
   }
  }
   Motor(40,40);delay(100);Motor(0,0);delay(50);
   Motor(40,0);delay(500);Motor(0,0);
}     
void boxg(int spl , int spr)
{
  Motor(40,40);delay(300);Motor(0,0);
      while(1)
  {
    if((mcp_f(0)>100)&&(mcp_f(1)>100))
    {
       Motor(spl,(spr+3));
    }
    
   else if((mcp_f(1)<=200)&&(mcp_f(3)>=400))
   {
      Motor(0,spr);
   }
   else if((mcp_f(0)>=200)&&(mcp_f(2)<400))
   {
       Motor(0,spr);
   }
   else if((mcp_f(0)<100) && (mcp_f(1)<100)||(mcp_f(2)<100) && (mcp_f(3)<100) )   
        {
          break;
        }
                
     else if((mcp_f(0)<100) && (mcp_f(1)<100)||(mcp_f(2)<100) && (mcp_f(3)<100) )   
        {
          break;
        }
 
        
  }
  
  Motor(0,0);

}
void lineb(int spl , int spr)
{
   Motor(40,40);delay(300);Motor(0,0);
   while(1)
   {
   if(( mcp_f(0)>200) && (mcp_f(2)>200)) //////////////หาเส้นดำ
      {
        Motor(spl,0);
      }
     else if (( mcp_f(1)>200) && (mcp_f(3)>200))
     {
       Motor(0,spr);
     }
   }
  while(1)
  {
      
     {
      
      
      if(( mcp_f(0)>500) && (mcp_f(2)>500)) //////////////หาเส้นดำ
      {
        Motor(spl,0);
      }
     else if (( mcp_f(1)>500) && (mcp_f(3)>500))
     {
       Motor(0,spr);
     }
     */
      /*
     if((mcp_f(0)>300)&&(mcp_f(1)>300)) //ถ้าลบcommenให้เปลี่ยนตรงนี้จาก if เป็น else if
        {
          Motor(spl,spr);
        }
        
     else if((mcp_f(0) <200) && (mcp_f(1)>300))// ||( mcp_f(2)<200) && (mcp_f(3)>500))   //||( mcp_f(2)<500) && (mcp_f(3)>500)||(mcp_f(0)<=100)&&(mcp_f(1)>=250)
        {
          Motor(0,spr);
        }
     else if((mcp_f(0) > 300) && (mcp_f(1)<200))//||( mcp_f(2)>500) && (mcp_f(3)<200) )    //||( mcp_f(2)>500) && (mcp_f(3)<500)||(mcp_f(0)>=150)&&(mcp_f(1)<150)
        {
          Motor(spl,0);
        }
        
     else if((mcp_f(0)<150) && (mcp_f(1)<150)||(mcp_f(2)<150) && (mcp_f(3)<150) )   //||(mcp_f(0)<150) && (mcp_f(1)<150)
        {
          break;
        }
        
        
     else if((mcp_f(0)<150) && (mcp_f(1)<150) ) //||(mcp_f(0)<150) && (mcp_f(1)<150)  
        {
          break;
        }        
     }
     
     Motor(0,0); 
  }
}
*/

  
