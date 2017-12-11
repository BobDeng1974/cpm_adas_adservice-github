#ifndef __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_AVM_ENGINE_STATE_MACHINE_H__
#define __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_AVM_ENGINE_STATE_MACHINE_H__

#include <memory>
#include "TraceMacros.h"
#include "TypeDefine.h"
#include "platformdef.h"

#include "State.h"
#include "StateMachine.h"
#include "AvmEventDefine.h"

#include "EngineStateMachine/AvmEngineStateDefault.h"
#include "EngineStateMachine/AvmEngineStateOff.h"
#include "EngineStateMachine/AvmEngineStateError.h"
#include "EngineStateMachine/AvmEngineStateTopView.h"
#include "EngineStateMachine/AvmEngineStateD1View.h"
#include "EngineStateMachine/AvmEngineStateD2View.h"
#include "EngineStateMachine/AvmEngineStateD3View.h"
#include "EngineStateMachine/AvmEngineStateD4View.h"
#include "EngineStateMachine/AvmEngineStateD5View.h"
#include "EngineStateMachine/AvmEngineStateD6View.h"
#include "EngineStateMachine/AvmEngineStateD7View.h"
#include "EngineStateMachine/AvmEngineStateD8View.h"
#include "EngineStateMachine/AvmEngineStateFrontWideAngleView.h"
#include "EngineStateMachine/AvmEngineStateRearWideAngleView.h"


using namespace std;

using Harman::Adas::AFramework::AFoundation::State;
using Harman::Adas::AFramework::AFoundation::StateMachine;
using Harman::Adas::AFramework::AFoundation::Subject;
using namespace Harman::Adas::AFramework::AFoundation;

using namespace Harman::Adas::AProject::GWMV2MH::AVM;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {

class CAvmEngineStateMachine : public StateMachine
{
public:
    CAvmEngineStateMachine(const string& name);

    ~CAvmEngineStateMachine(){}

public:
	//Default
	shared_ptr<State> m_pAvmEngineStateDefault;
	//Off
	shared_ptr<State> m_pAvmEngineStateOff;
	//Error
	shared_ptr<State> m_pAvmEngineStateError;	
	//TopView	
	shared_ptr<State> m_pAvmEngineStateTopView;
	//D1View	
	shared_ptr<State> m_pAvmEngineStateD1View;
	//D2View	
	shared_ptr<State> m_pAvmEngineStateD2View;
	//D3View	
	shared_ptr<State> m_pAvmEngineStateD3View;
	//D4View	
	shared_ptr<State> m_pAvmEngineStateD4View;
	//D5View
	shared_ptr<State> m_pAvmEngineStateD5View;
	//D6View
	shared_ptr<State> m_pAvmEngineStateD6View;
	//D7View
	shared_ptr<State> m_pAvmEngineStateD7View;
	//D8View
	shared_ptr<State> m_pAvmEngineStateD8View;
	//FrontWideAngleView
	shared_ptr<State> m_pAvmEngineStateFrontWideAngleView;
	//RearWideAngleView
	shared_ptr<State> m_pAvmEngineStateRearWideAngleView;

private:

	friend class CAvmEngineStateDefault;
	friend class CAvmEngineStateOff;
	friend class CAvmEngineStateError;	
	friend class CAvmEngineStateTopView;
	friend class CAvmEngineStateD1View;
	friend class CAvmEngineStateD2View;
	friend class CAvmEngineStateD3View;
	friend class CAvmEngineStateD4View;
	friend class CAvmEngineStateD5View;
	friend class CAvmEngineStateD6View;
	friend class CAvmEngineStateD7View;
	friend class CAvmEngineStateD8View;
	friend class CAvmEngineStateFrontWideAngleView;
	friend class CAvmEngineStateRearWideAngleView;
};

//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman


#endif //__HARMAN_ADAS_APROJECT_GWMV2MH_AVM_AVM_ENGINE_STATE_MACHINE_H__
