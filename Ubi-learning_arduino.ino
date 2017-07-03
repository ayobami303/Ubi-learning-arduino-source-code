/*********
  source code from:
  Rui Santos
  Complete project details at http://randomnerdtutorials.com 
  For Ubi-learning app 
  By: Omotosho Ayobami
*********/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

MDNSResponder mdns;

// Replace with your network credentials
const char* ssid = "ayo";
const char* password = "ayobami10000";

ESP8266WebServer server(80);

String webPage = "";
String webPage2 = "";
String webPage3 = "";

int gpio0_pin = 0;
int gpio2_pin = 2;

void setup(void){
  //webPage += "<h1>ESP8266 Web Server</h1><p>Socket #1 <a href=\"socket1On\"><button>ON</button></a>&nbsp;<a href=\"socket1Off\"><button>OFF</button></a></p>";
  //webPage += "<p>Socket #2 <a href=\"socket2On\"><button>ON</button></a>&nbsp;<a href=\"socket2Off\"><button>OFF</button></a></p>";
  webPage += "<?xml version=\"1.0\" encoding=\"UTF-8\"?><infos>	<info><infoname>Assignment submission deadline</infoname><imgurl>R.drawable.slab</imgurl><description>this starts soon</description></info><info><infoname>Exam rules</infoname><imgurl>R.drawable.hlab</imgurl><description>5</description></info><info><infoname>Test scheduled</infoname><imgurl>R.drawable.hod</imgurl><description>5</description></info></infos>";
  webPage2 += "<?xml version=\"1.0\" encoding=\"UTF-8\"?><infos><info> <infoname>Fortran Practical</infoname> <imgurl>R.drawable.slab</imgurl>	<description>Fortran formerly FORTRAN derived from Formula Translation is a general-purpose\, imperative programming language</description></info><info> <infoname>Java material</infoname><imgurl>R.drawable.hlab</imgurl><description>Java is a general-purpose computer programming language that is concurrent, class-based, object-oriented, and specifically designed to have as few implementation dependencies as possible. It is intended to let application developers write once, run anywhere (WORA), ";
  webPage2 += "meaning that compiled Java code can run on all platforms that support Java without the need for recompilation.As of 2016, Java is one of the most popular programming languages in use, particularly for client-server web applications, with a reported 9 million developers. Java was originally developed by James Gosling at Sun Microsystems (which has since been acquired by Oracle Corporation) and released in 1995 as a core component of Sun Microsystems' Java platform. The language derives much of its syntax from C and C++, but it has fewer low-level facilities than either of them. Java is the base language for developing android apps in combination with XML. </description>	</info>	<info>	<infoname>Test scheduled</infoname><imgurl>R.drawable.hod</imgurl><description>5</description>	</info>	</infos>";
  //webPage2 += "<?xml version=\"1.0\" encoding=\"UTF-8\"?><infos><info> <infoname>Fortran Practical</infoname> <imgurl>R.drawable.slab</imgurl>	<description>Fortran formerly FORTRAN, derived from Formula Translation is a general-purpose, imperative programming language that is especially suited to numeric computation and scientific computing.</description></info><info> <infoname>Java material</infoname><imgurl>R.drawable.hlab</imgurl><description>Java is a general-purpose computer programming language that is concurrent, class-based, object-oriented, and specifically designed to have as few implementation dependencies as possible. It is intended to let application developers write once, run anywhere (WORA), meaning that compiled Java code can run on all platforms that support Java without the need for recompilation. </description>	</info>	<info>	<infoname>Test scheduled</infoname><imgurl>R.drawable.hod</imgurl><description>5</description>	</info>	</infos>";
  webPage3 += "<?xml version=\"1.0\" encoding=\"UTF-8\"?><infos><info><infoname>CSC 203 Practical</infoname><imgurl>R.drawable.slab</imgurl>	<description>CSC 203 is a course about digital electronics.logic gates would be like AND Gates, OR gates, NOT gates etc. C programming is used to program intel galileo board.C is a general purpose imperative programming language that supports structured programming, lexical variable scope and recursion. C provides constructs that map efficiently and directly to typical machine instructions making it popular in applications that had formerly been coded in assembly language. It has been in operating systems and various software applications for computers ranging from supercomputer to embedded systems.</description></info><info><infoname>Computer Repairs</infoname><imgurl>R.drawable.hlab</imgurl>";
  webPage3 += "<description>This involves computer repairs, replacement and installation</description></info><info> <infoname>Test scheduled</infoname><imgurl>R.drawable.hod</imgurl><description>5</description></info></infos>";
  // preparing GPIOs
  pinMode(gpio0_pin, OUTPUT);
  digitalWrite(gpio0_pin, LOW);
  pinMode(gpio2_pin, OUTPUT);
  digitalWrite(gpio2_pin, LOW);
  
  delay(1000);
  Serial.begin(115200);
  //WiFi.begin(ssid, password);
  //Serial.println("");

  // Wait for connection
 // while (WiFi.status() != WL_CONNECTED) {
   // delay(500);
    //Serial.print(".");
 // }
  Serial.println("");
  Serial.print("Connected to ");
 // Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
  
  server.on("/", [](){
    server.send(200, "text/xml", webPage);
  });
  server.on("/23F3BE00", [](){
    server.send(200, "text/xml", webPage2);
    //digitalWrite(gpio0_pin, HIGH);
    //delay(1000);
  });
  server.on("/65DCBE00", [](){
    server.send(200, "text/xml", webPage);
    //digitalWrite(gpio0_pin, LOW);
    //delay(1000); 
  });
  server.on("/F3D6BE00", [](){
    server.send(200, "text/xml", webPage3);
    //digitalWrite(gpio2_pin, HIGH);
    //delay(1000);
  });
  /*server.on("/socket2Off", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(gpio2_pin, LOW);
    delay(1000); 
  });*/
  server.begin();
  Serial.println("HTTP server started");
}
 
void loop(void){
  server.handleClient();
} 
