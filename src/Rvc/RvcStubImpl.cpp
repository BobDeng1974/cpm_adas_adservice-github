#include "Rvc/RvcStubImpl.h"
#include "Rvc/RvcMsgQDefine.h"
#include "RvcServiceStubImplGWM.h"
#include "v0/com/harman/adas/RVCBaseType.hpp"
#include "AFoundation.h"

using namespace Harman::Adas::AFramework::AFoundation;
using namespace Harman::Adas::AFramework::AGraphic;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

RvcStubImpl::RvcStubImpl(CameraHub* hub)
    :ARvcBase(hub)
{
    m_pRvcGLine = new RvcGuideLine();
}

RvcStubImpl::~RvcStubImpl()
{

}

a_status  RvcStubImpl::initialize()
{
    
    ALOGD("RvcStubImpl::initialize\n");
    registerFunc((UInt32)eCameraActivate_ON, makeFunctor(this, &RvcStubImpl::showCamera));
    registerFunc((UInt32)eCameraActivate_OFF, makeFunctor(this, &RvcStubImpl::hideCamera));
    m_pRearCamera->OpenCamera();
    m_pRearCamera->StartCapture();

    m_pRvcGLine->start();

    return a_status(0); 
}

VOID  RvcStubImpl::afterHandleMessageQueue()
{

}

VOID  RvcStubImpl::showCamera(const string& pData)
{
    ALOGI("showCamera [%s]\n", pData.c_str());

    if(camState == CAM_ON)
    {
        ALOGI("notify hmi show camera [%s]\n", pData.c_str());
        RvcServiceStubImplGWM::getInstance()->setRvcStateAttribute(::v0::com::harman::adas::RVCBaseType::enRvcState::e_RVC_ON);
    }

    if(camState == CAM_ERROR)
    {
        ALOGI("notify hmi show camera error [%s]\n", pData.c_str());
        RvcServiceStubImplGWM::getInstance()->setRvcStateAttribute(::v0::com::harman::adas::RVCBaseType::enRvcState::e_RVC_UNAVAILABLE);
    }
}

VOID  RvcStubImpl::hideCamera(const string& pData)
{
	ALOGI("hideCamera [%s]\n", pData.c_str());

	if(camState == CAM_ON)
	{
		ALOGI("notify hmi hide camera [%s]\n", pData.c_str());
        RvcServiceStubImplGWM::getInstance()->setRvcStateAttribute(::v0::com::harman::adas::RVCBaseType::enRvcState::e_RVC_OFF);
	}
    if(camState == CAM_ERROR)
    {
        ALOGI("notify hmi hide camera error [%s]\n", pData.c_str());
        RvcServiceStubImplGWM::getInstance()->setRvcStateAttribute(::v0::com::harman::adas::RVCBaseType::enRvcState::e_RVC_UNAVAILABLE);
    }
}

}
}
}
}