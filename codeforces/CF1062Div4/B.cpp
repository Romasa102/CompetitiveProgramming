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
    ll q;
    cin >> q;
    rep(i,q){
        ll n;
        cin >> n;
        string S,T;
        cin >> S >> T;
        ll chars[27];
        ll ansChars[27];
        rep(j,27){
            chars[j] = 0;
            ansChars[j] = 0;
        }
        rep(j,n){
            chars[S[j]-'a']++;
            ansChars[T[j]-'a']++;
        }
        bool works = true;
        rep(j,27){
            if(chars[j] != ansChars[j]){
                cout << "NO" << endl;
                works = false;
                break;
            }
        }
        if(works)cout << "YES" <<endl;
    }
}