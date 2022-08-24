# Copyright (C) 2022 Andrea Ballestrazzi

# ================ Test Executable ================
set(TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_main.cpp)
add_executable(popl_test ${TEST_SOURCES})

configure_file(test.conf "${PROJECT_SOURCE_DIR}/bin" COPYONLY)

set_target_properties(popl_test
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
)

# ================ Third Party libraries ================
# Here we configure the libraries that are stored under the "third-party" folders.

set(THIRD_PARTY_FOLDER "third-party/")
add_subdirectory("${THIRD_PARTY_FOLDER}")
