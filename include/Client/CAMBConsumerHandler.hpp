/*********************************************************************
* Project         GWM V2
* (c) copyright   2016
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

#ifndef AMB_CONSUMER_HANDLER_HPP
#define AMB_CONSUMER_HANDLER_HPP

#include "TraceMacros.h"
//#include "AFoundation.h"


#include "v0/com/harman/amb/adas_types.hpp"

//using namespace std;
using namespace v0::com::harman::amb;
//using namespace Harman::Adas::AFramework::AFoundation;


namespace Harman 	{
namespace Adas 		{
namespace AProject 	{
namespace GWMV2MH 	{

class AMBConsumerHandler
{
    public:      
		AMBConsumerHandler();
		~AMBConsumerHandler();
    

		/**
		@brief initializing all variable and providing  interface to set RVVservicestub  pointer. 
		@param  RVCServiceStubImpl shared Pointer
		*/
		void InitializeAMBConsumerHandler();
 
		// ADAS CallBacks Start
		void CB_getFPAS_WorkSts_emAttribute(adas_types::FPAS_WorkSts_em value);

    private :      
        //bool m_bCameraMaxSpeed;
        //CContext *m_pobjContext;
        //void PostChangeInSpeedToPresCore(bool p_bIsMaxSpeed);
};

}
}
}
}


#endif

