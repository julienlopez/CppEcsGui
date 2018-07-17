#pragma once

#include <typedefs.hpp>

namespace TL
{
template <class TYPE_KEY> TYPE_KEY makeRequirement_imp()
{
    return 0;
}

template <class TYPE_KEY, class U, typename... Params> TYPE_KEY makeRequirement_imp()
{
    return U::s_key | makeRequirement_imp<TYPE_KEY, Params...>();
}
}

/**
 * \brief simple typelist to compute the system requirement out of it's needed used component types
 */
template <class T, class... Args> class RequirementMaker
{
public:
    static QBomberMan::type_key makeRequirement()
    {
        return TL::makeRequirement_imp<QBomberMan::type_key, T, Args...>();
    }
};
