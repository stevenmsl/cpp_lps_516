#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol516;

/*

 Example 1:
 Input:
"bbbab"
 Output:
 4
 One possible longest palindromic subsequence is "bbbb".
*/
tuple<string, int>
testFixture1()
{
  return make_tuple("bbbab", 4);
}

/*
 Example 2:
 Input:
 "cbbd"
 Output:
 2
 One possible longest palindromic subsequence is "bb".
*/
tuple<string, int>
testFixture2()
{
  return make_tuple("cbbd", 2);
}
void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::longest(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::longest(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}