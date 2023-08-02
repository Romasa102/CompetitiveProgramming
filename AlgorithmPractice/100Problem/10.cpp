#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int N;
    cin >> N;
    ll A[N];
    rep(i,N){
        cin >> A[i];
    }
    ll Q;
    cin >> Q;
    bool ans = false;
    ll m;
    rep(i,Q){
        cin >> m;
        ans = false;
        for(int bit = 0; bit < (1<<N); bit++){
            ll sum = 0;
            for(int i = 0; i < N; i++){
                if(bit & 1<<i){
                    sum += A[i];
                }
            }
            if(sum == m){
                cout << "yes" << endl;
                ans = true;
                break;
            }
        }
        if(ans == false){
            cout << "no" << endl;
        }
    }
}