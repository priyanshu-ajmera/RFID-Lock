# RFID-Lock
RFID cards are issued to specific people in the shop. Card Reader is present at both the ends of the doorway and is required to read on both entry and exit. PIR sensor is present in the room to detect the human presence and turn on the lights if detected.
Every time an entry is registered at the first reader, a timer for 10 seconds starts such that the card is to be shown to the reader present inside the room. If failed to do, an alarm will buzz off creating a lock-in situation and an automated message using GSM 900 will be sent to the owner of the shop to take the needful action.
Along with that, a gas sensor MQ2 and MQ6 are used in case of gas leakage detection and a temperature controller IC LM35 is used for controlling the room temperature.
