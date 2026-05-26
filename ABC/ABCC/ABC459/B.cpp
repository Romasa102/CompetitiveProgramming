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
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    string S[N];
    rep(i,N)cin >> S[i];
    rep(i,N){
        if('a' <= S[i][0] && S[i][0] <= 'c'){
            cout << 2;
        }else if('d' <= S[i][0] && S[i][0] <= 'f'){
            cout << 3;
        }else if('g' <= S[i][0] && S[i][0] <= 'i'){
            cout << 4;
        }else if('j' <= S[i][0] && S[i][0] <= 'l'){
            cout << 5;
        }else if('m' <= S[i][0] && S[i][0] <= 'o'){
            cout << 6;
        }else if('p' <= S[i][0] && S[i][0] <= 's'){
            cout << 7;
        }else if('t' <= S[i][0] && S[i][0] <= 'v'){
            cout << 8;
        }else if('w' <= S[i][0] && S[i][0] <= 'z'){
            cout << 9;
        }
    }cout << '\n';
}