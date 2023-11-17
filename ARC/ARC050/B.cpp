#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll R,B;
    ll x,y;
    cin >> R >> B >> x >> y;
    ll left = -1;
    ll right = 1LL<<61;
    while(left!=right){
        ll mid = (left+right+1)/2;
        if(mid>R||mid>B){
            right=mid-1;
            continue;
        }
        ll RemainR = R-mid;
        ll RemainB = B-mid;
        if((RemainR/(x-1))+(RemainB/(y-1))>=mid){
            left=mid;
        }else{
            right=mid-1;
        }
    }
    cout<<left << endl;
}