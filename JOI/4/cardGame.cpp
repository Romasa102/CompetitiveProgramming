#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >>N;
    vector<ll> Taros;
    map<ll,bool> Taro;
    vector<ll> Hana;
    rep(i,N){
        ll A;
        cin >> A;
        Taro[A] = true;
        Taros.push_back(A);
    }
    repp(i,1,2*N+1){
        if(Taro.find(i) == Taro.end()){
            Hana.push_back(i);
        }
    }
    sort(Taros.begin(),Taros.end());
    sort(Hana.begin(),Hana.end());
    ll current = 0;
    bool TaroTurn = true;
    while(true){
        if(TaroTurn){
            if(Taros.empty()){
                cout << Hana.size() << endl << Taros.size() << endl;
                return 0;
            }
            bool exist = false;
            rep(i,Taros.size()){
                if(Taros[i] > current){
                    exist = true;
                    current = Taros[i];
                    Taros.erase(std::remove(Taros.begin(), Taros.end(),Taros[i]),Taros.end());
                    break;
                }
            }
            if(!exist)current = 0;
            TaroTurn = false;
        }else{
            if(Hana.empty()){
                cout << Hana.size() << endl << Taros.size() << endl;
                return 0;
            }
            bool exist = false;
            rep(i,Hana.size()){
                if(Hana[i] > current){
                    exist = true;
                    current = Hana[i];
                    Hana.erase(std::remove(Hana.begin(), Hana.end(),Hana[i]),Hana.end());

                    break;
                }
            }
            if(!exist)current = 0;
            TaroTurn = true;
        }
    }
}