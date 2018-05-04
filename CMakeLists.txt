set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(smoker
	threads.cpp
	main.cpp)

TARGET_LINK_LIBRARIES(smoker
	pthread)