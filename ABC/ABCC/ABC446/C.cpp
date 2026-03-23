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
    ll T;
    cin >> T;
    rep(i,T){
        ll N,D;
        cin >> N >> D;
        ll A[N];
        rep(i,N)cin >> A[i];
        ll B[N];
        rep(i,N)cin >> B[i];
        queue<P> eggs;
        rep(i,N){
            ll task = B[i];
            eggs.push({A[i],i});
            while(task > 0){
                if(task > eggs.front().first){
                    task -= eggs.front().first;
                    eggs.pop();
                }else{
                    eggs.front().first -= task;
                    task = 0;
                }
            }
            while((i-eggs.front().second)>=D){
                eggs.pop();
            }
        }
        ll ans = 0;
        while(!eggs.empty()){
            ans+= eggs.front().first;
            eggs.pop();
        }
        cout << ans << endl;
    }
}