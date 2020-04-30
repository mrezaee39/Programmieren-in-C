# Exercise Week 3 - Build Your C Program

In this exercise you are going to compile, archive
and link a little library.
The file `fibonacci.h` contains the declaration of a function,
that takes an integer `n` as a parameter and returns an integer.
The return value shall be the `n`-th member of the fibonacci sequence.

The implementation of the function is missing.
Your task is to build as much of the project as
possible and then add the fibonacci implementation.

Similarly to the last exercise you will
add missing pieces to existing code.
This time however the existing code resides in
files that you do not need to change.

### Building the testing library

The files

* `test.c`
* `test.h`
* `fibonacci_test.c`
* `fibonacci_test.h`

contain code that is used to test your
fibonacci function implementation and
provide some command line output.

Take a look at the `fibonacci_test.c` file.
This file uses the not yet implemented `fibonacci`
function. You can still compile it with

```shell script
gcc -c fibonacci_test.c
```

The file `test.c` compiles as well.
You can run

```shell script
gcc -c fibonacci_test.c test.c
```

to compile both files with one command.
**The `main.c` file can be compiled the same way, but
emits a warning. What do you have to add to `fibonacci_test.h`
to get rid of that warning?**

Now you should see the object files `test.o` and `fibonacci_test.o`
in the project folder. A library is an archive containing
various object files. Library names usually start with
the prefix `lib`. We will build a **static** library,
these have the suffix `.a`. Use the archiver `ar` to
bundle the object files and create the library

```shell script
ar rv libbuilding_c_programs.a test.o fibonacci_test.o
```

The `r` flag tells the archiver to replace object files that
are already present in the archive with new ones. The `v` flag
enables verbose output.
You can use
```shell script
ar t libbuilding_c_programs.a
```
to list all object files present in the archive.
Use
```shell script
ar rv libbuilding_c_programs.a main.o
```
to include the main function in the object file as well.
Call
```shell script
nm libbuilding_c_programs.a
```
to show all symbols present in the library.

### Implementing the fibonacci sequence and building your executable file

Following an iterative process
we will first make sure we obtain
an executable file and then correct
the calculation of the fibonacci sequence.
Perform the following steps:
* Create the missing `fibonacci.c` file
* include the `fibonacci.h` header file
  * run `gcc -c fibonacci.c && nm fibonacci.o` to compile it and
   print the symbol table
* Add a minimal function implementation to it
  * Can you leave the function body empty or 
  do you have to add something?
  * compile and list the symbol tables again
* Now build the executable file by running 
    ```shell script
    gcc -o main fibonacci.o -lbuilding_c_programs -L./
    ```
  The `-l` flag specifies the libraries name without pre- and suffix,
  while the `-L` flag tells the linker in which directories to search
  for libraries. On Windows you will have to adjust the path and the output
  file name.
* Executing the resulting binary will show you a bunch of failing tests.
  Now add code to the `fibonacci` function to make these tests pass.
  You will have to recompile the function and link your executable file
  after every change.

After your code runs (hopefully) successfully, list the symbols in your executable
file by running
```shell script
nm main
```
**How does the output differ from the output for the library and what is the reason for
this result?**

**When looking at the `fibonacci_test.c` file you will notice
three include directives. Strictly speaking one of them
is not necessary. Which one is that and why do we list
it anyway?**
