#pragma once

#include "system.hpp"
#include "systemfactory.hpp"
#include "updatepolicies.hpp"

template <class T, template <class> class UPDATE_POLICY = OneByOnePolicy>
class CRTP_System : public System, public UPDATE_POLICY<T>
{
    friend class UPDATE_POLICY<T>;

protected:
    template <typename... Args>
    CRTP_System(Args&&... args)
        : System(std::forward<Args>(args)...)
    {
    }

    virtual type_key key() const
    {
        return s_key;
    }

    virtual type_key requirement() const override
    {
        return T::makeRequirement();
    }

    virtual void do_update(double dt) override
    {
        UPDATE_POLICY<T>::dispatchEntitiesForUpdate(dt);
    }

public:
    static const type_key s_key;
};

template <class T, template <class> class UPDATE_POLICY>
const typename CRTP_System<T, UPDATE_POLICY>::type_key CRTP_System<T, UPDATE_POLICY>::s_key
    = SystemFactory::registerProduct([]() { return new T(); });
