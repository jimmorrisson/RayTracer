add_subdirectory(math)

set (SOURCES_SRC
    Sphere.cpp
    Ray.cpp
    Cube.cpp
    Plane.cpp
    Color.cpp
)

set (HEADERS_SRC
    Sphere.h
    Shape.h
    Ray.h    
    Functions.h
    Cube.h
    Plane.h
    Color.h
)

add_library(shapes ${SOURCES_SRC} ${HEADERS_SRC})
target_include_directories(shapes PUBLIC .)