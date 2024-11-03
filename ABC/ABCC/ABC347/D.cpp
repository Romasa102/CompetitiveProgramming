#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    vector<ll> v;
    ll popC = 0;
    while(c!=0){
        v.push_back(c%2);
        c /= 2;
        if(v.back() == 1){
            popC++;
        }
    }
    while(v.size() < 60){
        v.push_back(0);
    }
    if(popC > a+b || abs(b-a) > popC || (b%2 + a%2)%2 != popC%2){
        cout << "-1" << endl;
        return 0;
    }
    vector<ll>A(60,0);
    vector<ll>B(60,0);
    ll del = (a+b-popC)/2;
    a-=del;
    b-=del;
    rep(i,60){
        if(v[i] == 0 && del > 0){
            A[i] = 1;
            B[i] = 1;
            del--;
        }else if(v[i] == 1){
            if(a>0){
                A[i] = 1;
                a--;
            }else{
                B[i] = 1;
                b--;
            }
        }
    }
    ll ansa =0;
    ll ansb =0;
    vector<ll> pow2 = {1};
    rep(i,61)pow2.push_back(pow2.back()<<1);
    rep(i,60){
        ansa += A[i]*pow2[i];
        ansb += B[i]*pow2[i];
    }
    cout << ansa << " " << ansb << endl;
}