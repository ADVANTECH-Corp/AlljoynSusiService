#define AJ_MODULE AJSVCAPP
#include <aj_debug.h>
#include <alljoyn.h>
#include "ControlPanelProvided.h"

#include "SusiMethods.h"

#ifndef NDEBUG
extern AJ_EXPORT uint8_t dbgAJSVCAPP;
#endif

AJ_Status AJSUSI_I2CGetCaps_Handler(AJ_Message* msg)
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
    if (AJ_SusiI2CGetCaps(id, itemId, &value)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret=0x%x\n", __func__, value));
    AJ_InitArg(&replyArg, AJ_ARG_UINT32, 0, &value, 0);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_I2CWriteReadCombine_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    AJ_Arg replyArg;
    uint32_t id, addr, writelen, readlen;
    uint8_t i, rbuffer[I2C_MAXIMUM_BUFFER_LENGTH];
    uint8_t *wbuffer;
    size_t size;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uuayuu", &id, &addr, (const void**)&wbuffer, &size, &writelen, &readlen);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, addr=0x%x, writelen=%d, readlen=%d\n", __func__, id, addr, writelen, readlen));
    AJ_InfoPrintf(("%s : size=%d, wbuffer= ", __func__, size));
    for (i=0 ; i < writelen ; i++)
    {
        if (i < writelen - 1)
            printf("0x%02X ", wbuffer[i]);
        else
            printf("0x%02X\n", wbuffer[i]);
    }

    //SUSI API
    if (AJ_SusiI2CWriteReadCombine(id, addr, wbuffer, writelen, rbuffer, readlen)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret= ", __func__));
    for (i=0 ; i < readlen ; i++)
    {
        if (i < readlen - 1)
            printf("0x%02X ", rbuffer[i]);
        else
            printf("0x%02X\n", rbuffer[i]);
    }
    AJ_InitArg(&replyArg, AJ_ARG_BYTE, AJ_ARRAY_FLAG, rbuffer, readlen);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_I2CReadTransfer_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    AJ_Arg replyArg;
    uint32_t id, addr, cmd, readlen;
    uint8_t i, buffer[I2C_MAXIMUM_BUFFER_LENGTH];

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uuuu", &id, &addr, &cmd, &readlen);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, addr=0x%x, cmd=0x%x, readlen=%d\n", __func__, id, addr, cmd, readlen));

    //SUSI API
    if (AJ_SusiI2CReadTransfer(id, addr, cmd, buffer, readlen)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret= ", __func__));
    for (i=0 ; i < readlen ; i++)
    {
        if (i < readlen - 1)
            printf("0x%02X ", buffer[i]);
        else
            printf("0x%02X\n", buffer[i]);
    }
    AJ_InitArg(&replyArg, AJ_ARG_BYTE, AJ_ARRAY_FLAG, buffer, readlen);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_I2CWriteTransfer_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    uint32_t id, addr, cmd, bytecnt;
    uint8_t i, *buffer;
    size_t size;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uuuayu", &id, &addr, &cmd, (const void**)&buffer, &size, &bytecnt);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, addr=0x%x, cmd=0x%x, bytecnt=%d\n", __func__, id, addr, cmd, bytecnt));
    AJ_InfoPrintf(("%s : size=%d, buffer= ", __func__, size));
    for (i=0 ; i < bytecnt ; i++)
    {
        if (i < bytecnt - 1)
            printf("0x%02X ", buffer[i]);
        else
            printf("0x%02X\n", buffer[i]);
    }

    //SUSI API
    if (AJ_SusiI2CWriteTransfer(id, addr, cmd, buffer, bytecnt)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    return SendReplyMsg(msg, NULL);
}

AJ_Status AJSUSI_I2CProbeDevice_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    uint32_t id, addr;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "uu", &id, &addr);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s : id=%d, addr=%d\n", __func__, id, addr));

    //SUSI API
    if (AJ_SusiI2CProbeDevice(id, addr)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    return SendReplyMsg(msg, NULL);
}

AJ_Status AJSUSI_I2CGetFrequency_Handler(AJ_Message* msg)
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
    if (AJ_SusiI2CGetFrequency(id, &frequency)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret=0x%x\n", __func__, frequency));
    AJ_InitArg(&replyArg, AJ_ARG_UINT32, 0, &frequency, 0);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_I2CSetFrequency_Handler(AJ_Message* msg)
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
    if (AJ_SusiI2CSetFrequency(id, frequency)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    return SendReplyMsg(msg, NULL);
}

