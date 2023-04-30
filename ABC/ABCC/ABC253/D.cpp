#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int gcd(int a, int b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}
int lcm(int a, int b){
  return a*b / gcd(a, b);
}
int main(){
    ll N,A,B,C;
    cin >> N >> A >> B;
    ll ans = 0;
    C = lcm(A,B);
    ans = (1+N)*N/2;
    ll Aa,Ba,Ca;
    Aa = (N/A*A+A)*N/A/2;
    Ba = (N/B*B+B)*N/B/2;
    Ca = (N/C*C+C)*N/C/2;
    ans = ans - Aa - Ba + Ca;
    cout << ans << endl;
}