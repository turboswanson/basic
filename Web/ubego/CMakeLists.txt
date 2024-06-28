cmake_minimum_required(VERSION 3.1)

project(SentryTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

set(SENTRY_LIB_DIR "./sentry-native/install/lib")
set(SENTRY_INCLUDE_DIR "./sentry-native/install/include")

include_directories(${SENTRY_INCLUDE_DIR})

set(SOURCES
    main.cpp
    sentry_logger.cpp
)

set(HEADERS
    sentry_logger.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets
    Qt5::Network
    -L${SENTRY_LIB_DIR} -lsentry
)

set_property(TARGET ${PROJECT_NAME} PROPERTY DEBUG_POSTFIX _d)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG_MODE")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DRELEASE_MODE")
