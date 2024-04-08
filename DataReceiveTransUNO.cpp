#define E2END 1023

void EEPROM_write(int, byte);
byte EEPROM_read(int);

void setup() {
  Serial.begin(2400);
}

void loop() {
  if (Serial.available() > 0) {
    String receivedString = Serial.readStringUntil('\n');

    int address = 0;
    int strLength = receivedString.length();
    for (int i = 0; i < strLength; i++) {
      EEPROM_write(address + i, receivedString[i]);
    }

    Serial.println(receivedString);

    delay(100);
  }

  if (EEPROM_read(0) != 0) {
    String sentString = "";
    int address = 0;
    int strLength = EEPROM_read(address);
    for (int i = 0; i < strLength; i++) {
      char ch = EEPROM_read(address + 1 + i);
      sentString += ch;
    }
    Serial.println(sentString);

    for (int i = 0; i < E2END; i++) {
      EEPROM_write(i, 0);
    }

    delay(100);
  }
}

void EEPROM_write(int address, byte value) {
  while (EECR & (1 << EEPE)) {}
  EEAR = address;
  EEDR = value;
  EECR |= (1 << EEMPE);
  EECR |= (1 << EEPE);
}

byte EEPROM_read(int address) {
  while (EECR & (1 << EEPE)) {}
  EEAR = address;
  EECR |= (1 << EERE);
  return EEDR;
}
