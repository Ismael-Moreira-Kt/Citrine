cmake_minimum_required(VERSION 3.10)
project(CitrineProject C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(citrine)

file(GLOB CITRINE_SOURCES "citrine/*.c")
file(GLOB EXAMPLES_SOURCES "examples/*.c")
file(GLOB CITRINE_HEADERS "citrine/*.h")
file(GLOB EXAMPLES_HEADERS "examples/*.h")
file(GLOB CITRINE_ASM "citrine/*.asm")
file(GLOB EXAMPLES_ASM "examples/*.asm")

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set(SOURCES ${CITRINE_SOURCES} ${EXAMPLES_SOURCES})
set(ASM_SOURCES ${CITRINE_ASM} ${EXAMPLES_ASM})

foreach(asm_file ${ASM_SOURCES})
    get_filename_component(asm_name ${asm_file} NAME_WE)
    set(asm_obj ${CMAKE_BINARY_DIR}/${asm_name}.o)
    add_custom_command(
        OUTPUT ${asm_obj}
        COMMAND nasm -f elf64 -o ${asm_obj} ${asm_file}
        DEPENDS ${asm_file}
        COMMENT "Assembling ${asm_file}"
    )
    list(APPEND ASM_OBJECTS ${asm_obj})
endforeach()

add_executable(citrine_executable ${SOURCES} ${ASM_OBJECTS})

set_target_properties(citrine_executable PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(assemble ALL
    DEPENDS ${ASM_OBJECTS}
)
add_dependencies(citrine_executable assemble)