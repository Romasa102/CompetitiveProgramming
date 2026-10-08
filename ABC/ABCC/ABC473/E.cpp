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
    ll N,K;
    cin >> N >> K;
    ll A[N];
    rep(i,N)cin >> A[i];
    ll count = 0;
    set<ll> curM;
    curM.insert(0);
    ll curMod = 0;
    rep(i,N){
        curMod += A[i];
        curMod %= K;
        if(curM.find(curMod) != curM.end()){
            count ++;
            curM.clear();
        }
        curM.insert(curMod);
    }

    cout << count << endl;
}