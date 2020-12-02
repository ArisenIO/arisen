cmake_minimum_required(VERSION 2.8.10)

set(CTEST_SOURCE_DIRECTORY "/root/arisenx/arisen/1.0/src/cmake-3.13.2/Tests/VSProjectInSubdir")
set(CTEST_BINARY_DIRECTORY "/root/arisenx/arisen/1.0/src/cmake-3.13.2/Tests/CTestBuildCommandProjectInSubdir/Nested")
set(CTEST_CMAKE_GENERATOR "Unix Makefiles")
set(CTEST_PROJECT_NAME "VSProjectInSubdir")
set(CTEST_BUILD_CONFIGURATION "Debug")

ctest_empty_binary_directory(${CTEST_BINARY_DIRECTORY})
ctest_start(Experimental)
ctest_configure(OPTIONS "-DCMAKE_MAKE_PROGRAM:FILEPATH=/usr/bin/make")
ctest_build(TARGET test)
