class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());                           // sort the input vector
        vector<vector<int>>result;                             
        
        for (int i=0; i<nums.size(); i++)
            cout<<nums[i]<<" ";
        cout<<endl;
        
        for (int a=0; a<nums.size(); a++)                             // fix one number one by one
        {

            int sum=-nums[a];                                         // remove the part of first number from that 
            
            int left=a+1;                                             // left = a + 1 
            int right=nums.size()-1;                                  // right = nums.size() - 1
            
            
            // use 2 pointer method from here
            
            while (left<right)
            {
                if (nums[left]+nums[right]==sum)
                {
                    vector<int>temp{nums[a],nums[left],nums[right]};
                    result.push_back(temp);
                    left++;
                    right--;
                    while (left<right && nums[left]==nums[left-1]) left++;
                    while (left<right && nums[right]==nums[right+1]) right--; 
                }
                else if (nums[left]+nums[right]<sum)
                    left++;
                else if (nums[left]+nums[right]>sum)
                    right--;
                
                
               // cout<<a<<" "<<left<<" "<<right<<endl;
            }
            
            while (a+1<nums.size() && nums[a]==nums[a+1])
                a++;
        }
        
        return result;
    }
};
