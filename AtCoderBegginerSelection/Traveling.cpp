#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int T[110000] = {0};
    int X[110000] = {0};
    int Y[110000] = {0};

    cin >> N;
    bool Can = true;
    for(int i = 1; i <= N; i++){
        cin >> T[i] >> X[i] >> Y[i];
    }
    for(int i = 1; i <= N; i++){
        int Tdif = T[i] - T[i - 1];
        int Xdif = X[i] - X[i - 1];
        int Ydif = Y[i] - Y[i - 1];
        if(Tdif >= abs(Xdif) + abs(Ydif)){
            if(Tdif % 2 != (abs(Xdif) + abs(Ydif)) % 2){
                Can = false;
            }
        }else if(Tdif < abs(Xdif) + abs(Ydif)){
            Can = false;
        }
    }
    if(Can){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}