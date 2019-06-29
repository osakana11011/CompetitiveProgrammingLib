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

/*--- Macro ---*/
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define rep1(i, n) for(int i=1; i<(int)n; i++)
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()

/*---  Type ---*/
typedef long long ll;

/*--- Constants ---*/
template <typename T> const T INF = numeric_limits<T>::max() / 10;
const int MOD = (int)1e9 + 7;

// Floating
const double EPS = 1e-11;
#define EQ0(x) (abs(x) < EPS)
#define EQ(x, y) (abs(a-b) < EPS)

// Util
int max(int a, int b, int c) {return max(a, max(b, c));}
int min(int a, int b, int c) {return min(a, min(b, c));}
ll max(ll x, ll y) {return x > y ? x : y;}
ll min(ll x, ll y) {return x < y ? x : y;}
ll max(ll a, ll b, ll c) {return max(a, max(b, c));}
ll min(ll a, ll b, ll c) {return min(a, min(b, c));}

// How to use 「map」
/*
  - 宣言
    map<{key_type}, {value_type}> salary;
  - 要素の挿入
    salary["Alice"] = 1000;
  - 要素の取得 O(logn)
    salary.at("Alice");
  - 要素の削除
    salary.erase("Alice");
  - キー検索
    salary.find("Alice"); -> true
    salary.find("Bob");   -> false
  - イテレーション
    for(auto& [key, value] : salary) {...}
 */
// -------------------------------------


// How to use 「lower_bound」, 「upper_bound」
/*
  vector<int> a = {1, 2, 3, 4, 5};
  auto iter1 = lower_bound(all(a), 3);  <- 第二引数「以上」の最小イテレータが返る
  auto iter2 = upper_bound(all(a), 3);  <- 第二引数「より大きい」最小のイテレータが返る
 */
// -------------------------------------


// How to use 「struct sort」
/*
  struct Person {
    string name;
    int age;

    Person(string _name, int _age) {
      name = _name;
      age = _age;
    }

    bool operator<(const Person &another) const {
      return age < another.age;
    }
  };

  vector<Person> people;
  people.pb(Person("Alice", 20));
  people.pb(Person("Bob", 19));
  people.pb(Person("John", 40));
  people.pb(Person("Chris", 30));
  sort(all(people));
 */
 // -------------------------------------

// -------------------------------------------------------------------------------------



int main() {


  return 0;
}