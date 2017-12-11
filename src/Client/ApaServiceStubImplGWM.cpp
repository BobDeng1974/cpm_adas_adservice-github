
#include "ApaServiceStubImplGWM.h"


namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

ApaServiceStubImplGWM* ApaServiceStubImplGWM::m_pInstance = NULL;

ApaServiceStubImplGWM* ApaServiceStubImplGWM::getInstance()
{
    if(NULL == m_pInstance)
    {
        m_pInstance = new ApaServiceStubImplGWM();
    }

    return m_pInstance;
}

ApaServiceStubImplGWM::ApaServiceStubImplGWM()
{
}

ApaServiceStubImplGWM::~ApaServiceStubImplGWM()
{

}

void ApaServiceStubImplGWM::SwitchAPAView(const std::shared_ptr<CommonAPI::ClientId> _client,
    ::v1::com::harman::adas::APABaseType::enAPAViewStatus m_eAPAViewStatus,
    SwitchAPAViewReply_t)
{
    return;
}

} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman