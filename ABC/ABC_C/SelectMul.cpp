#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<ll> D;
    int digits =0;
    while(N > 0){
        D.insert(D.begin(),N%10);
        N/=10;
        digits ++;
    }
    sort(D.begin(),D.end());
    N = 0;
    ll maxN = 0;
    do{
        rep(i,digits){
            N += D[i] * pow(10,i);
        }
        rep(i,digits){
            int J = pow(10,i);
            int a = N/J;
            int b = N%J;
            if(maxN<a*b){
                maxN = a*b;
            }
        }
        cout << N << endl;
        N = 0;
    }while(next_permutation(D.begin(),D.end()));
}