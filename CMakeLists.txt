cmake_minimum_required(VERSION 3.2)
project(modern-cpp-playground)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES main.cpp AutoDecltype.cpp)

include_directories("/usr/local/Cellar/boost/1.72.0/include")
link_directories("/usr/local/Cellar/boost/1.72.0/lib")

include_directories("/usr/local/Cellar/sqlite/3.30.1/include")
link_directories("/usr/local/Cellar/sqlite/3.30.1/lib")

add_executable(ModernCpp ${SOURCE_FILES} Headers.h NullPtr.cpp AutoDecltype.cpp
    RangeBasedFor.cpp Lambdas.cpp StronglyTypedEnum.cpp
    StaticAssertTraits.cpp Constexpr.cpp )

add_executable(SmartPointerTest SmartPointers.cpp)

add_executable(Variadictest Variadic.cpp)
add_executable(UniformInitDemo UniformInit.cpp)
add_executable(MoveRvalueDemo MoveRvalue.cpp)
add_executable(RawStrings RawStrings.cpp)
add_executable(OverrideFinalDemo OverrideFinal.cpp)

add_executable(playground playground.cpp)
target_link_libraries(playground boost_filesystem boost_system)
target_link_libraries(playground sqlite3)