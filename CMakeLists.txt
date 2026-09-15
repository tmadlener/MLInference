cmake_minimum_required(VERSION 3.25)

SET(MLInference_VERSION_MAJOR 0)
SET(MLInference_VERSION_MINOR 1)
SET(MLInference_VERSION_PATCH 99)

SET(MLInference_VERSION  "${MLInference_VERSION_MAJOR}.${MLInference_VERSION_MINOR}.${MLInference_VERSION_PATCH}")

project(MLInference VERSION ${MLInference_VERSION} LANGUAGES CXX)

include(cmake/MLInferenceBuild.cmake)

include(GNUInstallDirs)

add_subdirectory(src)
