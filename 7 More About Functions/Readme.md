# Week 7
This time we revisit some concept from last weeks lecture as well as some concepts
from this week's lecture about functions.
Again there are a couple of mistakes in the code that you'll have to
fix.

* multiple definition of `exercise7`: why does this error occur? There are at least two possible ways to fix this. 
    What are pros and cons for each of them?

### Extending the `test_util` library
From now on we will incrementally extend and change the `test_util` library.
This means that previous exercises might cease to work and the clean
separation between master branch and solutions will stop working.
Therefore we will introduce a new branch for each week.
This means you will find the solution for week7 in the week8 branch and so on.

This week we want to get a nice summary of the failed tests.
Therefore we need to record for each test whether it has passed
or failed. For the implementation you have to change or extend the
existing `TestSuite` struct in the `test_util/test.h` file.
Additionally introduce two function `addFailResult` and `addPassResult`
that the user can use inside the tests to record the result.
As shown in the current `exercise.h` you can assume that the number
of tests is known at compile time.

Use the `exercise.c` file to write new tests and check if your
implementation works as expected.

##### Optional

What are features you would like to see next for our `test_util` library?
We opened the issue tracking system so you can add ideas under
[#1](https://git.uni-due.de/embedded-systems-public/teaching/programming-c/-/issues/1)

### Your Contribution
We'll try something new this week. We really like including your solutions
and ideas into the exercise, however posting them in the big blue button chat
is not always gonna work out, especially as the code base becomes more
complex. Therefore we want to try and open the repository for merge requests.
The idea is that you create a so called *Fork*, which is your personal copy
of the programming c repo. You can then develop your solution and in case you
want to show it to us and/or your fellow students you can issue a merge request.
We will then be able to present your whole solution in the exercise and give
feedback. To find out more about forks and merge requests you can visit https://docs.gitlab.com/ee/user/project/repository/forking_workflow.html