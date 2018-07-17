#pragma once

#include <utils/factorywithautoid.hpp>

#include "system.hpp"

typedef utils::FactoryWithAutoId<System, System::type_key> SystemFactory;
