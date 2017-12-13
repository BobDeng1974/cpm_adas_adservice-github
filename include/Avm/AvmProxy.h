#ifndef __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_PROXY_H_
#define __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_PROXY_H_

#include "CAdasManagerGWMv2.h"
#include "AdasModuleCtrlImpl.h"
#include "AvmMsgQDefine.h"
#include "AvmTyepDefine.h"
#include "v0/com/harman/adas/AVMServiceStubImpl.hpp"


using namespace std;
using namespace v0::com::harman::adas;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {


class CAvmProxy : public AVMServiceStubImpl
{
public:

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

//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman



#endif //__HARMAN_ADAS_APROJECT_GWMV2MH_AVM_PROXY_H_