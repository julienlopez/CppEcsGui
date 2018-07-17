#pragma once

#include "ecs/components/component.hpp"

#include <memory>
#include <vector>

namespace Ecs
{

class EntityManager;

class Entity
{
    friend class EntityManager;

public:
    using type_key = Component::type_key;
    using up_component = std::unique_ptr<Component>;
    using type_list_components = std::vector<up_component>;

    Entity();
    Entity(type_list_components&& lst);

    void add(up_component&& comp);
    void remove(type_key key);

    type_key key() const;

    void clear();
    bool empty() const;

    // TODO remove if entities become "just an id"
    bool operator==(const Entity& e) const;

private:
    type_key m_key;
    type_list_components m_components;

    static type_key makeKey(const type_list_components& lst);
};

} // Ecs
