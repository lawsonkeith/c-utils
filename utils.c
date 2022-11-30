/*
 * utils.c
 *
 *  Created on: 13 Jun 2022
 *      Author: KXL1003A
 */
#include "utils.h"
#include <stdint.h>

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @ INCLUDES
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// order is: c lib / micro api / any other api / user app

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @ GLOBAL VARS
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @ GLOBAL CONSTS
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @ FUNCTIONS
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
static event_t buf[8] = {0};
static uint32_t err_cnt = 0;

// super simple error recorder now we're on the prod board which has no debug LEDs
// errors will just have to be viewed via debugger in dev.
//
void LOG_EVENT(event_t val)
{
	// totals
	err_cnt++;

	// buffer
	buf[7] = buf[6];
	buf[6] = buf[5];
	buf[5] = buf[4];
	buf[4] = buf[3];
	buf[3] = buf[2];
	buf[2] = buf[1];
	buf[1] = buf[0];
	buf[0] = val;
}

