#include "EngineStateMachine/AvmEngineStateMachine.h"



namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {


CAvmEngineStateMachine::CAvmEngineStateMachine(const string& name)
    : StateMachine(name)
{
	ALOGI("CAvmEngineStateMachine::CAvmEngineStateMachine : start!\n");

    //init m_mapStateMapInt
    m_mapStateMapInt[AVM_STATE_OFF] = e_AVM_Off_State;
    m_mapStateMapInt[AVM_STATE_ERROR] = e_AVM_Error_State;
    m_mapStateMapInt[AVM_STATE_TOP_VIEW] = e_AVM_Top_View;
    m_mapStateMapInt[AVM_STATE_D1_VIEW] = e_AVM_D1_View;
    m_mapStateMapInt[AVM_STATE_D2_VIEW] = e_AVM_D2_View;
    m_mapStateMapInt[AVM_STATE_D3_VIEW] = e_AVM_D3_View;
    m_mapStateMapInt[AVM_STATE_D4_VIEW] = e_AVM_D4_View;
    m_mapStateMapInt[AVM_STATE_D5_VIEW] = e_AVM_D5_View;
    m_mapStateMapInt[AVM_STATE_D6_VIEW] = e_AVM_D6_View;
    m_mapStateMapInt[AVM_STATE_D7_VIEW] = e_AVM_D7_View;
    m_mapStateMapInt[AVM_STATE_D8_VIEW] = e_AVM_D8_View;
    m_mapStateMapInt[AVM_STATE_FRONT_WIDE_ANGLE_VIEW] = e_AVM_Front_Wide_Angle_View;
    m_mapStateMapInt[AVM_STATE_REAR_WIDE_ANGLE_VIEW] = e_AVM_Rear_Wide_Angle_View;	

    //creat specific State belongs to AvmStateMachine
    m_pAvmEngineStateDefault = make_shared<CAvmEngineStateDefault>(AVM_STATE_DEFAULT, this);
    m_pAvmEngineStateOff = make_shared<CAvmEngineStateOff>(AVM_STATE_OFF, this);	
	m_pAvmEngineStateError = make_shared<CAvmEngineStateError>(AVM_STATE_ERROR, this);		
	m_pAvmEngineStateTopView = make_shared<CAvmEngineStateTopView>(AVM_STATE_TOP_VIEW, this);	
	m_pAvmEngineStateD1View = make_shared<CAvmEngineStateD1View>(AVM_STATE_D1_VIEW, this);	
	m_pAvmEngineStateD2View = make_shared<CAvmEngineStateD2View>(AVM_STATE_D2_VIEW, this);	
	m_pAvmEngineStateD3View = make_shared<CAvmEngineStateD3View>(AVM_STATE_D3_VIEW, this);	
	m_pAvmEngineStateD4View = make_shared<CAvmEngineStateD4View>(AVM_STATE_D4_VIEW, this);	
	m_pAvmEngineStateD5View = make_shared<CAvmEngineStateD5View>(AVM_STATE_D5_VIEW, this);	
	m_pAvmEngineStateD6View = make_shared<CAvmEngineStateD6View>(AVM_STATE_D6_VIEW, this);	
	m_pAvmEngineStateD7View = make_shared<CAvmEngineStateD7View>(AVM_STATE_D7_VIEW, this);	
	m_pAvmEngineStateD8View = make_shared<CAvmEngineStateD8View>(AVM_STATE_D8_VIEW, this);	
	m_pAvmEngineStateFrontWideAngleView = make_shared<CAvmEngineStateFrontWideAngleView>(AVM_STATE_FRONT_WIDE_ANGLE_VIEW, this);	
	m_pAvmEngineStateRearWideAngleView = make_shared<CAvmEngineStateRearWideAngleView>(AVM_STATE_REAR_WIDE_ANGLE_VIEW, this);	

    //add specific State to AvmStateMachine
    AddState(m_pAvmEngineStateDefault, nullptr);
    AddState(m_pAvmEngineStateOff, m_pAvmEngineStateDefault);
    AddState(m_pAvmEngineStateError, m_pAvmEngineStateDefault);
    AddState(m_pAvmEngineStateTopView, m_pAvmEngineStateDefault);
    AddState(m_pAvmEngineStateD1View, m_pAvmEngineStateDefault);
    AddState(m_pAvmEngineStateD2View, m_pAvmEngineStateDefault);
    AddState(m_pAvmEngineStateD3View, m_pAvmEngineStateDefault);
    AddState(m_pAvmEngineStateD4View, m_pAvmEngineStateDefault);
    AddState(m_pAvmEngineStateD5View, m_pAvmEngineStateDefault);
    AddState(m_pAvmEngineStateD6View, m_pAvmEngineStateDefault);
    AddState(m_pAvmEngineStateD7View, m_pAvmEngineStateDefault);
    AddState(m_pAvmEngineStateD8View, m_pAvmEngineStateDefault);
    AddState(m_pAvmEngineStateFrontWideAngleView, m_pAvmEngineStateDefault);
    AddState(m_pAvmEngineStateRearWideAngleView, m_pAvmEngineStateDefault);
    // //set "m_pOffState" as init state of AvmStateMachine
	SetInitialState(m_pAvmEngineStateOff);

    // //start StateMachine
	Start();
	ALOGI("CAvmEngineStateMachine::CAvmEngineStateMachine : end!\n");
}


//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman

