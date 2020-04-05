using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LPS {

public:
  int findLPSLength(const string &st) {
    vector<vector<int>> dp(st.length(), vector<int>(st.length(), -1));
    return findLPSLengthRecursive(dp, st, 0, st.length() - 1);
  }

private:
  int findLPSLengthRecursive(vector<vector<int>> &dp, const string &st, int startIndex,
                             int endIndex) {
    if (startIndex > endIndex) {
      return 0;
    }

    // every sequence with one element is a palindrome of length 1
    if (startIndex == endIndex) {
      return 1;
    }

    if (dp[startIndex][endIndex] == -1) {
      // case 1: elements at the beginning and the end are the same
      if (st[startIndex] == st[endIndex]) {
        dp[startIndex][endIndex] = 2 + findLPSLengthRecursive(dp, st, startIndex + 1, endIndex - 1);
      } else {
        // case 2: skip one element either from the beginning or the end
        int c1 = findLPSLengthRecursive(dp, st, startIndex + 1, endIndex);
        int c2 = findLPSLengthRecursive(dp, st, startIndex, endIndex - 1);
        dp[startIndex][endIndex] = max(c1, c2);
      }
    }
    
    return dp[startIndex][endIndex];
  }
};

int main(int argc, char *argv[]) {
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cddpd") << endl;
  cout << lps->findLPSLength("pqr") << endl;

  delete lps;
}
