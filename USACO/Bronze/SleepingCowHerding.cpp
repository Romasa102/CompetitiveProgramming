#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("herding.in","r",stdin);
    ll num[3];
    rep(i,3)cin >> num[i];
    freopen("herding.out","w",stdout);

    sort(num,num+3);
    ll leftL = num[1]-num[0]-1;
    ll rightL = num[2]-num[1]-1;
    ll maxAns = max(leftL,rightL);
    ll minAns = 0;
    if(leftL==0&&rightL==0)minAns= 0;
    else if(rightL==1)minAns= 1;
    else if(leftL==1)minAns= 1;
    else minAns= 2;
    cout << minAns << endl << maxAns << endl;
}