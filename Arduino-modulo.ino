#include <SoftwareSerial.h>
#define DEBUG_ENABLED  // Descomenta esta línea si deseas ver la depuración en el monitor serie

SoftwareSerial barcodeSerial(2, 3);    // RX, TX para el lector de código de barras

void setup() {
  Serial.begin(4800);            // Inicializar la comunicación serie con el monitor serie
  barcodeSerial.begin(4800);     // Inicializar la comunicación serie con el lector de código de barras
}

void loop() {
  if (barcodeSerial.available() > 0) {
    char barcode[13];  // asumiendo un código de barras de 12 dígitos + caracter de fin de línea
    barcodeSerial.readBytesUntil('\n', barcode, 13);
    #ifdef DEBUG_ENABLED
      Serial.println(barcode);
    #endif
  }
}