set(SOURCES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
target_link_libraries(${PROJECT_NAME} PUBLIC
                                        SFML::Window 
                                        SFML::Graphics
                                        SFML::Audio
                                        SFML::System
                                        glm::glm #need to remove them from the main executable since they're going to be linked against each library individually
)
