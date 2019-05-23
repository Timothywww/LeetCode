/* 
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

 */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret = {};
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]==target-nums[i]){
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
        
    }
};
/* O(n^2) running time. O(1) space complexity.
hash table saves time.

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int>hash_table;
        for(int i=0;i<nums.size();i++){
            int find_number = target - nums[i];
            if(hash_table.find(find_number)!=hash_table.end()){
                result.push_back(hash_table[find_number]);
                result.push_back(i);
                return result;
            }
            hash_table[nums[i]]=i;
        }
        return result;
        
    }
};

/* one pass hash table.
while inserting numbers, we are trying to find the complement at the same time.
O(n) to traverse, O(1) to look up and O(n) for space */

/* Hash_table */