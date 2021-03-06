#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

using namespace sol516;
using namespace std;

/*takeaways
  - we start from a single char, scanning one additional
    char at a time, and visit all possible sub-sequences
    that can be generated by the one-char longer string
    to calculate  the max palindromic length for each
    of them.
  - give a string s[i]..s[j]
    - if s[i] == [j], we can extend the length by two
    - if s[i] != [j], we pick whichever is longer from
      the strings that has one-char less
      max(s[i+1][j], s[i][j-1]) since s[i]..s[j] has
      nothing to contribute but passing up the conclusion
      from before
  - use "bbbab" as an example
    - start with the very last char "b", s[4].
    - so dp[4][4] = 1
      - this means from s[4] to s[4], which is "b"
        the max palindromic length you can get is 1
    - next we look a bigger string starting from the back
      s[3]..s[4], which is "ab"
      - "ab" is not a palindrome so, we have
        to pick the max one from strings that
        are one char shorter
      - dp[3][4] = min(dp[4][4], dp[3][3])
        - so dp[3][4] == 1
    - now scan in one more char : "bab"
      - you are looking at two possibilities
      - s[2]..s[3] "ba"
        s[2] != s[3] so
        dp[2][3] = min(dp[3][3],dp[2][2]) = 1
      - s[2]..s[4] "bab"
        dp[2][4] = dp[2+1][4-1]+2= 1+2 =3
    - continue scanning more chars until you
      reach s[0]
*/
int Solution::longest(string &s)
{
  const int n = s.size();
  /*
    - dp[i][j] stores the max length of the
      palindrome contains in s[i]..s[j]
  */
  auto dp = vector<vector<int>>(n, vector<int>(n, 0));
  for (auto i = n - 1; i >= 0; i--)
  {
    /*a char is a palindrome */
    dp[i][i] = 1;
    for (auto j = i + 1; j < n; j++)
    {
      if (s[i] == s[j])
        /* first char is s[i], and last char is s[j]
           - so the length is 1 + 1 + in-between [i+1..j-1]
        */
        dp[i][j] = dp[i + 1][j - 1] + 2;
      else
        /* look at the string that has one-less char,
           and record which one's palindromic length
           is longer
           - [i+1..j] or [i..j-1]
        */
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
    }
  }

  return dp[0][n - 1];
}