/// concat - concatenates an arbitrary amount arguments of different types to a single string.
///          The types need to have a to_string() overload in an accessable namespace.
///
#ifndef ETL_CONCAT_HPP
#define ETL_CONCAT_HPP

#include <string>

namespace etl 
{
    template <typename...Args> 
    std::string concat(Args...args);
    
    namespace concat_intern 
    {
        std::string append(std::string& result)
        {
            return result;
        }
        
        template <typename First, typename...Rest>
        std::string append(std::string& result, First first, Rest...rest)
        {
            using namespace std;
            result += to_string(first);
            return append(result, rest...);
        }   
    }
    
    template <typename...Args>
    std::string concat(Args...args)
    {
        std::string result{};
        return concat_intern::append(result,args...);
    }
}





#endif
