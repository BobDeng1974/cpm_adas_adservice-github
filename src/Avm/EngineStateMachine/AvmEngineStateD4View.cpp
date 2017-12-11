#include "EngineStateMachine/AvmEngineStateD4View.h"
#include "EngineStateMachine/AvmEngineStateMachine.h"

#include "MessageForQueue.h"
#include <iostream>
#include <thread>
#include <chrono>

using Harman::Adas::AFramework::AFoundation::MessageForQueue;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {


VOID CAvmEngineStateD4View::Enter() const
{
    ALOGI("Enter state : %s !\n", GetStateName().c_str());
}

VOID CAvmEngineStateD4View::Exit() const
{
    ALOGI("Exit state : %s !\n", GetStateName().c_str());
}

BOOLEAN CAvmEngineStateD4View::ProcessMessage(UInt32 uiType, UInt32 uiMessageID, const string& pData) const
{
	ALOGI("CAvmEngineStateD4View::ProcessMessage : start!\n");
	ALOGI("CAvmEngineStateD4View::ProcessMessage : uiType is %d, uiMessageID is %d\n", (int)uiType,(int)uiMessageID);
	ALOGI("CAvmEngineStateD4View::ProcessMessage : pData is %s\n",pData.c_str()); 

	CAvmEngineStateMachine* csm;
	csm = dynamic_cast<CAvmEngineStateMachine*>(m_pStateMachine);
	bool ret = true;

	if (csm != nullptr)
	{
		ALOGI("CAvmEngineStateD4View::ProcessMessage : Transition To TopView!\n");
		m_pStateMachine->TransitionTo(csm->m_pAvmEngineStateTopView);
	}
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
	ALOGI("CAvmEngineStateD4View::ProcessMessage : end ret = %d\n",(int)ret);
	return ret;
}



//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman
