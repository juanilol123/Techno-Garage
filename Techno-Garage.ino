// Load library
#include <ESP8266WiFi.h>
#include <Servo.h>
#include <EasyBuzzer.h>


 
// Replace with your network credentials
const char* ssid = "Esp82";
const char* password = "mtph8634";

//// Set web server port number to 80
WiFiServer server(80);




//// Replace with your network credentials
//const char* ssid = "LABO";
//const char* password = "";
//
//
//// Set web server port number 
//WiFiServer server(8096);

//// Set your Static IP address
//IPAddress local_IP(192, 168, 100, 206);
//
//// Set your Gateway IP address
//IPAddress gateway(192, 168, 100, 254);
//IPAddress subnet(255, 255, 255, 0);
//IPAddress primaryDNS(8, 8, 8, 8); //optional
//IPAddress secondaryDNS(8, 8, 4, 4); //optional




// Variable to store the HTTP request
String header;


// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;



const int LED=D1;
const int LED1=D2;
Servo servoMotor;

void sonidoTerminado(){
  Serial.println("Sonido terminado");
}



void setup() {
  Serial.begin(115200);



   //Configures static IP address
//if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
//Serial.println("STA Failed to configure");
//}

 // Configuración del beep
  EasyBuzzer.setPin(D7);
  EasyBuzzer.beep(
  200,  // Frequency in Hertz(HZ).
  2   // The number of beeps.
);


  pinMode(LED,OUTPUT);
  pinMode(LED1,OUTPUT);
  servoMotor.write(0);
  servoMotor.attach(D8);

  

 // Connect to Wi-Fi network with SSID and password
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
  }
  // Print local IP address and start web server
Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());





server.begin();

}

void loop(){
EasyBuzzer.stopBeep();
  
WiFiClient client = server.available(); // Listen for incoming clients
//  if (!client) {
//    return;
//  }
// 
//  // Wait until the client sends some data
//  
//  while(!client.available()){
//    delay(1);
//  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');



if (request.indexOf("/ENCENDER=MOTOR") != -1) {
    EasyBuzzer.beep(700, 300, 300, 3, 300, 1  );
for (int i = 0; i <= 180; i++){
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(25);}}

  
  if (request.indexOf("/APAGAR=MOTOR") != -1)  {
 EasyBuzzer.beep(700, 300, 300, 3, 300, 1  );
 for (int i = 179; i > 0; i--){
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(25);}}


  
if (request.indexOf("/ENCENDER=LED") != -1)  {
    digitalWrite(LED,HIGH);
    digitalWrite(LED1,HIGH);
  }

  if (request.indexOf("/APAGAR=LED") != -1)  {
    digitalWrite(LED,LOW);
    digitalWrite(LED1,LOW);
  }
  //client.flush();
 

   
           client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'>");
client.println("<head>");
client.println("<link rel='stylesheet' href='https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@48,400,0,0' />");
client.println("<link rel='stylesheet' href='https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@48,400,0,0' />");
client.println("<style>");
    client.println("@import url('https://fonts.googleapis.com/css2?family=Michroma&family=Poppins:ital,wght@1,200&display=swap');");
     
     client.println("H1{");
         client.println("font-size: 150;");
         client.println("font-family: 'Poppins', sans-serif;");
         client.println("color: #ffffff;");
         client.println("text-align: center;}");
    
      client.println("body{");
        client.println("background: linear-gradient(to bottom, #000000, #19043d);");
        client.println("display: flex;");
        client.println("flex-direction: column;");
        client.println("min-height: 100vh;}");
    
    client.println("#main-container{");
          client.println("padding-top: 50px;");
          client.println("text-align: center;}");
    
    
        client.println("p{");
            client.println("margin-bottom: 30;}");
    
        

        client.println(".btn{");
          client.println("font-family: 'Michroma', sans-serif;");
          client.println("font-size: 20;");
          client.println("width: 20rem;");
          client.println("text-align: center;");
          client.println("cursor: pointer;");
          client.println("border-radius: 3px;");
          client.println("display: inline-block;");
          client.println("padding: 25px 20px;");
          client.println("text-decoration: none;");
          client.println("text-shadow: 0 1px 0 rgba(255,255,255,0.3);");
          client.println("box-shadow: 0 1px 1px rgba(0,0,0,0.3); }");
    
        client.println(".btn-green{");
          client.println("color: white;");
          client.println("background-color: #111cad;}");
        
        client.println(".btn-green:hover{");
          client.println("background-color: #0d168f;}");
        
        client.println(".btn-green:active{");
          client.println("background-color: #091073;}");
    
        client.println(".btn-red{");
          client.println("color: white;");
          client.println("background-color: #540c87;}");
          
        client.println(".btn-red:hover{");
          client.println("background-color: #430a6b; }");
          
        client.println(".btn-red:active{");
          client.println("background-color: #2c0647;}");

          client.println("footer {");
            client.println("width: auto;");
            client.println("background-color: #777;");
            client.println("padding: 1px;");
            client.println("text-align: center;");
            client.println("color: white; }");
            client.println("margin-top: auto;");

client.println("</style>");
client.println("</head>");
    
   client.println(" <body>");
             client.println("<H1>");
            client.println("TECHNO-GARAGE");
             client.println("</H1>");
            
        client.println("<div id='main-container'  style='margin: auto; text-align: center;'>");

    client.println("<p>   <a href=\"/ENCENDER=LED\"\" class='btn btn-green' input type='button'> <span class='material-symbols-outlined'> flashlight_on </span> ENCENDER LUCES</a> </p>");
    client.println("<p>   <a href=\"/APAGAR=LED\"\" class='btn btn-red' input type='button'> <span class='material-symbols-outlined'> flashlight_off</span> APAGAR LUCES </a>   </p>");
    client.println("<p>   <a href=\"/ENCENDER=MOTOR\"\" class='btn btn-green' input type='button'> <span class='material-symbols-outlined'> door_open </span> SUBIR PORTON </a>  </p>");
    client.println("<p>   <a href=\"/APAGAR=MOTOR\"\" class='btn btn-red' input type='button'> <span class='material-symbols-outlined'>door_front </span> BAJAR PORTON </a>   </p>");

        client.println("</div>");
            

        client.println("<footer>");

            client.println("<span class='material-symbols-outlined'>account_circle </span>   @juan_pisanii 1163219257");  

        client.println("</footer>");
    client.println("</body>");
client.println("</html>");
}
  
