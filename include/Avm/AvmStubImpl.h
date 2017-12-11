#ifndef __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_STUB_IMPL_H_
#define __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_STUB_IMPL_H_

#include "ADASManager/AVM/AAvmBase.h"
#include "TraceMacros.h"
#include "AvmMsgQDefine.h"
#include "AFoundation.h"
#include "AvmEventDefine.h"
#include "AvmTyepDefine.h"

#include "PriorityStateMachine/AvmPriorityStateMachine.h"
using namespace std;
using namespace Harman::Adas::AFramework::AFoundation;
using namespace Harman::Adas::AFramework::ABase::ADASManager;


namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {




class CAvmStubImpl : public CAvmBase
{
public:
	CAvmStubImpl();
	virtual ~CAvmStubImpl();

	a_status initialize();
    	VOID  afterHandleMessageQueue();
	VOID SwitchAVM(const string& pData);

private:
	CAvmPriorityStateMachine* m_pAvmPriorityStateMachine;
		
};


//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman





#endif //__HARMAN_ADAS_APROJECT_GWMV2MH_AVM_STUB_IMPL_H_