#include <Wire.h>
#include <DS1307.h>

int rtc[7];
byte rr[7];
char cc[7];
int ledPin =  13;
int seconds, minutes, hours, dow, day, month, year;

void setup()
{
  DDRC |= _BV(2) | _BV(3); // POWER:Vcc Gnd
  PORTC |= _BV(3); // VCC PINC3
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  /*RTC.get(rtc, true);
  if (1) //(rtc[6]<12)
  {
    RTC.stop();
    RTC.set(DS1307_SEC, 1);
    RTC.set(DS1307_MIN, 2);
    RTC.set(DS1307_HR, 3);
    RTC.set(DS1307_DOW, 7);
    RTC.set(DS1307_DATE, 14);
    RTC.set(DS1307_MTH, 8);
    RTC.set(DS1307_YR, 19);
    RTC.start();
  }*/
  //RTC.SetOutput(LOW);
  //RTC.SetOutput(HIGH);
  //RTC.SetOutput(DS1307_SQW1HZ);
  //RTC.SetOutput(DS1307_SQW4KHZ);
  //RTC.SetOutput(DS1307_SQW8KHZ);
  RTC.SetOutput(DS1307_SQW32KHZ);
}

void loop()
{
   seconds = RTC.get(DS1307_SEC, 1);
   minutes = RTC.get(DS1307_MIN, 2);
   hours = RTC.get(DS1307_HR, 3);
   dow = RTC.get(DS1307_DOW, 4);
   day = RTC.get(DS1307_DATE, 5);
   month = RTC.get(DS1307_MTH, 6);
   year = RTC.get(DS1307_YR, 7);
    Serial.print(hours);
    Serial.print(":");
    Serial.print(minutes);
    Serial.print(":");
    Serial.print(seconds);
    Serial.print(" ");
    Serial.print(dow);
    Serial.print(" ");
    Serial.print(day);
    Serial.print(".");
    Serial.print(month);
    Serial.print(".");
    Serial.print(year);
    Serial.println("");

  int i;
/*  RTC.get(rtc, true);



  for (i = 0; i < 7; i++)
  {
    Serial.print(rtc[i]);
    Serial.print(" ");
  }*/

  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
//  Serial.println(Serial.available());
  int n = Serial.available();

  if (n > 13)
  {
    char buf[2];
    Serial.println(n);
    seconds = Serial.parseInt();
    minutes  = Serial.parseInt();
    hours  = Serial.parseInt();
    dow  = Serial.parseInt();
    day  = Serial.parseInt();
    month  = Serial.parseInt();
    year = Serial.parseInt();

    Serial.print(seconds);
    Serial.print(" ");
    Serial.print(minutes);
    Serial.print(" ");
    Serial.print(hours);
    Serial.print(" ");
    Serial.print(dow);
    Serial.print(" ");
    Serial.print(day);
    Serial.print(" ");
    Serial.print(month);
    Serial.print(" ");
    Serial.print(year);
    Serial.print(" ");
    Serial.println("--");

    for (i = 0; i < Serial.available(); i++)
    {
      Serial.read();
    }

    Serial.println("SET TIME:");
    RTC.stop();
    RTC.set(DS1307_SEC, seconds);
    RTC.set(DS1307_MIN, minutes);
    RTC.set(DS1307_HR, hours);
    RTC.set(DS1307_DOW, dow);
    RTC.set(DS1307_DATE, day);
    RTC.set(DS1307_MTH, month);
    RTC.set(DS1307_YR, year);
    RTC.start();

  }
}

/*char BCD2DEC(char var) {
  if (var > 9) {
    var = (var >> 4) * 10 + (var & 0x0f);
  }
  return var;
}*/
