####################################################################################################

cmake_minimum_required(VERSION 3.16)
project(test-libinput LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

####################################################################################################

# https://wayland.freedesktop.org/libinput/doc/latest/building.html#building-against-libinput
# https://cmake.org/cmake/help/latest/module/FindLibinput.html
find_package(Libudev)
find_package(Libinput)

####################################################################################################

add_executable(${PROJECT_NAME}
  main.cpp
)
add_compile_options(${PROJECT_NAME}
  "-g"
)
target_link_libraries(${PROJECT_NAME} PUBLIC
  Libinput::Libinput
  ${Libudev_LIBRARIES}
)
