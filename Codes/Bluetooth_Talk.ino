/*
 * HC-05 Bluetooth Module icin kurulum ve test dosyası
 * 
 * 1) Arduino 8 ve 9 no'lu pinler sırasıyla Rx ve Tx, HC-05 pinleri ise tersi olmalidir, Tx ve Rx.
 * 2) Breakout modül EN pin'i ve buton ile birlikte sunuluyor. Buton'a basılarak EN pin'i +Vcc'ye bağlanırsa, cihaz kalibrasyon moduna giriyor.
 * 3) Kalibrasyon modunda varsayılan Baudrate 38400 bps.
 * 
 * Cesitli kodlar:
 *  AT+PSWD?      Mevcut sifreyi ogrenme
 *  AT+PSWD=xxxx  Yeni sifre atama
 *  AT+NAME?      Yayın adını öğrenme
 *  AT+NAME=xxxx  Yeni yayın adını girme
 *  AT+ROLE?      Slave/Master durumunu ogrenme
 *  AT+UART?      Normal mod icin Baud rate/stop/parity bit ogrenme
 *    
 *  Oneri:
 *  Google Play Store'da bulunnan "Bluetooth Terminal HC-05" guzel bir program, test icin kullanilabilir.
 */

#include <SoftwareSerial.h>


SoftwareSerial bt(8,9);//RX,TX 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
bt.begin(38400);


}

void loop() { // run over and over
  if (bt.available()) {
    Serial.write(bt.read());
  }
  if (Serial.available()) {
    bt.write(Serial.read());
  }
}
