#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll A,M,L,R;
    cin >> A >> M >> L >> R;
    ll ans = 0;
    ll right = 0;
    if(R>=0){
        right = (R+(M-A%M))/M;
    }
    ll left = 0;
    if(L>=0){
        left =  (L+(M-A%M))/M;
    }
    if(R<0){
        right = (-R+A%M)/M;
    }
    if(L<0){
        left = (-L+A%M)/M;
    }
    if(L==R){
        if(L%M==A%M){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
        return 0;
    }
    if(R>=0&&L>=0){
        cout << right-left << endl;
        return 0;
    }
    if(R<0&&L<0){
        cout << left-right << endl;
        return 0;
    }
    cout << right + left << endl;
}