#include "Apa/ApaStubImpl.h"
#include "Apa/ApaMsgQDefine.h"
#include "ApaServiceStubImplGWM.h"
#include "v1/com/harman/adas/APABaseType.hpp"

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

ApaStubImpl::ApaStubImpl()
    : AApaBase()
{

}

ApaStubImpl::~ApaStubImpl()
{

}

a_status  ApaStubImpl::initialize()
{
	printf(" [%s, %d]  initialize = apa\n", __FUNCTION__, __LINE__);
    ALOGD("APA initialize\n");
    //registerFunc((UInt32)eCameraActivate_ON, makeFunctor(this, &APAStubImpl::showCamera));
    registerFunc((UInt32)eAPA_ACTIVE, makeFunctor(this, &ApaStubImpl::activeAPA));
    registerFunc((UInt32)eAPA_DEACTIVE, makeFunctor(this, &ApaStubImpl::deactiveAPA));
    return a_status(0);
}

VOID  ApaStubImpl::afterHandleMessageQueue()
{

}

VOID  ApaStubImpl::activeAPA(const string& pData)
{
    ALOGD("activeAPA [%s]\n", pData.c_str());
	ApaServiceStubImplGWM::getInstance()->setAPAStatusAttribute(::v1::com::harman::adas::APABaseType::enAPAStatus::e_APA_ACTIVE);
}

VOID  ApaStubImpl::deactiveAPA(const string& pData)
{
    ALOGD("deactiveAPA [%s]\n", pData.c_str());
	ApaServiceStubImplGWM::getInstance()->setAPAStatusAttribute(::v1::com::harman::adas::APABaseType::enAPAStatus::e_APA_DEACTIVE);
}
}
}
}
}
