#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
ll N,X,Y;
ll counter = 0;
void Blue(int Lv,int X,int Y);
void Red(int Lv,int X,int Y);
int main(){
    cin >> N >> X >> Y;
    Red(N,X,Y);
    cout << counter << endl;
}
void Blue(int Lv,int X,int Y){
    if(Lv == 2){
        counter+=Y;
    }else{
        Red(Lv-1,X,Y);
        rep(i,Y){
            Blue(Lv-1,X,Y);
        }
    }
}
void Red(int Lv,int X,int Y){
    if(Lv > 2){
        Red(Lv-1,X,Y);
        rep(i,X){
            Blue(Lv,X,Y);
        }
    }else if(Lv == 2){
        counter+=Y*X;
    }
}