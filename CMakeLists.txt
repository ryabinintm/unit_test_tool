cmake_minimum_required(VERSION 3.8)

set(CT containers_tests)
set(TEST_CPPS
  vector_tests.cpp
  list_tests.cpp
)

set(WIN_FLAGS /W4 /WX)
set(UNIX_FLAGS -Wall -Wextra -Werror -pedantic)

find_package(GTest REQUIRED)

add_executable(${CT} ${TEST_CPPS})

target_compile_features(${CT} PUBLIC cxx_std_17)
set_target_properties(${CT} PROPERTIES
  CXX_STANDARD_REQUIRED ON
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)

if (MSVC)
  target_compile_options(${CT} PUBLIC ${WIN_FLAGS})
else ()
  target_compile_options(${CT} PUBLIC ${UNIX_FLAGS})
endif ()

target_link_libraries(${CT} PUBLIC ${GTEST_BOTH_LIBRARIES} pthread)
