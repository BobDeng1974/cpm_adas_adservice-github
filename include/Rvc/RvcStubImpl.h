#ifndef RVC_STUB_IMPL_H_
#define  RVC_STUB_IMPL_H_

#include "ADASManager/RVC/ARvcBase.h"
#include "TraceMacros.h"
#include "AGraphic.h"
#include "RvcGuideLine.h"

using namespace std;
using namespace Harman::Adas::AFramework::AFoundation;
using namespace Harman::Adas::AFramework::AGraphic;
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
	virtual a_status   initialize();
    VOID  afterHandleMessageQueue();

    VOID  showCamera(const string& pData);
    VOID  hideCamera(const string& pData);   

private:
	RvcGuideLine* m_pRvcGLine;
		
};

}
}
}
}




#endif
