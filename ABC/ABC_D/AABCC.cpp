#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<ll> Prime; //under 288675
    vector<ll> num(3000000,0);
    num[0] = 1;
    num[1] = 1;
    rep(i,288676){
        if(num[i]){
            continue;
        }else{
            Prime.push_back(i);
            rep(j,288678/i){
                num[(j+1)*i] = 1;
            }
        }
    }
    ll counter = 0;
    set<ll> M;
    rep(i,Prime.size()-2){
        if(Prime[i]*Prime[i] > N){
            break;
        }
        rep(j,Prime.size()-i-2){
            if(Prime[i]*Prime[i] * Prime[i+j+1] > N){
                break;
            }
            rep(k,Prime.size()-i-j-2){
                long long v=Prime[i]*Prime[i]*Prime[i+j+1];
                if(v>N){break;}
                v*=Prime[i+j+k+2];
                if(v>N){break;}
                v*=Prime[i+j+k+2];
                if(v>N){break;}
                counter++;
            }
        }
    }
    cout << counter << endl;
}