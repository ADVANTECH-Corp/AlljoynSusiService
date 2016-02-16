#define AJ_MODULE AJSVCAPP
#include <aj_debug.h>
#include <alljoyn.h>
#include "ControlPanelProvided.h"

#include "SusiMethods.h"

#ifndef NDEBUG
extern AJ_EXPORT uint8_t dbgAJSVCAPP;
#endif

AJ_Status AJSUSI_GPIOGetCaps_Handler(AJ_Message* msg)
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
    if (AJ_SusiGPIOGetCaps(id, itemId, &value)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret=0x%x\n", __func__, value));
    AJ_InitArg(&replyArg, AJ_ARG_UINT32, 0, &value, 0);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_GPIOGetDirection_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    AJ_Arg replyArg;
    uint32_t id, bitmask, direction;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uu", &id, &bitmask);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, bitmask=0x%x\n", __func__, id, bitmask));

    //SUSI API
    if (AJ_SusiGPIOGetDirection(id, bitmask, &direction)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret=0x%x\n", __func__, direction));
    AJ_InitArg(&replyArg, AJ_ARG_UINT32, 0, &direction, 0);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_GPIOSetDirection_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    uint32_t id, bitmask, direction;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uuu", &id, &bitmask, &direction);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, bitmask=0x%x, direction=%d\n", __func__, id, bitmask, direction));

    //SUSI API
    if (AJ_SusiGPIOSetDirection(id, bitmask, direction)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    return SendReplyMsg(msg, NULL);
}

AJ_Status AJSUSI_GPIOGetLevel_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    AJ_Arg replyArg;
    uint32_t id, bitmask, level;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uu", &id, &bitmask);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, bitmask=0x%x\n", __func__, id, bitmask));

    //SUSI API
    if (AJ_SusiGPIOGetLevel(id, bitmask, &level)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret=0x%x\n", __func__, level));
    AJ_InitArg(&replyArg, AJ_ARG_UINT32, 0, &level, 0);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_GPIOSetLevel_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    uint32_t id, bitmask, level;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uuu", &id, &bitmask, &level);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, bitmask=0x%x, level=%d\n", __func__, id, bitmask, level));

    //SUSI API
    if (AJ_SusiGPIOSetLevel(id, bitmask, level)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    return SendReplyMsg(msg, NULL);
}

