# CMake generated Testfile for 
# Source directory: /home/mitchelk/Downloads/SentryTest/sentry-native
# Build directory: /home/mitchelk/Downloads/SentryTest/sentry-native/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(sentry_example "/home/mitchelk/Downloads/SentryTest/sentry-native/build/sentry_example")
set_tests_properties(sentry_example PROPERTIES  _BACKTRACE_TRIPLES "/home/mitchelk/Downloads/SentryTest/sentry-native/CMakeLists.txt;588;add_test;/home/mitchelk/Downloads/SentryTest/sentry-native/CMakeLists.txt;0;")
subdirs("src")
subdirs("crashpad_build")
subdirs("tests/unit")
