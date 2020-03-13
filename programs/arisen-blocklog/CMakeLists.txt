add_executable( arisen-blocklog main.cpp )

if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling arisen-blocklog with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

target_include_directories(arisen-blocklog PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries( arisen-blocklog
        PRIVATE appbase
        PRIVATE arisen_chain fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )

copy_bin( arisen-blocklog )
install( TARGETS
   arisen-blocklog

   COMPONENT base

   RUNTIME DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
   LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
   ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
)
