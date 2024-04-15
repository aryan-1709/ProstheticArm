#include <esp_now.h>
#include <WiFi.h>

 int flex_thumb = 34;
 int flex_index =  35;
 int flex_ring = 32;
 int flex_pinky = 33;
 int flex_middle = A0;

int flex_middle_val ;
int flex_pinky_val ;
int flex_ring_val ;
int flex_index_val ;
int flex_thumb_val ;

// REPLACE WITH YOUR RECEIVER MAC Address
uint8_t broadcastAddress[] = {0xEC, 0xFA, 0xBC, 0x9C, 0xBA, 0x22};

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  int a;
  int b;
  int c;
  int d;
  int e;
} struct_message;

// Create a struct_message called myData
struct_message myData;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 
void setup() {
  // Init Serial Monitor
  Serial.begin(115200);
 
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}
 
void loop() {
  // Set values to send
  
  flex_thumb_val = analogRead ( flex_thumb ) ;
  flex_middle_val = analogRead ( flex_middle ) ;
  flex_pinky_val = analogRead ( flex_pinky ) ;
  flex_ring_val = analogRead ( flex_ring ) ;
  flex_index_val = analogRead ( flex_index ) ;
  myData.a = map( flex_thumb_val,560,360, 0, 180);
  myData.b =map( flex_middle_val,970, 430, 0, 180);
  myData.c = map( flex_pinky_val,720, 520, 0, 180);
  myData.d = map( flex_ring_val,760,450,0, 180);
  myData.e = map( flex_index_val,980, 590, 0, 180);
  Serial.print(" ");
  Serial.print(myData.a);
  Serial.print(" ");
  Serial.print(myData.b);
  Serial.print(" ");
  Serial.print(myData.c);
  Serial.print(" ");
  Serial.print(myData.d);
  Serial.print(" ");
  Serial.println(myData.e);
  
  Serial.println();
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  delay(2000);
}
