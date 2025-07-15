class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int l=0,r=nums1.size()-1,l2=0,r2=nums2.size()-1;
		while(l<=r&&l2<=r2){
			if(nums1[l]<nums2[l2]) l++;
			else if(nums1[l]>nums2[l2]) l2++;
			
		}
        return nums1[1];
    }
};