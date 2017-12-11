#include "PriorityStateMachine/AvmCtrl.h"




namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {

CAvmCtrl* CAvmCtrl:: m_pAvmCtrlInstance = NULL;


CAvmCtrl::CAvmCtrl()
{
	ALOGI("CAvmCtrl!\n");
	m_pAvmProxy = CAvmProxy::getInstance();
}

CAvmCtrl::~CAvmCtrl()
{

}


CAvmCtrl* CAvmCtrl::getInstance()
{
	if(NULL == m_pAvmCtrlInstance)
	{
		m_pAvmCtrlInstance = new CAvmCtrl();
	}

	return m_pAvmCtrlInstance;
}




BOOLEAN CAvmCtrl::initialize() 
{
	BOOLEAN ret = true;
    ALOGI("CAvmCtrl initialize\n");

	return ret;
}


VOID CAvmCtrl::updateState() 
{

    ALOGI("CAvmCtrl updateState start\n");
	ALOGI("CAvmCtrl setAVMCamStatusAttribute\n");
	//m_pAvmProxy->setAVMCamStatusAttribute(::v0::com::harman::adas::AVMBaseType::stAVMCamState);
    ALOGI("CAvmCtrl updateState end\n");	
}


//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman
