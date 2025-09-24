find_package(Qt5 REQUIRED COMPONENTS Core Quick QML Network)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(QT_QML_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/qml" CACHE PATH "Install path for QML" FORCE)
set(QML_IMPORT_PATH ${CMAKE_BINARY_DIR}/qml CACHE STRING "Extra QML Import Paths" FORCE)

file(GLOB MOC_SOURCES_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/main/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/presenter/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/presenter/viewmodels/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/presenter/viewInterface/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/controller/DAInterface/*.hpp
)

add_executable(${SERVER_TARGET_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main/server.cpp
)

qt5_add_resources(QT_RESOURCES resources.qrc)

qt_wrap_cpp(MOC_SOURCES
    ${MOC_SOURCES_FILES}
)

file(GLOB SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/controller/DAInterface/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/controller/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/presenter/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/presenter/viewInterface/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/usecase/*.cpp
)

target_sources(${SERVER_TARGET_NAME}
    PRIVATE
        ${SRC_FILES}
        ${MOC_SOURCES}
        ${QT_RESOURCES}
)

target_include_directories(${SERVER_TARGET_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

target_link_libraries(${SERVER_TARGET_NAME} PUBLIC
    Qt5::Core
    Qt5::Quick
    Qt5::Qml
    ${IPC_TARGET_NAME}
    ${FRAMEWORK_TARGET_NAME}
)

set_target_properties(${SERVER_TARGET_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/main
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/libs
)
