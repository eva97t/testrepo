using namespace std;

#include <iostream>
#include <string>

class LPS {

public:
  int findLPSLength(const string &st) {
    return findLPSLengthRecursive(st, 0, st.length() - 1);
  }

private:
  int findLPSLengthRecursive(const string &st, int startIndex, int endIndex) {
    if (startIndex > endIndex) {
      return 0;
    }

    // every sequence with one element is a palindrome of length 1
    if (startIndex == endIndex) {
      return 1;
    }

    // case 1: elements at the beginning and the end are the same
    if (st[startIndex] == st[endIndex]) {
      return 2 + findLPSLengthRecursive(st, startIndex + 1, endIndex - 1);
    }

    // case 2: skip one element either from the beginning or the end
    int c1 = findLPSLengthRecursive(st, startIndex + 1, endIndex);
    int c2 = findLPSLengthRecursive(st, startIndex, endIndex - 1);
    return max(c1, c2);
  }
};

int main(int argc, char *argv[]) {
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cddpd") << endl;
  cout << lps->findLPSLength("pqr") << endl;

  delete lps;
}

