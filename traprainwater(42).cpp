/* to find the height of the water just find the min of left max and right max and then subtract the height of the current element from it. We can use two pointers to find the left max and right max for each element. We will also keep track of the maximum height of water that can be trapped at each element and update it accordingly.
2. we can also stack , dp and prefix sum approach to solve this problem but two pointer approach is the most efficient one.
why these approaches will work since stack will help us to find the left max and right max for each element and dp will help us to store the left max and right max for each element and prefix sum will help us to find the left max and right max for each element in O(1) time after precomputing the prefix sum array.



*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int trap(vector<int> &height){
            int vector<int> getleftmaxarray(vector<int> &height , int n){
                vector<int> leftmax(n);//to store the left max for each element
                leftmax[0]=height[0];
                for(int i=1;i<n;i++){
                    leftmax[i]=max(leftmax[i-1], height[i]);
                }
                return leftmax;
            }
                int vector<int> getrightmaxarray(vector<int> &height,int n){
                    vectot<int> rightmax(n);//m size jo ki height ke equal hai
                    rightmax[n-1]=height[n-1];
                    for (int i=0;i<n-1;i++){
                        rightmax=max(rightmax[i+1],height[i]);

                    }
                    return rightmax;
                }



        int n =height.size();
       
        vector<int> leftmax=getleftmaxarray(height,n);
        vector<int> rightmax=getrightmaxarray(height,n);
        int sum=0;
        for(int i=0;i<n;i++){
            height[i]=min(leftmax[i], rightmax[i])-height[i];
            sum+=height[i];
        }
        return sum;
    }
}

