#ifndef __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_PRIORITY_STATE_MACHINE_H__
#define __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_PRIORITY_STATE_MACHINE_H__

#include <memory>
#include "TraceMacros.h"
#include "TypeDefine.h"
#include "platformdef.h"

#include "State.h"
#include "StateMachine.h"
#include "AvmEventDefine.h"

#include "EngineStateMachine/AvmEngineStateMachine.h"

#include "PriorityStateMachine/AvmPriorityStateDefault.h"
#include "PriorityStateMachine/AvmPriorityStateEnable.h"
#include "PriorityStateMachine/AvmPriorityStateDisable.h"
#include "PriorityStateMachine/AvmCtrl.h"


using namespace std;

using Harman::Adas::AFramework::AFoundation::State;
using Harman::Adas::AFramework::AFoundation::StateMachine;
using Harman::Adas::AFramework::AFoundation::Subject;
using namespace Harman::Adas::AFramework::AFoundation;

//using namespace Harman::Adas::AProject::GWMV2MH::AVM;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {

class CAvmPriorityStateMachine : public StateMachine
{
public:
    CAvmPriorityStateMachine(const string& name);

    ~CAvmPriorityStateMachine(){}

public:
	//Default
	shared_ptr<State> m_pAvmPriorityStateDefault;
	//Enable
	shared_ptr<State> m_pAvmPriorityStateEnable;
	//Disnable
	shared_ptr<State> m_pAvmPriorityStateDisable;
private:

	friend class CAvmPriorityStateDefault;
	friend class CAvmPriorityStateEnable;
	friend class CAvmPriorityStateDisable;
	
	CAvmEngineStateMachine* m_pAvmEngineStateMachine;
	CAvmCtrl* m_pAvmCtrl;
};

//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman


#endif //__HARMAN_ADAS_APROJECT_GWMV2MH_AVM_PRIORITY_STATE_MACHINE_H__
