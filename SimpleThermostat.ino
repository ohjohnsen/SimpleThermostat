
// Name:    SimpleThermostat.ino
// Created: 24.04.2019 19:10:45
// Author:  Øystein Holvik Johnsen

#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

const int ds18b20_pin = 10;  // Pin used to communicate with temperature sensor
OneWire oneWire(ds18b20_pin);
DallasTemperature ds18b20(&oneWire);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;  // Pins used to communicate with LCD display
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const float temperature_setpoint = 20.0;    // Temperature setpoint for fan control
const float temperature_hysteresis = 0.25;  // 0.25 degrees temperature hysteresis between

const int fan_pin = 8;                      // Pin used to control fan ON or OFF

float temperature;
bool fan_state;

void setup() {
    Serial.begin(115200);
    Serial.println("Simple Thermostat");

    ds18b20.begin();

    lcd.begin(16, 2);
    lcd.print("Temp:");

    lcd.setCursor(0, 1);
    lcd.print("Fan State: OFF");

    pinMode(fan_pin, OUTPUT);
    digitalWrite(fan_pin, LOW);

    pinMode(fan_pin, OUTPUT);
    digitalWrite(fan_pin, LOW);
}

void loop() {
    ds18b20.requestTemperatures();

    temperature = ds18b20.getTempCByIndex(0);
    Serial.print("Temperature: ");
    Serial.println(temperature);

    lcd.setCursor(6, 0);
    lcd.print(temperature);

    if (temperature > (temperature_setpoint + temperature_hysteresis) && fan_state == false) {
        Serial.println("It's too hot, turn fan ON");
        fan_state = true;
        lcd.setCursor(11, 1);
        lcd.print("ON ");
        digitalWrite(fan_pin, HIGH);
    }
    else if (temperature < (temperature_setpoint - temperature_hysteresis) && fan_state == true) {
        Serial.println("It's cold enough, turn fan OFF");
        fan_state = false;
        lcd.setCursor(11, 1);
        lcd.print("OFF");
        digitalWrite(fan_pin, LOW);
    }

    delay(500);
}
