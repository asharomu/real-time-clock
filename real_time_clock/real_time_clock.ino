#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal.h>
// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//initialize variable
int second,minute,hour,date,month,year,val,temp; 

String day = "";
// Initialize the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);

void setup()
{
  // Setup Serial connection
  Serial.begin(9600);
  
  // Initialize the rtc object
  rtc.begin();
  
  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(SUNDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(21, 02, 00);     // Set the time to 21:02:00 (24hr format)
  //rtc.setDate(19, 4, 2020);   // Set the date to 19.04.2020

  Wire.begin();
  Serial.begin(9600);
  
// Set up the LCD's number of columns and rows:
  lcd.begin(16,2);
  
// Print a message to the LCD.
  lcd.print("  Welcome to ");
  lcd.setCursor(0,1);
  lcd.print("Alejo's clock");
  delay(2000);
  lcd.clear();
}

void loop() 
{  
   Print_time();
   delay(150);
}

void Print_time()
{
  day  = rtc.getDOWStr();

  lcd.setCursor(0,0);
  
  if(day == "Monday")
  {
    lcd.print("MON -");
  }

  else if(day == "Tuesday")
  {
    lcd.print("TUE -");
  }

  else if(day == "Wednesday")
  {
    lcd.print("WED -");
  }

  else if(day == "Thursday")
  {
    lcd.print("THU -");
  }

  else if(day == "Friday")
  {
    lcd.print("FRI -");
  }

  else if(day == "Saturday")
  {
    lcd.print("SAT -");
  }

  else
  {
   lcd.print("SUN -"); 
  }
  
  lcd.setCursor(6, 0);
  lcd.print(rtc.getDateStr());

  lcd.setCursor(0,1);
  lcd.print(rtc.getTimeStr());

  lcd.setCursor(12,1);
  lcd.print(int(rtc.getTemp()));
  //Print degrees symbol
  lcd.write(0xdf);
  lcd.print("C");
  
  delay (1000);
}
