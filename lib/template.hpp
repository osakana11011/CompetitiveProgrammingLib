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
#define rep(i, N) for(int i=0; i<(int)N; i++)
#define erep(i, N) for(int i=0; i<=(int)N; i++)
#define mp make_pair
#define pb push_back

// Type
typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

// Constants
const int MOD = (int)1e9 + 7;
int dy[] = {0, 1, -1, 0};
int dx[] = {1, 0, 0, -1};

/**
  型に合わせたINFを返す
  int: 214,748,364 (2.14 * 1e8)
  ll : 922,337,203,685,477,580 (9.22 * 1e17)
*/
template <typename T>
T getINF() {
  // NOTE: INF同士を足してもオーバーフロー起こさないように、10で割っている
  return numeric_limits<T>::max() / 10;
}

// Floating
const double EPS = 1e-11;
#define EQ0(x) (abs(x) < EPS)
#define EQ(x, y) (abs(a-b) < EPS)

int main() {

  return 0;
}