

int photosensor = A0; //light sensor connected to A0
int led1 = D6;
int led2 = D5;

// Declaring variables
int analogvalue;  
char light[30];


void setup() {

	Serial.begin();
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);

	Particle.variable("analogvalue", analogvalue);

    Particle.variable("Stringlum", light);


}


void loop() {

    //Reading light value
	analogvalue = analogRead(photosensor);
	
	if (analogvalue < 2000 ) 
	{
	Particle.publish("lightLevel","Insufficient Light",PRIVATE);
	digitalWrite(led2,HIGH);
	}
	else
	{
	digitalWrite(led2,LOW);   
	}
	if (analogvalue >= 2000 ) 
	{
	Particle.publish("lightLevel","Sufficient Light",PRIVATE);   
	digitalWrite(led1,HIGH);
	}
	else
	{
	digitalWrite(led1,LOW);   
	}
	
	//Converting light value into string for particle.publish()
    sprintf(light,"%d", analogvalue);
    //Publishing
	Particle.publish("light", light, PRIVATE);


	delay(10000);
}

