#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>


using namespace std;


string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);

  ret += "#$";
  return ret;
}

int  longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.size();
  int P[n+10];
  memset(P,0,sizeof(P));
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)

    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;

    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }

  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
     return maxLen/2;
 // return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}



int main()
{
    string s;
    //freopen("a.txt","r",stdin);
    int cased=0;
    while(cin>>s)
    {
       // if(s=="END")break;
        string ss=preProcess(s);
        int ans=longestPalindrome(ss);
        printf("Case %d: %d\n",++cased,ans);

    }
    return 0;
}







