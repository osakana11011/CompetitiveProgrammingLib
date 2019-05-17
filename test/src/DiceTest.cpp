#include "gtest/gtest.h"
#include "../../lib/template.hpp"
#include "../../lib/Dice/common.hpp"

namespace {
  TEST(Dice, initialize) {
    Dice dice = Dice();
    EXPECT_EQ(1, dice.getFront());
    EXPECT_EQ(2, dice.getUp());
    EXPECT_EQ(3, dice.getRight());
    EXPECT_EQ(4, dice.getLeft());
    EXPECT_EQ(5, dice.getBottom());
    EXPECT_EQ(6, dice.getBack());
  }

  TEST(Dice, initialize2) {
    Dice dice = Dice(6, 5, 4, 3, 2, 1);
    EXPECT_EQ(6, dice.getFront());
    EXPECT_EQ(5, dice.getUp());
    EXPECT_EQ(4, dice.getRight());
    EXPECT_EQ(3, dice.getLeft());
    EXPECT_EQ(2, dice.getBottom());
    EXPECT_EQ(1, dice.getBack());
  }

  TEST(Dice, rollUp) {
    Dice dice = Dice();
    dice.rollUp();
    EXPECT_EQ(5, dice.getFront());
    EXPECT_EQ(1, dice.getUp());
    EXPECT_EQ(3, dice.getRight());
    EXPECT_EQ(4, dice.getLeft());
    EXPECT_EQ(6, dice.getBottom());
    EXPECT_EQ(2, dice.getBack());
  }

  TEST(Dice, rollDown) {
    Dice dice = Dice();
    dice.rollDown();
    EXPECT_EQ(2, dice.getFront());
    EXPECT_EQ(6, dice.getUp());
    EXPECT_EQ(3, dice.getRight());
    EXPECT_EQ(4, dice.getLeft());
    EXPECT_EQ(1, dice.getBottom());
    EXPECT_EQ(5, dice.getBack());
  }

  TEST(Dice, rollRight) {
    Dice dice = Dice();
    dice.rollRight();
    EXPECT_EQ(4, dice.getFront());
    EXPECT_EQ(2, dice.getUp());
    EXPECT_EQ(1, dice.getRight());
    EXPECT_EQ(6, dice.getLeft());
    EXPECT_EQ(5, dice.getBottom());
    EXPECT_EQ(3, dice.getBack());
  }

  TEST(Dice, rollLeft) {
    Dice dice = Dice();
    dice.rollLeft();
    EXPECT_EQ(3, dice.getFront());
    EXPECT_EQ(2, dice.getUp());
    EXPECT_EQ(6, dice.getRight());
    EXPECT_EQ(1, dice.getLeft());
    EXPECT_EQ(5, dice.getBottom());
    EXPECT_EQ(4, dice.getBack());
  }
}
