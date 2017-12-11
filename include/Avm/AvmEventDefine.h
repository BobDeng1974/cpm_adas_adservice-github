#ifndef __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_EVENT_DEFINE_H__
#define __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_EVENT_DEFINE_H__

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {


#define AVM_STATE_MACHINE   				"AvmStateMachine"

//name of AVM Priority state
#define AVM_DEFAULT					"AvmDefault"
#define AVM_ENABLE					"AvmEnable"
#define AVM_DISABLE					"AvmDisable"

//name of AVM Engine state
#define AVM_STATE_DEFAULT					"AvmStateDefault"
#define AVM_STATE_OFF						"AvmStateOff"
#define AVM_STATE_ERROR						"AvmStateError"
#define AVM_STATE_TOP_VIEW					"AvmStateTopView"
#define AVM_STATE_D1_VIEW					"AvmStateD1View"
#define AVM_STATE_D2_VIEW					"AvmStateD2View"
#define AVM_STATE_D3_VIEW					"AvmStateD3View"
#define AVM_STATE_D4_VIEW					"AvmStateD4View"
#define AVM_STATE_D5_VIEW					"AvmStateD5View"
#define AVM_STATE_D6_VIEW					"AvmStateD6View"
#define AVM_STATE_D7_VIEW					"AvmStateD7View"
#define AVM_STATE_D8_VIEW					"AvmStateD8View"
#define AVM_STATE_FRONT_WIDE_ANGLE_VIEW		"AvmStateFrontWideAngleView"
#define AVM_STATE_REAR_WIDE_ANGLE_VIEW		"AvmStateRearWideAngleView"

/*
 * Engine state
 */
typedef enum _AVM_Engine_State{
    e_AVM_Off_State,
    e_AVM_Error_State,
    e_AVM_Top_View,
    e_AVM_D1_View,
    e_AVM_D2_View,
    e_AVM_D3_View,
    e_AVM_D4_View,
    e_AVM_D5_View,
    e_AVM_D6_View,
    e_AVM_D7_View,
    e_AVM_D8_View,
    e_AVM_Front_Wide_Angle_View,
	e_AVM_Rear_Wide_Angle_View,
    e_AVM_State_Invalid
} Enum_AVMEngineState;

/*
 * Priority state
 */
typedef enum _AVM_Priority_State
{
	e_AVM_Enable,
	e_AVM_Disable,
	e_AVM_Invalid	
} Enum_AVMPriorityState;

/*
 * State Trigger Event (message type used by AVM Engine State Machine)
 */
typedef enum _AVM_Engine_Message
{
	e_AVM_Message_Engine_Error_State, //mey not to be used
	e_AVM_Message_Engine_Top_View,
	e_AVM_Message_Engine_D1_View,
	e_AVM_Message_Engine_D2_View,
	e_AVM_Message_Engine_D3_View,
	e_AVM_Message_Engine_D4_View,
	e_AVM_Message_Engine_D5_View,
	e_AVM_Message_Engine_D6_View,
	e_AVM_Message_Engine_D7_View,
	e_AVM_Message_Engine_D8_View,
	e_AVM_Message_Engine_Front_Wide_Angle_View,
	e_AVM_Message_Engine_Rear_Wide_Angle_View,
	e_AVM_Message_Engine_Invalid
} Enum_AVM_Engine_Message;


/*
 * State Trigger Event (message type used by AVM Priority State Machine)
 */
typedef enum _AVM_Message
{
	e_AVM_Message_Auto_Activate_Error_State, //mey not to be used
	e_AVM_Message_Auto_Activate_Top_View,
	e_AVM_Message_Auto_Activate_D1_View,
	e_AVM_Message_Auto_Activate_D2_View,
	e_AVM_Message_Auto_Activate_D3_View,
	e_AVM_Message_Auto_Activate_D4_View,
	e_AVM_Message_Auto_Activate_D5_View,
	e_AVM_Message_Auto_Activate_D6_View,
	e_AVM_Message_Auto_Activate_D7_View,
	e_AVM_Message_Auto_Activate_D8_View,
	e_AVM_Message_Auto_Activate_Front_Wide_Angle_View,
	e_AVM_Message_Auto_Activate_Rear_Wide_Angle_View,

	e_AVM_Message_Auto_Deactivate_Error_State, //mey not to be used
	e_AVM_Message_Auto_Deactivate_Top_View,
	e_AVM_Message_Auto_Deactivate_D1_View,
	e_AVM_Message_Auto_Deactivate_D2_View,
	e_AVM_Message_Auto_Deactivate_D3_View,
	e_AVM_Message_Auto_Deactivate_D4_View,
	e_AVM_Message_Auto_Deactivate_D5_View,
	e_AVM_Message_Auto_Deactivate_D6_View,
	e_AVM_Message_Auto_Deactivate_D7_View,
	e_AVM_Message_Auto_Deactivate_D8_View,
	e_AVM_Message_Auto_Deactivate_Front_Wide_Angle_View,
	e_AVM_Message_Auto_Deactivate_Rear_Wide_Angle_View,
	e_AVM_Message_Auto_AVM_Off,

	e_AVM_Message_Manual_Activate_Top_View,
	e_AVM_Message_Manual_Activate_D1_View,
	e_AVM_Message_Manual_Activate_D2_View,
	e_AVM_Message_Manual_Activate_D3_View,
	e_AVM_Message_Manual_Activate_D4_View,
	e_AVM_Message_Manual_Activate_D5_View,
	e_AVM_Message_Manual_Activate_D6_View,
	e_AVM_Message_Manual_Activate_D7_View,
	e_AVM_Message_Manual_Activate_D8_View,
	e_AVM_Message_Manual_Activate_Front_Wide_Angle_View,
	e_AVM_Message_Manual_Activate_Rear_Wide_Angle_View,

	e_AVM_Message_Manual_Deactivate_Front_Wide_Angle_View,
	e_AVM_Message_Manual_Deactivate_Rear_Wide_Angle_View,
	e_AVM_Message_Manual_AVM_Off,
	
    e_AVM_Message_Invalid
} Enum_AVM_Message;



/*
 * ERROR CODE
 */
static const ECode NO_ERROR                          = 0;
static const ECode E_IOCTL_VIDIOC_REQBUFS_EXCEPTION  = 1;

//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman

#endif // __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_EVENT_DEFINE_H__
