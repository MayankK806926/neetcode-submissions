class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        int tarIdx = total / 2;
        int prev = 0, curr = 0;
        int i=0,j=0;

        for(int step=0;step <= tarIdx;++step){
            prev = curr;
            if(i < n && (j >= m || nums1[i] <= nums2[j])){
                curr = nums1[i++];
            }else curr = nums2[j++];
        }        

        if(total % 2) return curr;
        else return (prev + curr) / 2.0;
    }
};
