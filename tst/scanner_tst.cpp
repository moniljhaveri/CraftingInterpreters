#include <gtest/gtest.h>
#include "Scanner.h"
#include "ErrorReport.h"


TEST(SolverTest, BasicInitialization) {
  // Expect two strings not to be equal.
  ErrorReport err;
  Scanner scanner("print \"Hello, World!\";", err);
}
TEST(SolverTest, Number) {
  // Expect two strings not to be equal.
  ErrorReport err;
  Scanner scanner("1.23;", err);
}
TEST(SolverTest, String) {
  // Expect two strings not to be equal.
  ErrorReport err;
  Scanner scanner("\"Hello, World!\";", err);
}
TEST(SolverTest, Error) {
  // Expect two strings not to be equal.
  ErrorReport err;
  Scanner scanner("12;4", err);
}