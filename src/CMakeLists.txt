add_executable(xiPeopleCounter main.cpp DetectionResult.h Detector.cpp Detector.h)

target_sources(xiPeopleCounter PRIVATE Camera.cpp)
target_sources(xiPeopleCounter PRIVATE Ui.cpp)

find_package(OpenCV REQUIRED)
target_include_directories(xiPeopleCounter PRIVATE ${OpenCV_INCLUDE_DIRS})

target_link_libraries(xiPeopleCounter ${OpenCV_LIBS})

target_link_libraries(xiPeopleCounter xiApiPlusOcv)