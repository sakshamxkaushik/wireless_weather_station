#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const uint64_t pipeIn = 0xE8E8F0F0E1LL; 
RF24 radio(9, 10);
struct MyData {
  byte h; 
  byte t;
};
MyData data;

void setup()
{
  Serial.begin(9600); 
  radio.begin();
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
  lcd.backlight();
  lcd.clear();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1, pipeIn);
  radio.startListening();
  Serial.println("Receiver ready...");
}

void recvData()
{
  if ( radio.available() ) {
    radio.read(&data, sizeof(MyData));
    Serial.print("Received data - Humidity: ");
    Serial.print(data.h);
    Serial.print(", Temperature: ");
    Serial.println(data.t);
  }
}

void loop()
{
  recvData();
  
  lcd.setCursor(0,0);
  lcd.print("Humidity:"); 
  lcd.print(data.h);
  lcd.print("%");
  
  lcd.setCursor(0,1);
  lcd.print("Temperature:");
  lcd.print(data.t);
  lcd.print(" C");
  
  delay(500); // Delay to allow LCD to refresh
}
