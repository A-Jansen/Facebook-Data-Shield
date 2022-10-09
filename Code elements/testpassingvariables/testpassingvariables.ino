float a;
float b;
float c;
float d;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("please enter first");
  while (Serial.available()==0){

  }

  a=Serial.parseFloat();
  Serial.println("second number");
  while(Serial.available()==0){

  }
  b=Serial.parseFloat();

  tally(a,b,c,d);
  Serial.print("Sum");
  Serial.println(c);
  Serial.print("Difference");
  Serial.println(d);

}

void tally(float first, float second, float &sum, float &diff){
  sum=first*2;
  diff= first*2;
  Serial.println(sum);
  Serial.println(diff);
  
}
