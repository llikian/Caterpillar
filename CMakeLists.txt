cmake_minimum_required(VERSION 3.25)
project(Caterpillar)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED)

# New Version of the Project
add_executable(${PROJECT_NAME}
        src/main.cpp

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

target_include_directories(${PROJECT_NAME} PUBLIC
        src
        ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
        ${SDL2_LIBRARIES}
        SDL2_ttf
)

# Old Version of the Project
add_executable(Old_Caterpillar
        old_src/old_main.cpp

        old_src/complex_functions.cpp
        old_src/color_functions.cpp
        old_src/graphic_functions.cpp
        old_src/caterpillar.cpp
)

target_include_directories(Old_Caterpillar PUBLIC
        old_src
        ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(Old_Caterpillar PUBLIC
        ${SDL2_LIBRARIES}
)

# Sets executable folder to bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)