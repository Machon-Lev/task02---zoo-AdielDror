cmake_minimum_required (VERSION 3.15)

project ("tasks_week3_adiel_dror")

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()


add_executable (tasks_week3_adiel_dror)

add_subdirectory (include)
add_subdirectory (src)
