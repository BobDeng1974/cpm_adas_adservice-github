#include "AvmProxy.h"



namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {


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
    ALOGI("CAvmProxy::initialize\n");

    return a_status(0); 
}

void CAvmProxy::SwitchAVMView(const std::shared_ptr<CommonAPI::ClientId> _client, ::v0::com::harman::adas::AVMBaseType::enAVMViewMode m_eAVMViewMode, SwitchAVMViewReply_t reply)
{
	 ALOGI("SwitchAVMView start m_eAVMViewMode is %d\n",(Int32)m_eAVMViewMode);
	switch (m_eAVMViewMode)
	{
		case ::v0::com::harman::adas::AVMBaseType::enAVMViewMode::e_SET_OFF:
			ALOGI("SwitchAVMView going to set off \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(AdasModuleCtrlImpl::eModuleType_AVM,eAvm_SWITCH, MANUAL_AVM_OFF));
			break;
		case ::v0::com::harman::adas::AVMBaseType::enAVMViewMode::e_SET_TOP_VIEW:
			ALOGI("SwitchAVMView going to top view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(AdasModuleCtrlImpl::eModuleType_AVM,eAvm_SWITCH, MANUAL_ACTIVATE_TOP_VIEW));
			break;
		case ::v0::com::harman::adas::AVMBaseType::enAVMViewMode::e_SET_FRONT_VIEW:
			ALOGI("SwitchAVMView going to front view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(AdasModuleCtrlImpl::eModuleType_AVM,eAvm_SWITCH, MANUAL_ACTIVATE_D1_VIEW));
			break;			
		case ::v0::com::harman::adas::AVMBaseType::enAVMViewMode::e_SET_REAR_VIEW:
			ALOGI("SwitchAVMView going to rear view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(AdasModuleCtrlImpl::eModuleType_AVM,eAvm_SWITCH, MANUAL_ACTIVATE_D8_VIEW));
			break;			
		case ::v0::com::harman::adas::AVMBaseType::enAVMViewMode::e_SET_RIGHT_VIEW:
			ALOGI("SwitchAVMView going to right view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(AdasModuleCtrlImpl::eModuleType_AVM,eAvm_SWITCH, MANUAL_ACTIVATE_D5_VIEW));
			break;			
		case ::v0::com::harman::adas::AVMBaseType::enAVMViewMode::e_SET_LEFT_VIEW:
			ALOGI("SwitchAVMView going to left view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(AdasModuleCtrlImpl::eModuleType_AVM,eAvm_SWITCH, MANUAL_ACTIVATE_D4_VIEW));			
			break;						
		case ::v0::com::harman::adas::AVMBaseType::enAVMViewMode::e_SET_FRONT_RIGHT_VIEW:
			ALOGI("SwitchAVMView going to front right view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(AdasModuleCtrlImpl::eModuleType_AVM,eAvm_SWITCH, MANUAL_ACTIVATE_D3_VIEW));
			break;			
		case ::v0::com::harman::adas::AVMBaseType::enAVMViewMode::e_SET_FRONT_LEFT_VIEW:
			ALOGI("SwitchAVMView going to front left view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(AdasModuleCtrlImpl::eModuleType_AVM,eAvm_SWITCH, MANUAL_ACTIVATE_D2_VIEW));
			break;
		case ::v0::com::harman::adas::AVMBaseType::enAVMViewMode::e_SET_REAR_RIGHT_VIEW:
			ALOGI("SwitchAVMView going to rear right view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(AdasModuleCtrlImpl::eModuleType_AVM,eAvm_SWITCH, MANUAL_ACTIVATE_D7_VIEW));
			break;			
		case ::v0::com::harman::adas::AVMBaseType::enAVMViewMode::e_SET_REAR_LEFT_VIEW:
			ALOGI("SwitchAVMView going to rear left view \n");			
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(AdasModuleCtrlImpl::eModuleType_AVM,eAvm_SWITCH, MANUAL_ACTIVATE_D6_VIEW));
			break;
		case ::v0::com::harman::adas::AVMBaseType::enAVMViewMode::e_SET_TOP_REAR_VIEW:
			ALOGI("SwitchAVMView going to top rear view \n");	
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(AdasModuleCtrlImpl::eModuleType_AVM,eAvm_SWITCH, MANUAL_ACTIVATE_REAR_WIDE_ANGLE_VIEW));
			break;			
		case ::v0::com::harman::adas::AVMBaseType::enAVMViewMode::e_SET_TOP_FRONT_VIEW:
			ALOGI("SwitchAVMView going to top front view \n");
			m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(AdasModuleCtrlImpl::eModuleType_AVM,eAvm_SWITCH, MANUAL_ACTIVATE_FRONT_WIDE_ANGLE_VIEW));
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



//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman