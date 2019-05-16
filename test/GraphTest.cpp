#include "gtest/gtest.h"
#include "../lib/Graph.hpp"

class GraphTest : public ::testing::Test {
  protected:
    Graph<long long> g0 = Graph<long long>(0);
    GraphTest() {
    }

    virtual void SetUp() {
    }
};

namespace {
  TEST_F(GraphTest, initialize) {
    EXPECT_EQ(0, g0.getNodeN());
  }
}
