#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
        cin >> N;
            rep(_,N){
                ll x1,y1,x2,y2,a,b;
                cin >> x1 >> y1 >> x2 >> y2 >> a >> b;
                ll D = (b-y1)*(x2-x1) - (a-x1)*(y2-y1);
        if(D > 0){
            cout <<"LEFT" << endl;
        }else if(D<0){
            cout << "RIGHT" << endl;
        }else{
            cout << "TOUCH" << endl;
        }
    }
}