#define AJ_MODULE AJSVCAPP
#include <aj_debug.h>
#include <alljoyn.h>
#include "ControlPanelProvided.h"

#include "SusiMethods.h"

#ifndef NDEBUG
extern AJ_EXPORT uint8_t dbgAJSVCAPP;
#endif

AJ_Status AJSUSI_VgaGetCaps_Handler(AJ_Message* msg)
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
    if (AJ_SusiVgaGetCaps(id, itemId, &value)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret=0x%x\n", __func__, value));
    AJ_InitArg(&replyArg, AJ_ARG_UINT32, 0, &value, 0);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_VgaGetBacklightEnable_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    AJ_Arg replyArg;
    uint32_t id, enable;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "u", &id);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d\n", __func__, id));

    //SUSI API
    if (AJ_SusiVgaGetBacklightEnable(id, &enable)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret=0x%x\n", __func__, enable));
    AJ_InitArg(&replyArg, AJ_ARG_UINT32, 0, &enable, 0);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_VgaSetBacklightEnable_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    uint32_t id, enable;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uu", &id, &enable);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, enable=%d\n", __func__, id, enable));

    //SUSI API
    if (AJ_SusiVgaSetBacklightEnable(id, enable)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    return SendReplyMsg(msg, NULL);
}

AJ_Status AJSUSI_VgaGetBacklightBrightness_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    AJ_Arg replyArg;
    uint32_t id, bright;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "u", &id);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d\n", __func__, id));

    //SUSI API
    if (AJ_SusiVgaGetBacklightBrightness(id, &bright)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret=0x%x\n", __func__, bright));
    AJ_InitArg(&replyArg, AJ_ARG_UINT32, 0, &bright, 0);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_VgaSetBacklightBrightness_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    uint32_t id, bright;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uu", &id, &bright);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, bright=%d\n", __func__, id, bright));

    //SUSI API
    if (AJ_SusiVgaSetBacklightBrightness(id, bright)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    return SendReplyMsg(msg, NULL);
}

AJ_Status AJSUSI_VgaGetBacklightLevel_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    AJ_Arg replyArg;
    uint32_t id, level;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "u", &id);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d\n", __func__, id));

    //SUSI API
    if (AJ_SusiVgaGetBacklightLevel(id, &level)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret=0x%x\n", __func__, level));
    AJ_InitArg(&replyArg, AJ_ARG_UINT32, 0, &level, 0);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_VgaSetBacklightLevel_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    uint32_t id, level;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uu", &id, &level);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, level=%d\n", __func__, id, level));

    //SUSI API
    if (AJ_SusiVgaSetBacklightLevel(id, level)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    return SendReplyMsg(msg, NULL);
}

AJ_Status AJSUSI_VgaGetPolarity_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    AJ_Arg replyArg;
    uint32_t id, polarity;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "u", &id);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d\n", __func__, id));

    //SUSI API
    if (AJ_SusiVgaGetPolarity(id, &polarity)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret=0x%x\n", __func__, polarity));
    AJ_InitArg(&replyArg, AJ_ARG_UINT32, 0, &polarity, 0);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_VgaSetPolarity_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    uint32_t id, polarity;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uu", &id, &polarity);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, polarity=%d\n", __func__, id, polarity));

    //SUSI API
    if (AJ_SusiVgaSetPolarity(id, polarity)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    return SendReplyMsg(msg, NULL);
}

AJ_Status AJSUSI_VgaGetFrequency_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    AJ_Arg replyArg;
    uint32_t id, frequency;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "u", &id);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d\n", __func__, id));

    //SUSI API
    if (AJ_SusiVgaGetFrequency(id, &frequency)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret=0x%x\n", __func__, frequency));
    AJ_InitArg(&replyArg, AJ_ARG_UINT32, 0, &frequency, 0);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_VgaSetFrequency_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    uint32_t id, frequency;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uu", &id, &frequency);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, frequency=%d\n", __func__, id, frequency));

    //SUSI API
    if (AJ_SusiVgaSetFrequency(id, frequency)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    return SendReplyMsg(msg, NULL);
}

