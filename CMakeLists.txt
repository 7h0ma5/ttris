project(ttris)
cmake_minimum_required(VERSION 2.8)

find_package(GLUT)
find_package(OpenGL)

set(CMAKE_C_FLAGS "-Wall -std=c99")

add_executable(ttris MACOSX_BUNDLE WIN32
    game.c
    block.c
    grid.c
    controls.c
    graphics.c
    main.c
)

target_link_libraries(ttris ${GLUT_LIBRARY} ${OPENGL_LIBRARY})
install(TARGETS ttris RUNTIME DESTINATION bin
                      BUNDLE DESTINATION /Applications)
