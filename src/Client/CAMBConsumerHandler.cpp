/*********************************************************************
* Project         GWM V2
* (c) copyright   2017
* Company         Harman International
*                 All rights reserved
*
*Secrecy Level    STRICTLY CONFIDENTIAL
*********************************************************************/
/**
* @file            AMBConsumerHandler.cpp
* @ingroup         ADAS
* @author          
* @brief           AMBConsumerHandler Consumes events from AMB and routes to required module(RVC,APA and VPA)
*                  based on the events it received.
*                  
*/
#include"CAMBConsumerHandler.hpp"
//#error "111111111"
#include "CAdasManagerGWMv2.h"
#include "ApaMsgQDefine.h"


using namespace Harman::Adas::AFramework::AFoundation;

namespace Harman 	{
namespace Adas 		{
namespace AProject 	{
namespace GWMV2MH 	{

AMBConsumerHandler:: AMBConsumerHandler()
{
    //m_bCameraMaxSpeed = false;
    //m_pobjContext = NULL;
    //LOG_INFO(LOG_COMMON,"AMBConsumerHandler constructor");
}


AMBConsumerHandler::~AMBConsumerHandler()
{
    
}


/**
    @brief initializing all variable and providing  interface to set RVVservicestub  pointer. 
    @param  RVCServiceStubImpl shared Pointer
 */
void AMBConsumerHandler::InitializeAMBConsumerHandler()
{

}

// ============================================ADAS SECTION START===============================================================//

void AMBConsumerHandler::CB_getFPAS_WorkSts_emAttribute(adas_types::FPAS_WorkSts_em value)
{
	if(adas_types::FPAS_WorkSts_em::EM_Active == value)
	{
		ALOGI("APA_WorkSts : value = %d[Active]\n", value);
		CAdasManagerGWMv2::getInstance()->pushMessage(new MessageForQueue(
			AdasModuleCtrlImpl::eModuleType_APA,
			eAPA_ACTIVE,
			"APA active"));
	}
	else if(adas_types::FPAS_WorkSts_em::EM_Failed == value)
	{
		ALOGI("APA_WorkSts : value = %d[Deactive]\n", value);
		CAdasManagerGWMv2::getInstance()->pushMessage(new MessageForQueue(
			AdasModuleCtrlImpl::eModuleType_APA,
			eAPA_DEACTIVE,
			"APA deactive"));
	}

}

} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman


