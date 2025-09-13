find_package(Qt5 REQUIRED COMPONENTS Core Quick QML Network)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(QT_QML_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/qml" CACHE PATH "Install path for QML" FORCE)
set(QML_IMPORT_PATH ${CMAKE_BINARY_DIR}/qml CACHE STRING "Extra QML Import Paths" FORCE)

add_executable(${SERVER_TARGET_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main/server.cpp
)

qt5_add_resources(QT_RESOURCES resources.qrc)

qt_wrap_cpp(MOC_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/main/server.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/presenter/serverPresenter.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/controller/serverController.hpp
)

target_sources(${SERVER_TARGET_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/controller/serverController.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/usecase/serverUsecase.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/presenter/serverPresenter.cpp
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
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/tests
)
