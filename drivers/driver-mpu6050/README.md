# MPU6050

## API

### Includes
```
#include "mpu6050.ceu"
```

### Code abstractions

#### MPU6050_Init
Initializes the mpu6050 with the given address or the default one.  The Init will take the device out of sleep mode (which must be done after start-up). It also sets both the accelerometer and the gyroscope to their most sensitive settings, namely +/- 2g and +/- 250 degrees/sec, and sets the clock source to use the X Gyro for reference, which is recomended at the datasheet.

```
code/await MPU6050_Init(var byte? address) -> none;
```

Parameters:
- `byte? address`: the I2C address. It can be `MPU6050_ADDRESS_AD0_LOW` (if the AD0 pin is low) or `MPU6050_ADDRESS_AD0_HIGH` (if AD0 is high). If none is provided, the default one is used (`MPU6050_DEFAULT_ADDRESS`), which by default is equals do `MPU6050_ADDRESS_AD0_LOW`.

#### MPU6050_setClockSource
Set clock source setting.

```
code/await MPU6050_setClockSource(var byte source) -> none;
```

Parameters:
- `byte`: clock source. The values can be:

    |                           | hex  | description                                             |
    |---------------------------|------|---------------------------------------------------------|
    | MPU6050_CLOCK_INTERNAL    | 0x00 | PLL with X Gyro reference                               |
    | MPU6050_CLOCK_PLL_XGYRO   | 0x01 | PLL with Y Gyro reference                               |
    | MPU6050_CLOCK_PLL_YGYRO   | 0x02 | PLL with Z Gyro reference                               |
    | MPU6050_CLOCK_PLL_ZGYRO   | 0x03 | PLL with external 32.768kHz reference                   |
    | MPU6050_CLOCK_PLL_EXT32K  | 0x04 | PLL with external 19.2MHz reference                     |
    | MPU6050_CLOCK_PLL_EXT19M  | 0x05 | Reserved                                                |
    | MPU6050_CLOCK_KEEP_RESET  | 0x07 | Stops the clock and keeps the timing generator in reset |

#### MPU6050_setFullScaleGyroRange
Set full-scale gyroscope range

```
code/await MPU6050_setFullScaleGyroRange(var byte range)  -> none;
```

Parameters:
- `byte`: New full-scale gyroscope range value. The values can be:

    |                      | hex  |
    |----------------------|------|
    | MPU6050_GYRO_FS_250  | 0x00 |
    | MPU6050_GYRO_FS_500  | 0x01 |
    | MPU6050_GYRO_FS_1000 | 0x02 |
    | MPU6050_GYRO_FS_2000 | 0x03 |

#### MPU6050_setFullScaleAccelRange
Set full-scale accelerometer range

```
code/await MPU6050_setFullScaleAccelRange(var byte range) -> none;
```

Parameters:
- `byte`: New full-scale accelerometer range setting. The values can be:

    |                     | hex  |
    |---------------------|------|
    | MPU6050_ACCEL_FS_2  | 0x00 |
    | MPU6050_ACCEL_FS_4  | 0x01 |
    | MPU6050_ACCEL_FS_8  | 0x02 |
    | MPU6050_ACCEL_FS_16 | 0x03 |

#### MPU6050_setSleepEnabled
Set sleep mode status.

```
MPU6050_setSleepEnabled(var bool enabled) -> none;
```

Parameters:
- `bool`: New sleep mode enabled status.

#### MPU6050_getRotation
Get 3-axis gyroscope readings.

```
code/await MPU6050_getRotation(var& int gx, var& int gy, var& int gz) -> none;
```

Parameters:
- `&int`: integer container for X-axis rotation
- `&int`: integer container for Y-axis rotation
- `&int`: integer container for Z-axis rotation

#### MPU6050_getAcceleration
Get 3-axis accelerometer readings.

```
code/await MPU6050_getAcceleration(var& int ax, var& int ay, var& int az) -> none;
```

Parameters:
- `&int`: integer container for X-axis acceleration
- `&int`: integer container for Y-axis acceleration
- `&int`: integer container for Z-axis acceleration

#### MPU6050_getTemperature
Get current internal temperature.
```
code/await MPU6050_getTemperature(none) -> int;
```

Return:
- `int`: Temperature reading in 16-bit 2's complement format

#### MPU6050_getMotion6
Get raw 6-axis motion sensor readings (accel/gyro). Retrieves all currently available motion sensor values.

```
code/await MPU6050_getMotion6(var& int ax, var& int ay, var& int az, var& int gx, var& int gy, var& int gz) -> none;
```

Parameters:
- `&int`: container for accelerometer X-axis value
- `&int`: container for accelerometer Y-axis value
- `&int`: container for accelerometer Z-axis value
- `&int`: container for gyroscope X-axis value
- `&int`: container for gyroscope Y-axis value
- `&int`: container for gyroscope Z-axis value


## Examples
### Get motion 6
```
#include "wclock.ceu"
#include "i2c.ceu"
#include "i2cdev.ceu"
#include "mpu6050.ceu"

_Serial.begin(9600);

emit I2C(on,_);

await MPU6050_Init(0x68);

var int ax=0; var int ay=0; var int az=0;
var int gx=0; var int gy=0; var int gz=0;

await MPU6050_getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
_Serial.println(ax);
_Serial.println(ay);
_Serial.println(az);
_Serial.println(gx);
_Serial.println(gy);
_Serial.println(gz);

await FOREVER;
```

### Get accel, gyro and temperature values
```
#include "wclock.ceu"
#include "i2c.ceu"
#include "i2cdev.ceu"
#include "mpu6050.ceu"

_Serial.begin(9600);

emit I2C(on,_);

await MPU6050_Init(0x68);

var int ax=0; var int ay=0; var int az=0;
var int gx=0; var int gy=0; var int gz=0;

_Serial.println("\n-ACC-----------------");
await MPU6050_getAcceleration(&ax, &ay, &az);
_Serial.println(ax);
_Serial.println(ay);
_Serial.println(az);

_Serial.println("\n-TMP-----------------");
var int raw_tmp = await MPU6050_getTemperature();
var real tmp = (raw_tmp as real)/340.00+36.53;
_Serial.println(raw_tmp);
_Serial.println(tmp);

_Serial.println("\n-ROT-----------------");
await MPU6050_getRotation(&gx, &gy, &gz);
_Serial.println(gx);
_Serial.println(gy);
_Serial.println(gz);

await FOREVER;
```