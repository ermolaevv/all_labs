set(nameBaseProj Queue) 
set(test "${nameBaseProj}_test")

include_directories(include)
add_subdirectory(samples)
add_subdirectory(src)
add_subdirectory(test)