CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(TegraCompression)

FIND_PACKAGE(OpenCV REQUIRED)

INCLUDE_DIRECTORIES(
  /usr/local/Cellar/glib/2.40.0_1/lib/glib-2.0/include/
  /usr/local/Cellar/glib/2.40.0_1/include/glib-2.0/
  /usr/local/Cellar/gstreamer/1.4.5/include/gstreamer-1.0/)

ADD_EXECUTABLE(Camera
  Source/Main.cpp
	Source/Camera/VgCamera.cpp
	Source/Camera/VgVideo.cpp)

TARGET_LINK_LIBRARIES(Camera
  ${OpenCV_LIBS})
