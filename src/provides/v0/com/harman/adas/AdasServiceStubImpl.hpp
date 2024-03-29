/**
 * generated by DCIF CodeGen Version: R2_v2.3.0
 * generated on: Thu Oct 12 15:16:26 CST 2017
 */

#ifndef V0_COM_HARMAN_ADAS_ADASSERVICESTUBIMPL_HPP
#define V0_COM_HARMAN_ADAS_ADASSERVICESTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include "v0/com/harman/adas/AdasServiceStubDefault.hpp"

namespace v0 {
namespace com {
namespace harman {
namespace adas {

class AdasServiceStubImpl : public v0::com::harman::adas::AdasServiceStubDefault
{

public:
	AdasServiceStubImpl();
    virtual ~AdasServiceStubImpl();

	virtual void getModuleState(const std::shared_ptr<CommonAPI::ClientId> _client, std::string moduleName, getModuleStateReply_t);
};

} // namespace adas
} // namespace harman
} // namespace com
} // namespace v0

#endif //V0_COM_HARMAN_ADAS_ADASSERVICESTUBIMPL_HPP
