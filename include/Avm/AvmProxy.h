#ifndef AVM_STUB_IMPL_H_
#define AVM_STUB_IMPL_H_

#include "CAdasManagerGWMv2.h"
#include "AdasModuleCtrlImpl.h"
#include "AvmMsgQDefine.h"
#include "v0/com/harman/adas/AVMServiceStubImpl.hpp"


#if 0
using namespace std;
using namespace v0;
using namespace com;
using namespace harman;
using namespace adas;
#endif

using namespace std;
using namespace v0::com::harman::adas;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

class CAvmProxy : public AVMServiceStubImpl
{
public:
//	CAvmProxy();
	static CAvmProxy* getInstance();
	virtual ~CAvmProxy();

	a_status initialize();
	
	void SwitchAVMView(const std::shared_ptr<CommonAPI::ClientId> _client, ::v0::com::harman::adas::AVMBaseType::enAVMViewMode m_eAVMViewMode, SwitchAVMViewReply_t reply);

	void SwitchGuideline(const std::shared_ptr<CommonAPI::ClientId> _client, ::v0::com::harman::adas::AVMBaseType::enAVMGuideLineMode m_eAVMGuideLinewMode, SwitchGuidelineReply_t reply);

	void SwitchCTA(const std::shared_ptr<CommonAPI::ClientId> _client, ::v0::com::harman::adas::CTABaseType::enCTAWorkMode m_eCATMode, SwitchCTAReply_t reply);

	void SwitchAutoCalibrationAuto(const std::shared_ptr<CommonAPI::ClientId> _client, ::v0::com::harman::adas::AVMBaseType::enAutoCaliWorkModeAuto m_eAutoCaliMode, SwitchAutoCalibrationAutoReply_t reply);

	void SwitchAutoCalibrationManually(const std::shared_ptr<CommonAPI::ClientId> _client, ::v0::com::harman::adas::AVMBaseType::enAutoCaliWorkModeManu m_eAutoCaliMode, SwitchAutoCalibrationManuallyReply_t reply);

private:
	CAvmProxy();
private:
	
	static CAvmProxy* m_pAvmInstance;
	CAdasManagerGWMv2* m_pCAdasManagerGWMv2;		
};

}
}
}
}




#endif
