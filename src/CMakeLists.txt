# Enable clang tidy checks
FIND_PROGRAM(CCACHE ccache)
SET(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=bugprone-*,clang-analyzer-*,concurrency-*,cppcoreguidelines-*,misc-*,modernize-*,performance-*,portability-*,readability-*,-misc-unused-using-decls,-cppcoreguidelines-pro-type-union-access,-readability-implicit-bool-conversion,-readability-magic-numbers,-bugprone-narrowing-conversions,-modernize-pass-by-value,-cppcoreguidelines-avoid-magic-numbers,-performance-inefficient-string-concatenation)

# Export compile commands
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(CMAKE_C_COMPILER_LAUNCHER ${CCACHE})
SET(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE})

# Add wiringpi
find_package(WiringPi REQUIRED)

# Specify executable
ADD_EXECUTABLE(photon ${SOURCE_FILES} ${MAIN_FILE})
TARGET_INCLUDE_DIRECTORIES(photon PRIVATE .)

# Link libraries
TARGET_LINK_LIBRARIES(photon PRIVATE photon_library)

# Custom commands
ADD_CUSTOM_COMMAND(TARGET photon POST_BUILD COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "--- MAIN  BUILT ---")