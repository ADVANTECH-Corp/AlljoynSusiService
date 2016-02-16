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

#ifndef CONTROLPANELPROVIDED_H_
#define CONTROLPANELPROVIDED_H_

#include "alljoyn.h"
#include "alljoyn/controlpanel/Common/DateTimeUtil.h"
#include "ControlPanelGenerated.h"

//////////////////////////////////////////////////////

uint32_t AJ_SusiBoardGetValue(uint32_t Id, uint32_t *pValue);
uint32_t AJ_SusiBoardGetStringA(uint32_t Id, char *pBuffer, uint32_t *pBufLen);

uint32_t AJ_SusiVgaGetCaps(uint32_t Id, uint32_t ItemId, uint32_t *pValue);
uint32_t AJ_SusiVgaGetBacklightEnable(uint32_t Id, uint32_t *pEnable);
uint32_t AJ_SusiVgaSetBacklightEnable(uint32_t Id, uint32_t Enable);
uint32_t AJ_SusiVgaGetBacklightBrightness(uint32_t Id, uint32_t *pBright);
uint32_t AJ_SusiVgaSetBacklightBrightness(uint32_t Id, uint32_t Bright);
uint32_t AJ_SusiVgaGetBacklightLevel(uint32_t Id, uint32_t *pLevel);
uint32_t AJ_SusiVgaSetBacklightLevel(uint32_t Id, uint32_t Level);
uint32_t AJ_SusiVgaGetPolarity(uint32_t Id, uint32_t *pPolarity);
uint32_t AJ_SusiVgaSetPolarity(uint32_t Id, uint32_t Polarity);
uint32_t AJ_SusiVgaGetFrequency(uint32_t Id, uint32_t *pFrequency);
uint32_t AJ_SusiVgaSetFrequency(uint32_t Id, uint32_t Frequency);

uint32_t AJ_SusiI2CGetCaps(uint32_t Id, uint32_t ItemId, uint32_t *pValue);
uint32_t AJ_SusiI2CWriteReadCombine(uint32_t Id, uint8_t Addr, uint8_t *pWBuffer, uint32_t WriteLen, uint8_t *pRBuffer, uint32_t ReadLen);
uint32_t AJ_SusiI2CReadTransfer(uint32_t Id, uint32_t Addr, uint32_t Cmd, uint8_t *pBuffer, uint32_t ReadLen);
uint32_t AJ_SusiI2CWriteTransfer(uint32_t Id, uint32_t Addr, uint32_t Cmd, uint8_t *pBuffer, uint32_t ByteCnt);
uint32_t AJ_SusiI2CProbeDevice(uint32_t Id, uint32_t Addr);
uint32_t AJ_SusiI2CGetFrequency(uint32_t Id, uint32_t *pFreq);
uint32_t AJ_SusiI2CSetFrequency(uint32_t Id, uint32_t Freq);

uint32_t AJ_SusiWDogGetCaps(uint32_t Id, uint32_t ItemId, uint32_t *pValue);
uint32_t AJ_SusiWDogStart(uint32_t Id, uint32_t DelayTime, uint32_t EventTime, uint32_t ResetTime, uint32_t EventType);
uint32_t AJ_SusiWDogStop(uint32_t Id);
uint32_t AJ_SusiWDogTrigger(uint32_t Id);

uint32_t AJ_SusiGPIOGetCaps(uint32_t Id, uint32_t ItemId, uint32_t *pValue);
uint32_t AJ_SusiGPIOGetDirection(uint32_t Id, uint32_t Bitmask, uint32_t *pDirection);
uint32_t AJ_SusiGPIOSetDirection(uint32_t Id, uint32_t Bitmask, uint32_t Direction);
uint32_t AJ_SusiGPIOGetLevel(uint32_t Id, uint32_t Bitmask, uint32_t *pLevel);
uint32_t AJ_SusiGPIOSetLevel(uint32_t Id, uint32_t Bitmask, uint32_t Level);

//////////////////////////////////////////////////////

void* getBoardManufacturerString(PropertyWidget* thisWidget);
void setBoardManufacturerString(char const* newBoardInfo);
void* getBoardNameString(PropertyWidget* thisWidget);
void setBoardNameString(char const* newBoardInfo);
void* getDriverVersionString(PropertyWidget* thisWidget);
void setDriverVersionString(char const* newBoardInfo);
void* getLibraryVersionString(PropertyWidget* thisWidget);
void setLibraryVersionString(char const* newBoardInfo);
void* getCPUTemperatureString(PropertyWidget* thisWidget);
void setCPUTemperatureString(char const* newBoardInfo);
void* getSubscription(PropertyWidget* thisWidget);
void setSubscription(uint32_t newValue);

void* getDisplayDevice(PropertyWidget* thisWidget);
void setDisplayDevice(uint32_t newValue);
void* getBrightnessValue(PropertyWidget* thisWidget);
void setBrightnessValue(uint32_t newValue);
void* getBacklightValue(PropertyWidget* thisWidget);
void setBacklightValue(uint32_t newValue);

void* getGPIOPin(PropertyWidget* thisWidget);
void setGPIOPin(uint32_t newValue);
void* getGPIODirValue(PropertyWidget* thisWidget);
void setGPIODirValue(uint32_t newValue);
void* getGPIOLevelValue(PropertyWidget* thisWidget);
void setGPIOLevelValue(uint32_t newValue);

void find_display_num();
void find_gpio_num();

uint8_t checkForUpdatesToSend();
uint8_t checkForEventsToSend();

const char* getNotificationString();
const char* getNotificationActionObjPath();
uint16_t isThereANotificationToSend();

#endif /* CONTROLPANELPROVIDED_H_ */

