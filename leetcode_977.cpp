#include <iostream>
#include<vector>

using namespace std;

vector<int> sortedSquares(vector<int>& nums)
{
    int i = 0, j = nums.size() - 1;

    while(i != j){

    }
}

int main(void)
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    sortedSquares(nums);
    for(auto i = nums.begin(); i != nums.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
}


