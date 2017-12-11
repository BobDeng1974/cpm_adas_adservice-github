#include "PriorityStateMachine/AvmPriorityStateEnable.h"

#include "TraceMacros.h"


namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {


VOID CAvmPriorityStateEnable::Enter() const
{
    ALOGI("Enter state : %s !\n", GetStateName().c_str());
}

VOID CAvmPriorityStateEnable::Exit() const
{
    ALOGI("Exit state : %s !\n", GetStateName().c_str());
}

BOOLEAN CAvmPriorityStateEnable::ProcessMessage(UInt32 uiType, UInt32 uiMessageID, const string& pData) const
{
	ALOGI("CAvmPriorityStateEnable::ProcessMessage : start!\n");
	ALOGI("CAvmPriorityStateEnable::ProcessMessage : uiType is %d, uiMessageID is %d\n", (int)uiType,(int)uiMessageID);
	ALOGI("CAvmPriorityStateEnable::ProcessMessage : pData is %s\n",pData.c_str()); 

	CAvmPriorityStateMachine* csm;
	csm = dynamic_cast<CAvmPriorityStateMachine*>(m_pStateMachine);
	bool ret = true;
	CAvmCtrl::getInstance()->updateState();
//	m_pAvmEngineStateMachine->SendMessage(new MessageForQueue(0 /*not used now*/, e_AVM_Top_View, AVM_STATE_MACHINE));
#if 0
	if (csm != nullptr)
	{
		ALOGI("CAvmPriorityStateEnable::ProcessMessage : Transition To TopView!\n");
		m_pStateMachine->TransitionTo(csm->m_pAvmStateTopView);
	}
#endif
#if 0
	switch(uiMessageID)
	{
		case 1 :

			csm = dynamic_cast<CAvmStateMachine*>(m_pStateMachine);
			if (csm != nullptr)
			{
				m_pStateMachine->TransitionTo(csm->m_pAvmStateOff);

				/*To do: call engine API*/
				ALOGI("OffState : To do call engine API\n");
				
				ret = true; /*get engie API result*/
				if(ret)
				{
					ALOGI("OffState : engine API return True!\n");
					return TRUE;
				}
				else
				{
					ALOGI("OffState : engine API return False!\n");
					return FALSE;				
				}
				
			}
			else{}
			
			break;

		default:
			ALOGE("error uiMessageID unknow uiMessageID = %d!!!\n", uiMessageID);
	}
#endif
	ALOGI("CAvmPriorityStateEnable::ProcessMessage : end ret = %d\n",(int)ret);
	return ret;
}



//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman