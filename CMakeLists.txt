## Setup the project name and required cmake version.
cmake_minimum_required(VERSION 2.8.12.2)
project(PICUP)
set(PROJECT_BRIEF "Particle-In-Cell Utility for Practice")

## Add subdirectories
add_subdirectory (src)
#add_subdirectory (test)

## Create documentation (adapted from quickdox by Nicolas Granger; github.com/pixelou/quickdox)
# Variables and options
option(DISABLE_DOT      "Disable class graph (HAVE_DOT) in doxygen" OFF)
option(DOC_GEN_HTML     "Generate HTML documentation"               ON)
option(DOC_GEN_PDF      "Generate PDF documentation"                OFF)
set(DOC_PROJECT_ROOT    ${PROJECT_SOURCE_DIR}                               CACHE PATH   "Root of the project sources")
set(DOC_PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}" CACHE STRING "Documentation version")
# Find Doxygen
find_package(Doxygen REQUIRED)
# Doxyfile variables
set(PROJECT_NUMBER PROJECT_VERSION)
set(OUTPUT_DIRECTORY       doc)
set(OPTIMIZE_OUTPUT_FOR_C  "YES")
set(BUILTIN_STL_SUPPORT    "YES")
set(INPUT                  "src test")
set(USE_MDFILE_AS_MAINPAGE "README.md")
set(SOURCE_BROWSER         "YES")

if(DOC_GEN_HTML)
  set(DOC_GENERATE_HTML "YES")
else()
  set(DOC_GENERATE_HTML "NO")
endif()

if(DOC_GEN_PDF)
  set(DOC_GENERATE_PDF "YES")
else()
  set(DOC_GENERATE_PDF "NO")
endif()

if(DOC_GEN_RTF)
  set(DOC_GENERATE_RTF "YES")
else()
  set(DOC_GENERATE_RTF "NO")
endif()

if(DOC_GEN_MAN)
  set(DOC_GENERATE_MAN "YES")
else()
  set(DOC_GENERATE_MAN "NO")
endif()

if(DOXYGEN_DOT_FOUND AND (NOT DISABLE_DOT))
  set(HAVE_DOT "YES" )
	set(CALL_GRAPH "YES")
	set(CALLER_GRAPH "YES")
else()
	set(HAVE_DOT "NO" )
endif()
# Generate Doxyfile
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
# Build targets
add_custom_target(
	doc ALL
	COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Generating API documentation with Doxygen" VERBATIM
	SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile
	)
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile PROPERTIES GENERATED 1)
if(DOC_GEN_HTML)
	set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_DIRECTORY}/html)
endif()
if(DOC_GEN_PDF)
	set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_DIRECTORY}/pdf)
endif()
