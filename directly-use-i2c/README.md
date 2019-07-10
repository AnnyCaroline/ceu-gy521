# Test GY521 directly using I2C driver

[I2C driver](https://github.com/JingruiLea/ceu-arduino/tree/ljr/libraries/driver-i2c)

Also important: [GY30 driver](https://github.com/JingruiLea/ceu-arduino/blob/ljr/ceu_examples/GY30/GY30.ceu)

## First energy measurement

Since I'm still using `Serial.print`, I needed to define `CEU_DEFS = -DCEU_PM_MIN` at `Makefile.conf`. Because of that, Céu is saving the minimum energy (`DCEU_PM_MIN`).

|                 | Arduino | Céu  (-DCEU_PM_MIN) |
| --------------- | ------- | ------------------- |
| Arduino UNO     | 53 mA   | 41.5 mA             |
| Mini Ultra 8MHz | 53 mA   | 41.5 mA             |