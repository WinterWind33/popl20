# Copyright (C) 2022 Andrea Ballestrazzi

# Here we want to add Catch2 as the main testing framework for this project.

if(USE_CATCH2_AS_TESTING_FRAMEWORK)
    message("[INFO] => Using Catch2 as the main testing framework.")
    add_subdirectory("Catch2")
endif()
