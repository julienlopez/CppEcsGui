#include "entity.hpp"

#include <algorithm>

namespace Ecs
{

Entity::Entity()
    : m_key(0)
{
}

Entity::Entity(type_list_components&& lst)
    : m_components(std::move(lst))
{
    m_key = makeKey(m_components);
}

void Entity::add(up_component&& comp)
{
    m_key |= comp->key();
    m_components.push_back(std::move(comp));
}

void Entity::remove(type_key key)
{
    m_key &= !key;
    std::remove_if(begin(m_components), end(m_components), [key](const up_component& c) { return c->key() == key; });
}

Entity::type_key Entity::key() const
{
    return m_key;
}

void Entity::clear()
{
    m_components.clear();
    m_key = 0;
}

bool Entity::empty() const
{
    return m_components.empty();
}

bool Entity::operator==(const Entity& e) const
{
    return m_components == e.m_components;
}

Entity::type_key Entity::makeKey(const type_list_components& lst)
{
    type_key res = 0;
    for(const up_component& p : lst)
    {
        res |= p->key();
    }
    return res;
}

} // Ecs
