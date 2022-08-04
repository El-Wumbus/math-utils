cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# set the project name and version
set(math-utils_VERSION_MAJOR "0")
set(math-utils_VERSION_MINOR "1")
set(ver ${math-utils_VERSION_MAJOR}.${math-utils_VERSION_MINOR})
project(math-utils VERSION ${ver} )
# specify the C++ standard

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CURRENT_SOURCE_DIR src)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dnorm.h++.in ${CMAKE_CURRENT_SOURCE_DIR}/dnorm.h++)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/absval.h++.in ${CMAKE_CURRENT_SOURCE_DIR}/absval.h++)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/add.h++.in ${CMAKE_CURRENT_SOURCE_DIR}/add.h++)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sub.h++.in ${CMAKE_CURRENT_SOURCE_DIR}/sub.h++)

add_executable(math.dnorm ${CMAKE_CURRENT_SOURCE_DIR}/dnorm.c++)
add_executable(math.abs ${CMAKE_CURRENT_SOURCE_DIR}/absval.c++)
add_executable(math.add ${CMAKE_CURRENT_SOURCE_DIR}/add.c++)
add_executable(math.sub ${CMAKE_CURRENT_SOURCE_DIR}/sub.c++)


install(TARGETS math.dnorm DESTINATION ${CMAKE_INSTALL_PREFIX}/opt/math-utils/bin)
install(TARGETS math.abs DESTINATION ${CMAKE_INSTALL_PREFIX}/opt/math-utils/bin)
install(TARGETS math.add DESTINATION ${CMAKE_INSTALL_PREFIX}/opt/math-utils/bin)
install(TARGETS math.sub DESTINATION ${CMAKE_INSTALL_PREFIX}/opt/math-utils/bin)

target_include_directories(math.dnorm INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
install(TARGETS math.dnorm DESTINATION lib)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/dnorm.h++ DESTINATION include)

enable_testing()
# define a function to simplify adding tests
function(do_test index target arg result)
add_test(NAME Test${index} COMMAND ${target} ${arg})
set_tests_properties(Test${index}
PROPERTIES PASS_REGULAR_EXPRESSION ${result}
)
endfunction()

do_test(1 /opt/math-utils/bin/math.dnorm "0" "0.39894228040143271945151132174")
do_test(2 /opt/math-utils/bin/math.dnorm "1" "0.241970724519143375234419938991")
do_test(3 /opt/math-utils/bin/math.abs "255" "255")
do_test(4 /opt/math-utils/bin/math.abs "-255" "255")
# do_test(5 /opt/math-utils/bin/math.add "1 2" "3")
# do_test(6 /opt/math-utils/bin/math.add "1 2 1 40" "44")
# do_test(7 /opt/math-utils/bin/math.sub "1 3" "-4")
# do_test(8 /opt/math-utils/bin/math.sub "10 3 1" "5")

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "LICENSE.md")
set(CPACK_PACKAGE_VERSION_MAJOR "${math-utils_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${math-utils_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)