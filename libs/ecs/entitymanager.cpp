#include "entitymanager.hpp"

#include <cassert>

namespace Ecs
{

EntityManager::type_key EntityManager::geTkey(type_id id)
{
    if(id >= m_entities.size()) return 0;
    return m_entities[id].key();
}

EntityManager::type_key EntityManager::addEntity(Entity::type_list_components&& lst)
{
    type_key res = m_entities.size();
    m_entities.emplace_back(std::move(lst));
    return res;
}

void EntityManager::for_each(std::function<void(Entity&)> f)
{
    for(Entity& e : m_entities)
    {
        f(e);
    }
}

void EntityManager::scheduleToRemoveEntity(Entity& entity)
{
    type_containr::iterator i = std::find(m_entities.begin(), m_entities.end(), entity);
    assert(i != m_entities.end());
    m_entitiesToRemove.push_back(i);
}

void EntityManager::removeScheduledEntities()
{
    for(auto i : m_entitiesToRemove)
    {
        i->clear();
    }
    m_entities.erase(
        std::remove_if(m_entities.begin(), m_entities.end(), std::bind(&Entity::empty, std::placeholders::_1)),
        m_entities.end());
    m_entitiesToRemove.clear();
}

} // Ecs
