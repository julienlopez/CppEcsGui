#include "catch.hpp"

#include "ecs/ecs.hpp"
#include "ecs/entity.hpp"

class DisplayComponent : public Ecs::Component
{
        public:
        DisplayComponent() : Ecs::Component(1)
            {}
};

class InputComponent : public Ecs::Component
{
    public:
        InputComponent() : Ecs::Component(2)
            {}
};

class DisplaySystem : public Ecs::System<DisplayComponent>
{
};

Ecs::Entity makeLabel()
{
    return Ecs::Entity({DisplayComponent()});
}

Ecs::Ecs ecs;
ecs.addEntity(makeLabel())