find_package( Boost COMPONENTS unit_test_framework REQUIRED )

add_executable(concat concat.cpp)
target_link_libraries(concat PRIVATE ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(NAME concat COMMAND concat)

