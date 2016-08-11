# TMK Firmware for The Wombat

### Clone
```
git clone git@github.com:egladman/wombat-tmk.git
cd wombat-tmk
git submodule update --init --recursive
```

### Compile
```bash
make
# or specify a keymap
make KEYMAP=plain
```

### Flash
*you might need to run the following command as super user*
```
avrdude -p atmega32u4 -P /dev/ttyACM0  -c avr109  -U flash:w:wombat_lufa.hex
```
