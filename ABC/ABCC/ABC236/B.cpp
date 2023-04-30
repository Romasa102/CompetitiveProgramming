#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    int a[4 * N - 1];
    rep(i,(4 * N) - 1){
        cin >> a[i];
    }
    sort(a,a + (4 * N - 1));
    int b;
    rep(i,N){
        b = a[4 * i];
        rep(j,4){
            if(a[(4 * i) + j] != b){
                cout << b << endl;
                return 0;
            }
        }
    }
}