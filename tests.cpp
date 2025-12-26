#include <gtest/gtest.h>
#include "octal.h"

TEST(OctalTest, Errors) {
    EXPECT_THROW(Octal::fromstring("18"), std::runtime_error);
    EXPECT_THROW(Octal::fromstring("1")->subtract(*Octal::fromstring("100")), std::runtime_error);
}

TEST(OctalTest, Sum) {
    Octal* o1 = Octal::fromstring("1002");
    Octal* o2 = Octal::fromstring("107");
    Octal* o3 = Octal::fromstring("0");
    Octal* o4 = Octal::fromstring("10000000");
    Octal* o5 = Octal::fromstring("777");
    Octal* o6 = Octal::fromstring("1");


    EXPECT_EQ(o1->add(*o2)->tostring(), "1111");
    EXPECT_EQ(o2->add(*o1)->tostring(), "1111");
    EXPECT_EQ(o3->add(*o4)->tostring(), "10000000");
    EXPECT_EQ(o4->add(*o4)->tostring(), "20000000");
    EXPECT_EQ(o5->add(*o6)->tostring(), "1000");

    delete o1, o2, o3, o4, o5, o6;
}

TEST(OctalTest, Difference) {
    Octal* o1 = Octal::fromstring("1002");
    Octal* o2 = Octal::fromstring("107");
    Octal* o3 = Octal::fromstring("1");
    Octal* o4 = Octal::fromstring("10000000");


    EXPECT_EQ(o1->subtract(*o2)->tostring(), "673");
    EXPECT_EQ(o4->subtract(*o4)->tostring(), "0");
    EXPECT_EQ(o4->subtract(*o3)->tostring(), "7777777");

    delete o1, o2, o3, o4;
}

TEST(OctalTest, GreaterThan) {
    Octal* o1 = Octal::fromstring("1002");
    Octal* o2 = Octal::fromstring("107");
    Octal* o3 = Octal::fromstring("1");
    Octal* o4 = Octal::fromstring("10000000");


    EXPECT_TRUE(o1->gt(*o2));
    EXPECT_FALSE(o4->gt(*o4));
    EXPECT_FALSE(o3->gt(*o4));
    EXPECT_TRUE(o4->gt(*o3));

    delete o1, o2, o3, o4;
}

TEST(OctalTest, LessThan) {
    Octal* o1 = Octal::fromstring("1002");
    Octal* o2 = Octal::fromstring("107");
    Octal* o3 = Octal::fromstring("1");
    Octal* o4 = Octal::fromstring("10000000");


    EXPECT_TRUE(o2->lt(*o1));
    EXPECT_FALSE(o4->lt(*o4));
    EXPECT_FALSE(o4->lt(*o3));
    EXPECT_TRUE(o3->lt(*o4));

    delete o1, o2, o3, o4;
}

TEST(OctalTest, Equal) {
    Octal* o1 = Octal::fromstring("1002");
    Octal* o2 = Octal::fromstring("107");
    Octal* o3 = Octal::fromstring("1");
    Octal* o4 = Octal::fromstring("10000000");


    EXPECT_TRUE(o1->eq(*o1));
    EXPECT_FALSE(o4->eq(*o2));

    delete o1, o2;
}