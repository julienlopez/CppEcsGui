#pragma once

#include <vector>

namespace Utils
{

template <class IdentifierType, class ProductType, class ProductCreator> class SimpleVectorStorage
{

protected:
    typedef std::vector<ProductCreator> type_containr;
    type_containr m_containr;

    static IdentifierType pos2id(std::size_t pos)
    {
        return pos;
    }

    static std::size_t id2pos(IdentifierType id)
    {
        return id;
    }
};

template <class IdentifierType, class ProductType, class ProductCreator> class VectorStorageWithFlagId
{

protected:
    using type_containr = std::vector<ProductCreator>;

    type_containr m_containr;

    static IdentifierType pos2id(std::size_t pos)
    {
        return 1 << pos;
    }

    static std::size_t id2pos(IdentifierType id)
    {
        return log2(id);
    }
};

} // Utils
