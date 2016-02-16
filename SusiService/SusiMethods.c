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

#include <alljoyn.h>
#include <alljoyn/services_common/ServicesCommon.h>
#include "ControlPanelProvided.h"
#include <aj_link_timeout.h>
#include <alljoyn/services_common/PropertyStore.h>
#include "PropertyStoreOEMProvisioning.h"

#include "SusiMethods.h"
#include "Susi4.h"

#ifndef NDEBUG
extern AJ_EXPORT uint8_t dbgAJSVCAPP;
#endif

/**
 * Published SUSI methods Interfaces
 */
static const char MethodsInterfaceName[] = "org.alljoyn.SusiService.Methods";

static const char* MethodsInterface[] =
{
    MethodsInterfaceName,         /* The first entry is the interface name. */
    "@Version>s",                 /* The Version Property */
    /* SUSI Board */
    "?SusiBoardGetValue Id<u Value>u",
    "?SusiBoardGetStringA Id<u Buffer>s",
    /* SUSI VGA */
    "?SusiVgaGetCaps Id<u ItemId<u Value>u",
    "?SusiVgaGetBacklightEnable Id<u Enable>u",
    "?SusiVgaSetBacklightEnable Id<u Enable<u",
    "?SusiVgaGetBacklightBrightness Id<u Bright>u",
    "?SusiVgaSetBacklightBrightness Id<u Bright<u",
    "?SusiVgaGetBacklightLevel Id<u Level>u",
    "?SusiVgaSetBacklightLevel Id<u Level<u",
    "?SusiVgaGetPolarity Id<u Polarity>u",
    "?SusiVgaSetPolarity Id<u Polarity<u",
    "?SusiVgaGetFrequency Id<u Frequency>u",
    "?SusiVgaSetFrequency Id<u Frequency<u",
    /* SUSI I2C */
    "?SusiI2CGetCaps Id<u ItemId<u Value>u",
    "?SusiI2CWriteReadCombine Id<u Addr<u WBuffer<ay WriteLen<u ReadLen<u Buffer>ay",
    "?SusiI2CReadTransfer Id<u Addr<u Cmd<u ReadLen<u Buffer>ay",
    "?SusiI2CWriteTransfer Id<u Addr<u Cmd<u Buffer<ay ByteCnt<u",
    "?SusiI2CProbeDevice Id<u Addr<u",
    "?SusiI2CGetFrequency Id<u Frequency>u",
    "?SusiI2CSetFrequency Id<u Frequency<u",
    /* SUSI Watchdog */
    "?SusiWDogGetCaps Id<u ItemId<u Value>u",
    "?SusiWDogStart Id<u DelayTime<u EventTime<u ResetTime<u EventType<u",
    "?SusiWDogStop Id<u",
    "?SusiWDogTrigger Id<u",
    //"?SusiWDogSetCallBack", 		/* Not support */
    /* SUSI GPIO */
    "?SusiGPIOGetCaps Id<u ItemId<u Value>u",
    "?SusiGPIOGetDirection Id<u Bitmask<u Direction>u",
    "?SusiGPIOSetDirection Id<u Bitmask<u Direction<u",
    "?SusiGPIOGetLevel Id<u Bitmask<u Level>u",
    "?SusiGPIOSetLevel Id<u Bitmask<u Level<u",
    /* SUSI Info */
    NULL
};

static const AJ_InterfaceDescription MethodsInterfaces[] =
{
    AJ_PropertiesIface,
    MethodsInterface,
    NULL
};

/*
 * Message identifiers for the method calls this service implements
 */

#define METHODS_OBJECT_INDEX                           0

#define METHODS_GET_PROP                               AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 0, AJ_PROP_GET)
#define METHODS_SET_PROP                               AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 0, AJ_PROP_SET)

#define METHODS_VERSION_PROP                           AJ_APP_PROPERTY_ID(METHODS_OBJECT_INDEX, 1, 0)
#define METHODS_SUSI_BOARD_GETVALUE                    AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, 1)
#define METHODS_SUSI_BOARD_GETSTRINGA                  AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, 2)
#define METHODS_SUSI_VGA_BASE 3
#define METHODS_SUSI_VGA_GETCAPS                       AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_VGA_BASE)
#define METHODS_SUSI_VGA_GETBACKLIGHTENABLE            AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_VGA_BASE + 1)
#define METHODS_SUSI_VGA_SETBACKLIGHTENABLE            AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_VGA_BASE + 2)
#define METHODS_SUSI_VGA_GETBACKLIGHTBRIGHTNESS        AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_VGA_BASE + 3)
#define METHODS_SUSI_VGA_SETBACKLIGHTBRIGHTNESS        AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_VGA_BASE + 4)
#define METHODS_SUSI_VGA_GETBACKLIGHTLEVEL             AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_VGA_BASE + 5)
#define METHODS_SUSI_VGA_SETBACKLIGHTLEVEL             AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_VGA_BASE + 6)
#define METHODS_SUSI_VGA_GETPOLARITY                   AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_VGA_BASE + 7)
#define METHODS_SUSI_VGA_SETPOLARITY                   AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_VGA_BASE + 8)
#define METHODS_SUSI_VGA_GETFREQUENCY                  AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_VGA_BASE + 9)
#define METHODS_SUSI_VGA_SETFREQUENCY                  AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_VGA_BASE +10)
#define METHODS_SUSI_I2C_BASE 14
#define METHODS_SUSI_I2C_GETCAPS                       AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_I2C_BASE)
#define METHODS_SUSI_I2C_WRITEREADCOMBINE              AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_I2C_BASE + 1)
#define METHODS_SUSI_I2C_READTRANSFER                  AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_I2C_BASE + 2)
#define METHODS_SUSI_I2C_WRITETRANSFER                 AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_I2C_BASE + 3)
#define METHODS_SUSI_I2C_PROBEDEVICE                   AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_I2C_BASE + 4)
#define METHODS_SUSI_I2C_GETFREQUENCY                  AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_I2C_BASE + 5)
#define METHODS_SUSI_I2C_SETFREQUENCY                  AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_I2C_BASE + 6)
#define METHODS_SUSI_WDOG_BASE 21
#define METHODS_SUSI_WDOG_GETCAPS                      AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_WDOG_BASE)
#define METHODS_SUSI_WDOG_START                        AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_WDOG_BASE + 1)
#define METHODS_SUSI_WDOG_STOP                         AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_WDOG_BASE + 2)
#define METHODS_SUSI_WDOG_TRIGGER                      AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_WDOG_BASE + 3)
#define METHODS_SUSI_GPIO_BASE 25
#define METHODS_SUSI_GPIO_GETCAPS                      AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_GPIO_BASE)
#define METHODS_SUSI_GPIO_GETDIRECTION                 AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_GPIO_BASE + 1)
#define METHODS_SUSI_GPIO_SETDIRECTION                 AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_GPIO_BASE + 2)
#define METHODS_SUSI_GPIO_GETLEVEL                     AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_GPIO_BASE + 3)
#define METHODS_SUSI_GPIO_SETLEVEL                     AJ_APP_MESSAGE_ID(METHODS_OBJECT_INDEX, 1, METHODS_SUSI_GPIO_BASE + 4)

AJ_Object MethodsObjectList[] = {
    { "/SusiMethods", MethodsInterfaces, AJ_OBJ_FLAG_ANNOUNCED, NULL },
    { NULL }
};

AJ_Status SusiMethods_Init()
{
    AJ_Status status = AJ_OK;
    SusiStatus_t SusiStatus;

    AJ_PrintXML(MethodsObjectList);
    AJ_RegisterObjects(MethodsObjectList, NULL);

    //Initialize SUSI
    SusiStatus = SusiLibInitialize();
    if (SusiStatus == SUSI_STATUS_ERROR)
    {
        AJ_ErrPrintf(("You must be root!\nAborting.\n"));
        return AJ_ERR_DISALLOWED;
    }
    if (SusiStatus != SUSI_STATUS_SUCCESS && SusiStatus != SUSI_STATUS_INITIALIZED)
    {
        AJ_ErrPrintf(("SusiLibInitialize() failed. (0x%08X)\n", SusiStatus));
        return AJ_ERR_FAILURE;
    }

    return status;
}

static AJ_Status SusiMethodsPropGetHandler(AJ_Message* replyMsg, uint32_t propId, void* context)
{
    if (propId == METHODS_VERSION_PROP)
        return AJ_MarshalArgs(replyMsg, "s", SUSIMETHODS_VERSION);
    else
        return AJ_ERR_UNEXPECTED;
}

static AJ_Status SusiMethodsPropSetHandler(AJ_Message* replyMsg, uint32_t propId, void* context)
{
    return AJ_ERR_UNEXPECTED;
}

AJSVC_ServiceStatus SusiMethodsMessageProcessor(AJ_BusAttachment* busAttachment, AJ_Message* msg, AJ_Status* msgStatus)
{
    AJSVC_ServiceStatus serviceStatus = AJSVC_SERVICE_STATUS_HANDLED;

    switch (msg->msgId) {
    case METHODS_GET_PROP:
        *msgStatus = AJ_BusPropGet(msg, SusiMethodsPropGetHandler, NULL);
        break;

    case METHODS_SET_PROP:
        *msgStatus = AJ_BusPropSet(msg, SusiMethodsPropSetHandler, NULL);
        break;
    /* SUSI Board */
    case METHODS_SUSI_BOARD_GETVALUE:
        *msgStatus = AJSUSI_BoardGetValue_Handler(msg);
        break;

    case METHODS_SUSI_BOARD_GETSTRINGA:
        *msgStatus = AJSUSI_BoardGetStringA_Handler(msg);
        break;
    /* SUSI VGA */
    case METHODS_SUSI_VGA_GETCAPS:
        *msgStatus = AJSUSI_VgaGetCaps_Handler(msg);
        break;

    case METHODS_SUSI_VGA_GETBACKLIGHTENABLE:
        *msgStatus = AJSUSI_VgaGetBacklightEnable_Handler(msg);
        break;

    case METHODS_SUSI_VGA_SETBACKLIGHTENABLE:
        *msgStatus = AJSUSI_VgaSetBacklightEnable_Handler(msg);
        break;

    case METHODS_SUSI_VGA_GETBACKLIGHTBRIGHTNESS:
        *msgStatus = AJSUSI_VgaGetBacklightBrightness_Handler(msg);
        break;

    case METHODS_SUSI_VGA_SETBACKLIGHTBRIGHTNESS:
        *msgStatus = AJSUSI_VgaSetBacklightBrightness_Handler(msg);
        break;

    case METHODS_SUSI_VGA_GETBACKLIGHTLEVEL:
        *msgStatus = AJSUSI_VgaGetBacklightLevel_Handler(msg);
        break;

    case METHODS_SUSI_VGA_SETBACKLIGHTLEVEL:
        *msgStatus = AJSUSI_VgaSetBacklightLevel_Handler(msg);
        break;

    case METHODS_SUSI_VGA_GETPOLARITY:
        *msgStatus = AJSUSI_VgaGetPolarity_Handler(msg);
        break;

    case METHODS_SUSI_VGA_SETPOLARITY:
        *msgStatus = AJSUSI_VgaSetPolarity_Handler(msg);
        break;

    case METHODS_SUSI_VGA_GETFREQUENCY:
        *msgStatus = AJSUSI_VgaGetFrequency_Handler(msg);
        break;

    case METHODS_SUSI_VGA_SETFREQUENCY:
        *msgStatus = AJSUSI_VgaSetFrequency_Handler(msg);
        break;
    /* SUSI I2C */
    case METHODS_SUSI_I2C_GETCAPS:
        *msgStatus = AJSUSI_I2CGetCaps_Handler(msg);
        break;

    case METHODS_SUSI_I2C_WRITEREADCOMBINE:
        *msgStatus = AJSUSI_I2CWriteReadCombine_Handler(msg);
        break;

    case METHODS_SUSI_I2C_READTRANSFER:
        *msgStatus = AJSUSI_I2CReadTransfer_Handler(msg);
        break;

    case METHODS_SUSI_I2C_WRITETRANSFER:
        *msgStatus = AJSUSI_I2CWriteTransfer_Handler(msg);
        break;

    case METHODS_SUSI_I2C_PROBEDEVICE:
        *msgStatus = AJSUSI_I2CProbeDevice_Handler(msg);
        break;

    case METHODS_SUSI_I2C_GETFREQUENCY:
        *msgStatus = AJSUSI_I2CGetFrequency_Handler(msg);
        break;

    case METHODS_SUSI_I2C_SETFREQUENCY:
        *msgStatus = AJSUSI_I2CSetFrequency_Handler(msg);
        break;
    /* SUSI Watchdog */
    case METHODS_SUSI_WDOG_GETCAPS:
        *msgStatus = AJSUSI_WDogGetCaps_Handler(msg);
        break;

    case METHODS_SUSI_WDOG_START:
        *msgStatus = AJSUSI_WDogStart_Handler(msg);
        break;

    case METHODS_SUSI_WDOG_STOP:
        *msgStatus = AJSUSI_WDogStop_Handler(msg);
        break;

    case METHODS_SUSI_WDOG_TRIGGER:
        *msgStatus = AJSUSI_WDogTrigger_Handler(msg);
        break;
    /* SUSI GPIO */
    case METHODS_SUSI_GPIO_GETCAPS:
        *msgStatus = AJSUSI_GPIOGetCaps_Handler(msg);
        break;

    case METHODS_SUSI_GPIO_GETDIRECTION:
        *msgStatus = AJSUSI_GPIOGetDirection_Handler(msg);
        break;

    case METHODS_SUSI_GPIO_SETDIRECTION:
        *msgStatus = AJSUSI_GPIOSetDirection_Handler(msg);
        break;

    case METHODS_SUSI_GPIO_GETLEVEL:
        *msgStatus = AJSUSI_GPIOGetLevel_Handler(msg);
        break;

    case METHODS_SUSI_GPIO_SETLEVEL:
        *msgStatus = AJSUSI_GPIOSetLevel_Handler(msg);
        break;

    default:
        serviceStatus = AJSVC_SERVICE_STATUS_NOT_HANDLED;
        break;
    }

    return serviceStatus;
}

AJ_Status SendReplyMsg(AJ_Message* msg, AJ_Arg* replyArg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;

    status = AJ_MarshalReplyMsg(msg, &reply);
    if (status != AJ_OK) {
        AJ_ErrPrintf(("AJ_MarshalReplyMsg failed! 0x%x\n", status));
        return status;
    }

    if (replyArg != NULL)
    {
        status = AJ_MarshalArg(&reply, replyArg);
        if (status != AJ_OK) {
            AJ_ErrPrintf(("AJ_MarshalArg failed! 0x%x\n", status));
            return status;
        }
    }

    status = AJ_DeliverMsg(&reply);
    if (status != AJ_OK) {
        AJ_ErrPrintf(("AJ_DeliverMsg failed! 0x%x\n", status));
    }
    return status;
}

void SusiMethods_DoWork(AJ_BusAttachment* busAttachment)
{
    return;
}

AJ_Status SusiMethods_Finish(AJ_BusAttachment* busAttachment)
{
    SusiStatus_t SusiStatus = SusiLibUninitialize();
    if (SusiStatus != SUSI_STATUS_SUCCESS)
    {
        AJ_ErrPrintf(("SusiLibUninitialize() failed. (%8X)\n", SusiStatus));
        return AJ_ERR_FAILURE;
    }
    return AJ_OK;
}
