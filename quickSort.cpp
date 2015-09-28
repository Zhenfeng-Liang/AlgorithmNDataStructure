#include <iostream>

using namespace std;

void quickSort(int arr[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot =  arr[(right - left) / 2 + left];

    while(i <= j)
    {
        while(arr[i] < pivot)
            i++;

        while(arr[j] > pivot)
            j--;

        while(i < j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if(left < j)
        quickSort(arr, left, j);

    if(i < right)
        quickSort(arr, i, right);
    

    return;
}


int main(int argc, char * argv[])
{

    const int size = 5;

    int a[size] = {20, 12, 1, 5, 2 };

    for(int i = 0; i < size; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
    
    quickSort(a, 0, size - 1);

    for(int i = 0; i < size; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
    

    return 0;
}
