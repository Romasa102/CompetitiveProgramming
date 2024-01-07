#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    char currentDir = 'R';//R D L U
    P curPos = {0,0};
    ll curNum = 1;
    vector<vector<ll>> ans(N,vector<ll>(N,-1));
    while(curPos.first!=(N+1)/2-1||curPos.second!=(N+1)/2-1){
        if(currentDir=='R'){
            if(curPos.first+1<N&&ans[curPos.first+1][curPos.second]==-1){
                ans[curPos.first][curPos.second]=curNum;
                curPos.first++;
                curNum++;
            }else{
                currentDir='D';
                continue;
            }
        }if(currentDir=='D'){
            if(curPos.second-1>=0&&ans[curPos.first][curPos.second-1]==-1){
                ans[curPos.first][curPos.second]=curNum;
                curPos.second--;
                curNum++;
            }else{
                currentDir='L';
                continue;
            }
        }if(currentDir=='L'){
            if(curPos.first-1>=0&&ans[curPos.first-1][curPos.second]==-1){
                ans[curPos.first][curPos.second]=curNum;
                curPos.first--;
                curNum++;
            }else{
                currentDir='U';
                continue;
            }
        }if(currentDir=='U'){
            if(curPos.second+1<N&&ans[curPos.first][curPos.second+1]==-1){
                ans[curPos.first][curPos.second]=curNum;
                curPos.second++;
                curNum++;
            }else{
                currentDir='R';
                continue;
            }
        }
    }
    rep(i,N){
        rep(j,N){
            if(i==(N+1)/2-1&&j==(N+1)/2-1){
                cout << "T ";
            }else{
                cout << ans[i][j] << " ";
            }
        }cout << endl;
    }
}