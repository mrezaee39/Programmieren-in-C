# Macros
This week we explore different ways of
extending the functionality of our test_util
library. We want to add two features:
* Removing the need to specify the type when
  calling an assert function. This means
  `assertEqualInt` and `assertEqualDouble` both become
  `assertEqual`.
* Additionally to the tests index we want to record the
  line number and source file for failed tests. These shall
  be printed in the summary.