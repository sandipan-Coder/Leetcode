class Solution {
public:

    void merge(vector<int>&nums,int lb, int mid, int hi,vector<int>&ans){
        int i = lb;
        int j = mid+1;
        int k = lb;
        while(i <= mid && j <= hi){
            if(nums[i] < nums[j]){
                ans[k++] = nums[i++];
            }
            else
               ans[k++] = nums[j++];
        }

        while(i <= mid){
            ans[k++] = nums[i++];
        }
        while(j <= hi){
           ans[k++] = nums[j++];
        }
        for(int l = lb; l <= hi; l++){
            nums[l] = ans[l];
        }
    }

    void mergeSort(vector<int>&nums,int lb,int hi,vector<int>&ans){
       
        if(lb < hi){
            int mid = lb + (hi - lb) / 2;
            mergeSort(nums,lb,mid,ans);
            mergeSort(nums,mid+1,hi,ans);
            merge(nums,lb,mid,hi,ans);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        mergeSort(nums,0,n-1,ans);
        return nums;
    }
};