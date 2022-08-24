# Copyright (C) 2022 Andrea Ballestrazzi

add_executable(popl_example popl_example.cpp)

target_include_directories(popl_example PUBLIC "${PROJECT_SOURC_DIR}/include")

set_target_properties(popl_example
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)
