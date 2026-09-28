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
ll comp(ll a,ll b,ll c,ll d){ //compare a/b and c/d if 0 equal; if 1 left bigger; if -1 right bigger
    if(a*d == b * c){
        return 0;
    }else if(a * d > b*c){
        return 1;
    }else{
        return -1;
    }
}
int main(){
    ll N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    ll cumW[N+1];
    cumW[0] = 0;
    rep(i,N){
        if(S[i] == 'o')
    }
}