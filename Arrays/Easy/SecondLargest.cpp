#include <bits/stdc++.h>
using namespace std;

int secondlargest(vector<int> arr) {
    int n = arr.size();
    if (n < 2) {
        cout << "Array needs at least two elements." << endl;
        return -1;
    }

    int largest = INT_MIN;
    int slargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            slargest = largest;
            largest = arr[i];
        } else if (arr[i] > slargest && arr[i] != largest) {
            slargest = arr[i];
        }
    }

    return slargest;
}

int main() {
    vector<int> arr = {22, 12, 13, 32, 15};
    int result = secondlargest(arr);
    cout<<result;
    return 0;
}
