#include "PriorityStateMachine/AvmPriorityStateDefault.h"

#include "TraceMacros.h"


namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {


VOID CAvmPriorityStateDefault::Enter() const
{
    ALOGI("Enter state : %s !\n", GetStateName().c_str());
}

VOID CAvmPriorityStateDefault::Exit() const
{
    ALOGI("Exit state : %s !\n", GetStateName().c_str());
}

BOOLEAN CAvmPriorityStateDefault::ProcessMessage(UInt32 uiType, UInt32 uiMessageID, const string& pData) const
{
	ALOGI("CAvmPriorityStateDefault::ProcessMessage : start!\n");
	ALOGI("CAvmPriorityStateDefault::ProcessMessage : uiType is %d, uiMessageID is %d\n", (int)uiType,(int)uiMessageID);
	ALOGI("CAvmPriorityStateDefault::ProcessMessage : pData is %s\n",pData.c_str()); 

	CAvmPriorityStateMachine* csm;
	csm = dynamic_cast<CAvmPriorityStateMachine*>(m_pStateMachine);
	bool ret = true;
	CAvmCtrl::getInstance()->updateState();

	ALOGI("CAvmPriorityStateDefault::ProcessMessage : end ret = %d\n",(int)ret);
	return ret;
}



//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman