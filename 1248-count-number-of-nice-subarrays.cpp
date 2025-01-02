class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int subarrays = 0,initialGap = 0,qsize =0,start = 0;
        for(int end = 0;end < nums.size();end++){
            if(nums[end] % 2 == 1){
                qsize++;
            }
            if(qsize == k){
                initialGap = 0;
                while(qsize == k){
                    qsize -= nums[start] % 2;
                    initialGap++;
                    start++;
                }
            }
            subarrays += initialGap;
        }
        return subarrays;
    }
};
