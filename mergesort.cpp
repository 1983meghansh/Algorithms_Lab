#include <bits/stdc++.h>
using namespace std;
int counter = 0;

void merge(int array[], int left, int mid, int right)
{
    int i = 0, j = 0, k = left;
    int an = mid - left + 1;
    int bn = right - mid;
    int a[an], b[bn];
    for (int i = 0; i < an; i++)
    {
        a[i] = array[left + i];
        // cout<<a[i]<<" ";
    }
    // cout<<endl;
    for (int i = 0; i < bn; i++)
    {
        b[i] = array[mid + 1 + i];
        // cout<<b[i]<<" ";
    }
    // cout<<endl;
    i = 0;
    j = 0;

    while (i < an and j < bn)
    {
        counter++;
        if (a[i] > b[j])
        {
            array[k] = b[j];
            j++;
        }
        else
        {
            array[k] = a[i];
            i++;
        }
        k++;
    }
    while (i < an)
    {
        counter++;
        array[k] = a[i];
        k++;
        i++;
    }
    while (j < bn)
    {
        counter++;
        array[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(int array[], int start, int end)
{
    if (start >= end)
        return;
    int mid = (end - start) / 2 + start;
    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, end);
    merge(array, start, mid, end);
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    // int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl<<"The count of the basic operations executed for this input is : ";
    cout << counter << endl;

    int a[500], b[500], c[500];
    for(int i = 0; i < 500; i ++){
        a[i] = i;
        b[i] = 500 - i;
        c[i] = int(rand()) % (i+1);
    }
    cout<<"INDEX\t BEST\t WORST \t RANDOM\n";
    for(int i = 16; i < 50; i ++){
        counter = 0;
        mergeSort(a, 0, i);
        cout<<"  "<<i<<"\t "<<counter<<"  \t";
        counter = 0;
        mergeSort(b, 0, i);
        cout<<counter<<" \t  ";
        counter = 0;
        mergeSort(c, 0, i);
        cout<<counter<<" \n";
    }

    cout << endl;
    return 0;
}
