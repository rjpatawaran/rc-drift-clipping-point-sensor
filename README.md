# RC Drifting Clipping Point Sensor using Arduino and HC-SR04 sensor

# Bill of Materials
|                       | Unit Price | Link                                                                                                                                                                                                     |   |   |
|-----------------------|------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---|---|
| HC-SR04               | ₱70.00     | https://www.lazada.com.ph/products/ultrasonic-sensor-distance-measuring-module-hc-sr04-5-pieces-i115868246-s119997165.html?spm=a2o4l.searchlist.list.5.5a7e15d0ckr1e8&search=1                           |   |   |
| Arduino Uno           | ₱201.75    | https://www.lazada.com.ph/products/arduino-uno-r3-ch340g-with-usb-cable-i277750314-s415428931.html?spm=a2o4l.searchlist.list.27.5cf93bd03xM06H&search=1                                                  |   |   |
| Neopixel RGB Led      | ₱61.00     | https://www.lazada.com.ph/products/neopixel-diffused-8mm-through-hole-led-5-pack-i111661085-s113849544.html?spm=a2o4l.searchlist.list.1.390832c1CbpClH&search=1                                          |   |   |
| Jumper Wires          | ₱99.75     | https://www.lazada.com.ph/products/40pcs-20cm-254mm-male-to-female-dupont-jumper-wires-cables-i6122012-s7751975.html?spm=a2o4l.searchlist.list.39.19293661BcKRfL&search=1                                |   |   |
| Potentiometer         | ₱27.80     | https://www.lazada.com.ph/products/idealhere-5pcs-10k-ohm-linear-mono-stereo-pot-rotary-15mm-resistor-potentiometer-knobs-i277389259-s414286851.html?spm=a2o4l.searchlist.list.3.77287f1aNTQsn3&search=1 |   |   |

# Pinout
| Component     |     | Arduino Uno  |   |               |
|---------------|-----|--------------|---|---------------|
|               | PIN |              |   | PIN           |
| LED           | 1   | Data In      |   | D11           |
|               | 2   | VCC          |   | 5V            |
|               | 3   | GND          |   | GND           |
| (Flat Side)   | 4   | Data Out     |   | Not Connected |
|               |     |              |   |               |
| Potentiometer | 1   | Fixed End    |   | GND           |
|               | 2   | Variable End |   | A2            |
|               | 3   | Fixed End    |   | 5V            |
|               |     |              |   |               |
| HC-SR04       | 1   | VCC          |   | 5V            |
|               | 2   | Trigger      |   | D9            |
|               | 3   | Echo         |   | D10           |
|               | 4   | GND          |   | GND           |
