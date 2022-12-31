/// concat - concatenates an arbitrary amount of arguments of different types to a single string.
///          The types need to have the operator<< overloaded in an accessable namespace.
///
#ifndef ETL_CONCAT_HPP
#define ETL_CONCAT_HPP

#include <sstream>

namespace etl 
{
    template <typename First, typename Second, typename...Rest> 
    std::string concat(First first, Second second, Rest... rest);
    
    namespace concat_intern 
    {
        template <typename Last>
        std::string append(std::stringstream& result, Last last)
        {
            result << last;
            return result.str();
        }
        
        template <typename First, typename...Rest>
        std::string append(std::stringstream& result, First first, Rest...rest)
        {
            result << first;
            return append(result, rest...);
        }   
    }
    
    template <typename First, typename Second, typename...Rest> 
    std::string concat(First first, Second second, Rest... rest)
    {
        std::stringstream result{};
        return concat_intern::append(result, first, second, rest...);
    }
}

#endif