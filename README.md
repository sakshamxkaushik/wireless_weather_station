# Wireless Temperature and Humidity Monitoring System

This project is a wireless temperature and humidity monitoring system using Arduino and NRF24L01 wireless transceiver modules. The system consists of two main parts: a transmitter node and a receiver node. 

## Transmitter Node

### Components Required:
- Arduino UNO/Nano
- NRF24L01 wireless transceiver module
- DHT11 temperature and humidity sensor

### Pin Connections:
- **NRF24L01 Module**:
  - VCC to Arduino 3.3V
  - GND to Arduino GND
  - CE to Arduino pin 9
  - CSN to Arduino pin 10
  - SCK to Arduino pin 13
  - MOSI to Arduino pin 11
  - MISO to Arduino pin 12

- **DHT11 Sensor**:
  - Data pin to Arduino pin 3
  - GND pin to Arduino GND
  - VCC to 3.3V Arduino 

## Receiver Node

### Components Required:
- Arduino UNO/Nano
- NRF24L01 wireless transceiver module
- 16x2 I2C LCD display

### Pin Connections:
- **NRF24L01 Module**:
  - VCC to Arduino 3.3V
  - GND to Arduino GND
  - CE to Arduino pin 9
  - CSN to Arduino pin 10
  - SCK to Arduino pin 13
  - MOSI to Arduino pin 11
  - MISO to Arduino pin 12

- **I2C LCD**:
  - SDA to Arduino A4
  - SCL to Arduino A5
  - VCC to Arduino 5V
  - GND to Arduino GND
