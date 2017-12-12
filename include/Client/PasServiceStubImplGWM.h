
#ifndef __HARMAN_ADAS_APROJECT_GWMV2MH_CLIENT_PASSERVICESTUBIMPLGWM_H__
#define __HARMAN_ADAS_APROJECT_GWMV2MH_CLIENT_PASSERVICESTUBIMPLGWM_H__

#include "v0/com/harman/adas/PASServiceStubImpl.hpp"
#include "TraceMacros.h"
#include "ADASManager/PAS/PASRenderLooperThread.h"

using v0::com::harman::adas::PASServiceStubImpl;
using Harman::Adas::AFramework::ABase::ADASManager::PASMessageHandler;

using namespace std;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

class PasServiceStubImplGWM : public PASServiceStubImpl
{
public:
    static PasServiceStubImplGWM* GetInstance();

    static void DelInstance();

    virtual ~PasServiceStubImplGWM();

    virtual void SwitchPASView(const std::shared_ptr<CommonAPI::ClientId> _client,
            ::v0::com::harman::adas::PASBaseType::enPASViewStatus m_ePASViewStatus,
            SwitchPASViewReply_t) override;

    PasServiceStubImplGWM(const PasServiceStubImplGWM&) = delete;
    PasServiceStubImplGWM& operator=(const PasServiceStubImplGWM&) = delete;

    void TestFrontLeftInside(const unsigned int distance) const;
    void TestFrontLeft(const unsigned int distance) const;
    void TestFrontRightInside(const unsigned int distance) const;
    void TestFrontRight(const unsigned int distance) const;

    void TestRearLeftInside(const unsigned int distance) const;
    void TestRearLeft(const unsigned int distance) const;
    void TestRearRightInside(const unsigned int distance) const;
    void TestRearRight(const unsigned int distance) const;

    void TestCarDoors(const unsigned int distance) const;

private:
    PasServiceStubImplGWM();

private:
    static PasServiceStubImplGWM* m_pInstance;

    PASMessageHandler* pHandler = nullptr;
};

} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman

#endif // __HARMAN_ADAS_APROJECT_GWMV2MH_CLIENT_PASSERVICESTUBIMPLGWM_H__