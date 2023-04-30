#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    int N = 0;
    cin >> N;
    int a,b,c;
    
    a = N%10;
    N /= 10;
    b = N%10;
    N /= 10;
    c = N%10;
    N /= 10;
    int d = 100 * a + 10 * b + c;
    int e = 100 * b + 10 * c + a;
    int f = 100 * c + 10 * a + b;
    cout << d + e + f << endl;
}