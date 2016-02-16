#define AJ_MODULE AJSVCAPP
#include <aj_debug.h>
#include <alljoyn.h>
#include "ControlPanelProvided.h"

#include "SusiMethods.h"

#ifndef NDEBUG
extern AJ_EXPORT uint8_t dbgAJSVCAPP;
#endif

AJ_Status AJSUSI_BoardGetValue_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    AJ_Arg replyArg;
    uint32_t id, value;

    //Get Args
    status = AJ_UnmarshalArgs(msg, "u", &id);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s: id=%d\n", __func__, id));

    //SUSI API
    if (AJ_SusiBoardGetValue(id, &value)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret=0x%x\n", __func__, value));
    AJ_InitArg(&replyArg, AJ_ARG_UINT32, 0, &value, 0);
    return SendReplyMsg(msg, &replyArg);
}

AJ_Status AJSUSI_BoardGetStringA_Handler(AJ_Message* msg)
{
    AJ_Status status = AJ_OK;
    AJ_Message reply;
    AJ_Arg replyArg;
    uint32_t id, buflen = NAME_MAXIMUM_LENGTH;
    char buffer[NAME_MAXIMUM_LENGTH];

    //Get Args
    status = AJ_UnmarshalArgs(msg, "u", &id);
    if (status != AJ_OK) {
        return status;
    }
    AJ_InfoPrintf(("%s: id=%d\n", __func__, id));

    //SUSI API
    if (AJ_SusiBoardGetStringA(id, (char*)&buffer, &buflen)) {
        AJ_MarshalErrorMsg(msg, &reply, AJ_ErrFeatureNotAvailable);
        return AJ_DeliverMsg(&reply);
    }

    //Status Reply
    AJ_InfoPrintf(("%s : ret=%s\n", __func__, buffer));
    AJ_InitArg(&replyArg, AJ_ARG_STRING, 0, buffer, 0);
    return SendReplyMsg(msg, &replyArg);
}
