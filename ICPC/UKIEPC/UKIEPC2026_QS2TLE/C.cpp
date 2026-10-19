#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define repp(i,x,n) for(int i = x; i < n; i++)
typedef long long ll;
int main(){
    string s;cin >> s;
    vector<char> x; //size = 1000;
    vector<char> y; //size = 1000;
    vector<char> z; //size = 1000;
    bool plusAppeared = false;
    bool equalAppeared = false;
    rep(i,s.size()){
        if(s[i]=='+'){
            plusAppeared=true;
        }
        else if(s[i]=='='){
            equalAppeared=true;
        }else{
            if(!plusAppeared && !equalAppeared){
                x.push_back(s[i]);
            }else if(!equalAppeared){
                y.push_back(s[i]);
            }else{
                z.push_back(s[i]);
            }
        }
    }
    vector<ll> muls;
    ll val = 1;
    rep(i,1010){
        muls.push_back(val);
        val*=10;
    }
    map<char,ll> mp;
    rep(a,10){
        mp['a']=a;
        rep(b,10){
            mp['b']=b;
            rep(c,10){
                mp['c']=c;
                rep(d,10){
                    mp['d']=d;
                    rep(e,10){
                        mp['e']=e;
                        if(
                            a == b || a == c || a == d || a == e || 
                            b == c || b == d || b == e || 
                            c == d || c == e || 
                            d == e
                        ){continue;}
                        ll numX = 0;
                        ll numY = 0;
                        ll numZ = 0;
                        rep(i,x.size()){
                            numX += muls[x.size()-1-i] * mp[x[i]];
                        }
                        rep(i,y.size()){
                            numY += muls[y.size()-1-i] * mp[y[i]];
                        }
                        rep(i,z.size()){
                            numZ += muls[z.size()-1-i] * mp[z[i]];
                        }
                        
                        if(numX + numY == numZ){
                            cout << a << b << c << d << e;
                            cout << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "impossible" << endl;
}