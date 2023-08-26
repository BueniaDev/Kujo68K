set(KUJO68K_HEADERS
	kujo68k.h)

set(KUJO68K_SOURCES
	kujo68k.cpp)

add_library(kujo68k ${KUJO68K_SOURCES} ${KUJO68K_HEADERS})
target_include_directories(kujo68k PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(kujo68k PRIVATE KUJO68K_STATIC=1 _CRT_SECURE_NO_WARNINGS=1)
add_library(libkujo68k ALIAS kujo68k)