/******************************************************************************
 * Copyright AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

/**
 * Per-module definition of the current module for debug logging.  Must be defined
 * prior to first inclusion of aj_debug.h.
 * The corresponding flag dbgAJSVCAPP is defined in the containing sample app.
 */
#define AJ_MODULE AJSVCAPP
#include <aj_debug.h>

#include "ControlPanelProvided.h"
#include "ControlPanelGenerated.h"
#include "alljoyn/controlpanel/Common/BaseWidget.h"

#include "Susi4.h"
#include "common.h"

#ifdef _WIN32
#define snprintf _snprintf
#endif

#ifndef snprintf
#include <stdio.h>
#endif

#ifndef NDEBUG
extern AJ_EXPORT uint8_t dbgAJSVCAPP;
#endif
	
/* SUSI Board */
uint32_t AJ_SusiBoardGetValue(uint32_t Id, uint32_t *pValue)
{
    SusiStatus_t status = SusiBoardGetValue(Id, pValue);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiBoardGetStringA(uint32_t Id, char *pBuffer, uint32_t *pBufLen)
{
    SusiStatus_t status = SusiBoardGetStringA(Id, pBuffer, pBufLen);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

/* SUSI VGA */
uint32_t AJ_SusiVgaGetCaps(uint32_t Id, uint32_t ItemId, uint32_t *pValue)
{
    SusiStatus_t status = SusiVgaGetCaps(Id, ItemId, pValue);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiVgaGetBacklightEnable(uint32_t Id, uint32_t *pEnable)
{
    SusiStatus_t status = SusiVgaGetBacklightEnable(Id, pEnable);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiVgaSetBacklightEnable(uint32_t Id, uint32_t Enable)
{
    SusiStatus_t status = SusiVgaSetBacklightEnable(Id, Enable);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiVgaGetBacklightBrightness(uint32_t Id, uint32_t *pBright)
{
    SusiStatus_t status = SusiVgaGetBacklightBrightness(Id, pBright);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiVgaSetBacklightBrightness(uint32_t Id, uint32_t Bright)
{
    SusiStatus_t status = SusiVgaSetBacklightBrightness(Id, Bright);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiVgaGetBacklightLevel(uint32_t Id, uint32_t *pLevel)
{
    SusiStatus_t status = SusiVgaGetBacklightLevel(Id, pLevel);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiVgaSetBacklightLevel(uint32_t Id, uint32_t Level)
{
    SusiStatus_t status = SusiVgaSetBacklightLevel(Id, Level);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiVgaGetPolarity(uint32_t Id, uint32_t *pPolarity)
{
    SusiStatus_t status = SusiVgaGetPolarity(Id, pPolarity);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiVgaSetPolarity(uint32_t Id, uint32_t Polarity)
{
    SusiStatus_t status = SusiVgaSetPolarity(Id, Polarity);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiVgaGetFrequency(uint32_t Id, uint32_t *pFrequency)
{
    SusiStatus_t status = SusiVgaGetFrequency(Id, pFrequency);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiVgaSetFrequency(uint32_t Id, uint32_t Frequency)
{
    SusiStatus_t status = SusiVgaSetFrequency(Id, Frequency);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

/* SUSI I2C */
uint32_t AJ_SusiI2CGetCaps(uint32_t Id, uint32_t ItemId, uint32_t *pValue)
{
    SusiStatus_t status = SusiI2CGetCaps(Id, ItemId, pValue);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiI2CWriteReadCombine(uint32_t Id, uint8_t Addr, uint8_t *pWBuffer, uint32_t WriteLen, uint8_t *pRBuffer, uint32_t ReadLen)
{
    SusiStatus_t status = SusiI2CWriteReadCombine(Id, Addr, pWBuffer, WriteLen, pRBuffer, ReadLen);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiI2CReadTransfer(uint32_t Id, uint32_t Addr, uint32_t Cmd, uint8_t *pBuffer, uint32_t ReadLen)
{
    SusiStatus_t status = SusiI2CReadTransfer(Id, Addr, Cmd, pBuffer, ReadLen);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiI2CWriteTransfer(uint32_t Id, uint32_t Addr, uint32_t Cmd, uint8_t *pBuffer, uint32_t ByteCnt)
{
    SusiStatus_t status = SusiI2CWriteTransfer(Id, Addr, Cmd, pBuffer, ByteCnt);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiI2CProbeDevice(uint32_t Id, uint32_t Addr)
{
    SusiStatus_t status = SusiI2CProbeDevice(Id, Addr);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiI2CGetFrequency(uint32_t Id, uint32_t *pFreq)
{
    SusiStatus_t status = SusiI2CGetFrequency(Id, pFreq);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiI2CSetFrequency(uint32_t Id, uint32_t Freq)
{
    SusiStatus_t status = SusiI2CSetFrequency(Id, Freq);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

/* SUSI Watchdog */
uint32_t AJ_SusiWDogGetCaps(uint32_t Id, uint32_t ItemId, uint32_t *pValue)
{
    SusiStatus_t status = SusiWDogGetCaps(Id, ItemId, pValue);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiWDogStart(uint32_t Id, uint32_t DelayTime, uint32_t EventTime, uint32_t ResetTime, uint32_t EventType)
{
    SusiStatus_t status = SusiWDogStart(Id, DelayTime, EventTime, ResetTime, EventType);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiWDogStop(uint32_t Id)
{
    SusiStatus_t status = SusiWDogStop(Id);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiWDogTrigger(uint32_t Id)
{
    SusiStatus_t status = SusiWDogTrigger(Id);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

/* SUSI GPIO */
uint32_t AJ_SusiGPIOGetCaps(uint32_t Id, uint32_t ItemId, uint32_t *pValue)
{
    SusiStatus_t status = SusiGPIOGetCaps(Id, ItemId, pValue);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiGPIOGetDirection(uint32_t Id, uint32_t Bitmask, uint32_t *pDirection)
{
    SusiStatus_t status = SusiGPIOGetDirection(Id, Bitmask, pDirection);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiGPIOSetDirection(uint32_t Id, uint32_t Bitmask, uint32_t Direction)
{
    SusiStatus_t status = SusiGPIOSetDirection(Id, Bitmask, Direction);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiGPIOGetLevel(uint32_t Id, uint32_t Bitmask, uint32_t *pLevel)
{
    SusiStatus_t status = SusiGPIOGetLevel(Id, Bitmask, pLevel);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

uint32_t AJ_SusiGPIOSetLevel(uint32_t Id, uint32_t Bitmask, uint32_t Level)
{
    SusiStatus_t status = SusiGPIOSetLevel(Id, Bitmask, Level);
    if (status)
        AJ_ErrPrintf(("%s failed! Err: 0x%x\n", __func__, status));
    return status;
}

////////////////////////////////////////////////////////////////
//For Board Info.
static char board_manufacturer_Buffer[STRING_MAXIMUM_LENGTH] = "";
static char board_name_Buffer[STRING_MAXIMUM_LENGTH] = "";
static char driver_version_Buffer[STRING_MAXIMUM_LENGTH] = "";
static char library_version_Buffer[STRING_MAXIMUM_LENGTH] = "";
//For Temperature
static char cpu_temperature_Buffer[STRING_MAXIMUM_LENGTH] = "";
static uint8_t subscription = FALSE;

static char* board_manufacturer_String = board_manufacturer_Buffer;
static char* board_name_String = board_name_Buffer;
static char* driver_version_String = driver_version_Buffer;
static char* library_version_String = library_version_Buffer;
static char* cpu_temperature_String = cpu_temperature_Buffer;
//For Display
static const uint8_t max_display_dev = SUSI_ID_BACKLIGHT_MAX;

static SusiId_t display_sel_dev = 0;
static uint32_t backlight_value = 0;
static uint32_t blightness_value = 0;
//For GPIO
static uint32_t selected_gpio = 0;
static uint32_t gpio_dir = 0;
static uint32_t gpio_level = 0;
static uint32_t gpio_mask = GPIO_MASK;

static SusiId_t display_pre_dev = -1;
static uint32_t backlight_pre_value = -1;
static uint32_t brightness_pre_value = -1;
static uint32_t gpio_pre_dir = -1;
static uint32_t gpio_pre_level = -1;

uint8_t backlight_flag = 1;
uint8_t brightness_flag = 1;

static uint8_t signalsToSend = 0;
static uint8_t eventsToSend = 0;

static char notificationText[51] = "Notification text goes here";
static char* notificationString = notificationText;
static uint16_t sendANotification = 0;
static const char* notificationActionObjPath = NULL;

void get_string_info(int index, char* buffer)
{
		uint32_t status;
		char getStr[STRING_MAXIMUM_LENGTH];
		uint32_t getStrLen;
	
		getStrLen = STRING_MAXIMUM_LENGTH;
	  status = AJ_SusiBoardGetStringA(index, getStr, &getStrLen);
	  if (status == SUSI_STATUS_SUCCESS)
	  {
		  	sprintf(buffer,"%s",getStr);
		  	buffer[getStrLen] = '\0';
	  }
}

void get_version(int index, char* buffer)
{
		uint32_t status, getVal;
	
		status = AJ_SusiBoardGetValue(SUSI_ID_BOARD_VER_BASE + index, &getVal);
		if (status == SUSI_STATUS_SUCCESS)
		{
				sprintf(buffer,"%u.%u.%u", (getVal >> 24), ((getVal >> 16) & 0xFF), (getVal & 0xFFFF));
				buffer[strlen(buffer)] = '\0';
		}
}

void get_temperature(int index, char* buffer)
{
		SusiStatus_t status;
		SusiId_t id;
		uint32_t getVal;
		float convVal;
		
		if (index == -1)
				return ;
		
		id = SUSI_ID_HWM_TEMP_BASE + index;
		status = AJ_SusiBoardGetValue(id, &getVal);
		if (status == SUSI_STATUS_SUCCESS)
		{
				convVal = SUSI_DECODE_CELCIUS((float)getVal);
				sprintf(buffer, "%.1f Celsius", convVal);
		}
		else
		{
				sprintf(buffer, "Get temperature failed.(0x%08X)", status);
		}	
}

void find_display_num()
{
		SusiStatus_t status;
		SusiId_t id;
		uint8_t index, i;
		uint32_t tmp;
		uint32_t enableFlag = 0;
		
		index = 0;	/* index for panel */
		for (i = 0; i < max_display_dev; i++)
		{
			id = i;
			enableFlag = 0;
	
			status = AJ_SusiVgaGetCaps(id, SUSI_ID_VGA_BRIGHTNESS_MAXIMUM, &tmp);
			if (status == SUSI_STATUS_SUCCESS && tmp > 0)
					enableFlag |= (1 << enablePWM);
	
			if ((enableFlag & (1 << enablePWM)) != 0)
			{
					status = AJ_SusiVgaGetCaps(id, SUSI_ID_VGA_BRIGHTNESS_MINIMUM, &tmp);
					if (status != SUSI_STATUS_SUCCESS)
							enableFlag &= ~(1 << enablePWM);
			}
	
			if (AJ_SusiVgaGetBacklightLevel(id, &tmp) == SUSI_STATUS_SUCCESS)
					enableFlag |= (1 << enableACPI);
	
			if (enableFlag == 0)
					continue;			
			
			index++;
		}
		
		SUSIAccessDisplayDeviceProperty.optParams.numConstraints = index;
}

void find_gpio_num()
{
		uint32_t supInput, supOutput, supPinNum;
		uint32_t status, supportPin, id;
		uint8_t index, j;
		
		index = 0;
		id = SUSI_ID_GPIO_BANK(index);
	
		status = AJ_SusiGPIOGetCaps(id, SUSI_ID_GPIO_INPUT_SUPPORT, &supInput);
		if (status != SUSI_STATUS_SUCCESS)
				return;
	
		status = AJ_SusiGPIOGetCaps(id, SUSI_ID_GPIO_OUTPUT_SUPPORT, &supOutput);
		if (status != SUSI_STATUS_SUCCESS)
				return;
	
		supportPin = supInput | supOutput;
	
		if (supportPin > 0)
		{
				for (j = 32; (supportPin & (1 << (j - 1))) == 0; j--);
						supPinNum = j;
				SUSIAccessGPIOProperty.optParams.numConstraints = supPinNum;
		}
		else
		{
				SUSIAccessGPIOProperty.optParams.numConstraints = 0;
		}
}

//-------------------------------------

void* getBoardManufacturerString(PropertyWidget* thisWidget)
{
		get_string_info(0, board_manufacturer_Buffer);
		return &board_manufacturer_String;
}

void setBoardManufacturerString(char const* newBoardInfo)
{
    //do nothing
}

void* getBoardNameString(PropertyWidget* thisWidget)
{
		get_string_info(1, board_name_Buffer);
		return &board_name_String;
}

void setBoardNameString(char const* newBoardInfo)
{
    //do nothing
}

void* getDriverVersionString(PropertyWidget* thisWidget)
{
		get_version(0, driver_version_Buffer);
		return &driver_version_String;
}

void setDriverVersionString(char const* newBoardInfo)
{
    //do nothing
}

void* getLibraryVersionString(PropertyWidget* thisWidget)
{
		get_version(1, library_version_Buffer);
		return &library_version_String;
}

void setLibraryVersionString(char const* newBoardInfo)
{
    //do nothing
}

void* getCPUTemperatureString(PropertyWidget* thisWidget)
{
		get_temperature(0, cpu_temperature_Buffer);
		return &cpu_temperature_String;
}

void setCPUTemperatureString(char const* newBoardInfo)
{
    //do nothing
}

void* getDisplayDevice(PropertyWidget* thisWidget)
{
		return &display_sel_dev;
}

void setDisplayDevice(uint32_t newValue)
{
  	display_sel_dev = newValue;
}

void* getBrightnessValue(PropertyWidget* thisWidget)
{
		AJ_SusiVgaGetBacklightBrightness(display_sel_dev, &blightness_value);
		return &blightness_value;
}

void setBrightnessValue(uint32_t newValue)
{
		AJ_SusiVgaSetBacklightBrightness(display_sel_dev, newValue);
		blightness_value = newValue;
}

void* getBacklightValue(PropertyWidget* thisWidget)
{
		AJ_SusiVgaGetBacklightEnable(display_sel_dev, &backlight_value);
		return &backlight_value;
}

void setBacklightValue(uint32_t newValue)
{
		AJ_SusiVgaSetBacklightEnable(display_sel_dev, newValue);	
		backlight_value = newValue;
}

void* getGPIOPin(PropertyWidget* thisWidget)
{
		return &selected_gpio;
}

void setGPIOPin(uint32_t newValue)
{
		selected_gpio = newValue & 0xFF;
}

void* getGPIODirValue(PropertyWidget* thisWidget)
{
		AJ_SusiGPIOGetDirection(selected_gpio, gpio_mask, &gpio_dir);
		return &gpio_dir;
}

void setGPIODirValue(uint32_t newValue)
{
		AJ_SusiGPIOSetDirection(selected_gpio, gpio_mask, newValue);
		gpio_dir = newValue;	
}

void* getGPIOLevelValue(PropertyWidget* thisWidget)
{
		AJ_SusiGPIOGetLevel(selected_gpio, gpio_mask, &gpio_level);
		return &gpio_level;
}

void setGPIOLevelValue(uint32_t newValue)
{
		AJ_SusiGPIOSetLevel(selected_gpio, gpio_mask, newValue);
		gpio_level = newValue;
}

void* getSubscription(PropertyWidget* thisWidget)
{
		return &subscription;
}

void setSubscription(uint32_t newValue)
{
		subscription = !subscription;
}
////////////////////////////////////////////////////////////////

void disableBrightness()
{
		setBaseEnabled(&SUSIAccessBrightnessProperty.base, FALSE);
		setBaseWritable(&SUSIAccessBrightnessProperty.base, FALSE);	
}

void enableBrightness()
{
		setBaseEnabled(&SUSIAccessBrightnessProperty.base, TRUE);
		setBaseWritable(&SUSIAccessBrightnessProperty.base, TRUE);
}

void disableGPIOLevel()
{
	  setBaseEnabled(&SUSIAccessGPIOLevelProperty.base, FALSE);
	  setBaseWritable(&SUSIAccessGPIOLevelProperty.base, FALSE);
}

void enableGPIOLevel()
{
		setBaseEnabled(&SUSIAccessGPIOLevelProperty.base, TRUE);
		setBaseWritable(&SUSIAccessGPIOLevelProperty.base, TRUE);
}

void setTemperatureFieldUpdate() 
{
    signalsToSend |= 1 << 0;
}

void setDisplayOptionUpdate() 
{
    signalsToSend |= 1 << 1;
}

void setBlacklightPropertyUpdate() 
{
    signalsToSend |= 1 << 2;
}

void setGPIOOptionUpdate() 
{
    signalsToSend |= 1 << 3;
}

uint8_t checkForUpdatesToSend()
{		
		signalsToSend = 0;

		AJ_SusiVgaGetBacklightEnable(display_sel_dev, &backlight_value);
		AJ_SusiVgaGetBacklightBrightness(display_sel_dev, &blightness_value);
		AJ_SusiGPIOGetDirection(selected_gpio, gpio_mask, &gpio_dir);
		AJ_SusiGPIOGetLevel(selected_gpio, gpio_mask, &gpio_level);		
	
		if (display_sel_dev != display_pre_dev)
		{
				switch (display_sel_dev)
				{
						case 0://HDMI
						case 1://VGA
										disableBrightness();
										break;	
						default://LVDS1,LVDS2
										enableBrightness();
										break;			
				}
				setBlacklightPropertyUpdate();
				display_pre_dev = display_sel_dev;
		}
		
		if ((backlight_value != backlight_pre_value) || (blightness_value != brightness_pre_value))
		{
				setDisplayOptionUpdate();
				backlight_pre_value = backlight_value;
				brightness_pre_value = blightness_value;
		}
		
		if ((gpio_dir != gpio_pre_dir) || (gpio_level != gpio_pre_level))
		{		
				setGPIOOptionUpdate();
				gpio_pre_dir = gpio_dir;
				gpio_pre_level = gpio_level;
		}

		if (subscription == TRUE)
			setTemperatureFieldUpdate();
				
    return signalsToSend;
}

////////////////////////////////////////////////////////////////

void setGPIO6HighEvent() {
    eventsToSend |= 1 << 0;
}

void setGPIO6LowEvent() {
    eventsToSend |= 1 << 1;
}

void setGPIO7HighEvent() {
    eventsToSend |= 1 << 2;
}

void setGPIO7LowEvent() {
    eventsToSend |= 1 << 3;
}

uint8_t checkForEventsToSend()
{
    eventsToSend = 0;

    if (display_sel_dev == 2 && backlight_value == 1 && backlight_flag == 0) {
				setGPIO6HighEvent();
				backlight_flag = 1;
    }
    else if (display_sel_dev == 2 && backlight_value == 0 && backlight_flag == 1) {
				setGPIO6LowEvent();
				backlight_flag = 0;
    }
    
    if((blightness_value <= 4) && brightness_flag == 0)
  	{
	  		setGPIO7HighEvent();
	  		brightness_flag = 1;
  	}
  	else if ((blightness_value > 4) && brightness_flag == 1)
  	{
	  		setGPIO7LowEvent();
	  		brightness_flag = 0;
  	}
    
    return eventsToSend;
}

const char* getNotificationString()
{
    sendANotification = 0;
    return notificationString;
}

const char* getNotificationActionObjPath()
{
    const char* retObjPath = notificationActionObjPath;
    notificationActionObjPath = NULL;
    return retObjPath;
}

uint16_t isThereANotificationToSend()
{
    return sendANotification;
}