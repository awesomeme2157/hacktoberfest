#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform counting sort
void countSort(vector<int> &arr)
{
    // Find the minimum and maximum element in the array
    int maxElement = *max_element(arr.begin(), arr.end());
    int minElement = *min_element(arr.begin(), arr.end());

    // Size of the range
    int range = maxElement - minElement + 1;

    // Create a count array to store the frequency of each element in the range
    vector<int> count(range, 0);

    // Store the count of each element in the count array
    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i] - minElement]++;
    }

    // Overwrite the original array with sorted elements using the count array
    int index = 0;
    for (int i = 0; i < range; i++)
    {
        while (count[i] > 0)
        {
            arr[index++] = i + minElement;
            count[i]--;
        }
    }
}

// Helper function to print the array
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {4, -2, 2, 8, 3, -3, 1};

    cout << "Original array: ";
    printArray(arr);

    countSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
