#pragma once

#include <stdexcept>

namespace Utils
{

template <class IdentifierType, class ProductType> class DefaultFactoryErrorPolicy
{
public:
    class Exception : public std::exception
    {
    public:
        Exception(IdentifierType id)
            : std::exception()
            , m_unknownId(id)
        {
        }

        virtual const char* what()
        {
            return "Unknown type given to the factory.";
        }

        typename IdentifierType getId() const
        {
            return m_unknownId;
        }

    private:
        IdentifierType m_unknownId;
    };

protected:
    static ProductType* onUnknownType(IdentifierType id)
    {
        throw Exception(id);
    }
};

} // Utils
