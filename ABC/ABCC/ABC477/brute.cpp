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
    ll N,Q;
    cin >> N >> Q;
    vector<bool> tiles(N,false);
    vector<char> col(N,'a');
    rep(i,Q){
        ll task;cin >> task;
        if(task == 1){
            ll X;cin >> X;
            X--;
            tiles[X]=!tiles[X];
        }
        else{
            char c;
            cin >> c;
            rep(i,N){
                if(!tiles[i]){
                    col[i]=c;
                }
            }
        }
    }
    rep(i,N){
        cout<< col[i];
    }cout << endl;
}