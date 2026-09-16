# 🌡️ ESP32 + DHT11: Monitor de Temperatura y Humedad por WiFi

Este proyecto convierte un **ESP32** en un servidor web local que lee los datos de temperatura y humedad de un sensor **DHT11** y los despliega en tiempo real en una página web accesible desde cualquier dispositivo (teléfono, tablet o computadora) conectado a su red.

---

## 🚀 Características

* **Monitoreo sin cables:** No requiere aplicaciones ni cables OTG; la lectura se realiza desde cualquier navegador web.
* **Red WiFi autónoma:** El ESP32 funciona como punto de acceso (Access Point), creando su propia red WiFi sin depender de un router de internet.
* **Actualización automática:** La página web refresca los valores de temperatura y humedad automáticamente cada 2 segundos.
* **Código optimizado:** Diseñado para evitar bloqueos de arranque (*boot loop*) utilizando pines de E/S seguros en la placa ESP32.

---

## 🛠️ Requisitos de Hardware

* **ESP32** (NodeMCU ESP32 o similar)
* **Sensor DHT11** (Humedad y Temperatura)
* Cables Dupont / Protoboard
* Fuente de alimentación USB (cargador de teléfono o batería)

---

## 🔌 Diagrama de Conexión

| Pin DHT11 | Pin ESP32 | Descripción |
| :--- | :--- | :--- |
| **VCC (+)** | **3V3** | Alimentación a 3.3V |
| **GND (-)** | **GND** | Tierra / Masa |
| **DATA (OUT)**| **GPIO 4 (D4)** | Pin de datos |

> ⚠️ **Nota importante:** Evita usar pines de arranque (*strapping pins*) como GPIO 2, 13 o VN para la señal de datos, ya que pueden causar fallos en la lectura o impedir que el programa suba correctamente.

---

## 📦 Librerías Necesarias

Para compilar este código en el **Arduino IDE**, debes instalar la siguiente librería desde el *Gestor de Librerías*:

* **`DHT sensor library`** (por *Adafruit*)
  * *Nota: Acepta instalar la dependencia `Adafruit Unified Sensor` cuando el IDE lo solicite.*

---

## 💻 Configuración del Software

1. Clona o descarga este repositorio.
2. Abre el archivo `.ino` en tu **Arduino IDE**.
3. Selecciona la placa **ESP32 Dev Module** y el puerto COM correcto.
4. Presiona el botón **Subir** (`Ctrl + U` / `Cmd + U`).

---

## 📱 ¿Cómo usarlo?

1. Una vez cargado el programa, alimenta el ESP32 con cualquier cable USB.
2. Desde tu celular o computadora, busca las redes WiFi disponibles y conéctate a:
   * **SSID:** `ESP32_Termometro`
   * **Contraseña:** `12345678password`
3. Abre tu navegador web favorito e ingresa a la siguiente dirección IP:
   ```text
   [http://192.168.4.1](http://192.168.4.1)
