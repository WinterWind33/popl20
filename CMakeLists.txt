#  ____   __  ____  __
# (  _ \ /  \(  _ \(  )
#  ) __/(  O )) __// (_/\
# (__)   \__/(__)  \____/

# This file is part of popl (program options parser lib)
# Copyright (C) 2015-2021 Johannes Pohl
# Copyright (C) 2022 Andrea Ballestrazzi

# This software may be modified and distributed under the terms
# of the MIT license.  See the LICENSE file for details.

cmake_minimum_required(VERSION 3.18)

set(PROJECT_VERSION "1.3.0")
project(popl_example)

# ================ COMPILATION CONFIGURATIONS ================
# This is required as some compilers don't support concepts
# automatically (like g++).
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message("[INFO] => Compiling with: -fconcepts.")
    add_compile_options(-fconcepts)
endif()

if(NOT MSVC)
    message("[INFO] => Adding -g option.")

    # With clang or gcc we need this option in order to debug the
    # project.
    add_compile_options(-g)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

# ============================================================

set(PROJECT_DESCRIPTION "Header-only C++ program options parser library")
set(PROJECT_URL "https://github.com/WinterWind33/popl20")

option(BUILD_EXAMPLE "Build example (build popl_example demo)" ON)
option(BUILD_TESTS "Build tests" ON)


if(NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)
    SET(CMAKE_INSTALL_INCLUDEDIR include CACHE
        PATH "Output directory for header files")
endif()

install(FILES include/popl.hpp DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

if (BUILD_EXAMPLE)
    add_subdirectory(example)
endif (BUILD_EXAMPLE)

if (BUILD_TESTS)
    option(USE_CATCH2_AS_TESTING_FRAMEWORK "Use Catch2 as testing framework" ON)

    # Here we need to create the bin directory here because this
    # will otherwise exists only after a succesfull operation. If we
    # put the configuration file now without the bin directory,
    # there will be an error.
    file(MAKE_DIRECTORY "./bin/")

    add_subdirectory(test)
endif (BUILD_TESTS)

