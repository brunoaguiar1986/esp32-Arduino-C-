#include <WiFi.h> // inclusão da biblioteca WiFi

const char* ssid     = "Nirvana"; // SSID é o nome da rede a ser conectada
const char* password = "Bruno#1986";     // senha da rede

WiFiServer server(80); // Em WiFiServer, é designada a porta que o servidor vai usar

void setup() {
    Serial.begin(115200);   // boudrate da comunicação serial com o monitor serial
    pinMode(2, OUTPUT);     // define o pino 2 da placa para ligar e desligar
    delay(10);              // delay de 10ms
    Serial.println();       // pular linha
    Serial.print("Conectado com: ");
    Serial.println(ssid);   // nome da rede

    WiFi.begin(ssid, password); // inicializa o WiFi colocando a rede e senha

    while (WiFi.status() != WL_CONNECTED) { // Retorna o status da conexão se está conectado ou não
        delay(500); 
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi Conectado!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    server.begin(); // inicializa a função servidor
}

int value = 0;

void loop() {
    WiFiClient client = server.available(); // WiFiClient inicia uma variável que confere se há algum cliente conectado

    if (client) { // Se conseguiu um cliente
        Serial.println("New Client.");
        String currentLine = ""; // faça uma String(texto) para armazenar dados recebidos do cliente
        
        while (client.connected()) { // enquanto cliente conectado
            if (client.available()) { // se o cliente estiver disponível
                char c = client.read(); // leia o byte
                Serial.write(c); // imprimir no monitor serial
                  
                if (c == '\n') { // se o byte for um caractere de nova linha
                    if (currentLine.length() == 0) { // se não tem mais nenhum dado para receber, responde ao cliente
                        int numerosPorSegundo = 1;
                        int valor = random(0, 100); // Gera um valor aleatório

                        // INÍCIO DA PÁGINA HTML
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println();

                        String html = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><script src=\"https://kit.fontawesome.com/06a72cc7b8.js\" crossorigin=\"anonymous\"></script><title>Esp Controller</title><style>";
                        html += "@import url('https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;500;600;700;900&display=swap');";
                        html += "@import url('https://fonts.cdnfonts.com/css/digital-numbers');";
                        html += "* {font-family: 'Poppins', sans-serif; margin: 0; padding: 0; box-sizing: border-box;}";
                        html += ":root {--dark: #02023c; --white: #f8f8f8; --accent1: #ff4500; --accent2: #32cd32; --header-height: 10vh; --width-general: 90vw; --border-radius: 15px; --box-shadow: 0 10px 15px rgba(0, 0, 0, 0.2); --transition: all 0.3s ease-in-out;}";
                        html += "body {background-color: #f0f4f8; color: var(--dark); display: flex; justify-content: center; align-items: flex-start; flex-direction: column; height: 100vh; overflow-x: hidden; padding: 20px;}";
                        html += "header {width: 100%; height: var(--header-height); background: linear-gradient(135deg, #b56f2e, #251db5); color: var(--white); display: flex; justify-content: center; align-items: center; font-size: 2rem; font-weight: 700; box-shadow: var(--box-shadow); text-transform: uppercase; margin-bottom: 20px; border-radius: 10px;}";
                        html += "main {width: 100%; max-width: 500px; display: flex; flex-direction: column; gap: 20px;}";
                        html += ".esp-info, .led-controller, .random-number {background: linear-gradient(135deg, #02023c, #1a73e8); color: var(--white); padding: 20px; border-radius: var(--border-radius); box-shadow: var(--box-shadow); transition: var(--transition);}";
                        html += ".esp-info:hover, .led-controller:hover, .random-number:hover {transform: translateY(-5px); box-shadow: 0 15px 25px rgba(0, 0, 0, 0.3);}";
                        html += ".esp-info {font-size: 1.2rem;}";
                        html += ".led-controller {display: flex; flex-direction: column; align-items: center; gap: 10px;}";
                        html += ".link {width: 100%; text-decoration: none; margin-bottom: 10px;}";
                        html += ".button {width: 100%; padding: 15px; border: none; border-radius: 50px; font-size: 1.2rem; color: var(--white); cursor: pointer; transition: var(--transition); box-shadow: 0 5px 10px rgba(0, 0, 0, 0.1);}";
                        html += ".button-on {background: linear-gradient(45deg, #32cd32, #55b07e); margin-bottom: 20px;}";
                        html += ".button-off {background: linear-gradient(45deg, #ff0000, #ff4747);}";
                        html += ".button:hover {transform: scale(1.05); box-shadow: 0 8px 16px rgba(0, 0, 0, 0.2);}";
                        html += ".random-number {display: flex; flex-direction: column; align-items: center; font-size: 1.5rem;}";
                        html += ".Numero-randomico {background: var(--white); color: var(--dark); padding: 10px 20px; border-radius: var(--border-radius); box-shadow: var(--box-shadow); width: 100%; text-align: center;}";
                        html += ".valor {font-size: 3rem; font-family: 'Digital Numbers', sans-serif; color: #d35400;}";
                        html += ".title-espinfo, .title-controller, .valor-aleatorio-title {font-size: 1.5rem; font-weight: 600; text-align: center;}";
                        html += "@media (max-width: 768px) {header {font-size: 1.5rem;} .button {font-size: 1rem; padding: 12px;} .esp-info, .led-controller, .random-number {padding: 5px;} .valor {font-size: 2.5rem;} .title-espinfo, .title-controller, .valor-aleatorio-title {font-size: 1.2rem;}}";
                        html += "@media (max-width: 480px) {header {font-size: 1.2rem;} .button {font-size: 0.9rem; padding: 10px;} .valor {font-size: 2rem;} .title-espinfo, .title-controller, .valor-aleatorio-title {font-size: 1rem;}}";
                        html += "</style></head><body>";
                        html += "<header><h1>Esp Controller</h1></header><main>";
                        html += "<div class=\"led-controller\"><div class=\"led-buttons\">";
                        html += "<h2 class=\"title-controller\">Controlador do ESP32</h2><br>";
                        html += "<a class=\"link\" href=\"/H\"><button class=\"button button-on\">On - Ligar LED</button></a><br>";
                        html += "<a class=\"link\" href=\"/L\"><button class=\"button button-off\">Off - Desligar LED</button></a></div></div>";
                        html += "<div class=\"random-number\"><h2 class=\"valor-aleatorio-title\">Senha aleatória</h2><br>";
                        html += "<div class=\"Numero-randomico\"><h1 class=\"valor\">" + String(valor) + "</h1></div></div>";
                        html += "<div class=\"esp-info\"><h2 class=\"title-espinfo\">Informações de conexão</h2><br>";
                        html += "Mac Address: <span class=\"info\">" + String(WiFi.macAddress()) + "</span><br>";
                        html += "Endereço IP: <span class=\"info\">" + WiFi.localIP().toString() + "</span><br>";
                        html += "Pacotes por segundo: <span class=\"info\">" + String(numerosPorSegundo) + "</span>";
                        html += "</div></main></body></html>";

                        
                        client.println(html); // envia a resposta ao cliente
                        //delay(1000 / numerosPorSegundo);
                        //client.print("<script> window.location.reload(); </script>");
                        break;
                    } else {
                        currentLine = "";
                    }
                } else if (c != '\r') { // se tiver algo no texto corrente
                    currentLine += c; // adicionar ao texto corrente
                }
                if (currentLine.endsWith("GET /H")) { // verificar o GET e acender o LED
                    digitalWrite(2, HIGH); // liga LED
                    //client.print("<script>document.write('<div style=\"color: green; text-align: center; font-size: 24px;\">Ligado</div>');</script>");
                    //client.print("<script>alert('Ligado');</script>");
                }
                if (currentLine.endsWith("GET /L")) { // verificar o GET e apagar o LED
                    digitalWrite(2, LOW); // desliga LED
                    //client.print("<script>document.write('<div style=\"color: red; text-align: center; font-size: 24px;\">Desligado</div>');</script>");
                    //client.print("<script>alert('Ligado');</script>");
                }
            }
        }
        client.stop(); // finaliza a conexão do cliente
        Serial.println("Client Disconnected.");
    }
}
