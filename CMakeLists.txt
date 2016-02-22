## Setup the project name and required cmake version.
cmake_minimum_required(VERSION 2.8.12.2)
project(PICUP)
set(PROJECT_BRIEF "Particle-In-Cell Utility for Practice")
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)

## Make sure the compiler is good enough
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
	message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

## Enable testing
enable_testing()

## Set variables for source and test directories
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

## Add subdirectories
add_subdirectory (src)
add_subdirectory (test)

## Create documentation (adapted from quickdox by Nicolas Granger;
#	github.com/pixelou/quickdox)
# Variables and options
option(DISABLE_DOT      "Disable class graph (HAVE_DOT) in doxygen" OFF)
option(DOC_GEN_HTML     "Generate HTML documentation"               ON)
option(DOC_GEN_PDF      "Generate PDF documentation"                OFF)
set(DOC_PROJECT_ROOT    ${PROJECT_SOURCE_DIR}/docs
	CACHE PATH   "Root of the project sources")
set(DOC_PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
	CACHE STRING "Documentation version")
# Find Doxygen
find_package(Doxygen REQUIRED)
# Doxyfile variables
set(PROJECT_NUMBER         ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})
set(OUTPUT_DIRECTORY       ../docs/doxygen)
set(OPTIMIZE_OUTPUT_FOR_C  "YES")
set(BUILTIN_STL_SUPPORT    "YES")
set(INPUT                  "../README.md ../src")
set(USE_MDFILE_AS_MAINPAGE "../README.md")
set(SOURCE_BROWSER         "YES")
set(FULL_PATH_NAMES        "NO")
set(STRIP_FROM_PATH        "")

if(DOC_GEN_HTML)
  set(GENERATE_HTML "YES")
else()
  set(GENERATE_HTML "NO")
endif()

if(DOC_GEN_PDF)
  set(GENERATE_LATEX "YES")
else()
  set(GENERATE_LATEX "NO")
endif()

if(DOXYGEN_DOT_FOUND AND (NOT DISABLE_DOT))
  set(HAVE_DOT "YES" )
  set(CALL_GRAPH "YES")
  set(CALLER_GRAPH "YES")
else()
  set(HAVE_DOT "NO" )
endif()
# Generate Doxyfile
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
	${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile @ONLY)
# Build targets
add_custom_target(
	dox ALL
	COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_SOURCE_DIR}/docs/Doxyfile
	DEPENDS ${PROJECT_SOURCE_DIR}/Doxyfile.in
		${PROJECT_SOURCE_DIR}/docs/Doxyfile
	COMMENT "Generating documentation with Doxygen" VERBATIM
	SOURCES ${PROJECT_SOURCE_DIR}/docs/Doxyfile
	)
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile
	PROPERTIES GENERATED 1)
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${OUTPUT_DIRECTORY})
