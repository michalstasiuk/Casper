/*
 * bms.h
 *
 *  Created on: Dec 23, 2021
 *      Author: stasiukm
 */

#ifndef BMS_BMS_H_
#define BMS_BMS_H_

#define MAX_VOLTAGE
#define MIN_VOLTAGE
#define MAX_CURRENT
#define

typedef struct{
	float current;
	float voltage;
	fload soc;
}battery;

battery* get_battery_status();

void update_battery_status();

#endif /* BMS_BMS_H_ */
