/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here 
#define BLYNK_TEMPLATE_ID           "TMPLLfq86kcK"
#define BLYNK_TEMPLATE_NAME         "Quickstart Template"
#define BLYN_AUTH_TOKEN            "VJhUzUbDuy-lBEhrixnivujA8t2pmVgv"
*/
#define BLYNK_TEMPLATE_ID "TMPL4MWjF3WiP"
#define BLYNK_TEMPLATE_NAME "Hello LED"
#define BLYNK_AUTH_TOKEN "sWqU7m7cxcdpowGQ1a4gV-oL-5fvjezW"
#define LED_PIN 13

#define BLYNK_PRINT Serial

#include <SPI.h>
#include <WiFi.h>
#include <BlynkSimpleWifi.h>

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "VodafoneMobileWifi";
char pass[] = "6913055804";
WidgetLED led1(V1);

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update LED
  Blynk.virtualWrite(V0, value);
  digitalWrite(13, value);  //LED 13 the built-in LED will light when the Blynk button is pressed
                            //Change this to any other LED 
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
  
  int tempVal = analogRead(A0);    //tempVal can be used to read and display Analog Port 0
  Blynk.virtualWrite(V4,tempVal);
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
