#define AJ_MODULE AJSVCAPP
#include <aj_debug.h>
#include <alljoyn.h>
#include "ControlPanelProvided.h"

#include "SusiMethods.h"

#ifndef NDEBUG
extern AJ_EXPORT uint8_t dbgAJSVCAPP;
#endif

AJ_Status AJSUSI_WDogGetCaps_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    AJ_Arg replyArg;
    uint32_t id, itemId, value;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uu", &id, &itemId);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, item=%d\n", __func__, id, itemId));

    //SUSI API
    if (AJ_SusiWDogGetCaps(id, itemId, &value)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret=0x%x\n", __func__, value));
    AJ_InitArg(&replyArg, AJ_ARG_UINT32, 0, &value, 0);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_WDogStart_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    uint32_t id, delaytime, eventtime, resettime, eventtype;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uuuuu", &id, &delaytime, &eventtime, &resettime, &eventtype);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, delaytime=%d, eventtime=%d, resettime=%d, eventtype=%d\n",
                   __func__, id, delaytime, eventtime, resettime, eventtype));

    //SUSI API
    if (AJ_SusiWDogStart(id, delaytime, eventtime, resettime, eventtype)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    return SendReplyMsg(msg, NULL);
}

AJ_Status AJSUSI_WDogStop_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    uint32_t id;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "u", &id);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d\n", __func__, id));

    //SUSI API
    if (AJ_SusiWDogStop(id)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    return SendReplyMsg(msg, NULL);
}

AJ_Status AJSUSI_WDogTrigger_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    uint32_t id;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "u", &id);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d\n", __func__, id));

    //SUSI API
    if (AJ_SusiWDogTrigger(id)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    return SendReplyMsg(msg, NULL);
}

