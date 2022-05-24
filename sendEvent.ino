#include <ESP8266WiFi.h>
/*#include <WiFiClientSecure.h>*/
#include <WiFiClient.h>
#include <Pushsafer.h>

// Initialize Wifi connection to the router
char ssid[] = "Akabeom";     // your network SSID (name)
char password[] = "daideptrai"; // your network key
int Sensor = D0;

// Pushsafer private or alias key
#define PushsaferKey "XUtb38w5DJop6zqrC2Dw"

/*WiFiClientSecure client;*/
WiFiClient client;
Pushsafer pushsafer(PushsaferKey, client);

void setup() {
  Serial.begin(115200);
  pinMode(Sensor, INPUT);
  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  pushsafer.debug = true;

  // Take a look at the Pushsafer.com API at
  // https://www.pushsafer.com/en/pushapi
  
  

  

// Serial.println("Sent");
//  
  // client.stop();
}

void loop() {
  struct PushSaferInput input;
  int gtSensor = digitalRead(Sensor);
//  int gtSensor = 1;
  if (gtSensor == 0)
  {
    input.message = "Cảm biến phát hiện vật thể";
    input.title = "alo alo alo";
    input.sound = "8";
    input.vibration = "1";
    input.icon = "1";
    input.iconcolor = "#FFCCCC";
    input.priority = "1";
    input.device = "a";
    input.url = "[đây là url dẫn về máy quay realtime ở nhà]";
    input.urlTitle = "Xem máy quay ngay";
    Serial.println(pushsafer.sendEvent(input));
    delay(10000);
  }
  
}
