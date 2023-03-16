cmake_minimum_required(VERSION 3.0.0)
project(web_balancer VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(web_balancer main.cpp ServersPool.cpp Balancer.cpp)

target_link_libraries(web_balancer jsoncpp)# 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
