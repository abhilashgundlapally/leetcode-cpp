#include <iostream>
#include <vector> 

using namespace std;

int search(std::vector<int>&, int, int , int );

int main(void)
{
    std::vector<int> vec = {-1, 0, 3, 5, 9, 12};
    int target = 2;
    cout<< search(vec, target, 0, vec.size() - 1);
    return 0;
}

int search(std::vector<int>& vec, int target, int i , int j)
{
    if ( i > j ) return -1;
    int mid = (i + j) / 2;
    int val = vec[mid];
    if (val == target) {
        return mid;
    }
    if(target > val)    return search(vec, target, mid+1, j);
    else                return search(vec, target, i, mid - 1); 

}
