#include <iostream>
using namespace std;

int main() {
    int n = 4; 
    int matrix[4][4]; 
    int no = 1; 
    int stRow = 0, edRow = n-1, stCol = 0, edCol = n-1; 
    while (stRow <= edRow && stCol <= edCol) {

        for (int i = stCol; i <= edCol; i++) 
        matrix[stRow][i] = no++;
        stRow++; 
        
        for (int i = stRow; i <= edRow; i++) 
        matrix[i][edCol] = no++;
        edCol--; 
        if (stRow <= edRow) {
            
            for (int i = edCol; i >= stCol; i--) 
            matrix[edRow][i] = no++;
            edRow--; 
        }
        
        if (stCol <= edCol) {
           
            for (int i = edRow; i >= stRow; i--) 
            matrix[i][stCol] = no++;
            stCol++;
        }
    }

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
        cout << matrix[i][j] << " ";
       cout<<endl;
    }

    return 0;
}