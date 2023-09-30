#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q,S,T;
    cin >> N >> Q >> S >> T;
    ll A[N+1];
    rep(i,N+1){
        cin >> A[i];
    }
    ll temp = 0;
    ll dif[N-1];
    rep(i,N){
        dif[i] = A[i+1]-A[i];
        if(A[i] < A[i+1]){
            temp -= (A[i+1] - A[i]) * S;
        }else{
            temp += (A[i] - A[i+1]) * T;
        }
    }
    rep(i,Q){
        ll l,r,x;
        cin >> l >> r >> x;
        l--;
        if(r != N){
            if(dif[r] > 0){
                temp += dif[r] * S;
            }else{
                temp += dif[r] * T;
            }
            dif[r] -= x;
            if(dif[r] > 0){
                temp -= dif[r] * S;
            }else{
                temp -= dif[r] * T;
            }
        }
        if(dif[l] > 0){
            temp += dif[l] * S;
        }else{
            temp += dif[l] * T;
        }
        dif[l] += x;
        if(dif[l] > 0){
            temp -= dif[l] * S;
        }else{
            temp -= dif[l] * T;
        }

        cout << temp << endl;
    }
}