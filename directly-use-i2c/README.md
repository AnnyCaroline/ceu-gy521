# Test GY521 directly using I2C driver

[I2C driver](https://github.com/JingruiLea/ceu-arduino/tree/ljr/libraries/driver-i2c)

Also important: [GY30 driver](https://github.com/JingruiLea/ceu-arduino/blob/ljr/ceu_examples/GY30/GY30.ceu)

## Energy measurement

### Using -DCEU_PM_MIN

|                 | Arduino | Céu (Serial and -DCEU_PM_MIN) | Céu (USART and -DCEU_PM_MIN) |
| --------------- | ------- | ----------------------------- | ---------------------------- |
| Arduino UNO     | 53 mA   | 41.5 mA                       | 41.6 mA                      |
| Mini Ultra 8MHz | 9,08 mA | 2,97 mA                       | 2,96 mA                      |

There is no difference between using the USART driver and the Arduino Serial when using the -DCEU_PM_MIN (minimum power saving mode), in this case, at least.

### Using sleep mode (without -DCEU_PM_MIN)

|                 | Arduino | Céu (Serial and -DCEU_PM_MIN) |
| --------------- | ------- | ----------------------------- |
| Arduino UNO     | 53 mA   | 39.6 mA                       |
| Mini Ultra 8MHz | 9,08 mA | 2.45 mA                       |
