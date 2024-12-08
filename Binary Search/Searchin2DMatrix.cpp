// search in 2d matrix
#include <bits/stdc++.h>
using namespace std;

bool BinarySearchIn2D(vector<vector<int>> matrix,int target){
    int nr = matrix.size();
    int nc = matrix[0].size();
    int row = 0; int col = nc-1;
    while(row<nr and col>=0){
        if(matrix[row][col]==target)
            return true;
        else if(target>matrix[row][col])
            row++;
        else    
            col--;
    }
    return false;

}

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // for(int i =0;i<matrix.size();i++){
    //     for(int j = 0;j<matrix[0].size();j++){
    //         cout<<matrix[i][j];
    //     }
    //     cout<<endl;
    // }
    cout<<BinarySearchIn2D(matrix,10);
    cout<<BinarySearchIn2D(matrix,15);
    return 0;
}