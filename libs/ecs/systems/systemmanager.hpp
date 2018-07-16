#pragma once

#include <memory>
#include <vector>

namespace Ecs
{

class System;

class SystemManager
{
public:
    using up_system = std::unique_ptr<System>;
    using type_list_systems = std::vector<up_system>;

    SystemManager();

    ~SystemManager();

    std::size_t count();

    void update(double dt);

    void add(up_system system);

private:
    type_list_systems m_container;
};

} // Ecs
