#include <gtest/gtest.h>
#include "Scanner.h"

TEST(SolverTest, BasicInitialization) {
  // Expect two strings not to be equal.
  Scanner scanner("print \"Hello, World!\";");
}
TEST(SolverTest, Number) {
  // Expect two strings not to be equal.
  Scanner scanner("1.23;");
}
TEST(SolverTest, String) {
  // Expect two strings not to be equal.
  Scanner scanner("\"Hello, World!\";");
}
TEST(SolverTest, Error) {
  // Expect two strings not to be equal.
  Scanner scanner("12;4");
}