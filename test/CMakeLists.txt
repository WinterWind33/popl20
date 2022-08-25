# Copyright (C) 2022 Andrea Ballestrazzi

# ================ Test Executable ================
set(TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_main.cpp)
add_executable(popl_test ${TEST_SOURCES})

set(POPL_TEST_BIN_DIR "${PROJECT_SOURCE_DIR}/bin")

configure_file(test.conf "${POPL_TEST_BIN_DIR}" COPYONLY)

set_target_properties(popl_test
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${POPL_TEST_BIN_DIR}"
)

if(MSVC)
    # Under Windows there is also the Debug folder that
    # is created during the compilation. We don't want that
    # so we can have an uniform folder configuration accross
    # platforms.
    set_target_properties(popl_test
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${POPL_TEST_BIN_DIR}"
    )
endif()

target_include_directories(popl_test PUBLIC "${PROJECT_SOURCE_DIR}/include")

# ================ Third Party libraries ================
# Here we configure the libraries that are stored under the "third-party" folders.

set(THIRD_PARTY_FOLDER "third-party/")
add_subdirectory("${THIRD_PARTY_FOLDER}")
