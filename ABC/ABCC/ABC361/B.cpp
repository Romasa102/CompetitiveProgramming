#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll a,b,c,d,e,f,g,h,i,j,k,l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    ll axis = 3;
    if((g<=min(a,d) && j<=min(a,d))||(max(a,d)<=j&&max(a,d)<=g)){
        axis--;
    }
    if((h<=min(b,e) && k<=min(b,e))||(max(b,e)<=h&&max(b,e)<=k)){
        axis--;
    }
    if((i<=min(c,f) && l<=min(c,f))||(max(c,f)<=i&&max(c,f)<=l)){
        axis--;
    }
    if(axis == 3){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}