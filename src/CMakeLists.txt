add_subdirectory(math)

set (SOURCES_SRC
    Sphere.cpp
    Ray.cpp
    Cube.cpp
)

set (HEADERS_SRC
    Sphere.h
    Shape.h
    Ray.h    
    Functions.h
    Cube.h
)

add_library(shapes ${SOURCES_SRC} ${HEADERS_SRC})