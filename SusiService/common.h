#ifndef _SUSI_COMMON_H_
#define _SUSI_COMMON_H_

#define GPIO_MASK 1
#define SUSIDEMO_INFORMATION_STRING_MAX 	7

/* Public */
#define STRING_MAXIMUM_LENGTH		64
#define NAME_MAXIMUM_LENGTH			32

#define SUSIDEMO_FUNCTIONS_GOBACK		(-1)
#define SUSIDEMO_FUNCTIONS_UNDEFINED	(-2)
#define SUSIDEMO_DEVICEID_UNDEFINED		((SusiId_t)0xFFFFFFFF)
#define SUSIDEMO_ITEM_UNDEFINED			(-1)

/*#define SUSIDEMO_ERRCODE_SUSIFUNCTION	1
#define SUSIDEMO_ERRCODE_NODEVCE		2
#define SUSIDEMO_ERRCODE_INVALIDINPUT	3*/

#define SUSIDEMO_PRINT_NONE		0
#define SUSIDEMO_PRINT_SUCCESS	1
#define SUSIDEMO_PRINT_ERROR	2

#define SUSIDEMO_DEVICE_AVAILALBE	1
#define SUSIDEMO_DEVICE_UNAVAILALBE	0

#define NELEMS(_array)	(uint32_t)(sizeof(_array) / sizeof(_array[0]))

typedef struct {
	uint32_t maxValue;
	uint32_t minValue;
	/*
	 *enableFlag
	 * bit0: PWM emthod enable
	 * bit1: ACPI emthod enable
	 * bit2: frequency control enable
	 * bit3: polarity control enable
	 * bit4: backlight control enable
	 * others: reserve
	 */
	uint32_t enableFlag;
} VGAInfo, *PVGAInfo;

typedef struct {
	uint32_t frequencyVal;
	uint32_t polarityVal;
	uint32_t backlightVal;
	uint32_t methodVal;
	uint32_t brightnessVal;
} VGAConfig, *PVGAConfig;

enum enableRank{	
	enablePWM,
	enableACPI,
	enableFrequency,
	enablePolarity,
	enableBacklight,
	NumEnable,
};

#endif /*_SUSI_COMMON_H_*/