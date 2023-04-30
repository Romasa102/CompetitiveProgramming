#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int B(int M){
    int h = 1;
    int k = M;
    int y = 1;
    while(k > 0){
        if(k/10  == 0){
            h*=k;
        }else if(k/100 == 0){
            
        }
        k /= 10;
        y *= 10;
    }y/=10;
    return 10 * (M - y*h) + h;
}
int main(){
    ll p = 0;
    ll a,N;
    cin >> a >> N;
    int count = 0;
    int O = 0;   
    ll t = N; 
    while(t > 0){
        p++;
        t/=10;
    }
    while(N!=1){
        if(O >= p){
            break;
        }
        if(N%a == 0){
            N /= a;
            count++;
            O = 0;
        }else{
            while(t > 0){
                p++;
                t/=10;
            }
            N = B(N);
            O++;
            count++; 
        }
      cout << N << endl;
      
    }
    if(N == 1){
        cout << count << endl;
    }else{
        cout << -1 << endl;
    }
}