#pragma once

#include <utility>

namespace Ecs
{

class Entity;

class System
{
public:
    using type_key = std::size_t;

    // static constexpr uint16_t nbMax = -1;

    System(const System&) = delete;
    System(System&&) = delete;

    System& operator=(const System&) = delete;
    System& operator=(System&&) = delete;

    virtual ~System() = default;

    virtual type_key requirement() const = 0;

    void update(double dt);

private:
    virtual void preUpdate();
    virtual void postUpdate();
    virtual void do_update(double dt) = 0;
};

} // Ecs
