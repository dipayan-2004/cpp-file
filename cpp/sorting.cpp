#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {                                                              // complexity O(n*n)
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag++;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;                                                 // complexity O(n*n)
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
            { // just finding the minIndex in the series
                minIndex = j;
            }
        }
        // swapping ...............
        swap(arr[minIndex],arr[i]);
        
    }
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n ; i++)
    {
        int curr = arr[i];
        int prev = i - 1;                                               // complexity O(n*n)
        while (prev >= 0 && arr[prev] >curr)
        {
           arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}



int main(void)
{
    int n;
    cout << "write the lenght of the array...\n";
    cin >> n;
    int arr[n];
    cout << "write the elements of the array...\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr, n);
    cout << "the array isss...\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}