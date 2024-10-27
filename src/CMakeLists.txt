add_subdirectory(array)
add_subdirectory(string)
add_subdirectory(twopointers)
add_subdirectory(slidingwindow)

# TODO support dynamic library
add_library(${PROJECT_NAME} STATIC ${ALL_OBJECT_FILES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
set(ALL_OBJECTS ${ALL_OBJECTS} PARENT_SCOPE)

add_subdirectory(bin)
