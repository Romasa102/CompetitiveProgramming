#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll a,b,d;
    ll ansX,ansY;
    cin >> a >> b >> d;
    double rad = (360 - d) * M_PI / 180;
    cout << fixed << setprecision(7) << a * cos(rad) - b * sin(rad) << " ";
    
    cout << fixed << setprecision(7) << a * sin(rad) + b * cos(rad);
    cout << endl;
}