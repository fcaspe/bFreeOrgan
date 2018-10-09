cmake_minimum_required (VERSION 2.6)
project (calibrate)
add_executable(calibrate main.c) 
target_link_libraries(calibrate m)
