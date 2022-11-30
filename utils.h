/*
 * utils.h
 *
 * Macro functions etc, not generally project specific.
 *
 *  Created on: 8 Apr 2022
 *      Author: KXL1003A
 */

#ifndef UTILS_H_
#define UTILS_H_

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @ DATATYPES
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// warning enum for debug LED (test brd)
//
typedef enum
{
    INIT_OK = 1 ,  // General purpose updateable watch vals 1-9
    SHUTDOWN = 2,
    ERR_ERROR = 10, // these errors latch in
    ERR_HW_INIT_ERR = 11,
    ERR_PWM_ERR = 12,
	ERR_OVERFLOW = 13
}event_t;

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @ FUNCTION PROTOTYPES
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void LOG_EVENT(event_t val);

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @ GLOBAL VARS (PUBLIC)
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @ GLOBAL CONSTS (PUBLIC)
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @ DEFINES
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// exponential moving average - a is the average, b is the input
// to be used with unsigned values!
// usage:  EMA_DIV8_AVG(filtered_adc_pack_temp, adc_pack_temp, uint16_t);
// c=cast, a=op b=ip
#define EMA_DIV8_AVG(a,b,c) (a = (c)(((a * 7) + b + 7) >> 3))
#define EMA_DIV16_AVG(a,b,c) (a = (c)(((a * 15) + b + 15) >> 4))
#define EMA_DIV32_AVG(a,b,c) (a = (c)(((a * 31) + b + 31) >> 5))

#define LENGTH(array) (sizeof(array) / sizeof (array[0]))

#define MIN( n1, n2 )   ((n1) > (n2) ? (n2) : (n1))
#define MAX( n1, n2 )   ((n1) > (n2) ? (n1) : (n2))
#define IS_ODD( num )   ((num) & 1)
#define IS_EVEN( num )  (!IS_ODD( (num) ))
#define IS_BETWEEN( numToTest, numLow, numHigh ) \
        ((unsigned char)((numToTest) >= (numLow) && (numToTest) <= (numHigh)))
#define IS_LITTLE_ENDIAN()  (((*(short *)"21") & 0xFF) == '2')

// in most my state machines there is also a substate counter to count time in the state
// this macro resets it when we change states.
#define SET_STATE(n) {state=n;substate=0;}

// you need to use both of these
#define UNOPTIMIZED __attribute__((optimize("O0")))
#define UNOPTIMIZED_VAR	volatile
#define OPTIMIZED_SPEED __attribute__((optimize("O3")))


// XMC helper funct for DIGITAL_IO_SetOutputLow(&LED_AC); -->  DIGITAL_IO_SetOutput(&LED_AC,true);
//
#define DIGITAL_IO_SetOutput(a,b)    (b ? (DIGITAL_IO_SetOutputHigh(a)) : DIGITAL_IO_SetOutputLow(a))


#define BIT0 (1)
#define BIT1 (1<<1)
#define BIT2 (1<<2)
#define BIT3 (1<<3)
#define BIT4 (1<<4)
#define BIT5 (1<<5)
#define BIT6 (1<<6)
#define BIT7 (1<<7)
#define BIT8 (1<<8)
#define BIT9 (1<<9)
#define BIT10 (1<<10)
#define BIT11 (1<<11)
#define BIT12 (1<<12)
#define BIT13 (1<<13)
#define BIT14 (1<<14)
#define BIT15 (1<<15)


#endif /* UTILS_H_ */
