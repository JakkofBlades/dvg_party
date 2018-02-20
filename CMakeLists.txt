cmake_minimum_required(VERSION 2.8.9)

project(dvg_party)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake_modules)

set(SOURCE_FILES
  src/main.cpp
  src/logger.cpp
  src/texture_map.cpp
  src/font_map.cpp
  src/game.cpp
  src/game_state_start.cpp
  )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=gnu++0x")

set(EXECUTABLE_NAME "dvg_party")
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
