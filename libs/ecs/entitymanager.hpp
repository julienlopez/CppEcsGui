#pragma once

#include "entity.hpp"

#include <algorithm>
#include <functional>
#include <stdexcept>
#include <vector>

namespace Ecs
{

class EntityManager
{

public:
    typedef std::size_t type_id;
    typedef Component::type_key type_key;

    type_key geTkey(type_id id);

    type_key addEntity(Entity::type_list_components&& lst);

    void for_each(std::function<void(Entity&)> f);

    void scheduleToRemoveEntity(Entity& entity);

    void removeScheduledEntities();

    template <class COMPONENT> static COMPONENT& getComponent(Entity& entity)
    {
        Entity::type_list_components::iterator i
            = std::find_if(entity.m_components.begin(), entity.m_components.end(),
                           [](Entity::up_component& comp) { return comp->key() == COMPONENT::s_key; });
        if(i == entity.m_components.end())
            throw std::logic_error("No such component " + std::string(typeid(COMPONENT).name()) + "for that entity");
        return static_cast<COMPONENT&>(**i);
    }

    template <class COMPONENT> static bool hasComponent(Entity& entity)
    {
        return std::find_if(entity.m_components.cbegin(), entity.m_components.cend(),
                            [](const Entity::up_component& comp) { return comp->key() == COMPONENT::s_key; })
               != entity.m_components.cend();
    }

private:
    EntityManager() = default;

    using type_containr = std::vector<Entity>;
    type_containr m_entities;
    std::vector<type_containr::iterator> m_entitiesToRemove;
};

} // Ecs
