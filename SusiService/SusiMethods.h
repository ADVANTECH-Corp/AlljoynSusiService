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

#ifndef SUSIMETHODS_H_
#define SUSIMETHODS_H_

#include <alljoyn.h>

AJ_Status SusiMethods_Init();

void SusiMethods_DoWork(AJ_BusAttachment* busAttachment);

AJ_Status SusiMethods_Finish(AJ_BusAttachment* busAttachment);

AJSVC_ServiceStatus SusiMethodsMessageProcessor(AJ_BusAttachment* busAttachment, AJ_Message* msg, AJ_Status* msgStatus);

AJ_Status SendReplyMsg(AJ_Message* msg, AJ_Arg* replyArg);

///////////////////////////////////////////////
#define SUSIMETHODS_VERSION "4.0.0"
#define NAME_MAXIMUM_LENGTH 32
#define I2C_MAXIMUM_BUFFER_LENGTH 0x100

AJ_Status AJSUSI_BoardGetValue_Handler(AJ_Message* msg);
AJ_Status AJSUSI_BoardGetStringA_Handler(AJ_Message* msg);
AJ_Status AJSUSI_VgaGetCaps_Handler(AJ_Message* msg);
AJ_Status AJSUSI_VgaGetBacklightEnable_Handler(AJ_Message* msg);
AJ_Status AJSUSI_VgaSetBacklightEnable_Handler(AJ_Message* msg);
AJ_Status AJSUSI_VgaGetBacklightBrightness_Handler(AJ_Message* msg);
AJ_Status AJSUSI_VgaSetBacklightBrightness_Handler(AJ_Message* msg);
AJ_Status AJSUSI_VgaGetBacklightLevel_Handler(AJ_Message* msg);
AJ_Status AJSUSI_VgaSetBacklightLevel_Handler(AJ_Message* msg);
AJ_Status AJSUSI_VgaGetPolarity_Handler(AJ_Message* msg);
AJ_Status AJSUSI_VgaSetPolarity_Handler(AJ_Message* msg);
AJ_Status AJSUSI_VgaGetFrequency_Handler(AJ_Message* msg);
AJ_Status AJSUSI_VgaSetFrequency_Handler(AJ_Message* msg);
AJ_Status AJSUSI_I2CGetCaps_Handler(AJ_Message* msg);
AJ_Status AJSUSI_I2CWriteReadCombine_Handler(AJ_Message* msg);
AJ_Status AJSUSI_I2CReadTransfer_Handler(AJ_Message* msg);
AJ_Status AJSUSI_I2CWriteTransfer_Handler(AJ_Message* msg);
AJ_Status AJSUSI_I2CProbeDevice_Handler(AJ_Message* msg);
AJ_Status AJSUSI_I2CGetFrequency_Handler(AJ_Message* msg);
AJ_Status AJSUSI_I2CSetFrequency_Handler(AJ_Message* msg);
AJ_Status AJSUSI_WDogGetCaps_Handler(AJ_Message* msg);
AJ_Status AJSUSI_WDogStart_Handler(AJ_Message* msg);
AJ_Status AJSUSI_WDogStop_Handler(AJ_Message* msg);
AJ_Status AJSUSI_WDogTrigger_Handler(AJ_Message* msg);
AJ_Status AJSUSI_GPIOGetCaps_Handler(AJ_Message* msg);
AJ_Status AJSUSI_GPIOGetDirection_Handler(AJ_Message* msg);
AJ_Status AJSUSI_GPIOSetDirection_Handler(AJ_Message* msg);
AJ_Status AJSUSI_GPIOGetLevel_Handler(AJ_Message* msg);
AJ_Status AJSUSI_GPIOSetLevel_Handler(AJ_Message* msg);

#endif /* SUSIMETHODS_H_ */
