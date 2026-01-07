#include <iostream>
#include <cmath>
using namespace std;
int main () {
    int matrix[5][5];
    int rows, cols;
    for (int i =0; i < 5; i++){
        for (int j =0; j< 5; j++){
            cin >> matrix[i][j];
            if (matrix[i][j] ==1){
                rows =i;
                cols =j;
            }
        }
    }

    int moves =abs(rows -2) + abs(cols -2);
    cout << moves;
    return 0;
}


