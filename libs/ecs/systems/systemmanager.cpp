#include "systemmanager.hpp"

#include "system.hpp"

namespace Ecs
{

SystemManager::SystemManager() = default;

SystemManager::~SystemManager() = default;

std::size_t SystemManager::count()
{
    return m_container.size();
}

void SystemManager::update(double dt)
{
    for(const up_system& s : m_container)
    {
        s->update(dt);
    }
    // EntityManager::removeScheduledEntities();
}

void SystemManager::add(up_system system)
{
    m_container.push_back(std::move(system));
}

} // Ecs
