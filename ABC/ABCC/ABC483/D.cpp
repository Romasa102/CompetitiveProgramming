#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N)cin >> A[i];
    ll curMax=0, curMin = 0;
    ll maxAfter[N+1];
    ll minAfter[N+1];
    ll maxBefore[N];
    ll minBefore[N];
    maxBefore[0]=0;
    minBefore[0]=0;
    ll cur = 0;
    ll posAt[N+1];
    posAt[0]=0;
    rep(i,N){
        posAt[i+1]=posAt[i]+A[i];
        cout << posAt[i+1] << " ";
    }
    maxAfter[N]=0;
    minAfter[N]=0;
    for(int i = N-1;  i>= 0 ; i--){
        maxAfter[i]=max(maxAfter[i+1],posAt[i+1]);
        minAfter[i]=min(minAfter[i+1],posAt[i+1]);
        cout << i << " " << curMax << "  " << curMin << endl;
    }
    cur=0;
    rep(i,N){
        cur+=A[i];
        maxBefore[i+1]=max(maxBefore[i],cur);
        minBefore[i+1]=min(minBefore[i],cur);
    }
    ll ans = maxAfter[0]-minAfter[0]+1;

        cout << "When flip " << 0 << "th " << " maxAfter is "<< maxAfter[0]<< 
        " minAfter is " << minAfter[0] << " and ans is "  << ans << endl;
    rep(i,N){
        ll change=-(A[i]*2);
        ans = max(
            ans,
            max(maxAfter[i]+change,maxBefore[i])- min(minAfter[i]+change,minBefore[i])+1
        );

        cout << "When flip " << i << "th " << " maxAfter is "<< max(maxAfter[i]+change,maxBefore[i]) << 
        " minAfter is " << min(minAfter[i]+change,minBefore[i]) << " and ans is "  << ans << endl;
    }
    cout << ans << endl;
}