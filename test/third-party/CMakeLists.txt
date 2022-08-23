# Copyright (C) 2022 Andrea Ballestrazzi

# We use FetchContent to clone the submodules.
include(FetchContent)

if(USE_CATCH2_AS_TESTING_FRAMEWORK)
    # Here we want to add Catch2 as the main testing framework for this project.
    message("[INFO] => Using Catch2 as the main testing framework.")

    FetchContent_Declare(Catch2
        GIT_REPOSITORY "https://github.com/catchorg/Catch2.git"
        GIT_TAG "devel"
    )

    FetchContent_MakeAvailable(Catch2)

    set(CATCH_DEVELOPMENT_BUILD ON)

    set_target_properties(Catch2
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
        LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
    )

    set_target_properties(Catch2WithMain
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
        LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
    )

    # We add the include directory to popl_test target so its files
    # can include Catch2 headers.
    target_include_directories(popl_test PUBLIC "Catch2/src")

    # For now we don't need our implementation of the entry point so we
    # can use the Catch2 one.
    target_link_libraries(popl_test PRIVATE Catch2::Catch2WithMain)
endif()
