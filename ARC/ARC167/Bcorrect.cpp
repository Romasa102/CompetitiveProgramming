#include<iostream>
#include<vector>
#include<cmath>
using ll = long long;
using namespace std;
const ll modv = 998244353;
const ll halfconst = 499122177;
ll findans(ll a, ll b) {
    bool bOdd = b%2;
    b = b%modv;
    vector<ll> factors;
    for(ll i = 2; i <= sqrt(a)+5; i++) {
        ll cnt = 0;
        while(a%i == 0) {
            a /= i;
            cnt++;
        }
        if(cnt != 0) {
            factors.push_back(cnt%modv);
        }
    }
    if(a != 1) factors.push_back(1);
    ll ans = b;
    bool fEven = true;
    for(ll i = 0; i < factors.size(); i++) {
        if(factors[i]%2 == 1) fEven = false;
        ans = (ans*((((factors[i]*b)%modv)+((ll) 1))%modv))%modv;
    }
    if(!fEven || !bOdd) return ((((ans%modv)+modv)%modv)*halfconst)%modv;
    return (((((ans-1)%modv)+modv)%modv)*halfconst)%modv;
}
int main () {
    ll a,b;
    cin>>a>>b ;
    cout << findans(a,b) << endl;
    return 0;
}