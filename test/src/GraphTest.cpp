#include "gtest/gtest.h"
#include "../../lib/template.hpp"
#include "../../lib/Graph/common.hpp"

class GraphTest : public ::testing::Test {
  protected:
    Graph g0 = Graph(0);
    GraphTest() {
    }

    virtual void SetUp() {
    }
};

namespace {
  TEST_F(, initialize) {
    EXPECT_EQ(0, g0.getNodeN());
  }
}
