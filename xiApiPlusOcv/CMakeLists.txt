add_library(xiApiPlusOcv SHARED xiApiPlusOcv.cpp)

find_package(OpenCV REQUIRED)
target_include_directories(xiApiPlusOcv PRIVATE ${OpenCV_INCLUDE_DIRS} )
target_link_libraries(xiApiPlusOcv ${OpenCV_LIBS})

if(CMAKE_SYSTEM_NAME STREQUAL Linux)
    SET(XIMEA_INCLUDE_DIRS /opt/XIMEA/include)
    SET(XIMEA_LIBS m3api)
endif(CMAKE_SYSTEM_NAME STREQUAL Linux)

target_include_directories(xiApiPlusOcv PRIVATE ${XIMEA_INCLUDE_DIRS})
target_link_libraries(xiApiPlusOcv ${XIMEA_LIBS})

