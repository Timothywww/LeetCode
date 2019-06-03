/* Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
] */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            int target = -nums[i];
            int front = i+1;
            int rear = nums.size()-1;
            
            while(front<rear){
                int sum = nums[front]+nums[rear];
                if(target>sum){
                    front++;
                }
                else if(target<sum){
                    rear--;
                }
                else{
                    vector<int> triplet(3,0);
                    triplet[0]=nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[rear];
                    ret.push_back(triplet);
                    while(front<rear && triplet[1]==nums[front]){
                        front++;
                    }
                    while(front<rear && triplet[2]==nums[rear]){
                        rear--;
                    }

                }
            }
            while(i+1<nums.size()&&nums[i+1]==nums[i]){
                i++;
            }
            
        }
    return ret;
        
    }
};

/*  */