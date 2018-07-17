#pragma once

#include <utility>

namespace Ecs
{

class Component
{
public:
    using type_key = std::size_t;
    // static constexpr uint8_t nbMax = 16;

    virtual ~Component() = default;

    Component& operator=(const Component&) = delete;
    Component& operator=(Component&&) = delete;

    virtual type_key key() const = 0;

protected:
    Component() = default;
};

} // Ecs
