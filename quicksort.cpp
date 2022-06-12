#include<iostream>
using namespace std;

int ct=0;
int partition( int arr[], int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {
        ct++;

        while(arr[i] <= pivot) 
        {
            i++;
            ct++;
        }

        while(arr[j] > pivot) {
            j--;
            ct++;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(int arr[], int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partitioon 
    int p = partition(arr, s, e);

    //left part sort karo
    quickSort(arr, s, p-1);

    //right part sort karo
    quickSort(arr, p+1, e);

}

int main() {

    int arr[17] = {2,4,1,6,9 ,9,9,9,9,9,34,2323,121121,55,1,0,3};
    int n = 17;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;
     cout << endl<<"The count of the basic operations executed for this input is : ";
    cout << ct << endl;
     int a[500], b[500], c[500];
    for(int i = 0; i < 500; i ++){
        a[i] = i;
        b[i] = 500 - i;
        c[i] = int(rand()) % (i+1);
    }
    cout<<"INDEX\t BEST\t WORST \t RANDOM\n";
    for(int i = 16; i < 50; i ++){
       ct = 0;
        quickSort(a, 0, i);
        cout<<"  "<<i<<"\t "<<ct<<"  \t";
        ct = 0;
       quickSort(b, 0, i);
        cout<<ct<<" \t  ";
        ct = 0;
        quickSort(c, 0, i);
        cout<<ct<<" \n";
    }

    cout << endl;


    return 0;
}