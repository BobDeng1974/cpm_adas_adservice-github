#include "Apa/ApaStubImpl.h"
#include "Apa/ApaMsgQDefine.h"

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

ApaStubImpl::ApaStubImpl()
    :AApaBase()
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
    return a_status(0); 
}

VOID  ApaStubImpl::afterHandleMessageQueue()
{

}

/*VOID  APAStubImpl::showAPA(const string& pData)
{
    ALOGD("showAPA [%s]\n", pData.c_str());
}*/

}
}
}
}
