#pragma once

#include <utils/factorywithautoid.hpp>

#include "component.hpp"

namespace Ecs
{

using ComponentFactory = Utils::FactoryWithAutoId<Component, Component::type_key, Utils::VectorStorageWithFlagId>;

} // Ecs
