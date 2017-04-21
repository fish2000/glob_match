# glob::match
Simple “glob” pattern matching:

* ‘*’ matches zero or more of any character.
* ‘?’ matches any single character.

Example:

    if (glob::match("hello*", arg)) …

See the unit test code in `glob_test.cpp` for more examples.

To build and run the unit test:

    g++ -Wall -Werror -std=c++17 glob_test.cpp glob.cpp && ./a.out
