/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.dbus 3.1.5.201702211714.
* Used org.franca.core 0.9.1.201412191134.
*
* generated by DCIF CodeGen Version: R2_v2.3.0
* generated on: Thu Oct 12 15:16:25 CST 2017
*/
#include <v0/com/harman/adas/PASService.hpp>
#include <v0/com/harman/adas/PASServiceDBusStubAdapter.hpp>

namespace v0 {
namespace com {
namespace harman {
namespace adas {

std::shared_ptr<CommonAPI::DBus::DBusStubAdapter> createPASServiceDBusStubAdapter(
                   const CommonAPI::DBus::DBusAddress &_address,
                   const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection,
                   const std::shared_ptr<CommonAPI::StubBase> &_stub) {
    return std::make_shared<PASServiceDBusStubAdapter>(_address, _connection, _stub);
}

INITIALIZER(registerPASServiceDBusStubAdapter) {
    CommonAPI::DBus::Factory::get()->registerStubAdapterCreateMethod(
    	PASService::getInterface(), &createPASServiceDBusStubAdapter);
}

PASServiceDBusStubAdapterInternal::~PASServiceDBusStubAdapterInternal() {
    deactivateManagedInstances();
    PASServiceDBusStubAdapterHelper::deinit();
}

void PASServiceDBusStubAdapterInternal::deactivateManagedInstances() {

}

const char* PASServiceDBusStubAdapterInternal::getMethodsDBusIntrospectionXmlData() const {
    static const std::string introspectionData =
        "<method name=\"getInterfaceVersion\">\n"
            "<arg name=\"value\" type=\"uu\" direction=\"out\" />"
        "</method>\n"
        "<method name=\"getPASStatusAttribute\">\n"
            "<arg name=\"value\" type=\"ai\" direction=\"out\" />"
        "</method>\n"
        "<signal name=\"onPASStatusAttributeChanged\">\n"
            "<arg name=\"changedValue\" type=\"ai\" />\n"
        "</signal>\n"
        "<method name=\"SwitchPASView\">\n"
            "<arg name=\"_m_ePASViewStatus\" type=\"i\" direction=\"in\" />\n"
        "</method>\n"

    ;
    return introspectionData.c_str();
}

CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        ::v0::com::harman::adas::PASServiceStub,
        CommonAPI::Version
        > PASServiceDBusStubAdapterInternal::getPASServiceInterfaceVersionStubDispatcher(&PASServiceStub::getInterfaceVersion, "uu");

CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        ::v0::com::harman::adas::PASServiceStub,
        std::vector<::v0::com::harman::adas::PASBaseType::enPASStatus>,
        CommonAPI::DBus::ArrayDeployment<CommonAPI::EmptyDeployment>
        > PASServiceDBusStubAdapterInternal::getPASStatusAttributeStubDispatcher(
            &::v0::com::harman::adas::PASServiceStub::getPASStatusAttribute
            , "ai"
            );



CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::v0::com::harman::adas::PASServiceStub,
    std::tuple<::v0::com::harman::adas::PASBaseType::enPASViewStatus>,
    std::tuple<>,
    std::tuple<CommonAPI::EmptyDeployment>,
    std::tuple<>
    
    > PASServiceDBusStubAdapterInternal::switchPASViewStubDispatcher(
    &PASServiceStub::SwitchPASView, "",
					std::make_tuple(static_cast<CommonAPI::EmptyDeployment*>(nullptr)),
                	std::make_tuple());


void PASServiceDBusStubAdapterInternal::firePASStatusAttributeChanged(const std::vector<::v0::com::harman::adas::PASBaseType::enPASStatus>& value) {
    CommonAPI::Deployable<std::vector<::v0::com::harman::adas::PASBaseType::enPASStatus>, CommonAPI::DBus::ArrayDeployment<CommonAPI::EmptyDeployment>> deployedValue(value, static_cast<CommonAPI::DBus::ArrayDeployment<CommonAPI::EmptyDeployment>*>(nullptr));
    CommonAPI::DBus::DBusStubSignalHelper<CommonAPI::DBus::DBusSerializableArguments<
    CommonAPI::Deployable<
        std::vector<::v0::com::harman::adas::PASBaseType::enPASStatus>,
        CommonAPI::DBus::ArrayDeployment<CommonAPI::EmptyDeployment>
    >
    >>
        ::sendSignal(
            *this,
            "onPASStatusAttributeChanged",
            "ai",
            deployedValue
    
    );
}



const PASServiceDBusStubAdapterHelper::StubDispatcherTable& PASServiceDBusStubAdapterInternal::getStubDispatcherTable() {
    return stubDispatcherTable_;
}

const CommonAPI::DBus::StubAttributeTable& PASServiceDBusStubAdapterInternal::getStubAttributeTable() {
    return stubAttributeTable_;
}

PASServiceDBusStubAdapterInternal::PASServiceDBusStubAdapterInternal(
        const CommonAPI::DBus::DBusAddress &_address,
        const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub)
	: CommonAPI::DBus::DBusStubAdapter(_address, _connection,false),
      PASServiceDBusStubAdapterHelper(_address, _connection, std::dynamic_pointer_cast<PASServiceStub>(_stub), false),
      stubDispatcherTable_({
            { { "getPASStatusAttribute", "" }, &com::harman::adas::PASServiceDBusStubAdapterInternal::getPASStatusAttributeStubDispatcher }
            ,
            { { "SwitchPASView", "i" }, &com::harman::adas::PASServiceDBusStubAdapterInternal::switchPASViewStubDispatcher }
            }),
        stubAttributeTable_() {

    stubDispatcherTable_.insert({ { "getInterfaceVersion", "" }, &com::harman::adas::PASServiceDBusStubAdapterInternal::getPASServiceInterfaceVersionStubDispatcher });
}

bool PASServiceDBusStubAdapterInternal::hasFreedesktopProperties() {
    return false;
}

} // namespace adas
} // namespace harman
} // namespace com
} // namespace v0
