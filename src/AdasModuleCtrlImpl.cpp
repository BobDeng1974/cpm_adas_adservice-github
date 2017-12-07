#include <CommonAPI/CommonAPI.hpp>

#include "AdasModuleCtrlImpl.h"
#include "Rvc/RvcStubImpl.h"
#include "Rvc/RvcMsgQDefine.h"
#include "Avm/AvmStubImpl.h"
#include "Avm/AvmMsgQDefine.h"
#include "Apa/ApaStubImpl.h"
#include "Apa/ApaMsgQDefine.h"

#include "ADASManager/Camera/CameraHub.h"
#include "Camera/CameraHubGWMv2.h"

using Harman::Adas::AProject::GWMV2MH::Camera::CameraHubGWMv2;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

AdasModuleCtrlImpl* AdasModuleCtrlImpl::m_pInstance = NULL;

AdasModuleCtrlImpl* AdasModuleCtrlImpl::getInstance()
{
   if(m_pInstance == NULL)
   {
      m_pInstance = new AdasModuleCtrlImpl();
   }
   return m_pInstance;
}

VOID AdasModuleCtrlImpl::deInstance()
{
   if(m_pInstance != NULL)
   {
      delete m_pInstance;
      m_pInstance = NULL;
   }
}

AdasModuleCtrlImpl::AdasModuleCtrlImpl()
{

}

AdasModuleCtrlImpl::~AdasModuleCtrlImpl()
{

}

a_status AdasModuleCtrlImpl::CreateModules(string moduleTab[], BYTE cameraFlag)
{
     CameraHub* camerahub = NULL;
     camerahub = CameraHubGWMv2::GetInstanceC11(cameraFlag);
     for(int index=0; moduleTab[index] != STRING_NULL; ++index)
    {
        if(moduleTab[index] == ADAS_MODULE_RVC)
        {
            m_mModuleMap.insert(makePair((UInt32)eModuleType_RVC, static_cast<ModuleBase*>(new RvcStubImpl(camerahub))));
            ALOGI("CreateModules [%s]\n", moduleTab[index].c_str());
        }
        else if(moduleTab[index] == ADAS_MODULE_AVM)
        {
            m_mModuleMap.insert(makePair((UInt32)eModuleType_AVM, static_cast<ModuleBase*>(new CAvmStubImpl())));
            ALOGI("CreateModules [%s]\n", moduleTab[index].c_str());

        }		
        else if(moduleTab[index] == ADAS_MODULE_APA)
        {
            m_mModuleMap.insert(makePair((UInt32)eModuleType_APA, static_cast<ModuleBase*>(new ApaStubImpl())));
            ALOGI("CreateModules [%s]\n", moduleTab[index].c_str());
        }
        #if 0
        else if(moduleTab[index] == ADAS_MODULE_SVC)
        {

        }
        else if(moduleTab[index] == ADAS_MODULE_AVM)
        {

        }
        else if(moduleTab[index] == ADAS_MODULE_PAS)
        {

        }
        else if(moduleTab[index]  == ADAS_MODULE_COMMON)
        {}
        #endif
    }
    return OK;
}

a_status AdasModuleCtrlImpl::ModuleInit()
{
    ALOGD("ModuleInit\n");
    initialize();
    return OK;
}

a_status AdasModuleCtrlImpl::InitializeAMBProxy()
{
    ALOGD("InitializeAMBProxy\n");
	a_status retCode = OK;

    /*
	 * create the runtime
	 */
	std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
	do
    {
        if(!runtime)
        {
            ALOGD("ADAS InitializeAMBProxy Runtime failed\n");
            retCode = NO_INIT;
            break;
        }   
        else
        {
			std::string domain = "local";
			
			// create the AdasService proxy
			std::string adasProxy_req_connection = "adas";
			std::string adasProxy_req_instance = "AutomotiveMessageBrokerProvider.adasInst0";
			
            //Register the attribute only if AMB is configured
            mAMBProxy = runtime->buildProxy<v0::com::harman::amb::adasProxy>(domain, adasProxy_req_instance, adasProxy_req_connection);
            ALOGD(" start Runtime instance for ambProxy\n");
            if(!mAMBProxy)
            {
                ALOGD(" Getting Runtime instance for ambProxy is failed\n");
                retCode = NO_INIT;
                break;
            } 
            else
            {
                ALOGD("Registering  to ambProxy Listener success!\n");
                //Registering function to vpa AMB interface  for notifying  Availability
                mAMBProxy->getProxyStatusEvent().subscribe(std::bind(&AdasModuleCtrlImpl::ADASProxyAvilabilityCB, this, std::placeholders::_1));
            } 

            ALOGD("end Runtime instance for ambProxy!\n");
        }
    }while(0);
	
    return retCode;
}

void AdasModuleCtrlImpl::ADASProxyAvilabilityCB(CommonAPI::AvailabilityStatus status)
{
	a_status retCode = OK;
	if(status == CommonAPI::AvailabilityStatus::AVAILABLE)
    {
        ALOGD("ADAS AMB Proxy is Avaliabel\n") ;

        retCode = SubScribeToADASEvents();
        if(NO_INIT == retCode)
        {
            ALOGD("Can't able to subscribe to ADAS proxy\n") ;
        }
    }
    else
    {
        ALOGD("ADAS AMB Proxy is Not Avaliabel\n") ;
        retCode = OK;
    }
}

a_status AdasModuleCtrlImpl::SubScribeToADASEvents()
{
    a_status l_status = NO_INIT;
    if(nullptr != mAMBProxy)
    {
        //Subscribing to GearPostionNotify attribute
        ALOGD("adas subscribing to amb Attribute\n");
        
        //Register only if AMB is configured
        mAMBProxy->getFPAS_WorkSts_emAttribute().getChangedEvent().subscribe(std::bind(&AMBConsumerHandler::CB_getFPAS_WorkSts_emAttribute, &mAMBConsumerHandler, std::placeholders::_1));
		l_status = OK;
	}
	
	return l_status;
}



}//GWMV2MH
}//AProject
}//Adas
}//Harman
