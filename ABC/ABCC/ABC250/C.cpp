#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,Q;
    cin >> N >> Q;
    vector<ll> Num(N + 1);
    vector<ll> Numl(N + 1);
    vector<ll> BNum(N + 1);
    vector<ll> BNuml(N + 1);
    rep(i,N){
        Num[i] = i+1;
        Numl[i+1] = i;
    }
    int que;
    int temp,templ;
    BNum = Num;
    BNuml = Numl;
    rep(i,Q){
        cin >> que;
        BNum = Num;
        BNuml = Numl;
        if(Numl[que] == N-1){
            Numl[que] -= 1;
            templ = Numl[que];
            Numl[BNum[templ]] += 1;
            temp = Num[BNuml[que]-1];
            Num[BNuml[que]-1] = Num[BNuml[que]];
            Num[BNuml[que]] = temp;
        }else{
            Numl[que] += 1;
            templ = Numl[que];
            Numl[BNum[templ]] -= 1;
            temp = Num[BNuml[que]+1];
            Num[BNuml[que]+1] = Num[BNuml[que]];
            Num[BNuml[que]] = temp;
        }
    }
        rep(i,N){
            cout << Num[i] << " ";
        }cout << endl;
}