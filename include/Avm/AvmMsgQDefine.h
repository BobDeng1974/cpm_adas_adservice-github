#ifndef AVM_MSGQ_DEFINE_H_
#define AVM_MSGQ_DEFINE_H_

#define  ADAS_MODULE_AVM    string("AVM")

enum eAVMEvent
{
    eAvm_SWITCH
};



enum eMessageType
{
	eMessageType_SwitchAVM,
	eMessageType_SwitchAVMView,
	eMessageType_SwitchGuideLine,
	eMessageType_SwitchCTA,
	eMessageType_UNKNOWN = 0x70000000
};



#endif /*AVM_MSGQ_DEFINE_H_*/
