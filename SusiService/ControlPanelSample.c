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

#include <alljoyn/controlpanel/ControlPanelService.h>
#include "ControlPanelProvided.h"
#include "ControlPanelGenerated.h"
#include "ControlPanelSample.h"
#include <aj_link_timeout.h>
#include <alljoyn/services_common/PropertyStore.h>

#ifndef NDEBUG
extern AJ_EXPORT uint8_t dbgAJSVCAPP;
#endif

static AJ_Object AJCPS_ObjectList[] = {
    AJCPS_CONTROLLEE_GENERATED_OBJECTS
    { NULL }
};

void init_hw()
{
	find_display_num();
	find_gpio_num();
}

AJ_Status Controlee_Init()
{
    AJ_Status status = AJCPS_Start(AJCPS_ObjectList, &GeneratedMessageProcessor, &IdentifyMsgOrPropId, &IdentifyMsgOrPropIdForSignal, &IdentifyRootMsgOrPropId);
    WidgetsInit();
    init_hw();    
    return status;
}

void Controlee_DoWork(AJ_BusAttachment* busAttachment)
{
    uint8_t sendUpdates = checkForUpdatesToSend();
    if (sendUpdates > 0) {

        if ((sendUpdates & (1 << 0)) != 0) {
            //AJ_AlwaysPrintf(("##### Sending update signal: temperature string field \n"));
            AJCPS_SendPropertyChangedSignal(busAttachment, EN_SUSIACCESS_TEMPERATUREPROPERTY_SIGNAL_VALUE_CHANGED, AJCPS_GetCurrentSessionId());
        }
        
        if ((sendUpdates & (1 << 1)) != 0) {
            //AJ_AlwaysPrintf(("##### Sending update signal: blacklight field \n"));
            AJCPS_SendPropertyChangedSignal(busAttachment, EN_SUSIACCESS_BACKLIGHTPROPERTY_SIGNAL_VALUE_CHANGED, AJCPS_GetCurrentSessionId());
            //AJ_AlwaysPrintf(("##### Sending update signal: blightness field \n"));
            AJCPS_SendPropertyChangedSignal(busAttachment, EN_SUSIACCESS_BRIGHTNESSPROPERTY_SIGNAL_VALUE_CHANGED, AJCPS_GetCurrentSessionId());
            //AJ_AlwaysPrintf(("##### Sending update signal: display device field \n"));
            AJCPS_SendPropertyChangedSignal(busAttachment, EN_SUSIACCESS_DISPLAYDEVICEPROPERTY_SIGNAL_VALUE_CHANGED, AJCPS_GetCurrentSessionId());
        }
        
        if ((sendUpdates & (1 << 2)) != 0) {     
        		//AJ_AlwaysPrintf(("##### Sending update signal: blacklight status \n")); 
            AJCPS_SendPropertyChangedSignal(busAttachment, EN_SUSIACCESS_BRIGHTNESSPROPERTY_SIGNAL_PROPERTIES_CHANGED, AJCPS_GetCurrentSessionId());
        }
        
        if ((sendUpdates & (1 << 3)) != 0) {
            //AJ_AlwaysPrintf(("##### Sending update signal: GPIO Dir field \n"));
            AJCPS_SendPropertyChangedSignal(busAttachment, EN_SUSIACCESS_GPIODIRPROPERTY_SIGNAL_VALUE_CHANGED, AJCPS_GetCurrentSessionId());
            //AJ_AlwaysPrintf(("##### Sending update signal: GPIO Level field \n"));
            AJCPS_SendPropertyChangedSignal(busAttachment, EN_SUSIACCESS_GPIOLEVELPROPERTY_SIGNAL_VALUE_CHANGED, AJCPS_GetCurrentSessionId());
            //AJ_AlwaysPrintf(("##### Sending update signal: GPIO Level status \n"));
            AJCPS_SendPropertyChangedSignal(busAttachment, EN_SUSIACCESS_GPIOLEVELPROPERTY_SIGNAL_PROPERTIES_CHANGED, AJCPS_GetCurrentSessionId());
        } 
    }
    return;
}

AJ_Status Controlee_Finish(AJ_BusAttachment* busAttachment)
{
    return AJ_OK;
}
