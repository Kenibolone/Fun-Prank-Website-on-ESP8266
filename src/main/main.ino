#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define APSSID "Not_a_Virus" // WiFi name
#define APPSK "Quandingle7098" // WiFi password

const char *ssid = APSSID;
const char *password = APPSK;
ESP8266WebServer server(80);

const char webpage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <style>
        body { background-color: black; color: green; font-family: monospace; text-align: center; overflow: hidden; }
        .hacked { color: red; font-size: 100px; font-weight: bold; position: absolute; top: 40%; left: 50%; transform: translate(-50%, -50%); text-shadow: 0px 0px 10px red; animation: blink 0.8s infinite alternate; display: none; }
        @keyframes blink { from { opacity: 1; } to { opacity: 0; } }
        canvas { position: absolute; top: 0; left: 0; width: 100%; height: 100%; display: none; }
    </style>
</head>
<body>
    <div id="loading" style="color: yellow; font-size: 30px; text-align: center; padding-top: 20%;">
        <p>Installing Virus...</p>
        <p>0% Complete</p>
    </div>
    <canvas id="matrix"></canvas>
    <div class='hacked'>YOU HAVE BEEN HACKED</div>
    
    <script>
        let loadingText = document.getElementById("loading");
        let hackedText = document.querySelector(".hacked");
        let canvas = document.getElementById("matrix");
        let ctx = canvas.getContext("2d");
        
        let percentage = 0;
        function fakeInstall() {
            percentage += Math.random() * 10;
            if (percentage > 100) {
                loadingText.style.display = "none";
                hackedText.style.display = "block";
                canvas.style.display = "block";
                startMatrixEffect();
            } else {
                loadingText.innerHTML = `<p>Installing Virus...</p><p>${Math.floor(percentage)}% Complete</p>`;
                setTimeout(fakeInstall, 500);
            }
        }
        
        function startMatrixEffect() {
            canvas.width = window.innerWidth;
            canvas.height = window.innerHeight;
            let letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789".split("");
            let fontSize = 16, columns = Math.floor(canvas.width / fontSize), drops = Array(columns).fill(1);
            function drawMatrix() {
                ctx.fillStyle = "rgba(0, 0, 0, 0.05)";
                ctx.fillRect(0, 0, canvas.width, canvas.height);
                ctx.fillStyle = "#0F0";
                ctx.font = fontSize + "px monospace";
                for (let i = 0; i < drops.length; i++) {
                    let text = letters[Math.floor(Math.random() * letters.length)];
                    ctx.fillText(text, i * fontSize, drops[i] * fontSize);
                    if (drops[i] * fontSize > canvas.height && Math.random() > 0.975) {
                        drops[i] = 0;
                    }
                    drops[i]++;
                }
            }
            setInterval(drawMatrix, 50);
        }
        
        setTimeout(fakeInstall, 1000);
    </script>
</body>
</html>
)rawliteral";

void handleRoot() 
{
    server.send(200, "text/html", webpage);
}

void setup() 
{
    Serial.begin(115200);
    WiFi.softAP(ssid, password);
    server.on("/", handleRoot);
    server.begin();
}

void loop() 
{
    server.handleClient();
}
