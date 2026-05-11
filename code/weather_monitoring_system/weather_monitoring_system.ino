#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "add yours"
#define BLYNK_TEMPLATE_NAME "climate condition"
#define BLYNK_AUTH_TOKEN "add yours"
#include <Wire.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <SFE_BMP180.h>
#include <LiquidCrystal_I2C.h> // Include the LiquidCrystal_I2C library

#define LDR 4
#define TH 5
#define Rain 34

double T, P;
char status;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize the LCD object

DHT dht(TH, DHT11);
BlynkTimer timer;
SFE_BMP180 bmp; // Declare BMP180 sensor object

char auth[] = "add yours";
char ssid[] = "add yours";
char pass[] = "add yours";

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  
  if (!bmp.begin()) {
    Serial.println("BMP180 initialization failed!");
    while (1); // Stop program if BMP180 initialization fails
  }

  dht.begin();
  lcd.begin(16, 2); // Initialize the LCD display with 16 columns and 2 rows
  lcd.backlight();

  pinMode(LDR, INPUT);
  pinMode(Rain, INPUT);
  analogReadResolution(12);

  lcd.setCursor(0, 0);
  lcd.print("System");
  lcd.setCursor(4, 1);
  lcd.print("Loading..");
  delay(4000);
  lcd.clear();
}

void DHT11sensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(t);

  lcd.setCursor(8, 0);
  lcd.print("H:");
  lcd.print(h);
}

void rainSensor() {
  int Rvalue = analogRead(Rain);
  Rvalue = map(Rvalue, 0, 4095, 0, 100);
  Rvalue = (Rvalue - 100) * -1;
  Blynk.virtualWrite(V2, Rvalue);

  lcd.setCursor(0, 1);
  lcd.print("R:");
  lcd.print(Rvalue);
  lcd.print(" ");
  Serial.println(Rvalue);
  if (Rvalue>=50)
  {
    Blynk.logEvent("it_is_raining");
  }
}

void pressure() {
  status = bmp.startTemperature();
  if (status != 0) {
    delay(status);
    status = bmp.getTemperature(T);

    status = bmp.startPressure(3);
    if (status != 0) {
      delay(status);
      status = bmp.getPressure(P, T);
    }
  }

  Blynk.virtualWrite(V3, P);
  lcd.setCursor(8, 1);
  lcd.print("P:");
  lcd.print(P);
}

void LDRsensor() {
  bool value = digitalRead(LDR);
  if (value == 1) {
    WidgetLED LED(V4);
    LED.on();
  } else {
    WidgetLED LED(V4);
    LED.off();
  }
}

void loop() {
  DHT11sensor();
  rainSensor();
  pressure();
  LDRsensor();
  Blynk.run();
}
