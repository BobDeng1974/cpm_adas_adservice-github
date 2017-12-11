#ifndef __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_PRIORITY_STATE_DISABLE_H__
#define __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_PRIORITY_STATE_DISABLE_H__

#include "State.h"
#include "StateMachine.h"

#include "PriorityStateMachine/AvmCtrl.h"
#include "PriorityStateMachine/AvmPriorityStateMachine.h"
#include "EngineStateMachine/AvmEngineStateMachine.h"

using namespace std;

using Harman::Adas::AFramework::AFoundation::State;
using Harman::Adas::AFramework::AFoundation::StateMachine;
using namespace Harman::Adas::AFramework::AFoundation;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {


class CAvmPriorityStateDisable : public State
{
public:
    CAvmPriorityStateDisable(const string& name, StateMachine* sm, CAvmEngineStateMachine* Subsm)
        : State(name, sm)
        , m_pAvmEngineStateMachine(Subsm)
    {
    
    }

    VOID Enter() const;
    VOID Exit() const;

    virtual BOOLEAN ProcessMessage(UInt32 uiType, UInt32 uiID, const string& pData) const;

    ~CAvmPriorityStateDisable()
    {

    }

private:
	CAvmEngineStateMachine* m_pAvmEngineStateMachine;
};

//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman


#endif //__HARMAN_ADAS_APROJECT_GWMV2MH_AVM_PRIORITY_STATE_DISABLE_H__
