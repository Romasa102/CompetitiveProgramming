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
    string S,T;
    cin >> S >> T;
    ll countS[27];
    ll countT[27];
    rep(i,27){
        countS[i]=0;
        countT[i]=0;
    }
    rep(i,S.size()){
        countS[S[i]-'a']++;
    }
    rep(i,T.size()){
        countT[T[i]-'a']++;
    }
    string ans = "";
    cout <<  ans << endl;
    rep(i,27){
        if(countS[i]==0&&countT[i]==0)continue;

        rep(j,max(countS[i],countT[i])){
            ans+=('a'+i);
        }
    }
    cout << ans << endl;
}