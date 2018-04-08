int i,j,temp;
int def=0;//for default ie; if density of trafic is same at all junctions

int count=0;
int a;

int count1=1;//for if loop conditions // it is given 1 since  the first time it iterates from function 1
int count2=0;//for if loop conditions
int count3=0;//for if loop conditions
int count4=0;//for if loop conditions


int value1=0;//for counting the density value in signal 1
int value2=0;//for counting the density value in signal 2
int value3=0;//for counting the density value in signal 3
int value4=0;//for counting the density value in signal 4


void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  for (i=2;i<14;i++)
  {
    pinMode(i,OUTPUT);//for allocating the leds used
  }

}
void loop() 
{
  // put your main code here, to run repeatedly:

  if(count==0)//for the 1st iteration
  {
    count++;
    goto function1;
  }


function1:// for 1st lane
  if(count1==1)
  {
    Serial.println("FUNCTION 1 IS WORKING\n");
    digitalWrite(2,LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);


    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);

    if((digitalRead(5))==LOW)
    {
      analogWrite(A5,0);//for checking the red light violation on lane 2
    } 

    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);


    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);                      
    count1=0;
    //since the green light is on this lane ,the traffic density on this lane not calculated   
    for(i=0;i<20;i++)
    {
      delay(250);
      if((a=digitalRead(A2))>0)//taking input from IR at lane 2
      {

        value2+=1;//calculating traffic density on lane 2
        Serial.print("DENSITY ON ROAD 2:");
        Serial.println(value2);
      }
      delay(250);
      if((a=digitalRead(A3))>0)//taking input from IR at lane 3
      {
        value3+=1;//calculating traffic density on lane 3
        Serial.print("DENSITY ON ROAD 3:");
        Serial.println(value3);
      }

      delay(250);
      if((a=digitalRead(A4))>0)//taking input from IR at lane 3
      {
        value4+=1;//calculating traffic density on lane 4
        Serial.print("DENSITY ON ROAD 4:");
        Serial.println(value4);
      }

    }
    Serial.print("    FINAL DENSITY ON ROAD 2:");
    Serial.println(value2);
    Serial.print("    FINAL DENSITY ON ROAD 3:");
    Serial.println(value3);
    Serial.print("    FINAL DENSITY ON ROAD 4:");
    Serial.println(value4);
    Serial.println("\n");               
  }        

  delay(250);


  if(value2>value1 && value2>value3 && value2>value4)//comparing densities at different lanes
  {

    count2=1;//since lane 2 should work as density there is max 
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto function2;
  }
  else if(value3>value2 && value3>value1 && value3>value4)
  {

    count3=1;//since lane 3 should work as density there is max
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto function3;
  }
  else if(value4>value2 && value4>value3 && value4>value1)
  {
    count4=1;//since lane 4 should work as density there is max
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto function4;
  }
  else
  {
    def=1;//since default function should work as density every where is equal

    count1=1;//as it should start with first lane as default(you can make any count=1 to start with that lane )   
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto fun_default;// default function, if traffic denity is equal on all four lanes
  }







function2:
  if(count2==1)
  {
    Serial.println("FUNCTION 2 IS WORKING\n");
    digitalWrite(2,HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);


    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);

    if((digitalRead(5))==LOW)
    {
      analogWrite(A5,0);
    } 

    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);


    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);                      

    count2=0;




    for(i=0;i<20;i++)
    {
      delay(250);
      if(digitalRead(A1)>0)
      {
        value1+=1;
        Serial.print("DENSITY ON ROAD 1:");
        Serial.println(value1);
      }

      delay(250);
      if(digitalRead(A3)>0)
      {
        value3+=1;
        Serial.print("DENSITY ON ROAD 3:");
        Serial.println(value3);
      }

      delay(250);  
      if(digitalRead(A4)>0)
      {
        value4+=1;
        Serial.print("DENSITY ON ROAD 4:");
        Serial.println(value4);
      }
    }
    Serial.print("    FINAL DENSITY ON ROAD 1:");
    Serial.println(value1);
    Serial.print("    FINAL DENSITY ON ROAD 3:");
    Serial.println(value3);
    Serial.print("    FINAL DENSITY ON ROAD 4:");
    Serial.println(value4);
    Serial.println("\n");  
  }     
  delay(250);
  if(value1>value2 && value1>value3 && value1>value4) 
  {
    count1=1;
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto function1;
  }
  else if(value3>value2 && value3>value1 && value3>value4)
  {

    count3=1;
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto function3;
  }
  else if(value4>value2 && value4>value3 && value4>value1)
  {
    count4=1;
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto function4;
  }
  else
  {
    def=1;
    count1=1;
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto fun_default;
  }


function3:  
  if(count3==1)
  {
    Serial.println("FUNCTION 3 IS WORKING\n");
    digitalWrite(2,HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);


    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);

    if((digitalRead(5))==HIGH)
    {
      analogWrite(A5,1000);
    } 

    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);


    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);                      

    count3=0;




    for(i=0;i<20;i++)
    {
      delay(250);
      if(digitalRead(A1)>0)
      {
        value1+=1;
        Serial.print("DENSITY ON ROAD 1:");
        Serial.println(value1);
      }
      delay(250);
      if(digitalRead(A2)>0)
      {
        value2+=1;
        Serial.print("DENSITY ON ROAD 2:");
        Serial.println(value2);
      }
      delay(250);
      if(digitalRead(A4)>0)
      {
        value4+=1;
        Serial.print("DENSITY ON ROAD 4:");
        Serial.println(value4);  
      }
    }
    Serial.print("    FINAL DENSITY ON ROAD 1:");
    Serial.println(value1);
    Serial.print("   FINAL DENSITY ON ROAD 2:");
    Serial.println(value2);
    Serial.print("    FINAL DENSITY ON ROAD 4:");
    Serial.println(value4);
    Serial.println("\n");  
  }       
  delay(250);

  if(value1>value2 && value1>value3 && value1>value4) 
  {
    count1=1;
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto function1;
  }
  else if(value2>value1 && value2>value3 && value2>value4)
  {

    count2=1;
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto function2;
  }
  else if(value4>value2 && value4>value3 && value4>value1)
  {
    count4=1;
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto function4;
  }
  else
  {
    def=1;
    count1=1;   
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto fun_default;
  }


function4:       
  if(count4==1)
  {
    Serial.println("FUNCTION 4 IS WORKING\n");
    digitalWrite(2,LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);


    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);

    if((digitalRead(5))==HIGH)
    {
      analogWrite(A5,1000);
    } 

    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);


    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);                      

    count4=0;

    for(i=0;i<20;i++)
    {
      delay(250);
      if(digitalRead(A1)>0)
      {
        value1+=1;
        Serial.print("DENSITY ON ROAD 1:");
        Serial.println(value1);  
      }

      delay(250);
      if(digitalRead(A2)>0)
      {
        value2+=1;
        Serial.print("DENSITY ON ROAD 2:");
        Serial.println(value2);
      }

      delay(250);
      if(digitalRead(A3)>0)
      {
        value3+=1;
        Serial.print("DENSITY ON ROAD 3:");
        Serial.println(value3);  
      }
    }
    Serial.print("    FINAL DENSITY ON ROAD 1:");
    Serial.println(value1);
    Serial.print("    FINAL DENSITY ON ROAD 2:");
    Serial.println(value2);
    Serial.print("    FINAL DENSITY ON ROAD 3:");
    Serial.println(value3);
    Serial.println("\n");  
  }    
  delay(250);


  if(value1>value2 && value1>value3 && value1>value4) 
  {
    count1=1;
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto function1;
  }
  else if(value2>value1 && value2>value3 && value2>value4)
  {

    count2=1;
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto function2;
  }
  else if(value3>value2 && value3>value1 && value3>value4)
  {

    count3=1;
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto function3;
  }
  else
  {
    def=1;
    count1=1;   
    value1=0;
    value2=0;
    value3=0;
    value4=0;
    goto fun_default;
  }

fun_default://it's a default function ,it works when the traffic density is equal on all 4 lanes,it starts with        
  //the first lane and then goes to all 4 lane while calculating total density at each lane
  //and then switches to the one having the traffic density the most.


  if(def==1)
  { 
    Serial.println("DEFAULT FUNCTION IS WORKING\n");

    if(count1==1)
    {
      digitalWrite(2,LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);


      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);

      if((digitalRead(5))==LOW)
      {
        analogWrite(A5,0);
      } 

      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);


      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);                      

      count2=1;
      count1=0;
      delay(1000);

      for(i=0;i<20;i++)
      {
        delay(250);
        if(digitalRead(A2)>0)
        {
          value2+=1;
          Serial.print("DENSITY ON ROAD 2:");
          Serial.println(value2);
        }

        delay(250); 
        if(digitalRead(A3)>0)
        {
          value3+=1;
          Serial.print("DENSITY ON ROAD 3:");
          Serial.println(value3);
        }

        delay(250); 
        if(digitalRead(A4)>0)
        {
          value4+=1;
          Serial.print("DENSITY ON ROAD 4:");
          Serial.println(value4);
        }
      } 
    } 
    delay(250);


    if(count2==1)
    {
      digitalWrite(2,HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);


      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);

      if((digitalRead(5))==LOW)
      {
        analogWrite(A5,0);
      }

      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);


      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);                      
      delay(1000);
      count3=1;
      count2=0;
      for(i=0;i<20;i++)
      {
        delay(250); 
        if(digitalRead(A1)>0)
        {
          value1+=1;
          Serial.print("DENSITY ON ROAD 1:");
          Serial.println(value1);
        }

        delay(250); 
        if(digitalRead(A3)>0)
        {
          value3+=1;
          Serial.print("DENSITY ON ROAD 3:");
          Serial.println(value3);
        }

        delay(250); 
        if(digitalRead(A4)>0)
        {
          value4+=1;
          Serial.print("DENSITY ON ROAD 4:");
          Serial.println(value4);
        }
      }


    }
    delay(250);


    if(count3==1)
    {
      digitalWrite(2,HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);


      digitalWrite(5,HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);

      if((digitalRead(5))==HIGH)
      {
        analogWrite(A5,1000);
      } 

      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);


      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);                      
      delay(1000);
      count4=1;
      count3=0;
      for(i=0;i<20;i++)
      {
        delay(250);
        if(digitalRead(A1)>0)
        {
          value1+=1;
          Serial.print("DENSITY ON ROAD 1:");
          Serial.println(value1);  
        }

        delay(250);
        if(digitalRead(A2)>0)
        {
          value2+=1;
          Serial.print("DENSITY ON ROAD 2:");
          Serial.println(value2);  
        }

        delay(250);
        if(digitalRead(A4)>0)
        {
          value4+=1;
          Serial.print("DENSITY ON ROAD 4:");
          Serial.println(value4);  
        }
      }

    }     
    delay(250);



    if(count4==1)
    {
      digitalWrite(2,LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);


      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);

      if((digitalRead(5))==HIGH)
      {
        analogWrite(A5,1000);
      } 

      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);


      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);                      
      delay(1000);
      count4=0;
      def=0;


      for(i=0;i<20;i++)
      {
        delay(250);
        if(digitalRead(A1)>0)
        {
          value1+=1;
          Serial.print("DENSITY ON ROAD 1:");
          Serial.println(value1);
        }

        delay(250);
        if(digitalRead(A2)>0)
        {
          value2+=1;
          Serial.print("DENSITY ON ROAD 2:");
          Serial.println(value2);
        }

        delay(250);
        if(digitalRead(A3)>0)
        {
          value3+=1;
          Serial.print("DENSITY ON ROAD 3:");
          Serial.println(value3);
        }
      }     

    }
    delay(250);
    Serial.print("    FINAL DENSITY ON ROAD 1:");
    Serial.println(value1);
    Serial.print("    FINAL DENSITY ON ROAD 2:");
    Serial.println(value2);
    Serial.print("    FINAL DENSITY ON ROAD 3:");
    Serial.println(value3);
    Serial.print("    FINAL DENSITY ON ROAD 4:");
    Serial.println(value4);
    Serial.println("\n");  

    if(value1>value2 && value1>value3 && value1>value4) 
    {
      count1=1;
      value1=0;
      value2=0;
      value3=0;
      value4=0;
      goto function1;
    }
    else if(value2>value1 && value2>value3 && value2>value4)
    {

      count2=1;
      value1=0;
      value2=0;
      value3=0;
      value4=0;
      goto function2;
    }
    else if(value3>value2 && value3>value1 && value3>value4)
    {

      count3=1;
      value1=0;
      value2=0;
      value3=0;
      value4=0;
      goto function3;
    }
    else if(value4>value2 && value4>value3 && value4>value1)
    {
      count4=1;
      value1=0;
      value2=0;
      value3=0;
      value4=0;
      goto function4;
    }
    else
    {
      def=1;
      count1=1;   
      value1=0;
      value2=0;
      value3=0;
      value4=0;
      goto fun_default;
    }

  }//def  

}//loop   

