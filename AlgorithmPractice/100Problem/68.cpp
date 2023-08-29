#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N = 1000000;
    bool Prime[N];
    rep(i,N){
        Prime[i] = true;
    }
    vector<ll> primes;
    repp(i,2,N){
        if(Prime[i]){
            primes.push_back(i);
            ll j = i+i;
            while(j < N){
                Prime[j] = false;
                j+=i;
            }
        }
    }
    ll Num;
    cin >> Num;
    ll currentPrime = 0;
    cout << Num << ":";
    while(Num > 1){
        if(currentPrime == primes.size()){
            cout << " " << Num;
            break;
        }
        if(Num % primes[currentPrime] == 0){
            Num/=primes[currentPrime];
            cout << " " << primes[currentPrime];
        }else{
            currentPrime++;
        }
    }
    cout << endl;
}