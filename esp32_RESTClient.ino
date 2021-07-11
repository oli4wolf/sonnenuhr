/**
 * Just a quick hack of code with
 * Modified code https://github.com/arduino-libraries/NTPClient
 * Followed https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use
 * And https://arduinojson.org/v6/api/dynamicjsondocument/
 */


#include <ArduinoJson.h>
#include "WiFi.h"
#include <HTTPClient.h>
#include <NTPClient.h>
#include <TimeLib.h>
#include <Adafruit_NeoPixel.h>

tmElements_t tm;
int Year, Month, Day, Hour, Minute, Second;

unsigned long sunrise, sunset, solar_noon, day_length, civil_twilight_begin, civil_twilight_end, nautical_twilight_begin, nautical_twilight_end, astronomical_twilight_begin, astronomical_twilight_end;

int last_daylight_position = 0;

const char* ssid = "";
const char* password =  "";

// By default 'pool.ntp.org' is used with 60 seconds update interval and
// no offset
// You can specify the time server pool and the offset, (in seconds)
// additionally you can specify the update interval (in milliseconds).
// NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// Which pin on the Arduino is connected to the NeoPixels?
#define LED_PIN   12
// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 90
// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(5000);
    Serial.println("Connecting to WiFi..");
  }

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

  timeClient.begin();
  Serial.println("Connected to the WiFi network");
}

/*
   https://api.sunrise-sunset.org/json
   https://api.sunrise-sunset.org/json?lat=36.7201600&lng=-4.4203400
   https://api.sunrise-sunset.org/json?lat=46.93578&lng=7.42996&formatted=0
   ,

   results
  sunrise "2021-05-24T03:44:37+00:00"
  sunset  "2021-05-24T19:09:46+00:00"
  solar_noon  "2021-05-24T11:27:11+00:00"
  day_length  55509
  civil_twilight_begin  "2021-05-24T03:07:13+00:00"
  civil_twilight_end  "2021-05-24T19:47:10+00:00"
  nautical_twilight_begin "2021-05-24T02:17:45+00:00"
  nautical_twilight_end "2021-05-24T20:36:38+00:00"
  astronomical_twilight_begin "2021-05-24T01:13:35+00:00"
  astronomical_twilight_end "2021-05-24T21:40:48+00:00"
  status  "OK"
*/
void loop() {

  if ((WiFi.status() == WL_CONNECTED)) {

    HTTPClient http; //Instance of HTTPClient
    http.begin("https://api.sunrise-sunset.org/json?lat=46.93578&lng=7.42996&formatted=0"); //URL for request
    int httpCode = http.GET(); //Answer of the server

    if (httpCode == 200) {
      String payload = http.getString(); //Save data in variable
      const size_t capacity = JSON_ARRAY_SIZE(1) + 5 * JSON_OBJECT_SIZE(10) + JSON_OBJECT_SIZE(1) + 200;
      DynamicJsonDocument doc(capacity);
      deserializeJson(doc, payload);
      String sunrise_txt = doc["results"][String("sunrise")];

      sunrise = getEpochTime(doc["results"]["sunrise"]);
      sunset = getEpochTime(doc["results"]["sunset"]);
      civil_twilight_begin = getEpochTime(doc["results"]["civil_twilight_begin"]);
      civil_twilight_end = getEpochTime(doc["results"]["civil_twilight_end"]);
      nautical_twilight_begin = getEpochTime(doc["results"]["nautical_twilight_begin"]);
      nautical_twilight_end = getEpochTime(doc["results"]["nautical_twilight_end"]);
      astronomical_twilight_begin = getEpochTime(doc["results"]["astronomical_twilight_begin"]);
      astronomical_twilight_end = getEpochTime(doc["results"]["astronomical_twilight_end"]);

      Serial.println(sunrise_txt);
    }
  }

  timeClient.update();
  lightzone();
  Serial.println(timeClient.getEpochTime());
  delay(10000);
}

/*
   Decide which time zone it is before hoping into the details.
   Twilights are only blue in different tonality and strength.
*/
void lightzone() {
  unsigned long actualTime = timeClient.getEpochTime();
  //Values will be reset to the actual day so it shoud work with day changes.
  // Omit the timezone and only use the +0 reference time everywhere.
  if (actualTime < astronomical_twilight_begin) {
    // Nighttime
    Serial.println("Nighttime morning");
    nighttime();
  } else if (actualTime > astronomical_twilight_begin && actualTime < nautical_twilight_begin) {
    // Daytime astronomical twilight
    Serial.println("Daytime astronomical twilight");
    astronomical_twilight();
  } else if (actualTime > nautical_twilight_begin && actualTime < civil_twilight_begin) {
    //Daytime nautical_twilight morning
    Serial.println("Daytime nautical twilight");
    nautical_twilight();
  } else if (actualTime > civil_twilight_begin && actualTime < sunrise) {
    //Daytime civil_twilight_begin morning
    Serial.println("Daytime civil twilight");
    civil_twilight();
  } else if (actualTime > sunrise && actualTime < sunset) {
    //Daytime logic here
    Serial.println("Daytime");
    daylight();
  } else if (actualTime > sunset && actualTime < civil_twilight_end) {
    //Nightime civil twilight
    Serial.println("Nighttime civil twilight");
    civil_twilight();
  } else if (actualTime > civil_twilight_end && actualTime < nautical_twilight_end) {
    //Nighttime nautical twilight
    Serial.println("Nighttime  nautical twilight");
    nautical_twilight();
  } else if (actualTime > nautical_twilight_end && actualTime < astronomical_twilight_end) {
    //Nighttime astronomical twilight
    Serial.println("Nighttime astronomical twilight");
    astronomical_twilight();
  } else if (actualTime > astronomical_twilight_end ) {
    // Nighttime
    Serial.println("Nighttime evening");
    nighttime();
  }
}


void daylight() {
  unsigned long daylength = (sunset - sunrise);
  Serial.println("daylength: ");Serial.println(daylength);
  int led_position = (sunset - timeClient.getEpochTime()) / (daylength / 90);
  Serial.println("time in day: ");Serial.println(sunset - timeClient.getEpochTime());
  Serial.println("led position: ");Serial.println(led_position);

  if(last_daylight_position != led_position){
    last_daylight_position = led_position;
    strip.fill(strip.Color( 0,   0, 0));
    strip.show();
    delay(50);
  }

  // Led position inverted with LED_COUNT
  strip.setPixelColor(LED_COUNT - led_position, strip.Color( 255,   255, 255));
  strip.show();
}

void civil_twilight() {
  strip.fill(strip.Color( 0,   0, 175));
  strip.show();
}

void nautical_twilight() {
  strip.fill(strip.Color( 0,   0, 100));
  strip.show();
}

void astronomical_twilight() {
  strip.fill(strip.Color( 0,   0, 50));
  strip.show();
}

void nighttime() {
  strip.fill(strip.Color( 0,   0, 0));
  strip.show();
}

//input "2021-05-24T03:44:37+00:00"
unsigned long getEpochTime(const char *str)
{
  sscanf(str, "%d-%d-%dT%d:%d:%d", &Year, &Month, &Day, &Hour, &Minute, &Second);
  tm.Year = CalendarYrToTm(Year);
  tm.Month = Month;
  tm.Day = Day;
  tm.Hour = Hour;
  tm.Minute = Minute;
  tm.Second = Second;
  return makeTime(tm);
}
