# Casper

# Comunication Flow

There are 2 different objects in program: Connection, Control and Robot. 

### Connection

Conection module is for TCP/IP or serial connection. It sends and receives given data in a form of a following frames, each frame type starts with it's own special character.

* Movement
  * *Character:* '!'
* External PWM
  * *Character:* '#'
* Telemetrics
  * *Character:* '@'
* Video Stream *TO BE DEVELOPED*
  * *Character:* '$'

##### Control frames

There are 3 control frames

* Enable/Disable movement permission - permission is lathed and confirmed

| Byte0 | Byte1 | Byte2 |
| ----- | ---- | ---- |
| '!' | '!' | permission [boolean] |


* Robot movement - *Full control over movement*

| Byte0 | Byte1 | Byte2 | Byte3 |
| ----- | ---- | ---- | ---- |
| '!' | '?' | Left  | Rigth|

* Robot movement - *wsad control*

| Byte0 | Byte1 | Byte2 |
| ----- | ---- | ---- |
| '!' | '@' | character (wsad)  |

*Left* and *Right* are [-100 ; 100] meaning -100 is max value backward for side and 100 max value for one side. 
Coded as unsinged int, so 0 is read as -100 control value and 200 is 100 control value. 

##### Manipulator movement - 3 axis

| Byte0 | Byte1 | Byte2 | Byte3 | Byte4 | Byte5 | Byte6 |
| ----- | ---- | ---- | ---- | ---- | ---- | ---- |
| '#' | axis 1 high | axis 1 low | axis 2 high | axis 2 low |axis 3 high | axis 3 low |

axis x high and axis x low are treated as unsinged int16 and are [0 ; 360], sent value is the exact desired angle.

#### Telemetrics

*TO BE DEVELOPED*

| Byte0 | Byte1 | Byte2 | Byte3 | Byte4 | Byte5 | Byte6 | Byte7 | Byte8 |
| ----- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| '#' | Battery voltage high | Battery voltage low | Current high | Current low | RPM left high | RPM left low | RPM right high | RPM right low |
