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
    ll n,q;
    cin >> n;
    ll S[n];
    rep(i,n){
        cin >> S[i];
    }
    cin >> q;
    ll T[q];
    rep(i,q){
        cin >> T[i];
    }
    ll counter = 0;
    rep(i,q){
        //check each T[i] if it exist in S[i]
        if(binary_search(S,S+n,T[i])){
            counter++;
        }
    }
    cout << counter << endl;
}