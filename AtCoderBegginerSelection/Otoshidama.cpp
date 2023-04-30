#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,Y;
    cin >> N >> Y;
    int A,B,C = 0;
    bool IsAnswer = false;
    for(int i = 0;i <= N; i++){
        for(int j = 0;j <= N - i;j++){             
            if(i * 10000 + j * 5000 + (N - j - i) * 1000 == Y){
                A = i;
                B = j;
                C = N - i - j;
                IsAnswer = true;
            }
        }
    }
    if(IsAnswer){
        cout << A << " "<< B << " "<< C << endl;
    }else{
        cout << -1 << " " << -1 << " " << -1 << endl;
    }
}