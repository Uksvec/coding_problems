/*
Problem:
Given an array of integers arr[] that is first strictly increasing and then maybe strictly decreasing, find the bitonic point, that is the maximum element in the array.
Bitonic Point is a point before which elements are strictly increasing and after which elements are strictly decreasing.

Note: It is guaranteed that the array contains exactly one bitonic point.

Examples:

Input: arr[] = [1, 2, 4, 5, 7, 8, 3]
Output: 8
Explanation: Elements before 8 are strictly increasing [1, 2, 4, 5, 7] and elements after 8 are strictly decreasing [3].
Solution: The bitonic point is the maximum element in the array.
The bitonic point can be found using binary search in O(log n) time complexity.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class BitonicPoint {
    int main(){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int ans=arr[0];
        for(int i=1;i<arr.size();i++){
            if (ans> arr[i]){
                return ans;
            }
            ans=arr[i];
        }
        cout<<ans<<endl;
        return 0;
    }
};
