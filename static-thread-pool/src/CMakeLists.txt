set(TARGET static_thread_pool)

file(GLOB HEADER_FILES *.hpp)
file(GLOB SOURCE_FILES *.cpp)

add_executable(${TARGET} ${HEADER_FILES} ${SOURCE_FILES})