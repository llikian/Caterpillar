cmake_minimum_required(VERSION 3.25)
project(Caterpillar)

set(CMAKE_CXX_STANDARD 23)

# New Version of the Project
add_executable(${PROJECT_NAME}
        main.cpp

        src/core/Particle.cpp
        src/core/Colony.cpp

        src/UI/Application.cpp

        src/utilities/Color.cpp
        src/utilities/draw.cpp
        src/utilities/HSL.cpp
        src/utilities/Point.cpp
        src/utilities/utility.cpp
        src/utilities/vec2.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2main SDL2 SDL2_ttf)

# Old Version of the Project
add_executable(OLD_PROJECT
        old_main.cpp

        libs/complex_functions.cpp
        libs/color_functions.cpp
        libs/graphic_functions.cpp
        libs/caterpillar.cpp
)

target_include_directories(OLD_PROJECT PUBLIC src)
target_link_libraries(OLD_PROJECT PUBLIC SDL2main SDL2)

# Sets executable folder to bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)