#include "Avm/AvmStubImpl.h"

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {




CAvmStubImpl::CAvmStubImpl() 
	:CAvmBase()
{
    ALOGI("CAvmStubImpl");
}

CAvmStubImpl::~CAvmStubImpl()
{

}

a_status  CAvmStubImpl::initialize()
{
//    ALOGD("CAvmStubImpl::initialize\n");
	ALOGI("CAvmStubImpl::initialize\n");
	registerFunc((UInt32)eAvm_SWITCH, makeFunctor(this, &CAvmStubImpl::SwitchAVM));
    return a_status(0); 
}

VOID  CAvmStubImpl::afterHandleMessageQueue()
{

}

VOID  CAvmStubImpl::SwitchAVM(const string& pData)
{
    ALOGI("SwitchAVM [%s]\n", pData.c_str());

}



}
}
}
}