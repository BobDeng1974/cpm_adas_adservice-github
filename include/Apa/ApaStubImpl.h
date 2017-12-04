#ifndef  _APA_STUB_IMPL_H_
#define  _APA_STUB_IMPL_H_

#include "ADASManager/APA/AApaBase.h"


using namespace std;
using namespace Harman::Adas::AFramework::ABase::ADASManager;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

class ApaStubImpl : public AApaBase
{
public:
	//APAStubImpl(CameraHub* hub);
	ApaStubImpl();
	virtual ~ApaStubImpl();

public:
	a_status initialize();
	VOID afterHandleMessageQueue();
	//VOID showCamera(const string& pData);

private:
		
};

}
}
}
}




#endif
