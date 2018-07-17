#pragma once

#include <utility>

namespace Ecs
{

class Component
{
public:

    using type_key = std::size_t;

    Component();

    type_key key() const;

};

} // Ecs
