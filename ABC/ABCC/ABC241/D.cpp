#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll Q;
    cin >> Q;
    vector<ll> A;
    rep(i,Q){
        ll num;
        cin >> num;
        ll x = 0;
        cin >> x;
        if(num == 1){
            A.push_back(x);
            sort(A.begin(),A.end());
        }
        if(num == 2){
            ll k = 0;
            cin >> k;
            ll o = -1;
            rep(j,A.size()){
                if(A[j] >= x){
                    o = j;
                    break;
                }
            }
            if(o < 0){
                o = A.size() - 1;
            }
            if(o - k >= 0){
                cout << A[o - k] << endl;
            }else{
                cout << -1 << endl;
            }
        }
        if(num == 3){
            ll k = 0;
            cin >> k;
            ll o = -1;
            rep(j,A.size()){
                if(A[j] > x){
                    o = j;
                    break;
                }
            }
            if(o >= 0 && o + k - 1 < A.size()){
                cout << A[o + k - 1] << endl;
            }else{
                cout << -1 << endl;
            }
        }
    }
}