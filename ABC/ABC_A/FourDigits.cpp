#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int Num = N;
    int digits = 0;
    while (Num > 0){
        Num /= 10;
        digits += 1;
    }
    for (int i = 0; i < 4 -digits; i++)
    {
        cout << 0;
    }
    if(N != 0){
        cout << N << endl;
    }
}