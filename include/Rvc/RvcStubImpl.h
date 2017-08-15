#ifndef RVC_STUB_IMPL_H_
#define  RVC_STUB_IMPL_H_

#include "ADASManager/RVC/ARvcBase.h"


using namespace std;
using namespace Harman::Adas::AFramework::ABase::ADASManager;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

class RvcStubImpl : public ARvcBase
{
public:
	RvcStubImpl(CameraHub* hub);
	virtual ~RvcStubImpl();

public:
	a_status  initialize();
              VOID       afterHandleMessageQueue();

              VOID      showCamera(const string& pData);

private:
		
};

}
}
}
}




#endif