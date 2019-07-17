# Test GY521 directly using I2C driver

[I2C driver](https://github.com/JingruiLea/ceu-arduino/tree/ljr/libraries/driver-i2c)

Also important: [GY30 driver](https://github.com/JingruiLea/ceu-arduino/blob/ljr/ceu_examples/GY30/GY30.ceu)

## Energy measurement

|                 | Arduino | Céu (with -DCEU_PM_MIN) | Céu (without -DCEU_PM_MIN) |
| --------------- | ------- | ----------------------- | -------------------------- |
| Arduino UNO     | 53 mA   | 45.5 mA                 | 43.5 mA                    |
| Mini Ultra 8MHz | 9.08 mA | 6.73 mA                 | 6.13 mA                    |
