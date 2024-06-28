#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "sentry::sentry" for configuration "RelWithDebInfo"
set_property(TARGET sentry::sentry APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(sentry::sentry PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libsentry.so"
  IMPORTED_SONAME_RELWITHDEBINFO "libsentry.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS sentry::sentry )
list(APPEND _IMPORT_CHECK_FILES_FOR_sentry::sentry "${_IMPORT_PREFIX}/lib/libsentry.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
