#include <iostream>
using namespace std;

int main() {
    int n;
    string a; 
    cin >> n;
    int X=0;
    for (int i=0; i<n; i++){
        cin >> a;
        if (a=="++X" || a=="X++")
        {
            X++;
        }
        else if(a=="--X" || a=="X--"){
            X--;
    }}
    cout << X;
    return 0;
}