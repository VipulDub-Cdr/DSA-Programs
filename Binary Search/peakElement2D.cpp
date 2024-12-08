//find the peak element in 2D matrix
#include <bits/stdc++.h>
using namespace std;

bool greaterThanNeighbours(vector<vector<int>> matrix,int maxElementRow,int midColumn){
        bool allgreater = false;
}
int peakElement(vector<vector<int>> matrix){
    int nc = matrix[0].size();
    int nr = matrix.size();
    int left = 0; int right = nc-1;
    while(left<=right){
        //find the  midcolumn
        int midColumn = (left+right)/2;
        //then find the largest in the midcolumn and store its rownumber
        int maxElement = INT_MIN;
        int maxElementRow = -1;
        for(int i =0;i<nr;i++){
            if(matrix[i][midColumn]>maxElement){
                maxElement = matrix[i][midColumn];
                maxElementRow = i;
            }
        }
        //Check for peak
        if(greaterThanNeighbours){
            return 
        }

    }
}

int main() {
    vector<vector<int>> matrix = {{10,20,15},{21,30,14},{7,16,32}};

    return 0;
}