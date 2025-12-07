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
    ll N,A,B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    ll As[N+1];
    ll Bs[N+1];
    rep(i,N+1){
        As[i]=0;
        Bs[i]=0;
    }
    repp(i,1,N+1){
        As[i] = As[i-1];
        Bs[i] = Bs[i-1];
        if(S[i-1]=='a'){
            As[i]++;
        }else{
            Bs[i]++;
        }
    }
    ll ans = 0;
    repp(i,1,N+1){
        ll temp = ((upper_bound(As,As+N+1,As[i]-A)-As) - (lower_bound(Bs,Bs+N+1,Bs[i]-B+1)-Bs));
        if(temp > 0)ans+=temp;
    }
    cout << ans << endl;
}
