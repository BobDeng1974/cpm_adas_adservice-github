
#include "PasServiceStubImplGWM.h"
#include "ADASManager/PAS/PasManager.h"

using Harman::Adas::AFramework::ABase::ADASManager::PasManager;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

PasServiceStubImplGWM* PasServiceStubImplGWM::m_pInstance = nullptr;

PasServiceStubImplGWM* PasServiceStubImplGWM::GetInstance()
{
    if(nullptr == m_pInstance) {
        m_pInstance = new PasServiceStubImplGWM();
    }

    return m_pInstance;
}

void PasServiceStubImplGWM::DelInstance()
{
    if(m_pInstance != nullptr) {
        delete m_pInstance;
        m_pInstance = nullptr;
    }
}

PasServiceStubImplGWM::PasServiceStubImplGWM()
{
    pHandler = new PASMessageHandler();
}

PasServiceStubImplGWM::~PasServiceStubImplGWM()
{
    if(pHandler != nullptr) {
        delete pHandler;
        pHandler = nullptr;
    }
}

void PasServiceStubImplGWM::SwitchPASView(const std::shared_ptr<CommonAPI::ClientId> _client,
    ::v0::com::harman::adas::PASBaseType::enPASViewStatus m_ePASViewStatus,
    SwitchPASViewReply_t)
{
    return;
}

void PasServiceStubImplGWM::TestFrontLeftInside(const unsigned int distance) const
{
    PasManager::GetInstance()->m_pFrontLeftInside->Flush(distance);
}

void PasServiceStubImplGWM::TestFrontLeft(const unsigned int distance) const
{
    PasManager::GetInstance()->m_pFrontLeft->Flush(distance);
}

void PasServiceStubImplGWM::TestFrontRightInside(const unsigned int distance) const
{
    PasManager::GetInstance()->m_pFrontRightInside->Flush(distance);
}

void PasServiceStubImplGWM::TestFrontRight(const unsigned int distance) const
{
    PasManager::GetInstance()->m_pFrontRight->Flush(distance);
}

void PasServiceStubImplGWM::TestRearLeftInside(const unsigned int distance) const
{
    PasManager::GetInstance()->m_pRearLeftInside->Flush(distance);
}

void PasServiceStubImplGWM::TestRearLeft(const unsigned int distance) const
{
    PasManager::GetInstance()->m_pRearLeft->Flush(distance);
}

void PasServiceStubImplGWM::TestRearRightInside(const unsigned int distance) const
{
    PasManager::GetInstance()->m_pRearRightInside->Flush(distance);
}

void PasServiceStubImplGWM::TestRearRight(const unsigned int distance) const
{
    PasManager::GetInstance()->m_pRearRight->Flush(distance);
}

void PasServiceStubImplGWM::TestCarDoors(const unsigned int distance) const
{
    //PasManager::GetInstance()->m_pCar->Flush(2);
}

} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman