#include <NfcAdapter.h>
#include <PN532.h>
#include <Wire.h>
#include <PN532_I2C.h>



PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);

void setup() {
    Serial.begin(115200);
    Serial.println("NDEF Writer");
    nfc.begin();
}

void loop() {
    Serial.println("\nPlace a formatted Mifare Classic or Ultralight NFC tag on the reader.");
    if (nfc.tagPresent()) {
        NdefMessage message = NdefMessage();
        message.addUriRecord("Your weight: ");

        bool success = nfc.write(message);
        if (success) {
            Serial.println("Success. Try reading this tag with your phone.");
        } else {
            Serial.println("Write failed.");
        }
    }
    delay(5000);
}
