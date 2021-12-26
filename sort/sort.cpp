#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;

void selection_sort(vector<int> &v)
{
    for(int i = 0; i < v.size() - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < v.size(); j++)  if (v[min] > v[j]) min = j;
        swap(v[i], v[min]);
    }
}

void insertion_sort(vector<int> &v)
{
    for(int i = 1; i < v.size(); i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(v[j] < v[j-1]) swap(v[j], v[j-1]);
            else break;
        }
    }
}

void merge(vector<int> &v, vector<int> &a, int l, int m , int h)
{
    for(int k = l; k <= h; k++) a[k] = v[k]; 
    int i = l, j = m + 1;
    for(int k = l; k <= h; k++)
    {
        if(j > h) v[k] = a[i++];
        else if(i > m) v[k] = a[j++];
        else if(v[i] > v[j]) v[k] = a[j++];
        else v[k] = a[i++];
    }
}

void merge_sort(vector<int> &v, vector<int> &a, int l, int h)
{
    if(l >= h) return;
    int m = l + (h - l)/2;
    merge_sort(v, a, l, m);
    merge_sort(v, a, m+1, h);
    merge(v, a, l, m, h);
}

int quick_partition(vector<int> &v, int l, int h)
{
    int i = l;
    int j = h + 1;
    while(true)
    {
        while((v[l] > v[++i]) && ( i != h));
        while((v[l] < v[--j]) && ( j != l));
        if(i >= j) break;
        swap(v[i], v[j]);
    }
    swap(v[j], v[l]);
    return j;
}

void quick_sort(vector<int> &v, int l, int h)
{
    if(l >= h) return;
    int p = quick_partition(v, l, h);
    quick_sort(v, l, p);
    quick_sort(v, p+1, h);
}

int main(void)
{
    vector<int> v{1, 2 , 0 , 5 , 3, 4};
    vector<int> a(v.size()); 
    //selection_sort(v);
    //insertion_sort(v);
    //sort(v.begin(), v.end());
    //merge_sort(v, a, 0, v.size()-1);
    quick_sort(v, 0, v.size() - 1);
    for(auto i = v.begin(); i != v.end(); i++) cout << *i << " " ;
    cout << endl;
    //for(auto i = a.begin(); i != a.end(); i++) cout << *i << " " ;
    //cout << endl; return 0;
}
