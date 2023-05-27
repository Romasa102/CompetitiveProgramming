#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    map<char,int> cardOne;
    string S,T;
    cin >> S >> T;
    rep(i,S.length()){
        cardOne[S[i]]++;
    }
    map<char,int> cardTwo;
    rep(i,T.length()){
        cardTwo[T[i]]++;
    }
    string English = "abcdefghijklmnopqrstuvwxyz";
    rep(i,English.length()){
        cardOne.find(English[i]);
    }
}