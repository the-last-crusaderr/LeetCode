class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        
        int temp = INT_MAX;                                     // take max for highest difference
        int result;       
        
        for (int a=0; a<nums.size(); a++)
        {
            int left = a+1;                                      // left pointer
            int right = nums.size()-1;                           // right pointer
            int sum = target - nums[a];                          // target composed of 3 elements, remove one from it and find the sum 
                                                                    // in remaining pairs                        
            
            
            // 2 pointer method
            while (left<right)
            {
                // find the value closest to target
                
                if (temp > abs(nums[left]+nums[right]-sum))
                {
                    temp = abs(nums[left]+nums[right]-sum);
                    result = nums[a]+nums[left]+nums[right];
                }
                
                // find the target and move pointer accordingly
                
                if (nums[left]+nums[right]==sum)
                    return target;
                else if (nums[left]+nums[right]>sum)
                    right--;
                else if (nums[left]+nums[right]<sum)    
                    left++;
            }
            
        }
        
        return result;
        
    }
};
