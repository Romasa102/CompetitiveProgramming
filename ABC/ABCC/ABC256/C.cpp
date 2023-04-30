#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 1; i <= (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll h1,h2,h3;
    ll w1,w2,w3;
    ll a,b,c,d,e,f,g,h,i;
    ll P = 0;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;  
    if(h1+h2+h3 != w1+w2+w3){
     cout << 0 << endl;
     return 0;
    }
    rep(j,h1-2){
        rep(k,h1 - i - 1){
            a = j;
            b = k;
            c = h1 - j - k;
            cout << a << b << c;
            rep(l,h2 - 2){
                rep(m,h2 - l - 1){
                    d = l;
                    e = m;
                    f = h2 - l - m;
                    rep(n,h3 - 2){
                        rep(o,h3 - n - 1){
                            g = n;
                            h = o;
                            i = h3 - n - o;

                            if(a + d + g == w1){
                                if(b + e + h == w2){
                                    if(c+f+i == w3){
                                        P++;
                                    }else{
                                        break;
                                    }
                                }else{
                                    break;
                                }
                            }else{
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << P << endl;
}