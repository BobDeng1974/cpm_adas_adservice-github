#include "AvmStubImpl.h"




namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {

/*
 * static
 */

static Struct_AVM_CMDAttribute s_aryAVMCmdToEvent[]=
{
	{	string(AUTO_ACTIVATE_ERROR_STATE).c_str(),				e_AVM_Message_Auto_Activate_Error_State					},
	{	string(AUTO_ACTIVATE_TOP_VIEW).c_str(),					e_AVM_Message_Auto_Activate_Top_View					},
	{	string(AUTO_ACTIVATE_D1_VIEW).c_str(),					e_AVM_Message_Auto_Activate_D1_View						},
	{	string(AUTO_ACTIVATE_D2_VIEW).c_str(),					e_AVM_Message_Auto_Activate_D2_View						},
	{	string(AUTO_ACTIVATE_D3_VIEW).c_str(),					e_AVM_Message_Auto_Activate_D3_View						},
	{	string(AUTO_ACTIVATE_D4_VIEW).c_str(),					e_AVM_Message_Auto_Activate_D4_View						},
	{	string(AUTO_ACTIVATE_D5_VIEW).c_str(),					e_AVM_Message_Auto_Activate_D5_View						},
	{	string(AUTO_ACTIVATE_D6_VIEW).c_str(),					e_AVM_Message_Auto_Activate_D6_View						},
	{	string(AUTO_ACTIVATE_D7_VIEW).c_str(),					e_AVM_Message_Auto_Activate_D7_View						},
	{	string(AUTO_ACTIVATE_D8_VIEW).c_str(),					e_AVM_Message_Auto_Activate_D8_View						},
	{	string(AUTO_ACTIVATE_FRONT_WIDE_ANGLE_VIEW).c_str(),	e_AVM_Message_Auto_Activate_Front_Wide_Angle_View 		},
	{	string(AUTO_ACTIVATE_REAR_WIDE_ANGLE_VIEW).c_str(), 	e_AVM_Message_Auto_Activate_Rear_Wide_Angle_View		},
				
	{	string(AUTO_DEACTIVATE_ERROR_STATE).c_str(),			e_AVM_Message_Auto_Deactivate_Error_State 				},
	{	string(AUTO_DEACTIVATE_TOP_VIEW).c_str(),				e_AVM_Message_Auto_Deactivate_Top_View					},
	{	string(AUTO_DEACTIVATE_D1_VIEW).c_str(),				e_AVM_Message_Auto_Deactivate_D1_View 					},
	{	string(AUTO_DEACTIVATE_D2_VIEW).c_str(),				e_AVM_Message_Auto_Deactivate_D2_View 					},
	{	string(AUTO_DEACTIVATE_D3_VIEW).c_str(),				e_AVM_Message_Auto_Deactivate_D3_View 					},
	{	string(AUTO_DEACTIVATE_D4_VIEW).c_str(),				e_AVM_Message_Auto_Deactivate_D4_View 					},
	{	string(AUTO_DEACTIVATE_D5_VIEW).c_str(),				e_AVM_Message_Auto_Deactivate_D5_View 					},
	{	string(AUTO_DEACTIVATE_D6_VIEW).c_str(),				e_AVM_Message_Auto_Deactivate_D6_View 					},
	{	string(AUTO_DEACTIVATE_D7_VIEW).c_str(),				e_AVM_Message_Auto_Deactivate_D7_View 					},
	{	string(AUTO_DEACTIVATE_D8_VIEW).c_str(),				e_AVM_Message_Auto_Deactivate_D8_View 					},
	{	string(AUTO_DEACTIVATE_FRONT_WIDE_ANGLE_VIEW).c_str(),	e_AVM_Message_Auto_Deactivate_Front_Wide_Angle_View		},
	{	string(AUTO_DEACTIVATE_REAR_WIDE_ANGLE_VIEW).c_str(),	e_AVM_Message_Auto_Deactivate_Rear_Wide_Angle_View		},
	{	string(AUTO_AVM_OFF).c_str(),							e_AVM_Message_Auto_AVM_Off								},
				
	{	string(MANUAL_ACTIVATE_TOP_VIEW).c_str(),				e_AVM_Message_Manual_Activate_Top_View					},
	{	string(MANUAL_ACTIVATE_D1_VIEW).c_str(),				e_AVM_Message_Manual_Activate_D1_View 					},
	{	string(MANUAL_ACTIVATE_D2_VIEW).c_str(),				e_AVM_Message_Manual_Activate_D2_View 					},
	{	string(MANUAL_ACTIVATE_D3_VIEW).c_str(),				e_AVM_Message_Manual_Activate_D3_View 					},
	{	string(MANUAL_ACTIVATE_D4_VIEW).c_str(),				e_AVM_Message_Manual_Activate_D4_View 					},
	{	string(MANUAL_ACTIVATE_D5_VIEW).c_str(),				e_AVM_Message_Manual_Activate_D5_View 					},
	{	string(MANUAL_ACTIVATE_D6_VIEW).c_str(),				e_AVM_Message_Manual_Activate_D6_View 					},
	{	string(MANUAL_ACTIVATE_D7_VIEW).c_str(),				e_AVM_Message_Manual_Activate_D7_View 					},
	{	string(MANUAL_ACTIVATE_D8_VIEW).c_str(),				e_AVM_Message_Manual_Activate_D8_View 					},
	{	string(MANUAL_ACTIVATE_FRONT_WIDE_ANGLE_VIEW).c_str(),	e_AVM_Message_Manual_Activate_Front_Wide_Angle_View		},
	{	string(MANUAL_ACTIVATE_REAR_WIDE_ANGLE_VIEW).c_str(),	e_AVM_Message_Manual_Activate_Rear_Wide_Angle_View		},
				
	{	string(MANUAL_DEACTIVATE_FRONT_WIDE_ANGLE_VIEW).c_str(),e_AVM_Message_Manual_Deactivate_Front_Wide_Angle_View	},
	{	string(MANUAL_DEACTIVATE_REAR_WIDE_ANGLE_VIEW).c_str(), e_AVM_Message_Manual_Deactivate_Rear_Wide_Angle_View	},
	{	string(MANUAL_AVM_OFF).c_str(), 						e_AVM_Message_Manual_AVM_Off							}
};



CAvmStubImpl::CAvmStubImpl() 
	:CAvmBase()
	,m_pAvmPriorityStateMachine(NULL)
{
    ALOGI("CAvmStubImpl");
}

CAvmStubImpl::~CAvmStubImpl()
{

}

a_status  CAvmStubImpl::initialize()
{
	ALOGI("CAvmStubImpl::initialize\n");
	
	a_status initResult = INAVAILABEL;
	
	m_pAvmPriorityStateMachine = new CAvmPriorityStateMachine(AVM_STATE_MACHINE);

	if(m_pAvmPriorityStateMachine)
	{
		registerFunc((UInt32)eAvm_SWITCH, makeFunctor(this, &CAvmStubImpl::SwitchAVM));

		initResult = OK;
	}
	else
	{
		ALOGE("CAvmStubImpl::initialize error Avm state machine create failed !\n");		
		initResult = NO_INIT;
	}

    return initResult; 
}

VOID  CAvmStubImpl::afterHandleMessageQueue()
{

}

VOID  CAvmStubImpl::SwitchAVM(const string& pData)
{
	ALOGI("SwitchAVM [%s]\n", pData.c_str());
	
	UInt32 uiItemNum = sizeof(s_aryAVMCmdToEvent)/sizeof(s_aryAVMCmdToEvent);
	UInt32 uiIterator;
	Enum_AVM_Message eAvmStateEvent = e_AVM_Message_Invalid;
	
	for(uiIterator=0; uiIterator<uiItemNum; ++uiIterator)
	{
		if(0 == pData.compare(s_aryAVMCmdToEvent[uiIterator].sAvmCMD))
		{
			eAvmStateEvent = s_aryAVMCmdToEvent[uiIterator].eAvmStateMachineEvent;
		}
		else{/*donothing*/}
	}

	if(uiIterator > uiItemNum)
	{
		ALOGE("SwitchAVM: Error AVM CMD \n");
		eAvmStateEvent = e_AVM_Message_Auto_Activate_Error_State;
	}
	else
	{
		ALOGI("SwitchAVM: find AVM state Event = %d\n", eAvmStateEvent);
	}
	
	m_pAvmPriorityStateMachine->SendMessage(new MessageForQueue(0 /*not used now*/, eAvmStateEvent, AVM_STATE_MACHINE));
}


//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman
