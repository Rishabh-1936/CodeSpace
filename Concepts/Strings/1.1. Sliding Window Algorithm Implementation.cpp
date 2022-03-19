/*
Questions:
Given the text T & pattern P, find whether P exists in T or not. If it exists then print all its occurences.

Input: 
T = Code by Coding
P = co

Output:
0,8
*/

#include<bits/stdc++.h>

#define REP(s,e,incr) for(int i = s; i < e; i+=incr)

using namespace std;

bool match(string T, string P, int start, int end)
{
  for(int i = 0; i < P.size(); ++i)
  {
    if(T[start + i] != P[i])
    {
      return false;
    }
  }
  return true;
}


int main()
{
  string T, P;
  cin >> T >> P;

  int LT = T.size();
  int LP = P.size();

  for(int L = 0, R = LP-1; R < LT; ++L, ++R){
    if(match(T, P, L, R)){
      cout << L << " ";
    }
  }


// Another Implementation
  int flag;
  for(int i = 0; i < LT; ++i){
    flag = 1;
    for(int j = 0; j < LP; ++j){
      if(T[i+j] != P[j]){
        flag=0;
        break;
      }
    }
    if(flag){
      cout << i << " ";
    }
  }
}

/*
T.C:
|T| = N, |P| = M
Total windows to match = N - M + 1
Matching time for 1 window: M
total Time Complexity: N*M - M*M + M ~ O(N*M) for N>>M
*/