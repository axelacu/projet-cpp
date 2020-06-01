//
// Created by axel_ on 13/05/2020.
//

#include <include/gtest/gtest.h>
#include <test.h>
/**
 *
 * TEST DE LA LIBRARI GOOGLE POUR LE TEST UNITAIRE C++
 *
 */
TEST(basic_test,toto_test){
    ASSERT_TRUE(toto());
}

TEST(basic_test,eq_test){
    ASSERT_TRUE(equal(5,5));
    ASSERT_FALSE(equal(2,4));
}