
#include "Pas/PDCServiceFord.h"
#include "Pas/PDCMsgDefineFord.h"

#include "ADASManager/PAS/GraphicCore/GraphicVDT.h"

#include "CMessage.h"
#include <stdlib.h>
#include <stdio.h>

using Harman::Adas::AFramework::AFoundation::tagBaseMessage;
using Harman::Adas::AFramework::ABase::ADASManager::GraphicVDT;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
namespace Pas {

PDCServiceFord* PDCServiceFord::m_pInstance=NULL;

PDCServiceFord* PDCServiceFord::getInstance()
{
   if(m_pInstance == NULL)
   {
      m_pInstance = new PDCServiceFord();
   }
   return m_pInstance;
}

void PDCServiceFord::delInstance()
{
   if(m_pInstance != NULL)
   {
      delete m_pInstance;
      m_pInstance = NULL;
   }
}

PDCServiceFord::~PDCServiceFord()
{
   delete m_PDCSensorHub;
}


PDCServiceFord::PDCServiceFord()
: CPDCService("PDCServiceFord")
{
	m_PDC_Cfg = true;
	m_bLastPDCDisp = false;//set by EOL / multi combination
	memset(m_PDCSensorMsg,0,sizeof(m_PDCSensorMsg));
	for(int i=0;i<ePDCSIGNUM;i++)
	{
		m_PDCSensorMsg[i][0] = i;
	}
	m_PDCSensorHub = new PDCSensorHub();
	m_cVDTLuanchControl =0;

}

BOOLEAN PDCServiceFord::initialize(string sServiceName)
{
	return TRUE;
}

bool PDCServiceFord::bGetPDCState()
{
	return m_PDCSensorHub->bIsActive();
};


void PDCServiceFord::vInitialize(CMessageQueue* pMsgQueue, GraphicVPAFord* pPDCGraphicFord) {
	setMsgQueue(pMsgQueue);
	m_pVPAGraphicFord = pPDCGraphicFord;
	PDCA_LOG_INFO("PDCServiceFord initialization done! ") ;
	//setPDCStatusAttribute(v1::com::harman::ParkAssist::PDCBaseType::enPDCStatus::e_PDC_OFF);
	//m_pPDCGraphicFord->init(800,480);
	//m_pPDCGraphicFord->bSetPDCSize(152,228);
	//m_pPDCGraphicFord->bSetPDCLeftBottom(100,100);
#ifndef PRESCORE_SUPPORT
	start();
#endif
}

void PDCServiceFord::vUpdateSize(void* pData) {
	m_pVPAGraphicFord->bSetPDCSize(((int*)pData)[0],((int*)pData)[1]);
}

void PDCServiceFord::vSetDayMode() {
	m_pVPAGraphicFord->vSetDayMode();
}
void PDCServiceFord::vSetNightMode() {
	m_pVPAGraphicFord->vSetNightMode();
}

void PDCServiceFord::vUpdatePosition(void* pData) {
	m_pVPAGraphicFord->bSetPDCLeftBottom(((int*)pData)[0],((int*)pData)[1]);
}

void PDCServiceFord::vUpdateDistance(void* pData) {

}

void PDCServiceFord::beforeHandleMsgQueue() {

}

void PDCServiceFord::afterHandleMsgQueue() {

}
tagBaseMessage s_PDCMsg[100];
void PDCServiceFord::pushPDCMsg(const eFordPDCMsgType eMsgType,const int iMsgId, int* data)
{
	PDCA_LOG_INFO("pDCServiceFord::pushPDCMsg: eMsgType[%d] -  iMsgId[%d] - Value[%d] \n",(int)eMsgType,iMsgId,data[0]) ;
	//save the message in static buffer
	m_PDCSensorMsg[iMsgId][1]=data[0];
	s_PDCMsg[iMsgId]._uiType=(int)eMsgType;
	s_PDCMsg[iMsgId]._pData=(char*)&m_PDCSensorMsg[iMsgId];//buffer is static
#ifndef PRESCORE_SUPPORT
	pushMessage(s_PDCMsg[iMsgId], 2);
#else
//replace queue to process directly
	//dispatchEvent(eMsgType, (void*) s_PDCMsg[iMsgId]._pData);

	string str = std::to_string(*data);

	dispatchEvent(eMsgType, str);
#endif

}

//hmi request to close view only when full screen is possible
//1 rear gear - samll view ; 2 PDC txt - full view can active it
void PDCServiceFord::SetPDCViewState(bool bPDCViewState)
{
	if(m_bLastPDCDisp == bPDCViewState)
	{
		PDCA_LOG_INFO("exit on not valid show/hide requet, PDCServiceFord::SetPDCViewState %d\n",bPDCViewState);
		return;
	}

	m_PDCSensorHub->SetPDCViewState(bPDCViewState);

	if(m_PDCSensorHub->bIsActive()) m_pVPAGraphicFord->pause();
	m_pVPAGraphicFord->bSetGraphicPDCState(m_PDCSensorHub->pGetPDCState());
	if(bPDCViewState)
	{
		m_pVPAGraphicFord->resume();
		PDCA_LOG_INFO("PDCServiceFord graphic on! ") ;
	}
	else
	{
		//m_pVPAGraphicFord->pause();
		PDCA_LOG_INFO("PDCServiceFord graphic off! ") ;
	}
};

int s_cLastTxtVal =-1;
 void PDCServiceFord::onABMPDCMsg(const char* data)
 {
 	//get msg pData
 	//int* pdata = &data;

	std::string::size_type sz;
	int i_dec = std::stoi(string(data), &sz);
	int pdata[2] = {0, i_dec};

 	PDCA_LOG_INFO("PDCServiceFord::onABMPDCMsg: %d\n",pdata[1]);

	if(s_cLastTxtVal != pdata[1])
	{
		s_cLastTxtVal = pdata[1];
	}
	else
	{
		//dont return for a Non-CAN rqeust can hide view too
		PDCA_LOG_INFO("exit on repeat PDCTxt val, PDCServiceFord::onABMPDCMsg: %d\n",pdata[1]);
	}

	//if(m_PDCDisp)//pdcdisp is a dynamic condition result from msg txt
	m_PDCSensorHub->vSetPDCTxt((int) pdata[1]);

	if(m_bLastPDCDisp != m_PDCSensorHub->bIsActive())
	{
		m_bLastPDCDisp = m_PDCSensorHub->bIsActive();
	}
	else if(m_bLastPDCDisp == false)
	{
		PDCA_LOG_INFO("exit on repeat off requet, PDCServiceFord::onABMPDCMsg: %d\n",pdata[1]);
		return;
	}

	//check  if sns is still active
	//if(m_PDCSensorHub->bIsActive())

	//printf(" [%s, %d] %d\n", __FUNCTION__, __LINE__, m_PDCSensorHub->bIsActive());
	if(m_PDCSensorHub->bIsActive()) m_pVPAGraphicFord->pause();
	m_pVPAGraphicFord->bSetGraphicPDCState(m_PDCSensorHub->pGetPDCState());
	//printf(" [%s, %d] %d\n", __FUNCTION__, __LINE__, m_PDCSensorHub->bIsActive());
	//update PDC state
	#if 1
	if(m_PDCSensorHub->bIsActive())
	{
		m_pVPAGraphicFord->resume();
		PDCA_LOG_INFO("resume PDCServiceFord::onABMPDCMsg : %d\n",pdata[1]);
		//setPDCStatusAttribute(v1::com::harman::ParkAssist::PDCBaseType::enPDCStatus::e_PDC_ON);
	}
	else
	{
		//auto hide guide line on PDC is not request any more
		m_pVPAGraphicFord->bSetVDTDisable();
		PDCA_LOG_INFO("pause PDCServiceFord::onABMPDCMsg : %d\n",pdata[1]);
		//setPDCStatusAttribute(v1::com::harman::ParkAssist::PDCBaseType::enPDCStatus::e_PDC_OFF);
	}
	#endif
}

void PDCServiceFord::vResetPDCGraphicState()
{
	if(!m_PDCSensorHub->bIsActive())
	{
		PDCA_LOG_INFO("received ResetPDCGraphicState reqeust but PDC is not actived\n");
		return;
	}

	m_PDCSensorHub->ResetPDCGraphicState();

	m_pVPAGraphicFord->pause();
	m_pVPAGraphicFord->bSetGraphicPDCState(m_PDCSensorHub->pGetPDCState());
	m_pVPAGraphicFord->resume();

}

void PDCServiceFord::onSensorPosition(const char* data)
{
	//int* pdata = (int* )data;
	std::string::size_type sz;
	int i_dec = std::stoi(string(data), &sz);
	int pdata[2] = {0, i_dec};

	if(pdata[0]>(int)ePDCSIGNUM)
	{
		PDCA_LOG_INFO("PDCServiceFord::onSensorPosition exceed: %d - %d\n",pdata[0],pdata[1]);
	}

    //check current state to all sersor
    m_PDCSensorHub->vSetPDCMsg(pdata[0],pdata[1]);//adpt graphic lib data, todo add more png index and to match
	if(!m_PDCSensorHub->bIsActive())
	{
		PDCA_LOG_INFO("received distance val but PDC is not actived: %d - %d\n",pdata[0],pdata[1]);
		return;
	}
	m_bLastPDCDisp = true;

	//int* pdcStauts = iPDCState;
     /*PDCL_LOG_INFO("PDCServiceFord::onSensorPosition %d%d%d%d-%d%d%d%d-%d%d%d%d-%d%d%d%d-%d!\n", \
        pdcStauts[0],pdcStauts[1],pdcStauts[2],pdcStauts[3], \
        pdcStauts[4],pdcStauts[5],pdcStauts[6],pdcStauts[7], \
        pdcStauts[8],pdcStauts[9],pdcStauts[10],pdcStauts[11], \
        pdcStauts[12],pdcStauts[13],pdcStauts[14],pdcStauts[15],\
        pdcStauts[16]);*/

	//table to graphic lib side must algin to the usr.cfg
	//the trailer and other specil png to be added

	m_pVPAGraphicFord->pause();
	m_pVPAGraphicFord->bSetGraphicPDCState(m_PDCSensorHub->pGetPDCState());
	m_pVPAGraphicFord->resume();
}

int s_cLastCMDVal =-1;
void PDCServiceFord::onGuideLineCmd(const char* data)
{
//get msg pData
 	//int* pdata = (int*)data;
 	std::string::size_type sz;
	int i_dec = std::stoi(string(data), &sz);
	int pdata[2] = {0, i_dec};

 	PDCA_LOG_INFO("PDCServiceFord::onGuideLineCmd: %d\n",pdata[1]);

	if(s_cLastCMDVal != pdata[1])
	{
		s_cLastCMDVal = pdata[1];
	}
	else
	{
		//dont return for a Non-CAN rqeust can hide view too
		PDCA_LOG_INFO("repeat GuideLineCmd val, PDCServiceFord::onGuideLineCmd: %d\n",pdata[1]);
	}
	//m_pVPAGraphicFord->bSetVDTState(pdata[1]);
	 if((0x7!=m_cVDTLuanchControl)&&(0xF!=m_cVDTLuanchControl))
	{
		PDCA_LOG_INFO("exit on GuideLine not launched for parameter is not ready [%d]\n",m_cVDTLuanchControl);
		return;
	}
	if((eGUIDELINETXT_ON == (eFordGuideLineMsg)pdata[1])&& m_PDCSensorHub->bIsActive())
	{
		m_pVPAGraphicFord->bSetVDTEnable();
	}
	else
	{
		m_pVPAGraphicFord->bSetVDTDisable();
	}
}
/*
the PrkAidDrvDir_D_Stat is now going to indicate the turning and driving direction with the signals.
This is again going to be covered in the new v1.3 SPSS but here is a summary of what is in that new SPSS:

1	ForwardNegative will show driving lines extending toward the front and left side of the vehicle
2	ForwardPositive will show driving lines extending toward the front and right side of the vehicle
3	BackwardNegative will show driving lines extending toward the rear and left side of the vehicle
4	BackwardPositive will show driving lines extending toward the rear and right side of the vehicle

My understanding is that the point of tangency will not vary dynamically,
for the example case below it would always be the right rear POT and the left front POT and they are fixed.
The thing that varies based on steering wheel angle is the point you have circled in red (you called it the ??quad circle??)
CAN sig    <---> Line tended     <----> POT
FrtNeg           Frt-Left		        bottom left(long left)   +top right(short right)
FrtPos           Frt-Right		        top left   (short left)  +bottom right(long right)
BakNeg           Rear-Left		        top left   (long left)   +bottom right(short right)
BakPos           Rear-Right		        bottom left(short left)  +top right(long right)

*short radius is always 1/4 cycle
*the center of the cycle changes

table of forward & rearward , positive & negative , radius , cycle point
	       FN    FP    BN    BP
short R
long  R

*/

void PDCServiceFord::onGuideLineRadius(const char* data)
{
	//int* pdata = (int*)data;
	std::string::size_type sz;
	int i_dec = std::stoi(string(data), &sz);
	int pdata[2] = {0, i_dec};

	if(pdata[0]>(int)ePDCSIGNUM)
	{
		PDCA_LOG_INFO("PDCServiceFord::onGuideLineRadius exceed: %d - %d\n",pdata[0],pdata[1]);
	}

    //check current state to all sersor
    int msgID = pdata[0];
    int msgVAL = pdata[1];
    static eFordGuideLineDriState vdtDir = eDIRNOTKNOW;
    static int vdtStatus=0;
    static int iDriveDir = 0;
    static int shortRadius=0;
    static int longRadius=0;
	//if CAN send left and right radius ,need to transfer to short and long radius
	static int leftRadius=0;
    static int rightRadius=0;

    PDCA_LOG_INFO("onGuideLineRadius :msgID[%d] msgVAL[%d]\n",msgID,msgVAL);
	switch (msgID)
	{
		case /*PDCServiceFord::*/eGUIDELINERADILEFT:
			leftRadius = msgVAL;
			m_cVDTLuanchControl |= 0x1;
			break;
		case /*PDCServiceFord::*/eGUIDELINERADIRIGHT:
			rightRadius = msgVAL;
			m_cVDTLuanchControl |= 0x2;
			break;
		case /*PDCServiceFord::*/eGUIDELINEDRVDRI:
			vdtDir = (eFordGuideLineDriState)msgVAL;
			if((eFPOSITIVE == vdtDir)||(eFNEGATIVE == vdtDir))
			{
				iDriveDir = GraphicVDT::eForward;
			}
			else if((eBPOSITIVE == vdtDir)||(eBNEGATIVE == vdtDir))
			{
				iDriveDir = GraphicVDT::eRearward;
			}
			else
			{
				break;
			}

			if((eFPOSITIVE == vdtDir)||(eBPOSITIVE == vdtDir))
			{
				vdtStatus = GraphicVDT::ePositive;
			}
			else if((eFNEGATIVE == vdtDir)||(eBNEGATIVE == vdtDir))
			{
				vdtStatus = GraphicVDT::eNegative;
			}

			m_cVDTLuanchControl |= 0x4;
			break;
		default:
			PDCA_LOG_INFO("onGuideLineRadius err :msgID[%d] msgVAL[%d]\n",msgID,msgVAL);
	}
    PDCA_LOG_INFO("onGuideLineRadius :m_cVDTLuanchControl[%d]\n",m_cVDTLuanchControl);
	if(0x7==m_cVDTLuanchControl)
	{
		PDCA_LOG_INFO("GuideLine parameter all ready\n");
		if((eGUIDELINETXT_ON == (eFordGuideLineMsg)s_cLastCMDVal)
		&&m_PDCSensorHub->bIsActive())
		{
			m_pVPAGraphicFord->bSetVDTEnable();
			PDCA_LOG_INFO("GuideLine launched for parameter ready and VDT was request to show\n");
		}
		m_cVDTLuanchControl = 0xF;
	}
	else if(0xF == m_cVDTLuanchControl)
	{
		;
	}
	else
	{
		PDCA_LOG_INFO("GuideLine not launched for parameter is not ready [%d]\n",m_cVDTLuanchControl);
		return;
	}

	//transfer left/right Radius to short/long Radius
	if((eFNEGATIVE == vdtDir)||(eBNEGATIVE == vdtDir))
	{
	    if(leftRadius>=rightRadius)
	    {
			PDCA_LOG_INFO("onGuideLineRadius err :leftR[%d] shall be shorter than rightR[%d] on dir[%d] \n",leftRadius,rightRadius,vdtDir);
			longRadius = leftRadius;
			shortRadius= rightRadius;
		}
		else
		{
			//PDCA_LOG_INFO("onGuideLineRadius  :leftR[%d]rightR[%d] on dir[%d] \n",leftRadius,rightRadius,vdtDir);
			longRadius = rightRadius;
			shortRadius= leftRadius;
		}
	}
	else if((eFPOSITIVE == vdtDir)||(eBPOSITIVE == vdtDir))
	{
	    if(rightRadius>=leftRadius)
	    {
			PDCA_LOG_INFO("onGuideLineRadius err :rightR[%d] shall be shorter than leftR[%d] on dir[%d] \n",rightRadius,leftRadius,vdtDir);
			longRadius = rightRadius;
			shortRadius= leftRadius;
		}
		else
		{
			//PDCA_LOG_INFO("onGuideLineRadius  :leftR[%d]rightR[%d] on dir[%d] \n",leftRadius,rightRadius,vdtDir);
			longRadius = leftRadius;
			shortRadius= rightRadius;
		}

	}
	else
	{
		PDCA_LOG_INFO("onGuideLineRadius left[%d] right[%d]on dir[%d]\n",leftRadius,rightRadius,vdtDir);
	}
	PDCA_LOG_INFO("onGuideLineRadius  :shortRadius[%d]longRadius[%d] on dir[%d] \n",shortRadius,longRadius,vdtDir);
    if((shortRadius==0)&&(longRadius==0))
	{
		PDCA_LOG_INFO("onGuideLineRadius left[0] right[0]\n");
	}

	printf("	 [%s, %d] VDTState is ===%d, %d, %d, %d===\n", __FUNCTION__, __LINE__, shortRadius);
	m_pVPAGraphicFord->bSetVDTState(iDriveDir,vdtStatus,shortRadius,longRadius);
}

//---------------------------------PDCServiceFord msg handler--------------------------------------------------
// BEGIN_DISPATCH(PDCServiceFord)

// 	DISPATCH_EVENT(eSENSORTXT, onABMPDCMsg)
// 	DISPATCH_EVENT(eSENSORDISTANCE, onSensorPosition)
// 	DISPATCH_EVENT(eGUIDELINECMD, onGuideLineCmd)
// 	DISPATCH_EVENT(eGUIDELINERADISTATE, onGuideLineRadius)

// END_DISPATCH

VOID PDCServiceFord::dispatchEvent(UInt32 uiEventID, const string& pData)
{
	switch(uiEventID)
	{
		case eSENSORTXT:
			onABMPDCMsg(pData.c_str());
			break;
		case eSENSORDISTANCE:
			onSensorPosition(pData.c_str());
			break;
		case eGUIDELINECMD:
			onGuideLineCmd(pData.c_str());
			break;
		case eGUIDELINERADISTATE:
			onGuideLineRadius(pData.c_str());
			break;
		default:
			break;
	}
	return;
}

void PDCServiceFord::vSyncLayers() {

}

} // namespace Pas
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman