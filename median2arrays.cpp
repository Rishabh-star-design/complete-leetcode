#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //using binary search to find median of two sorted arrays 
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2){
        int n=nums1.size();
        int m=nums2.size();
        if(n<m){
            return findMedianSortedArrays(nums1,nums2);
        }
        int start=0; int end=n;//why chosing smaller array kyunki ye confirm hai ki usme less elements honge aur usme hi median hoga.
        while (start<=end){
            //partitioning the arrays into two halves and checking if the left half of both arrays is less than or equal to the right half of both arrays.where partitionX and partitionY are the partition points of the two arrays and maxLeftX, minRightX, maxLeftY, minRightY are the maximum and minimum elements of the left and right halves of the two arrays respectively.
            int partitionX=(start+end)/2;
            int partitionY=(n+m+1)/2-partitionX;
            int maxLeftX=(partitionX==0)?INT_MIN:nums1[partitionX-1];.//
            int minRightX=(partitionX==n)?INT_MAX:nums1[partitionX];
            int maxLeftY=(partitionY==0)?INT_MIN:nums2[partitionY-1];
            int minRightY=(partitionY==m)?INT_MAX:nums2[partitionY];
            if(maxLeftX<=minRightY && maxLeftY<=minRightX){
                if((n+m)%2==0){
                    return (max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2.0;
                }
                else{
                    return max(maxLeftX,maxLeftY);
                }
            }
            else if(maxLeftX>minRightY){
                end=partitionX-1;
            }
            else{
                start=partitionX+1;
            }
        }
    }
}//this approach is also known as divide and conquer and partitioning approach and it has a time complexity of O(log(min(n,m))) and space complexity of O(1).

/*lets dry each and every step of the code with an example :
let nums1=[1,3] and nums2=[2]
where n=2 and m=1
now line 9 will check if n<m which is false so we will not swap the arrays and we will proceed with the original arrays.
now we will initialize start=0 and end=2 and we will enter the while loop.
now we will calculate partitionX=(0+2)/2=1 and partitionY=(2+1+1)/2-1=1
ab hum max








*/



