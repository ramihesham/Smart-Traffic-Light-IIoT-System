#include <esp_now.h>
#include <WiFi.h>

const int ledPins[] = {18, 19, 5, 33, 25, 32, 13, 12, 14};
const int numLEDs = sizeof(ledPins) / sizeof(ledPins[0]);

struct __attribute__((packed)) dataPacket {
  bool buttonStates[numLEDs];
};

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  dataPacket packet;
  memcpy(&packet, incomingData, sizeof(packet));

  Serial.println("Received packet:");

  for (int i = 0; i < numLEDs; i++) {
    Serial.print("LED ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(packet.buttonStates[i]);

    digitalWrite(ledPins[i], packet.buttonStates[i]);
  }
}

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  // Empty loop as the main operation is handled in the callback function
}
