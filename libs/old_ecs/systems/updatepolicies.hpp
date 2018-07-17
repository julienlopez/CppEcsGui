#pragma once

#include "entitymanager.hpp"

#include <utils/safepointer.hpp>

template <class T> class OneByOnePolicy
{
protected:
    void dispatchEntitiesForUpdate(double dt)
    {
        T& s = static_cast<T&>(*this);
        EntityManager::for_each([&s, dt](Entity& e) {
            if((e.key() & s.requirement()) != s.requirement()) return;
            static_cast<OneByOnePolicy<T>&>(s).do_update(e, dt);
        });
    }

    virtual void do_update(Entity& entity, double dt) = 0;
};

template <class T> class ListPolicy
{
public:
    using type_list_entities = std::list<utils::safe_pointer<Entity>>;

protected:
    void dispatchEntitiesForUpdate(double dt)
    {
        T& s = static_cast<T&>(*this);
        type_list_entities lst;
        EntityManager::for_each([&lst, &s](Entity& e) {
            if((e.key() & s.requirement()) != s.requirement()) return;
            lst.emplace_back(&e);

        });
        static_cast<ListPolicy<T>&>(s).do_update(std::move(lst), dt);
    }

    virtual void do_update(type_list_entities&& entities, double dt) = 0;
};
