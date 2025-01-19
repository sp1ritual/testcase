cmake_minimum_required(VERSION 3.10)
project(TestCase)

# Указываем путь к Google Test
set(CMAKE_PREFIX_PATH "/usr/local/Cellar/googletest/1.15.2")

# Ищем Google Test
find_package(GTest REQUIRED)

# Указываем, где искать заголовочные файлы
include_directories(${GTEST_INCLUDE_DIRS})

# Указываем, где искать заголовочные файлы проекта
include_directories("${CMAKE_SOURCE_DIR}/include")

# Добавляем исходники и тесты
add_library(calculate libs/calculate.cpp)
add_executable(test_calculate tests/test_calculate.cpp
                libs/calculate.cpp)

# Линкуем с Google Test (с использованием GTest::Main, чтобы избежать дублирования)
target_link_libraries(test_calculate calculate GTest::GTest GTest::Main)
