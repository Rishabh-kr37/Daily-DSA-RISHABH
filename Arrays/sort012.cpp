#include <iostream>
using namespace std;

#include <bits/stdc++.h>

void shifting(int arr[], int n)
{

        int low = 0;
        int high = n - 1;
        int mid = 0;

        while (low <= high)
        {

                switch (arr[mid])
                {

                case 0:
                        swap(arr[low++], arr[mid++]);
                        break;

                case 1:
                        mid++;
                        break;

                case 2:
                        swap(arr[mid], arr[high--]);
                        break;
                }
        }
        for (int i = 0; i < n; i++)
        {
                cout << arr[i] << " ";
        }
        cout << endl;
}
void print(int arr[], int n)
{

        for (int i = 0; i < n; i++)
        {
                cout << arr[i] << " ";
        }
        cout << endl;
}

int main()
{

        int arr[] = {2, 2, 0, 1, 0, 1};
        int n = 6;

        shifting(arr, n);
        print(arr, n);
}