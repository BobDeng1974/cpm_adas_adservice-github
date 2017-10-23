/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.dbus 3.1.5.201702211714.
* Used org.franca.core 0.9.1.201412191134.
*
* generated by DCIF CodeGen Version: R2_v2.3.0
* generated on: Thu Oct 12 15:16:25 CST 2017
*/
#ifndef V0_COM_HARMAN_ADAS_AVM_Service_DBUS_STUB_ADAPTER_HPP_
#define V0_COM_HARMAN_ADAS_AVM_Service_DBUS_STUB_ADAPTER_HPP_

#include <v0/com/harman/adas/AVMServiceStub.hpp>
#include "v0/com/harman/adas/AVMServiceDBusDeployment.hpp"        
#include <v0/com/harman/adas/CTABaseTypeDBusDeployment.hpp>
#include <v0/com/harman/adas/AVMBaseTypeDBusDeployment.hpp>        

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/DBus/DBusAddressTranslator.hpp>
#include <CommonAPI/DBus/DBusFactory.hpp>
#include <CommonAPI/DBus/DBusStubAdapterHelper.hpp>
#include <CommonAPI/DBus/DBusStubAdapter.hpp>
#include <CommonAPI/DBus/DBusDeployment.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v0 {
namespace com {
namespace harman {
namespace adas {

typedef CommonAPI::DBus::DBusStubAdapterHelper<AVMServiceStub> AVMServiceDBusStubAdapterHelper;

class AVMServiceDBusStubAdapterInternal
    : public virtual AVMServiceStubAdapter,
      public AVMServiceDBusStubAdapterHelper
{
public:
    AVMServiceDBusStubAdapterInternal(
            const CommonAPI::DBus::DBusAddress &_address,
            const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection,
            const std::shared_ptr<CommonAPI::StubBase> &_stub);

    ~AVMServiceDBusStubAdapterInternal();

    virtual bool hasFreedesktopProperties();

    inline static const char* getInterface() {
        return AVMService::getInterface();
    }

    void fireAVMCamStatusAttributeChanged(const ::v0::com::harman::adas::AVMBaseType::stAVMCamState& value);
    void fireCTAStatusAttributeChanged(const ::v0::com::harman::adas::CTABaseType::stCTAStatus& value);
    void fireAutoStatusAttributeChanged(const ::v0::com::harman::adas::AVMBaseType::enAutoCaliState& value);

    void fireBcAVMViewStatusEvent(const ::v0::com::harman::adas::AVMBaseType::enAVMStatus& m_AVMStatus);


    const AVMServiceDBusStubAdapterHelper::StubDispatcherTable& getStubDispatcherTable();
    const CommonAPI::DBus::StubAttributeTable& getStubAttributeTable();

    void deactivateManagedInstances();
    

static CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        ::v0::com::harman::adas::AVMServiceStub,
        CommonAPI::Version
        > getAVMServiceInterfaceVersionStubDispatcher;

static CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        ::v0::com::harman::adas::AVMServiceStub,
        ::v0::com::harman::adas::AVMBaseType::stAVMCamState,
        ::v0::com::harman::adas::AVMBaseType_::stAVMCamStateDeployment_t                
        > getAVMCamStatusAttributeStubDispatcher;
static CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        ::v0::com::harman::adas::AVMServiceStub,
        ::v0::com::harman::adas::CTABaseType::stCTAStatus,
        ::v0::com::harman::adas::CTABaseType_::stCTAStatusDeployment_t                
        > getCTAStatusAttributeStubDispatcher;
static CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        ::v0::com::harman::adas::AVMServiceStub,
        ::v0::com::harman::adas::AVMBaseType::enAutoCaliState                
        > getAutoStatusAttributeStubDispatcher;



static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::v0::com::harman::adas::AVMServiceStub,
    std::tuple<::v0::com::harman::adas::AVMBaseType::enAVMViewMode>,
    std::tuple<>,
    std::tuple<CommonAPI::EmptyDeployment>,
    std::tuple<>
    
    > switchAVMViewStubDispatcher;

static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::v0::com::harman::adas::AVMServiceStub,
    std::tuple<::v0::com::harman::adas::AVMBaseType::enAVMGuideLineMode>,
    std::tuple<>,
    std::tuple<CommonAPI::EmptyDeployment>,
    std::tuple<>
    
    > switchGuidelineStubDispatcher;

static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::v0::com::harman::adas::AVMServiceStub,
    std::tuple<::v0::com::harman::adas::CTABaseType::enCTAWorkMode>,
    std::tuple<uint8_t>,
    std::tuple<CommonAPI::EmptyDeployment>,
    std::tuple<CommonAPI::EmptyDeployment>
    
    > switchCTAStubDispatcher;

static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::v0::com::harman::adas::AVMServiceStub,
    std::tuple<::v0::com::harman::adas::AVMBaseType::enAutoCaliWorkModeAuto>,
    std::tuple<uint8_t>,
    std::tuple<CommonAPI::EmptyDeployment>,
    std::tuple<CommonAPI::EmptyDeployment>
    
    > switchAutoCalibrationAutoStubDispatcher;

static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::v0::com::harman::adas::AVMServiceStub,
    std::tuple<::v0::com::harman::adas::AVMBaseType::enAutoCaliWorkModeManu>,
    std::tuple<uint8_t>,
    std::tuple<CommonAPI::EmptyDeployment>,
    std::tuple<CommonAPI::EmptyDeployment>
    
    > switchAutoCalibrationManuallyStubDispatcher;




 protected:
    virtual const char* getMethodsDBusIntrospectionXmlData() const;

 private:
    AVMServiceDBusStubAdapterHelper::StubDispatcherTable stubDispatcherTable_;
    CommonAPI::DBus::StubAttributeTable stubAttributeTable_;
};

class AVMServiceDBusStubAdapter
    : public AVMServiceDBusStubAdapterInternal,
      public std::enable_shared_from_this<AVMServiceDBusStubAdapter> {
public:
    AVMServiceDBusStubAdapter(
    	const CommonAPI::DBus::DBusAddress &_address,
        const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub)
    	: CommonAPI::DBus::DBusStubAdapter(
    		_address, 
    		_connection,
            false),
          AVMServiceDBusStubAdapterInternal(
          	_address, 
          	_connection, 
          	_stub) { 
    }
};

} // namespace adas
} // namespace harman
} // namespace com
} // namespace v0

#endif // V0_COM_HARMAN_ADAS_AVM_Service_DBUS_STUB_ADAPTER_HPP_
