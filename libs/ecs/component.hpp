#pragma once

#include <utility>

namespace Ecs
{

class Component
{

protected:
    Component();

public:
    using type_key = std::size_t;

    type_key key() const;
};

} // Ecs
