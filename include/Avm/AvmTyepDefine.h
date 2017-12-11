#ifndef __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_TYPE_DEFINE_H__
#define __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_TYPE_DEFINE_H__

#include "AvmEventDefine.h"

using namespace std;

//using Harman::Adas::AProject::GWMV2MH::AVM;


namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {


/*
 * define
 */
#define AUTO_ACTIVATE_ERROR_STATE					string("Auto_Activate_Error_State")
#define AUTO_ACTIVATE_TOP_VIEW						string("Auto_Activate_Top_View")
#define AUTO_ACTIVATE_D1_VIEW						string("Auto_Activate_D1_View")
#define AUTO_ACTIVATE_D2_VIEW						string("Auto_Activate_D2_View")
#define AUTO_ACTIVATE_D3_VIEW						string("Auto_Activate_D3_View")
#define AUTO_ACTIVATE_D4_VIEW						string("Auto_Activate_D4_View")
#define AUTO_ACTIVATE_D5_VIEW						string("Auto_Activate_D5_View")
#define AUTO_ACTIVATE_D6_VIEW						string("Auto_Activate_D6_View")
#define AUTO_ACTIVATE_D7_VIEW						string("Auto_Activate_D7_View")
#define AUTO_ACTIVATE_D8_VIEW						string("Auto_Activate_D8_View")
#define AUTO_ACTIVATE_FRONT_WIDE_ANGLE_VIEW			string("Auto_Activate_Front_Wide_Angle_View")
#define AUTO_ACTIVATE_REAR_WIDE_ANGLE_VIEW			string("Auto_Activate_Rear_Wide_Angle_View")

#define AUTO_DEACTIVATE_ERROR_STATE					string("Auto_Deactivate_Error_State")
#define AUTO_DEACTIVATE_TOP_VIEW					string("Auto_Deactivate_Top_View")
#define AUTO_DEACTIVATE_D1_VIEW						string("Auto_Deactivate_D1_View")
#define AUTO_DEACTIVATE_D2_VIEW						string("Auto_Deactivate_D2_View")
#define AUTO_DEACTIVATE_D3_VIEW						string("Auto_Deactivate_D3_View")
#define AUTO_DEACTIVATE_D4_VIEW						string("Auto_Deactivate_D4_View")
#define AUTO_DEACTIVATE_D5_VIEW						string("Auto_Deactivate_D5_View")
#define AUTO_DEACTIVATE_D6_VIEW						string("Auto_Deactivate_D6_View")
#define AUTO_DEACTIVATE_D7_VIEW						string("Auto_Deactivate_D7_View")
#define AUTO_DEACTIVATE_D8_VIEW						string("Auto_Deactivate_D8_View")
#define AUTO_DEACTIVATE_FRONT_WIDE_ANGLE_VIEW		string("Auto_Deactivate_Front_Wide_Angle_View")
#define AUTO_DEACTIVATE_REAR_WIDE_ANGLE_VIEW		string("Auto_Deactivate_Rear_Wide_Angle_View")
#define AUTO_AVM_OFF								string("Auto_AVM_Off")

#define MANUAL_ACTIVATE_TOP_VIEW					string("Manual_Activate_Top_View")
#define MANUAL_ACTIVATE_D1_VIEW						string("Manual_Activate_D1_View")
#define MANUAL_ACTIVATE_D2_VIEW						string("Manual_Activate_D2_View")
#define MANUAL_ACTIVATE_D3_VIEW						string("Manual_Activate_D3_View")
#define MANUAL_ACTIVATE_D4_VIEW						string("Manual_Activate_D4_View")
#define MANUAL_ACTIVATE_D5_VIEW						string("Manual_Activate_D5_View")
#define MANUAL_ACTIVATE_D6_VIEW						string("Manual_Activate_D6_View")
#define MANUAL_ACTIVATE_D7_VIEW						string("Manual_Activate_D7_View")
#define MANUAL_ACTIVATE_D8_VIEW						string("Manual_Activate_D8_View")
#define MANUAL_ACTIVATE_FRONT_WIDE_ANGLE_VIEW		string("Manual_Activate_Front_Wide_Angle_View")
#define MANUAL_ACTIVATE_REAR_WIDE_ANGLE_VIEW		string("Manual_Activate_Rear_Wide_Angle_View")

#define MANUAL_DEACTIVATE_FRONT_WIDE_ANGLE_VIEW		string("Manual_Deactivate_Front_Wide_Angle_View")
#define MANUAL_DEACTIVATE_REAR_WIDE_ANGLE_VIEW		string("Manual_Deactivate_Rear_Wide_Angle_View")
#define MANUAL_AVM_OFF								string("Manual_AVM_Off")


/*
 * struct
 */

typedef struct _AVM_CMDAttribute
{
   const char*					sAvmCMD;
   Enum_AVM_Message		eAvmStateMachineEvent;
}Struct_AVM_CMDAttribute;

#if 0

/*
 * state
 */
typedef enum _AVM_State{
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
} Enum_AVMState;

/*
 * State Trigger Event (message type used by AVM State Machine)
 */
typedef enum _AVM_State_Message
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
} Enum_AVM_State_Message;



/*
 * ERROR CODE
 */
static const ECode NO_ERROR                          = 0;
static const ECode E_IOCTL_VIDIOC_REQBUFS_EXCEPTION  = 1;
#endif 
//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman


#endif // __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_TYPE_DEFINE_H__
