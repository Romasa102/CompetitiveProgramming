#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n;
    cin>>n;
    array<ll,3>ans={(ll)1e18,-1,-1};
    for(ll a=n+1;a<2*n;a++){
        if(n*a%(a-n))continue;
        ans=min(ans,array<ll,3>{a+abs(n*a/(a-n)),a,abs(n*a/(a-n))});
    }
    cout<<ans[1]<<' '<<ans[2]<<endl;
}