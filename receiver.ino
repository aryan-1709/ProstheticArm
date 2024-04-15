#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Servo.h>
#define l1 4
#define l2 5
#define r1 0
#define r2 2
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
// #define p D3;

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
 int a;
 int b;
 int c;
 int d;
 int e;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));
    Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print(myData.a+" ");
  Serial.print(myData.b+" ");
  Serial.print(myData.c+" ");
  Serial.print(myData.d+" ");
  Serial.println(myData.e);
  s1.write(myData.a);
  s2.write(myData.b);
  s3.write(myData.c);
  s4.write(myData.d);
  s5.write(myData.e);

}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(14, OUTPUT);
  s1.attach(14);
  s2.attach(4);
  s3.attach(5);
  s4.attach(0);
  s5.attach(2);

  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
 
}
