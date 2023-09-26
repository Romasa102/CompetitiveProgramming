#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    deque<ll> A(N);
    rep(i,N)cin >> A[i];
    ll diff = 0;
    ll count = 0;
    ll ans  = 0;
    ll currentMax = 0;
    ll currentMin = 0;
    rep(i,A.size())cout << A[i] << " ";
    cout << endl;
    ll ansB = 0;
    while(A.size() != 1){
        currentMax = max({A[0],A[1],currentMax});
        currentMin = min({A[0],A[1],currentMin});
        if(((diff+(count+1)*(currentMax-currentMin)) - ansB>K || count == M)&&count!=0){
            ans += K+count*diff;
            diff=0;
            count = 0;
            cout << A.size() << K+count * diff << endl;
            continue;
        }
        diff += currentMax-currentMin;
        A.pop_front();
        count++;
        ansB = diff+count*(currentMax-currentMin);
        cout << A.size() << endl;
    }
    if(count!=0){
        ans += K+count*diff;
        cout << A.size() << K+count * diff << endl;
    }
    cout << ans << endl;
}