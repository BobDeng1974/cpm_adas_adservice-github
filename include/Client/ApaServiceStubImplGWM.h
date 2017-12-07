#ifndef APA_SERVICE_STUB_IMPL_GWM_H_
#define APA_SERVICE_STUB_IMPL_GWM_H_

#include "v0/com/harman/adas/APAServiceStubImpl.hpp"
#include "TraceMacros.h"

using namespace std;
using namespace v0::com::harman::adas;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

class ApaServiceStubImplGWM : public APAServiceStubImpl
{
public:
	static ApaServiceStubImplGWM* getInstance();
	virtual ~ApaServiceStubImplGWM();
	virtual void SwitchAPAView(const std::shared_ptr<CommonAPI::ClientId> _client,
		::v1::com::harman::adas::APABaseType::enAPAViewStatus m_eAPAViewStatus,
		SwitchAPAViewReply_t) override;

private:
	ApaServiceStubImplGWM();

private:
	static ApaServiceStubImplGWM* m_pInstance;
		
};

}
}
}
}

#endif
