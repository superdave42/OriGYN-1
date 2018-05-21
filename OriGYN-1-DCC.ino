
//                                                  OriGYN-1 3D CNC Probe

// Designed by David Cook of www.dc-concepts.com    with help from Arduino examples, YouTube videos and help in the forums.
// Arduino sketch hacked together from bits of stuff here and there ( I have no idea what I'm doing obviously, but it works)
// Feel free to modify and distribute this code however you want.  
// This is a fun project to learn about sensors,microcontrolers,CNC,interfaces and does have potential to be very accurate.
// This code is intended to read a touch/contact event from a piezoelectric disc.  The Piezo disc can output up to ~100 volts AC. 
// I used a 1M resistor accross +,- of the Piezo disc to remove the built up charge and used a 5.1 volt Zener diode to clip the AC output to 5 volts
// Trigger is adjustable, I suggest atarting with 25 and go up or down from there in increments of 2.

// I am using this on my Openbuilds CNC machine using an Arduino Uno & CNC shield with Grlbl 1.1 and Universal Gcode Platform
// my OriGYN-1 prototype in action  https://www.youtube.com/watch?v=ldndRDcyWkg

//************************************************************************************************************************************************************************************************************************************************************

// these constants will not change

const int PiezoPin= A1; // analog input from Piezo + (clipped with 5.1 zener diode to protect input)..
const int Probe_Pin= 12;  //  This is the digital output for the CNC Probe as well as a LED indicator if used.(change to your desired PIN ).  (I had to use a NPN transitor and a pullup to invert the signal for GRBL probe input)


// These variables will change :

int ledState = LOW;  // ledState used to set the LED

int Trigger= 15 ;  //Set the Piezo trigger level (25 is a good place to start)


 
void setup()
{
//Serial.begin(9600); //Start the Serial Monitor  un-comment to activate
pinMode(Probe_Pin, OUTPUT); // this sets the constant LED_Pin as an output.
}


void loop()
{
// here is where you'd put code that needs to be running all the time.

 
int reading= analogRead(PiezoPin);
//Serial.println(reading);    //display read values on the serial monitor     un-comment to activate

if (reading > Trigger) // If the rading is greater that the Trigger setting it will set the Probe Pin HIGH for the duration set in milliseconds in delay command below.
{
 
digitalWrite(Probe_Pin, HIGH);  // Lights up the LED pin ( or triggers whatever you have plugged in there) and stays HIGH for the duration set below.
delay(200);                   // simple delay in milliseconds.  in this example the delay command is ok to use because we are only doing 1 thing in the loop.

digitalWrite(Probe_Pin, LOW);   // re-sets the LED pin back to LOW until the trigger is activated again next time through the loop.

}
}
