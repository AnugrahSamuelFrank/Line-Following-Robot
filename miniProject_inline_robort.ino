int EnB=13;   //Initializing the pin numbers
int In3=14; 
int In4=12; 

int EnA=27;
int In1=26;
int In2=25;

int ir1=33;
int obj1;
int ir2=32;
int obj2;

void setup()
{ 
  pinMode(EnB,OUTPUT);              //Configuring the pins as inputs or outputs
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);


  pinMode(EnA,OUTPUT);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);

  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
 }

void loop()
{ 
  obj1=digitalRead(ir1);                                     //Scanning whether the line is present or not
  obj2=digitalRead(ir2);                                    //path present=>0 otherwise=>1 
  
  if(obj1==0&&obj2==0)                                     //if path is sensed by both IR sensor
  {
    analogWrite(EnA,50);                                  //giving pulse width modulation to adjust speed  
    digitalWrite(In1,0);                                   //direction in clockwise
    digitalWrite(In2,1);
    
    analogWrite(EnB,50);                                  //giving pulse width modulation to adjust speed 
    digitalWrite(In4,0);                                   //direction in clockwise
    digitalWrite(In3,1);
    delay(200);
  }

  if(obj1==0&&obj2==1)                                     //if path is sensed by left IR sensor and not by right ir sensor
  {
    analogWrite(EnA,50);                                   //giving pulse width modulation to adjust speed 
    digitalWrite(In1,0);                                    //stopping the right motor
    digitalWrite(In2,0);
    
    analogWrite(EnB,50);                                   //giving pulse width modulation to left motor to adjust speed 
    digitalWrite(In4,0);                                    //direction in clockwise
    digitalWrite(In3,1);
    delay(200);
  }

  if(obj1==1&&obj2==0)                             //if path is not sensed by left IR sensor and is sensed by right ir sensor
  {
    analogWrite(EnA,50);                          //giving pulse width modulation to right motor to adjust speed
    digitalWrite(In1,0);                           //direction in clockwise
    digitalWrite(In2,1);
    
    analogWrite(EnB,50);                         //giving pulse width modulation to adjust speed
    digitalWrite(In4,0);                         //stopping the left motor
    digitalWrite(In3,0);
    delay(200);
  }

  if(obj1==1&&obj2==1)                         //if path is not sensed by both IR sensors
  {
    analogWrite(EnA,0);                        //giving pulse width modulation to adjust speed
    digitalWrite(In1,0);                      //stopping the right motor
    digitalWrite(In2,1);
    
    analogWrite(EnB,0);                     //giving pulse width modulation to adjust speed
    digitalWrite(In4,0);                    //stopping the left motor
    digitalWrite(In3,1);
    delay(200);
  }
}
