
#ifndef __HARMAN_ADAS_APROJECT_GWMV2MH_PAS_PDCSENSOR_H__
#define __HARMAN_ADAS_APROJECT_GWMV2MH_PAS_PDCSENSOR_H__

#include "PDCServiceFord.h"
#include "PDCMsgDefineFord.h"

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
namespace Pas {

class PDCSensorBase;
class IPDCSensorIntfFord
{
	public:
	virtual ~IPDCSensorIntfFord(){};
	virtual int  iGetSenorState()=0;
	virtual void vSnsMsgTxt(int val)=0;
	virtual void vSnsMsgState(int val)=0;
	virtual void vSetSenorVal(int val)=0;
	virtual int  iGetSnsExtState()=0;
};

class PDCSensorHub
{
public:

	//Inner state from sns only on active state m_PDCDisp = true.
	enum ePDC_State{
		e_MISSING = 0,
		e_ACTIVE,
		e_INACTIVE,
		e_FAULT,
	};

	enum ePDCMsgTxt{
		e_All_Park_Sensors_Off =0,
		e_R_Snsrs_On_F_Snsrs_Off=1,
		e_R_Snsrs_Off_F_Snsrs_On=2,
		e_NotUsed3=3,
		e_NotUsed4=4,
		e_R_Snsrs_On_F_Snsrs_On=5,
		e_Park_Sys_Alternate_Mode=6,
		e_NotUsed7=7,
		e_R_Sns_Trlr_F_Sns_Blk=8,
		e_Fail_Mode_with_Chime=9,
		e_Fail_Mode_no_Chime=0xA,
		e_Not_Avail_Trlr_attchd=0xB,
		e_R_Sns_Inactive_Trlr_atch=0xC,
		e_R_Sns_Blk_F_Sns_ON=0xD,
		e_R_Sns_ON_F_Sns_Blk=0xE,
		e_All_Sns_Blk=0xF,
	}; //PDC_Stat: MISSING ACTIVE INACTIVE FAULT --> ONLY ON ACTIVE STATE -->PDCDISP = TRUE -->SHOW PDC VIEW

	//display state shall match to grpahic interfaces
	//max warn grpahic picture is 6 , so warn set to 6 values
	//put idle image and other state at fixed index , the number of distance png file is different

	enum eSns_DispState{
		e_LastState = -2,  //grpahic layer will not process ,in order to show defult by cfg file
		e_Inactive 	= -1,
		e_NoState   = 0,
		e_Blocked 	= 1,
		e_OnTrailer = 2,
		e_Idle 		= 3,
		e_Warn_1 	= 4,
		e_Warn_2 ,
		e_Warn_3 ,
		e_Warn_4 ,
		e_Warn_5 ,
		e_Warn_6 ,

		e_Sns_DispState_num ,
	};
	#define PDC_DISTANCE_RES_OFFSET (PDCSensorHub::e_Idle)

//the index of the value save in buffer
//to indicate png res, used by graphic ,same order as usr.cfg
//resouces to be displayed at same time should be coding at different group
	enum ePDCSensorPNG{
		e_FRONTLEFTCNTR,
		e_FRONTRIGHTCNTR,
		e_FRONTLEFTCRNR,
		e_FRONTRIGHTCRNR,

		e_SIDELEFT1,
		e_SIDERIGHT1,
		e_SIDELEFT2,
		e_SIDERIGHT2,

		e_SIDELEFT3,
		e_SIDERIGHT3,
		e_SIDELEFT4,
		e_SIDERIGHT4,

		e_REARLEFTCRNR,
		e_REARRIGHTCRNR,
		e_REARLEFTCNTR,
		e_REARRIGHTCNTR,

		e_EXTSTATEFRONT,
		e_EXTSTATEREAR,
		e_EXTSTATELEFT,
		e_EXTSTATERIGHT,

		e_CARSTATE,

		e_PDCPNGNUM,
	};
	enum ePDCSensorExtPNG{
		e_TARILERSTATE,
		e_BLKSTATE,
		e_PDCPNGExtNUM,
	};

	enum eSns_RearLogicSector{
		e_Rear_OL ,
		e_Rear_OR ,
		e_Rear_IL,
		e_Rear_IR ,
		e_Rear_SnsNum ,
	};
	enum eSns_FrontLogicSector{
		e_Front_OL ,
		e_Front_OR ,
		e_Front_IL,
		e_Front_IR ,
		e_Front_SnsNum ,
	};
	enum eSns_LeftLogicSector{
		e_Left_1 ,
		e_Left_2 ,
		e_Left_3 ,
		e_Left_4 ,
		e_Left_SnsNum ,
	};
	enum eSns_RightLogicSector{
		e_Right_1 ,
		e_Right_2 ,
		e_Right_3 ,
		e_Right_4 ,
		e_Right_SnsNum ,
	};
	enum eSns_LogicArea{
		e_Front_Area ,
		e_Rear_Area ,
		e_Left_Area ,
		e_Right_Area ,
		e_Area_Num ,
	};
	PDCSensorHub();
	~PDCSensorHub();
	void vSetPDCMsg(int sensor , int val);
	void vSetPDCTxt(int val);
	int* pGetPDCState();//stata buffer is kept in hub
	bool bIsActive() {return m_PDCDisp;};
	void SetPDCViewState(bool bPDCViewState);
	void ResetPDCGraphicState();
	static void vSetCarOutLineState(unsigned int iSnsId) {m_spCarOutlineState |= 1<<iSnsId;};
	static void vClrCarOutLineState(unsigned int iSnsId) {m_spCarOutlineState &= (~(1<<iSnsId));};
private:
	bool bOnSnsMsgTxt();
	bool bOnSnsMsgDistance();
	void vUpdateTxtToAllSensor(int val);
	void vUpdateAreaSnsExtState(IPDCSensorIntfFord** pSnsInf, int iArea, int iAreaSnsNum);
	void vSetAreaSnsState(IPDCSensorIntfFord** pSnsInf, int iArea, int iAreaSnsNum,int val);

	int m_PDCMsgTxt;
	ePDC_State m_PDC_Stat;
	bool m_PDCDisp; //report to hmi
	IPDCSensorIntfFord* m_pRearSns[e_Rear_SnsNum];
	IPDCSensorIntfFord* m_pFrontSns[e_Front_SnsNum];
	IPDCSensorIntfFord* m_pRightSns[e_Right_SnsNum];
	IPDCSensorIntfFord* m_pLeftSns[e_Left_SnsNum];
	int* m_pAreaExtState[e_Area_Num];//to check sensors in one area all normal or not. use bit mask
	static int m_spCarOutlineState; //to updated car outline state based on all the sensors
};
//==============================================================
//todo : support keep msg value even pdc is not on?
class PDCSensorBase
{
	public:
		PDCSensorBase(int* pStateLUT,int* pDispStateLUT,int* piWarnState, unsigned int uiSnsId);
		void vSetSnsState(int val);
		void vSetSnsStateVal(int val);//directly set state
		int iGetSnsState() {return *m_pWarnState;};
		int iGetSnsExtState() {return m_ExtState;};//when single sensor err , whole area show err
		int iGetMsgVal() 	{return m_MsgVal;};
		void vSetCarOutLineState() {PDCSensorHub::vSetCarOutLineState(m_SnsId);};
		void vClrCarOutLineState() {PDCSensorHub::vClrCarOutLineState(m_SnsId);};
		virtual ~PDCSensorBase();

		//the outside state of sensors
		enum eSns_State{
			e_Sns_On = 0,
			e_Trailer = 1,
			e_SnsBlocked = 2,
			e_Sns_Off    = 3,//ONLY DISP = FALSE
		};


	protected:
		int* m_pStateLUT;
		int* m_pDispStateLUT;
		//to indicate zone png val
		int* m_pWarnState;
		//to indicate blk and trailer png val
		//todo : after extstate back to normal,shall we use last distance val or reset and wait for new one
		int  m_ExtState;
		int  m_MsgVal;
		eSns_State m_eSnsState;
		unsigned int  m_SnsId;
};
//==============================================================


//state is apply to four rear sensor, only different on four sensor is zone number
//need add a matrix of grpahic files to the dispstates
class PDCRearSensor : public PDCSensorBase, public IPDCSensorIntfFord
{
public:
	PDCRearSensor(int* pStateLUT,int* pDispStateLUT,int* piWarnState, unsigned int uiSnsId);
	void vSnsMsgTxt(int val);
	void vSnsMsgState(int val);
	int iGetSenorState() {return *m_pWarnState;};
	void vSetSenorVal(int val){*m_pWarnState = val;};
	int  iGetSnsExtState(){return m_ExtState;};
} ;
//==============================================================
//state is apply to four front sensor
class PDCFrontSensor : public PDCSensorBase, public IPDCSensorIntfFord
{
public:
	PDCFrontSensor(int* pStateLUT,int* pDispStateLUT,int* piWarnState, unsigned int uiSnsId);
	void vSnsMsgTxt(int val);
	void vSnsMsgState(int val);
	int iGetSenorState() {return *m_pWarnState;};
	void vSetSenorVal(int val){*m_pWarnState = val;};
	int  iGetSnsExtState(){return m_ExtState;};
} ;


//==============================================================
//state is apply to eight side sensor
class PDCSideSensor : public PDCSensorBase, public IPDCSensorIntfFord
{
public:
	PDCSideSensor(int* pStateLUT,int* pDispStateLUT,int* piWarnState, unsigned int uiSnsId);
	void vSnsMsgTxt(int val);
	void vSnsMsgState(int val);
	int iGetSenorState() {return *m_pWarnState;};
	void vSetSenorVal(int val){*m_pWarnState = val;};
	int  iGetSnsExtState(){return m_ExtState;};
};

} // namespace Pas
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman

#endif // __HARMAN_ADAS_APROJECT_GWMV2MH_PAS_PDCSENSOR_H__