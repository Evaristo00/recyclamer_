cmake_minimum_required(VERSION 3.0.2)
project(cdr)


find_package(catkin REQUIRED COMPONENTS roscpp geometry_msgs std_msgs )


catkin_package()


include_directories(include ${catkin_INCLUDE_DIRS})


add_executable(subTeclado src/subTeclado.cpp)
target_link_libraries(subTeclado ${catkin_LIBRARIES} )
