#include "AvmProxy.h"



namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

CAvmProxy* CAvmProxy:: m_pAvmInstance = NULL;

CAvmProxy::CAvmProxy()
{
	m_pCAdasManagerGWMv2 = CAdasManagerGWMv2::getInstance();
}

CAvmProxy::~CAvmProxy()
{

}

CAvmProxy* CAvmProxy::getInstance()
{
	if(NULL == m_pAvmInstance)
	{
		m_pAvmInstance = new CAvmProxy();
	}

	return m_pAvmInstance;
}


a_status  CAvmProxy::initialize()
{
//    ALOGD("CAvmProxy::initialize\n");
    ALOGI("CAvmProxy::initialize\n");

    return a_status(0); 
}

void CAvmProxy::SwitchAVMView(const std::shared_ptr<CommonAPI::ClientId> _client, ::v0::com::harman::adas::AVMBaseType::enAVMViewMode m_eAVMViewMode, SwitchAVMViewReply_t reply)
{
	 ALOGI("SwitchAVMView start m_eAVMViewMode is %d\n",(Int32)m_eAVMViewMode);
	switch (m_eAVMViewMode)
	{
		case 0 :
			ALOGI("SwitchAVMView going to set off \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(2,eAvm_SWITCH, string("OFF")));
			break;
		case 1 :
			ALOGI("SwitchAVMView going to top view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(2,eAvm_SWITCH, string("TOP_VIEW")));
			break;
		case 2 :
			ALOGI("SwitchAVMView going to front view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(2,eAvm_SWITCH, string("FRONT_VIEW")));
			break;			
		case 3 :
			ALOGI("SwitchAVMView going to rear view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(2,eAvm_SWITCH, string("REAR_VIEW")));
			break;			
		case 4 :
			ALOGI("SwitchAVMView going to right view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(2,eAvm_SWITCH, string("RIGHT_VIEW")));
			break;			
		case 5 :
			ALOGI("SwitchAVMView going to left view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(2,eAvm_SWITCH, string("LEFT_VIEW")));			
			break;						
		case 6 :
			ALOGI("SwitchAVMView going to front right view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(2,eAvm_SWITCH, string("FRONT_RIGHT_VIEW")));
			break;			
		case 7 :
			ALOGI("SwitchAVMView going to front rear left view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(2,eAvm_SWITCH, string("REAR_LEFT_VIEW")));
			break;
		case 8 :
			ALOGI("SwitchAVMView going to front rear right view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(2,eAvm_SWITCH, string("REAR_RIGHT_VIEW")));
			break;			
		case 9 :
			ALOGI("SwitchAVMView going to front front left view \n");			
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(2,eAvm_SWITCH, string("FRONT_LEFT_VIEW")));
			break;
		case 10 :
			ALOGI("SwitchAVMView going to front top rear view \n");	
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(2,eAvm_SWITCH, string("TOP_REAR_VIEW")));
			break;			
		case 11 :
			ALOGI("SwitchAVMView going to front top front view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(2,eAvm_SWITCH, string("TOP_FRONT_VIEW")));
			break;			
		default:
		    ALOGI("SwitchAVMView error AVM View mode is %d\n",(Int32)m_eAVMViewMode);
	}
	reply();
	ALOGI("SwitchAVMView end\n");
}

void CAvmProxy::SwitchGuideline(const std::shared_ptr<CommonAPI::ClientId> _client, ::v0::com::harman::adas::AVMBaseType::enAVMGuideLineMode m_eAVMGuideLinewMode, SwitchGuidelineReply_t reply)
{

}

void CAvmProxy::SwitchCTA(const std::shared_ptr<CommonAPI::ClientId> _client, ::v0::com::harman::adas::CTABaseType::enCTAWorkMode m_eCATMode, SwitchCTAReply_t reply)
{

}

void CAvmProxy::SwitchAutoCalibrationAuto(const std::shared_ptr<CommonAPI::ClientId> _client, ::v0::com::harman::adas::AVMBaseType::enAutoCaliWorkModeAuto m_eAutoCaliMode, SwitchAutoCalibrationAutoReply_t reply)
{


}

void CAvmProxy::SwitchAutoCalibrationManually(const std::shared_ptr<CommonAPI::ClientId> _client, ::v0::com::harman::adas::AVMBaseType::enAutoCaliWorkModeManu m_eAutoCaliMode, SwitchAutoCalibrationManuallyReply_t reply)
{

}

}
}
}
}