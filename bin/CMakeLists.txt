add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
        ${PROJECT_NAME} PRIVATE commands
)

target_link_libraries(
        ${PROJECT_NAME} PRIVATE parser
)

target_link_libraries(
        ${PROJECT_NAME} PRIVATE game
)

target_link_libraries(
        ${PROJECT_NAME} PRIVATE manager
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})