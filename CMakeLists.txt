# Portability Library
# https://github.com/kit10us/Portability
# Copyright (c) 2002, Kit10 Studios LLC
# 
# This file is part of Portability Library (a.k.a. Port)
# 
# Port is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# Port is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with Port.  If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required (VERSION 3.29.0)

project(port VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(TARGET_NAME ${PROJECT_NAME})
set(NAMESPACE "port")

file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/${NAMESPACE}/*.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/${NAMESPACE}/*.inl"
)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:port>
)

target_compile_features(${PROJECT_NAME} INTERFACE
	cxx_std_20
)

#	EXCLUDE_FROM_ALL TRUE
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_SOURCES})
target_sources(${PROJECT_NAME} INTERFACE
	PRIVATE
		${ALL_SOURCES}
)

#target_sources(${PROJECT_NAME} INTERFACE
#	FILE_SET HEADERS
#	BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
#	FILES ${ALL_SOURCES}
#)


if(PROJECT_IS_TOP_LEVEL)
	set(BUILD_TESTS_DEFAULT ON)
else()
	set(BUILD_TESTS_DEFAULT OFF)
endif()

option(BUILD_TESTS "Build unit tests" ${BUILD_TESTS_DEFAULT})

if(BUILD_TESTS)
	message("Building unit tests...")
	enable_testing()
	add_subdirectory(tests)
endif()
