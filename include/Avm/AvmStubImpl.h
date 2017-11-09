#ifndef AVM_STUB_IMPL_H_
#define AVM_STUB_IMPL_H_

#include "ADASManager/AVM/AAvmBase.h"
#include "TraceMacros.h"
#include "AvmMsgQDefine.h"
#include "AFoundation.h"

using namespace std;
using namespace Harman::Adas::AFramework::AFoundation;
using namespace Harman::Adas::AFramework::ABase::ADASManager;


namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {



class CAvmStubImpl : public CAvmBase
{
public:
	CAvmStubImpl();
	virtual ~CAvmStubImpl();

	a_status initialize();
    	VOID  afterHandleMessageQueue();
	VOID SwitchAVM(const string& pData);

private:
		
};

}
}
}
}




#endif
