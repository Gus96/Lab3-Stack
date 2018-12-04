#include "gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);//инициализация теста
    return RUN_ALL_TESTS();//запуск
}
