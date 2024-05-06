#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <DHT.h>

const uint64_t pipeOut = 0xE8E8F0F0E1LL; 
#define DHTPIN 3
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

RF24 radio(9, 10); //  CE and CSN  pins of NRF24L01
struct MyData {
  byte h;
  byte t;
};
MyData data;

void setup()
{
  Serial.begin(9600); 
  Serial.println("Starting transmitter...");
  
  dht.begin();
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(pipeOut);

  Serial.println("Transmitter ready...");
}

void loop()
{
  data.h = dht.readHumidity();
  data.t = dht.readTemperature();
  
  Serial.print("Humidity: ");
  Serial.print(data.h);
  Serial.print(", Temperature: ");
  Serial.println(data.t);
  
  if (isnan(data.h) || isnan(data.t)){
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  radio.write(&data, sizeof(MyData));
  
  delay(1000);
}
