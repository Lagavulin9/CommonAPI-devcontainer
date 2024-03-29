/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_PINGPONG_Pong_PROXY_HPP_
#define V1_PINGPONG_Pong_PROXY_HPP_

#include <v1/pingpong/PongProxyBase.hpp>


#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif


#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace pingpong {

template <typename ... _AttributeExtensions>
class PongProxy
    : virtual public Pong,
      virtual public PongProxyBase,
      virtual public _AttributeExtensions... {
public:
    PongProxy(std::shared_ptr<CommonAPI::Proxy> delegate);
    ~PongProxy();

    typedef Pong InterfaceType;


    /**
     * Returns the CommonAPI address of the remote partner this proxy communicates with.
     */
    virtual const CommonAPI::Address &getAddress() const;

    /**
     * Returns true if the remote partner for this proxy is currently known to be available.
     */
    virtual bool isAvailable() const;

    /**
     * Returns true if the remote partner for this proxy is available.
     */
    virtual bool isAvailableBlocking() const;

    /**
     * Returns the wrapper class that is used to (de-)register for notifications about
     * the availability of the remote partner of this proxy.
     */
    virtual CommonAPI::ProxyStatusEvent& getProxyStatusEvent();

    /**
     * Returns the wrapper class that is used to access version information of the remote
     * partner of this proxy.
     */
    virtual CommonAPI::InterfaceVersionAttribute& getInterfaceVersionAttribute();

    virtual std::future<void> getCompletionFuture();

    /**
     * Calls pingMe with synchronous semantics.
     *
     * All const parameters are input parameters to this method.
     * All non-const parameters will be filled with the returned values.
     * The CallStatus will be filled when the method returns and indicate either
     * "SUCCESS" or which type of error has occurred. In case of an error, ONLY the CallStatus
     * will be set.
     */
    virtual void pingMe(std::string _ping, CommonAPI::CallStatus &_internalCallStatus, std::string &_pong, const CommonAPI::CallInfo *_info = nullptr);
    /**
     * Calls pingMe with asynchronous semantics.
     *
     * The provided callback will be called when the reply to this call arrives or
     * an error occurs during the call. The CallStatus will indicate either "SUCCESS"
     * or which type of error has occurred. In case of any error, ONLY the CallStatus
     * will have a defined value.
     * The std::future returned by this method will be fulfilled at arrival of the reply.
     * It will provide the same value for CallStatus as will be handed to the callback.
     */
    virtual std::future<CommonAPI::CallStatus> pingMeAsync(const std::string &_ping, PingMeAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr);



 private:
    std::shared_ptr< PongProxyBase> delegate_;
};

typedef PongProxy<> PongProxyDefault;


//
// PongProxy Implementation
//
template <typename ... _AttributeExtensions>
PongProxy<_AttributeExtensions...>::PongProxy(std::shared_ptr<CommonAPI::Proxy> delegate):
        _AttributeExtensions(*(std::dynamic_pointer_cast< PongProxyBase>(delegate)))...,
        delegate_(std::dynamic_pointer_cast< PongProxyBase>(delegate)) {
}

template <typename ... _AttributeExtensions>
PongProxy<_AttributeExtensions...>::~PongProxy() {
}

template <typename ... _AttributeExtensions>
void PongProxy<_AttributeExtensions...>::pingMe(std::string _ping, CommonAPI::CallStatus &_internalCallStatus, std::string &_pong, const CommonAPI::CallInfo *_info) {
    delegate_->pingMe(_ping, _internalCallStatus, _pong, _info);
}

template <typename ... _AttributeExtensions>
std::future<CommonAPI::CallStatus> PongProxy<_AttributeExtensions...>::pingMeAsync(const std::string &_ping, PingMeAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
    return delegate_->pingMeAsync(_ping, _callback, _info);
}

template <typename ... _AttributeExtensions>
const CommonAPI::Address &PongProxy<_AttributeExtensions...>::getAddress() const {
    return delegate_->getAddress();
}

template <typename ... _AttributeExtensions>
bool PongProxy<_AttributeExtensions...>::isAvailable() const {
    return delegate_->isAvailable();
}

template <typename ... _AttributeExtensions>
bool PongProxy<_AttributeExtensions...>::isAvailableBlocking() const {
    return delegate_->isAvailableBlocking();
}

template <typename ... _AttributeExtensions>
CommonAPI::ProxyStatusEvent& PongProxy<_AttributeExtensions...>::getProxyStatusEvent() {
    return delegate_->getProxyStatusEvent();
}

template <typename ... _AttributeExtensions>
CommonAPI::InterfaceVersionAttribute& PongProxy<_AttributeExtensions...>::getInterfaceVersionAttribute() {
    return delegate_->getInterfaceVersionAttribute();
}


template <typename ... _AttributeExtensions>
std::future<void> PongProxy<_AttributeExtensions...>::getCompletionFuture() {
    return delegate_->getCompletionFuture();
}

} // namespace pingpong
} // namespace v1



// Compatibility
namespace v1_0 = v1;

#endif // V1_PINGPONG_Pong_PROXY_HPP_
