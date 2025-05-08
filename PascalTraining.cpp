/*
Problem:
Given a positive integer n, return the nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.
i=1 => 1
i=2 => 1 1
i=3 => 1 2 1
i=4 => 1 3 3 1
i=5 => 1 4 6 4 1
i=6 => 1 5 10 10 5 1
Solution:
The formula for the nth row of pascal's triangle is:
C(n, 0), C(n, 1), C(n, 2), ..., C(n, n)
k is index starts from 0
where C(n, k) = (C(n,k-1)*(n-k))/k.
*/

#include <iostream>
#include <vector>
using namespace std;
class PascalTriangle {
    int main(){
        int n;
        cin>>n;
        vector<int> ans;
        ans.push_back(1);
        for(int i=1; i<=n; i++){
            ans.push_back((ans[i-1]*(n-i+1))/i);
        }
        for(int i=0; i<=n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
};
