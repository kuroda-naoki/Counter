#include <Arduino.h>
#include <M5StickCPlus.h>

bool isButton(int pin)
{

  static bool flag = false;

  if (digitalRead(pin) == 1)
  {
    if (!flag)
    {
      flag = true;
      return true;
    }
  }
  else
  {
    flag = false;
  }

  return false;

}

void countUpdate(int count)
{

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(80, 30);
  M5.Lcd.println(count);
  
}

void setup()
{

  //pinMode(BUTTON_A_PIN, INPUT);

  M5.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(100, 80);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(20);

}

void loop()
{

  static int count = 0;
  static int oldcount = 0;

  oldcount = count;

  if (isButton(BUTTON_A_PIN)) count++;
  if (isButton(BUTTON_B_PIN)) count--;

  if (oldcount != count) countUpdate(count);

  delay(10);

}