# Create core library with all source files
set(SOURCES
    studentas.cpp
    papildomos_funkcijos.cpp
    generavimas.cpp
    ived_isved.cpp
    tyrimai.cpp
)

add_library(StudentuSistemaCore ${SOURCES})

# Include directories
target_include_directories(StudentuSistemaCore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
)

# Create main executable
add_executable(StudentuSistema main.cpp)
target_link_libraries(StudentuSistema PRIVATE StudentuSistemaCore)

target_include_directories(StudentuSistema PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
