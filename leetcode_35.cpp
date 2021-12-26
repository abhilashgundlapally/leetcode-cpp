#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target){
    int i = 0 , j = nums.size()-1, mid;
    while(i<=j){
        mid = i + (j-i)/2;
        if(nums[mid] > target) j = mid -1 ;
        else                    i = mid + 1;
        if(nums[mid] == target) return mid;
    }
    return i;
}

int main(void){
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    cout << searchInsert(nums, target) << endl;
    return 0;
}



