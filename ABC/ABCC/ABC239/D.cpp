#include <bits/stdc++.h>
using ll = long long;
#define rep(i,j,n) for(ll i = (j); i <= (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll A,B,C,D;
    cin >> A >> B >> C >> D;
    ll counter = 0;
    rep(i,A,B){
        rep(k,C,D){
            ll o = i + k;
            if(o==2||o==3||o==5||o== 7 ||o==11||o== 13||o== 17 ||o==19||o== 23||o== 29||o== 31||o== 37||o== 41||o== 43||o== 47||o== 53||o== 59||o== 61||o== 67||o== 71||o== 73||o== 79||o== 83||o== 89||o== 97||o== 101 ||o==103||o== 107||o== 109||o== 113||o== 127 ||o==131 ||o==137||o== 139||o== 149||o== 151||o== 157 ||o==163 ||o==167 ||o==173||o== 179 ||o==181||o== 191 ||o==193 ||o==197||o== 199){
                counter++;
                break;
            }
        }
    }
    if(counter >= B - A){
        cout <<"Aoki" << endl;
    }else{
        cout << "Takahashi" << endl;
    }
}