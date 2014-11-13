project(LabExam)
cmake_minimum_required(VERSION 2.8)

set (SOURCES main.cpp
            WindowManager.cpp
            WindowManager.h
            Object.cpp
            Object.h
            Geometries.h
            House.h
            House.cpp
            Tree.h
            Tree.cpp
            Rocket.h
            Rocket.cpp
            Light.cpp
            Light.h
            Sky.cpp
            Sky.h
            Fountain.h
            Fountain.cpp
            Mountains.h
            Mountains.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} -lGL -lglut -lGLU)

