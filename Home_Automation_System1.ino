#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

#define room1led1 D0
#define room1led2 D1
#define room1fan1 D2
#define room1fan2 D3
#define room2led1 D4
#define room2led2 D5
#define room2fan1 D6
#define room2fan2 D7


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("Mooazam", "mooazam123");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  server.begin();
  pinMode(room1led1, OUTPUT);
  pinMode(room1led2, OUTPUT);
  pinMode(room1fan1, OUTPUT);
  pinMode(room1fan2, OUTPUT);
  pinMode(room2led1, OUTPUT);
  pinMode(room2led2, OUTPUT);
  pinMode(room2fan1, OUTPUT);
  pinMode(room2fan2, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  client = server.available();  //Gets a client that is connected to the server and has data available for reading.
  if (client == 1)
  {
    String request =  client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if (request == "GET /room1led1on HTTP/1.1")
    {
      digitalWrite(room1led1, HIGH);
      Serial.println("ROOM1 LED 1 is ON");
    }
    if (request == "GET /room1led1off HTTP/1.1")
    {
      digitalWrite(room1led1, LOW);
      Serial.println("ROOM1 LED 1 is OFF");
    }
    if (request == "GET /room1led2on HTTP/1.1")
    {
      digitalWrite(room1led2, HIGH);
      Serial.println("ROOM1 LED 2 is ON");
    }
    if (request == "GET /room1led2off HTTP/1.1")
    {
      digitalWrite(room1led2, LOW);
      Serial.println("ROOM1 LED 2 is OFF");
    }
    if (request == "GET /room1fan1on HTTP/1.1")
    {
      digitalWrite(room1fan1, HIGH);
      Serial.println("ROOM1 FAN 1 is ON");
    }
    if (request == "GET /room1fan1off HTTP/1.1")
    {
      digitalWrite(room1fan1, LOW);
      Serial.println("ROOM1 FAN 1 is OFF");
    }
    if (request == "GET /room1fan2on HTTP/1.1")
    {
      digitalWrite(room1fan2, HIGH);
      Serial.println("ROOM1 FAN 2 is ON");
    }
    if (request == "GET /room1fan2off HTTP/1.1")
    {
      digitalWrite(room2fan2, LOW);
      Serial.println("ROOM2 FAN 2 is OFF");
    }
    if (request == "GET /room2led1on HTTP/1.1")
    {
      digitalWrite(room2led1, HIGH);
      Serial.println("ROOM2 LED 1 is ON");
    }
    if (request == "GET /room2led1off HTTP/1.1")
    {
      digitalWrite(room2led1, LOW);
      Serial.println("ROOM2 LED 1 is OFF");
    }
    if (request == "GET /room2led2on HTTP/1.1")
    {
      digitalWrite(room2led2, HIGH);
      Serial.println("ROOM2 LED 2 is ON");
    }
    if (request == "GET /room2led2off HTTP/1.1")
    {
      digitalWrite(room2led2, LOW);
      Serial.println("ROOM2 LED 2 is OFF");
    }
    if (request == "GET /room2fan1on HTTP/1.1")
    {
      digitalWrite(room2fan1, HIGH);
      Serial.println("ROOM2 FAN 1 is ON");
    }
    if (request == "GET /room2fan1off HTTP/1.1")
    {
      digitalWrite(room2fan1, LOW);
      Serial.println("ROOM2 FAN 1 is OFF");
    }
    if (request == "GET /room2fan2on HTTP/1.1")
    {
      digitalWrite(room2fan2, HIGH);
      Serial.println("ROOM2 FAN 2 is ON");
    }
    if (request == "GET /room2fan2off HTTP/1.1")
    {
      digitalWrite(room2fan2, LOW);
      Serial.println("ROOM2 FAN 2 is OFF");
    }
 
  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println("Connection: close");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<title>Document</title>");
  client.println("<style>");
  client.println("body {text-align: center;}");
  client.println("</style>");
  client.println("</head>");
  client.println("<body>");
  client.println("<h1>Home Automation System.<br><br>Made By: Areeba Ghazal.<br><br>Mah E Urooj.</h1>");
  client.println("<h2>Room 1</h2>");
  client.println("<a href=\"/room1led1on\"\"><button>LED 1 ON</button></a>");
  client.println("<a href=\"/room1led1off\"\"><button>LED 1 OFF</button></a>");
  client.println("<br><br>");
  
  client.println("<a href=\"/room1led2on\"\"><button>LED 2 ON</button></a>");
  client.println("<a href=\"/room1led2off\"\"><button>LED 2 OFF</button></a>");
  client.println("<br><br>");
  
  client.println("<a href=\"/room1fan1on\"\"><button>FAN 1 ON</button></a>");
  client.println("<a href=\"/room1fan1off\"\"><button>FAN 1 OFF</button></a>");
  client.println("<br><br>");
  
  client.println("<a href=\"/room1fan2on\"\"><button>FAN 2 ON</button></a>");
  client.println("<a href=\"/room1fan2off\"\"><button>FAN 2 OFF</button></a>");
  client.println("<br><br>");
  
  client.println("<h3>Room 2</h3>");
  
  client.println("<a href=\"/room2led1on\"\"><button>LED 1 ON</button></a>");
  client.println("<a href=\"/room2led1off\"\"><button>LED 1 OFF</button></a>");
  client.println("<br><br>");
  
  client.println("<a href=\"/room2led2on\"\"><button>LED 2 ON</button></a>");
  client.println("<a href=\"/room2led2off\"\"><button>LED 2 OFF</button></a>");
  client.println("<br><br>");
  
  client.println("<a href=\"/room2fan1on\"\"><button>FAN 1 ON</button></a>");
  client.println("<a href=\"/room2fan1off\"\"><button>FAN 1 OFF</button></a>");
  client.println("<br><br>");
  
  client.println("<a href=\"/room2fan2on\"\"><button>FAN 2 OFF</button></a>");
  client.println("<a href=\"/room2fan2off\"\"><button>FAN 2 ON</button></a>");
  client.println("<br><br>");
  client.println("</body>");
  client.println("</html>");
}
