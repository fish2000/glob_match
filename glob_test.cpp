/*
  g++ -Wall -Werror -std=c++17 glob_match_test.cpp glob_match.cpp && ./a.out
*/

/*
 This software is distributed under the "Simplified BSD license":

 Copyright Michael Cook <michael@waxrat.com>. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "glob.hh"
#include <cstdlib>
#include <iostream>

#define EXPECT(X) do {                                                  \
  if (!(X)) {                                                           \
    std::cout << "failed at " << __FILE__ << " line " << __LINE__       \
              << std::endl;                                             \
    pass = false;                                                       \
  }                                                                     \
} while (0)

int main() {
  bool pass = true;

  EXPECT(glob::match("hello", "hello"));
  EXPECT(!glob::match("hello", "hello!"));
  EXPECT(!glob::match("hello", "hi"));

  EXPECT(glob::match("he?lo", "hello"));
  EXPECT(glob::match("h*o", "hello"));
  EXPECT(glob::match("h******o", "hello"));
  EXPECT(glob::match("h***?***o", "hello"));
  EXPECT(glob::match("*o", "hello"));
  EXPECT(glob::match("h*", "hello"));

  EXPECT(!glob::match("", "hello"));
  EXPECT(glob::match("", ""));
  EXPECT(glob::match("*", ""));
  EXPECT(glob::match("*", "hello"));
  EXPECT(!glob::match("?", ""));

  EXPECT(glob::match(std::string("h***?***o"), std::string("hello")));

  EXPECT(!glob::match("hello", "HELLO"));
  EXPECT(glob::imatch("hello", "HELLO"));
  EXPECT(glob::imatch("h*L?", "hello"));
  EXPECT(!glob::match("h*L?", "hello"));

  std::cout << (pass ? "pass" : "fail") << '\n';
  
  return pass ? EXIT_SUCCESS : EXIT_FAILURE;
}
