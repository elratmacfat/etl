#define BOOST_TEST_MODULE CLP_Unit_Test
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "etl/concat.hpp"


struct my_type {
    int value;
};

std::string to_string(const my_type& mt) { 
    return std::string("my_type=") + std::to_string(mt.value); 
}

BOOST_AUTO_TEST_SUITE( concat_testsuite )

BOOST_AUTO_TEST_CASE( no_parameters )
{
    std::string expected{};
    std::string actual{ etl::concat() };
    BOOST_CHECK_EQUAL( actual, expected );
}

BOOST_AUTO_TEST_CASE( integral_types )
{
    std::string expected("123456789");
    std::string actual{ etl::concat(123,4,5,678,9) };
    BOOST_CHECK_EQUAL( actual, expected );
}


BOOST_AUTO_TEST_CASE( custom_type )
{
    my_type mt;
    mt.value = -5;
    std::string expected("1337my_type=-5");
    std::string actual{ etl::concat(1337,mt) };
    BOOST_CHECK_EQUAL( actual, expected );
}

BOOST_AUTO_TEST_SUITE_END()