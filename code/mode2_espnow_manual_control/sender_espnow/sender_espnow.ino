#include <esp_now.h>
#include <WiFi.h>

const int buttonPins[] = {18, 19, 5, 33, 25, 32, 13, 12, 14};
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);

uint8_t broadcastAddress[] = {0x08, 0xD1, 0xF9, 0x29, 0x6D, 0xF8};

struct __attribute__((packed)) dataPacket {
  bool buttonStates[numButtons];
};

esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 
void setup() {
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(OnDataSent);
  
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}
 
void loop() {
  dataPacket packet;

  for (int i = 0; i < numButtons; i++) {
    packet.buttonStates[i] = !digitalRead(buttonPins[i]); // Reverse logic for active-low buttons
  }

  esp_now_send(broadcastAddress, (uint8_t *) &packet, sizeof(packet));

  delay(30);
}
