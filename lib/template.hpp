// WARNING: Add compile option "-std=c++11" for C++11 compile.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <regex>
#include <numeric>
using namespace std;

// Macro
#define REP(i, N) for(int i=0; i<(int)N; i++)
#define REPR(i, N) for(int i=(int)N-1; i>=0; i--)

// Type
using ll = long long;
template <typename T = int> using P = pair<T, T>;

// Constants
const ll MOD = 1000000007;

/**
  型に合わせたINFを返す
  int: 214,748,364 (2.14 * 1e8)
  ll : 922,337,203,685,477,580 (9.22 * 1e17)
*/
template <typename T = int>
T getINF() {
  // NOTE: INF同士を足してもオーバーフロー起こさないように、10で割っている
  return numeric_limits<T>::max() / 10;
}

// Floating
const double EPS = 1e-11;
#define EQ0(x) (abs(x) < EPS)
#define EQ(x, y) (abs(a-b) < EPS)