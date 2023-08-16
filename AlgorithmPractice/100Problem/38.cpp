#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    rep(i,N){
        string A,B;
        cin >> A >> B;
        ll cont[A.size() + 1][B.size() + 1];
        rep(m,A.size() +1) {
            rep(n, B.size()+1) {
                cont[m][n] = 0;
            }
        }
        rep(j,A.size()){
            rep(k,B.size()){
                if(A[j] == B[k]){
                    cont[j+1][k+1] = max({cont[j][k]+1,cont[j+1][k],cont[j][k+1]});
                }else{
                    cont[j+1][k+1] = max(cont[j+1][k],cont[j][k+1]);
                }
            }
        }
        cout << cont[A.size()][B.size()] << endl;
    }
}