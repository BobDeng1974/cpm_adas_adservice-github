#ifndef __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_ENGINE_STATE_TOP_VIEW_STATE_H__
#define __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_ENGINE_STATE_TOP_VIEW_STATE_H__

#include "State.h"
#include "StateMachine.h"
#include "AvmEventDefine.h"

using namespace std;

using Harman::Adas::AFramework::AFoundation::State;
using Harman::Adas::AFramework::AFoundation::StateMachine;
using namespace Harman::Adas::AFramework::AFoundation;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
namespace AVM {

class CAvmEngineStateTopView : public State
{
public:
    CAvmEngineStateTopView(const string& name, StateMachine* sm)
        : State(name, sm)
    {
    
    }

    VOID Enter() const;
    VOID Exit() const;

    virtual BOOLEAN ProcessMessage(UInt32 uiType, UInt32 uiID, const string& pData) const;

    ~CAvmEngineStateTopView()
    {

    }

private:

};

} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman


#endif //__HARMAN_ADAS_APROJECT_GWMV2MH_AVM_ENGINE_STATE_TOP_VIEW_STATE_H__
