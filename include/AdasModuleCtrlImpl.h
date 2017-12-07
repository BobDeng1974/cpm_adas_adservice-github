#ifndef ADAS_MODULE_CTRL_IMPL_H_
#define ADAS_MODULE_CTRL_IMPL_H_

#include "v0/com/harman/amb/adas.hpp"
#include "v0/com/harman/amb/adasProxy.hpp"


#include "ADASManager/AdasModuleCtrl.h"
#include "TraceMacros.h"

#include "CAMBConsumerHandler.hpp"

using namespace Harman::Adas::AFramework::AFoundation;

using namespace Harman::Adas::AFramework::ABase::ADASManager;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

class AdasModuleCtrlImpl : public AdasModuleCtrl
{
public:
    enum eModuleType
    {
        eModuleType_RVC,
        eModuleType_SVC,
        eModuleType_AVM,
        eModuleType_PAS,
        eModuleType_APA,
        eModuleType_COMMON,

        eModuleType_UNKNOWN = 0x70000000
    };
    
public:
    static AdasModuleCtrlImpl*   getInstance();
    static VOID             deInstance();
    virtual ~AdasModuleCtrlImpl();

    a_status CreateModules(string moduleTab[], BYTE cameraFlag);
    a_status ModuleInit();
    a_status InitializeAMBProxy();
	a_status SubScribeToADASEvents();
	void ADASProxyAvilabilityCB(CommonAPI::AvailabilityStatus status);

protected:
    AdasModuleCtrlImpl();

private:

    static AdasModuleCtrlImpl* m_pInstance;

private:
    //std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<v0::com::harman::amb::adasProxy<>> mAMBProxy;
    AMBConsumerHandler mAMBConsumerHandler;
};

}//GWMV2MH
}//AProject
}//Adas
}//Harman


#endif