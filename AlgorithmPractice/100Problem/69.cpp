#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll Q;
    cin >> Q;
    vector<bool> prime(100010,true);
    vector<ll> primeCount(100010,0);
    vector<ll> primes;
    primeCount[0] = 0;
    repp(i,2,100010){
        if(prime[i]){
            ll j = i + i;
            primes.push_back(i);
            while(j <= 100010){
                prime[j] = false;
                j += i;
            }
        }
    }
    vector<bool> AlikeP(100010,false);
    rep(i,primes.size()){
        if(primes[i] == 2){
            continue;
        }
        if(prime[(primes[i]+1)/2]){
            AlikeP[primes[i]] = true;
        }
    }
    repp(i,2,100010){
        if(AlikeP[i]){
            primeCount[i] = primeCount[i-1] + 1;
        }else{
            primeCount[i] = primeCount[i-1];
        }
    }
    rep(i,Q){
        ll l,r;
        cin >> l >> r;
        cout << primeCount[r] - primeCount[l-1] << endl;
    }
}