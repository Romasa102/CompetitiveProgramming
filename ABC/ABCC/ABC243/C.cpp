#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
using T = tuple<ll,ll,char>;
int main(){
    ll N;
    cin >> N;
    vector<ll> X(N);
    vector<ll> U(N);
    vector<T> Y(N);
    rep(i,N){
        cin >> X[i] >> U[i];
    }
    string S;
    cin >> S;
    rep(i,N){
        Y[i] = make_tuple(U[i], X[i],S[i]);
    }
    ll jl = 0;
    bool Ans = false;
    sort(Y.begin(),Y.end());
    for(ll i = jl;i < N - 1;i++){
        for(ll j = i + 1;j < N;j++){
            if(get<0>(Y[i]) != get<0>(Y[j])){
                jl = j;
                break;
            }else{
                if(get<1>(Y[i]) > get<1>(Y[j])){
                    if(get<2>(Y[i]) == 'L' && get<2>(Y[j]) == 'R'){
                        Ans = true;
                    }
                }
                if(get<1>(Y[i]) < get<1>(Y[j])){
                    if(get<2>(Y[i]) == 'R' && get<2>(Y[j]) == 'L'){
                        Ans = true;
                    }
                }
            }
        }
    }
    if(Ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}