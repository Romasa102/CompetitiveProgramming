#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("taming.in","r",stdin);
    freopen("taming.out","w",stdout);
    ll N;cin>>N;
    ll a[N];rep(i,N)cin>>a[i];
    ll counter = a[N-1];
    for (ll i = N-1; i >= 0; --i) {
        if(counter!=-1){
            if(a[i]==-1){
                a[i]=counter;
                counter=a[i]-1;
            }else{
                if(a[i]!=counter){
                    cout << -1 << endl;
                    return 0;
                }
                counter--;
            }
        }else{
            if(a[i]==-1){
                counter=-1;
                continue;
            }
            counter=a[i]-1;
        }
    }
    if(a[0]!=0&&a[0]!=-1){
        cout << -1 << endl;
        return 0;
    }
    a[0]=0;
    ll minA = 0;
    ll maxA = 0;
    rep(i,N){
        if(a[i]==0){
            minA++;
            maxA++;
        }
        if(a[i]==-1){
            maxA++;
        }
    }
    cout << minA << " " << maxA << endl;
}