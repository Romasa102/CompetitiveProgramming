#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll A,B,C;
    cin >> A >> B;
    string As;
    if(A==1){
        As = "100";
    }else if(A == 2){
        As = "010";
    }else if(A == 3){
        As = "110";
    }else if(A == 4){
        As = "001";
    }else if(A == 5){
        As = "101";
    }else if(A == 6){
        As = "011";
    }else if(A == 7){
        As = "111";
    }
    string Bs;
    if(B==1){
        Bs = "100";
    }else if(B == 2){
        Bs = "010";
    }else if(B == 3){
        Bs = "110";
    }else if(B == 4){
        Bs = "001";
    }else if(B == 5){
        Bs = "101";
    }else if(B == 6){
        Bs = "011";
    }else if(B == 7){
        Bs = "111";
    }
    C = 0;
    if(As[0] == '1'||Bs[0]=='1'){
        C+=1;
    }
    if(As[1] == '1'||Bs[1] =='1'){
        C+=2;
    }
    if(As[2] == '1'||Bs[2] =='1'){
        C+=4;
    }
    cout << C << endl;
}