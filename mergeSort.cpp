/*
  Merge sort.

  Created on 28, Sep, 2015

  Zhenfeng Liang. All copyrights(C) reserved.
*/

#include <iostream>


using namespace std;

void merge(int * vec, int start, int mid, int end)
{
    int i, j;
    i = start;
    j = mid + 1;
    int tmp[end - start + 1];

    int k = 0;
    while(i <= mid && j <= end)
    {
        if(vec[i] <= vec[j])
        {
            tmp[k++] = vec[i++];
        }
        else
        {
            tmp[k++] = vec[j++];
        }
    }

    while(i <= mid)
    {
        tmp[k++] = vec[i++];
    }

    while(j <= end)
    {
        tmp[k++] = vec[j++];
    }

    i = start;
    k = 0;

    while(i <= end)
    {
        vec[i++] = tmp[k++];
    }

    return;
}


void mergeSort(int * vec, int start, int end)
{
    
    if(start < end)
    {
        int mid = (end - start) / 2 + start; // We don't use (start + end) / 2 here in case it will be overflow.
        mergeSort(vec, start, mid);
        mergeSort(vec, mid + 1, end);
        merge(vec, start, mid, end);
    }
    
    return;
}



int main(int argc, char* argv[])
{
    const int size = 5;

    int a[size] = {20, 12, 1, 5, 2 };

    for(int i = 0; i < size; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
    
    mergeSort(a, 0, size - 1);

    for(int i = 0; i < size; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
    
    return 0;
}
