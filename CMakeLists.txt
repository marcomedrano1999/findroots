cmake_minimum_required(VERSION "3.18.3")

project("findroots")

add_executable("${PROJECT_NAME}" "Main.cpp")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)	#${CMAKE_INSTALL_PREFIX}/bin
install(FILES "Main.cpp" DESTINATION src)		#${CMAKE_INSTALL_PREFIX}/src

include(CTest)

add_test("test1" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}" "1" "0" "-3" "2")

include(CPack)