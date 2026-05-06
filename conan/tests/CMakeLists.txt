find_package(Catch2 3 REQUIRED)

add_executable(my_app_tests
	test_calculations.cpp
)

target_link_libraries(my_app_tests PRIVATE
	my_app_lib
	Catch2::Catch2WithMain
)

include(Catch)
catch_discover_tests(my_app_tests)
