set(CORE_SOURCES
  Error.cpp
  Logger.cpp
  Session.cpp
)

add_library(MLInference_Core ${CORE_SOURCES})
add_library(MLInference::Core ALIAS MLInference_Core)
target_include_directories(MLInference_Core PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
