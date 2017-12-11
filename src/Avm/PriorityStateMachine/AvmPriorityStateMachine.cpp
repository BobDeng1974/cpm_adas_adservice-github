#include "PriorityStateMachine/AvmPriorityStateMachine.h"



namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {


CAvmPriorityStateMachine::CAvmPriorityStateMachine(const string& name)
    : StateMachine(name)
    , m_pAvmEngineStateMachine(nullptr)
    , m_pAvmCtrl(nullptr)
{
	ALOGI("CAvmPriorityStateMachine::CAvmPriorityStateMachine : start!\n");
	
	m_pAvmEngineStateMachine = new CAvmEngineStateMachine(AVM_STATE_MACHINE);

	if(m_pAvmEngineStateMachine == nullptr)
	{
		ALOGE("CAvmPriorityStateMachine::new CAvmEngineStateMachine failed return@@!\n");
		return;
	}
	else
	{
		m_pAvmCtrl = new CAvmCtrl();

		if(m_pAvmEngineStateMachine != nullptr)
		{
			ALOGI("CAvmPriorityStateMachine::new CAvmEngineStateMachine succeed !\n");
		}
		else
		{
			ALOGE("CAvmPriorityStateMachine::new m_pAvmEngineStateMachine failed return@@!\n");
			return;
		}
	}
	
    //init m_mapStateMapInt
    m_mapStateMapInt[AVM_ENABLE] = e_AVM_Enable;
    m_mapStateMapInt[AVM_DISABLE] = e_AVM_Disable;

    //creat specific State belongs to AvmStateMachine
    m_pAvmPriorityStateDefault = make_shared<CAvmPriorityStateDefault>(AVM_DEFAULT, this,m_pAvmEngineStateMachine);
    m_pAvmPriorityStateEnable = make_shared<CAvmPriorityStateEnable>(AVM_ENABLE, this,m_pAvmEngineStateMachine);
	m_pAvmPriorityStateDisable = make_shared<CAvmPriorityStateDisable>(AVM_DISABLE, this,m_pAvmEngineStateMachine);


    //add specific State to AvmStateMachine
    AddState(m_pAvmPriorityStateDefault, nullptr);
    AddState(m_pAvmPriorityStateEnable, m_pAvmPriorityStateDefault);
    AddState(m_pAvmPriorityStateDisable, m_pAvmPriorityStateDefault);

    // //set "m_pOffState" as init state of AvmStateMachine
	SetInitialState(m_pAvmPriorityStateDisable);

    // //start StateMachine
	Start();
	ALOGI("CAvmPriorityStateMachine::CAvmPriorityStateMachine : end!\n");
}


//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman

