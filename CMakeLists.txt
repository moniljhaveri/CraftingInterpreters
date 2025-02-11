# CMakeList.txt : CMake project for CraftingInterpreters, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CraftingInterpreters")
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()


target_link_libraries(
  hello_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)

# Add source to this project's executable.
add_executable (CraftingInterpreters "CraftingInterpreters.cpp" "CraftingInterpreters.h" "LinkedList.cpp" "LinkedList.h" "Lox.h" "Lox.cpp" "token.h" "Scanner.h" "Scanner.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CraftingInterpreters PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
