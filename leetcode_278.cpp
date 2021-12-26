#include <iostream>
using namespace std;

bool isBadVersion(int i ){
    return  i >= 1702766719 ? true : false;
}

//2126753390
//1702766719

int firstBadVersion(int v)
{
    int m = 0;
    for (unsigned int i = 1, j = v, m = ((long)(i+j))/2; i <= j ;  ) {
        cout << i << " " << j << " " << m << endl;
        m = (i + j)/ 2;
        if (isBadVersion(m) && !isBadVersion(m-1)) {
            return m;
        }
        if (isBadVersion(m)) {
            j = m - 1;
        }else{
            i = m + 1;
        }

    }
    return -1;
}

int main(void)
{
    cout << firstBadVersion(2126753390);
    return 0;
}





