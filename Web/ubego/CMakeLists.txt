cmake_minimum_required(VERSION 3.16)  # 3.16+ recommended for better Qt6 support

project(SentryTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure CMake can find your Qt6 installation
set(CMAKE_PREFIX_PATH "/home/mitchelk/Qt/6.6.3/gcc_64")

# Find Qt6 components
find_package(Qt6 COMPONENTS Widgets Network REQUIRED)

# Specify the Sentry Native directories
set(SENTRY_LIB_DIR "${CMAKE_SOURCE_DIR}/sentry-native/install/lib")
set(SENTRY_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/sentry-native/install/include")

include_directories(${SENTRY_INCLUDE_DIR})

# Specify sources and headers
set(SOURCES
    main.cpp
    sentry_logger.cpp
)

set(HEADERS
    sentry_logger.h
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(${PROJECT_NAME}
    Qt6::Widgets
    Qt6::Network
    ${SENTRY_LIB_DIR}/libsentry.so  # Adjust to the actual library file
)

# Set debug and release flags
set_property(TARGET ${PROJECT_NAME} PROPERTY DEBUG_POSTFIX _d)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG_MODE")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DRELEASE_MODE")
