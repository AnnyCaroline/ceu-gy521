# Test GY521 directly using I2C driver

[I2C driver](https://github.com/JingruiLea/ceu-arduino/tree/ljr/libraries/driver-i2c)

Also important: [GY30 driver](https://github.com/JingruiLea/ceu-arduino/blob/ljr/ceu_examples/GY30/GY30.ceu)

## Energy measurement using Serial and -DCEU_PM_MIN

|                 | Arduino | Céu  (-DCEU_PM_MIN) |
| --------------- | ------- | ------------------- |
| Arduino UNO     | 53 mA   | 41.5 mA             |
| Mini Ultra 8MHz | 2,97 mA | 9,08 mA             |