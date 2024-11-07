//program
#include <bits/stdc++.h>
using namespace std;
int largestElement(vector<int> arr){
    int n = arr.size();
    int largest = INT_MIN;
    for(auto it:arr){
        largest = max(largest,it);
    }
    return largest;
}
int main(){
    vector<int> arr = {1,2,32,5,10};
    cout<<largestElement(arr)<<endl;
    return 0;
}