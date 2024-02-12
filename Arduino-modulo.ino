#include <SoftwareSerial.h>
#define DEBUG_ENABLED  // Descomenta esta línea si deseas ver la depuración en el monitor serie

SoftwareSerial barcodeSerial(2, 3);    // RX, TX para el lector de código de barras

void setup() {
  Serial.begin(4800);            // Inicializar la comunicación serie con el monitor serie
  barcodeSerial.begin(4800);     // Inicializar la comunicación serie con el lector de código de barras
}

void loop() {
  if (barcodeSerial.available() > 0) {
    char barcode[14];  // asumiendo un código de barras de 13 dígitos + caracter de fin de línea
    barcodeSerial.readBytesUntil('\r', barcode, 14);
    
 // Crear un nuevo array sin el carácter de retorno de carro ('\r')
    char barcodeWithoutCR[14];
    int j = 0;
    for (int i = 0; i < strlen(barcode); i++) {
      if (barcode[i] != '\r') {
        barcodeWithoutCR[j++] = barcode[i];
      }
    }
    barcodeWithoutCR[j] = '\0';  // Agregar el carácter nulo al final del nuevo array

    // Puedes imprimir o usar el nuevo array sin el carácter de retorno de carro
    #ifdef DEBUG_ENABLED
      Serial.print(barcodeWithoutCR);
    #endif
  }
}
