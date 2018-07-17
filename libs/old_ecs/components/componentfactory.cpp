#include "componentfactory.hpp"

#include <cassert>

namespace Ecs
{

// Component* ComponentFactory::create(type_key id)
// {
//     if(id >= m_containr.size()) return 0;
//     return m_containr[id]();
// }
//
// //#include <iostream>
// // using namespace std;
//
// ComponentFactory::type_key ComponentFactory::registerProduct(type_callback creator)
// {
//     type_key res = m_containr.size();
//     assert(res < Component::nbMaxComponents);
//     m_containr.push_back(creator);
//     //    cerr << "registered a type at " << res << endl;
//     return res;
// }

} // Ecs
