cmake_minimum_required(VERSION 3.30.0)
project(SDLTemplate LANGUAGES C CXX)

include_directories(${CMAKE_SOURCE_DIR}/src/include
                    ${CMAKE_SOURCE_DIR}/src/include/imgui)

link_directories(
    ${CMAKE_SOURCE_DIR}/src/lib)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/src/Game/Game.cpp
    ${CMAKE_SOURCE_DIR}/src/Game/Screen.cpp
    ${CMAKE_SOURCE_DIR}/src/Entities/HostNode.cpp
    ${CMAKE_SOURCE_DIR}/src/Entities/ProgramCard.cpp
    ${CMAKE_SOURCE_DIR}/src/Entities/Player.cpp
    ${CMAKE_SOURCE_DIR}/src/Entities/NetworkGraph.cpp
    ${CMAKE_SOURCE_DIR}/src/Debug/NodeTesting.cpp
    ${CMAKE_SOURCE_DIR}/src/Rendering/MapRenderer.cpp
    ${CMAKE_SOURCE_DIR}/src/Rendering/GUIRenderer.cpp
    ${CMAKE_SOURCE_DIR}/src/Utils/LoadDataHelper.cpp

    #imgui core
    ${CMAKE_SOURCE_DIR}/src/imgui/imgui.cpp
    ${CMAKE_SOURCE_DIR}/src/imgui/imgui_widgets.cpp
    ${CMAKE_SOURCE_DIR}/src/imgui/imgui_tables.cpp
    ${CMAKE_SOURCE_DIR}/src/imgui/imgui_draw.cpp
    ${CMAKE_SOURCE_DIR}/src/imgui/imgui_demo.cpp

    #imgui sdl2 backend
    ${CMAKE_SOURCE_DIR}/src/imgui/imgui_impl_sdlrenderer2.cpp
    ${CMAKE_SOURCE_DIR}/src/imgui/imgui_impl_sdl2.cpp

)

add_executable(main ${SOURCES})

target_link_libraries(main mingw32 SDL2main SDL2 SDL2_image)

add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/SDL2.dll
    $<TARGET_FILE_DIR:main>)

add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/SDL2_image.dll
    $<TARGET_FILE_DIR:main>)