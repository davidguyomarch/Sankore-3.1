
if(NOT "/workspace/build_qt6/_deps/quazip-subbuild/quazip-populate-prefix/src/quazip-populate-stamp/quazip-populate-gitinfo.txt" IS_NEWER_THAN "/workspace/build_qt6/_deps/quazip-subbuild/quazip-populate-prefix/src/quazip-populate-stamp/quazip-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/workspace/build_qt6/_deps/quazip-subbuild/quazip-populate-prefix/src/quazip-populate-stamp/quazip-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/workspace/build_qt6/_deps/quazip-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/workspace/build_qt6/_deps/quazip-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout --config "advice.detachedHead=false" "https://github.com/stachenov/quazip.git" "quazip-src"
    WORKING_DIRECTORY "/workspace/build_qt6/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/stachenov/quazip.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout v1.4 --
  WORKING_DIRECTORY "/workspace/build_qt6/_deps/quazip-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'v1.4'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/workspace/build_qt6/_deps/quazip-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/workspace/build_qt6/_deps/quazip-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/workspace/build_qt6/_deps/quazip-subbuild/quazip-populate-prefix/src/quazip-populate-stamp/quazip-populate-gitinfo.txt"
    "/workspace/build_qt6/_deps/quazip-subbuild/quazip-populate-prefix/src/quazip-populate-stamp/quazip-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/workspace/build_qt6/_deps/quazip-subbuild/quazip-populate-prefix/src/quazip-populate-stamp/quazip-populate-gitclone-lastrun.txt'")
endif()

