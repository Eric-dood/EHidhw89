//COMSC-210 | Lab 9 (Part 1) | Eric-Giulio Hedes
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//SIZE is the maximum size for the array, and in this case, it will be 30.
const int SIZE = 30;

void printArray(array<int, SIZE>);

int main()
{
    //Declare the array with the maximum size and the data type
    //This array will most likely be based on human adult heights, averaging from 120 to 200 cm.
    array<int, SIZE> heights;

    //Random seed generator
    srand(time(0));

    //Add a file variable that'll be used up for adding array elements
    ifstream file;
    int line, index = 0;
    file.open("test.txt");
    if (!file.good()) throw "I/O error";
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> line;
            heights[index++] = line;
        }
    }

    //file.close();

    //Start doing certain functions with the array
    //1) Print out the elements of the array
    cout << "1) Elements: ";
    printArray(heights);
    //2) Array size
    cout << "2) Size: " << heights.size() << endl;
    //3) 14th element
    cout << "3) 14th element: " << heights[14] << endl;
    //4) Random element
    cout << "4) Random element: " << heights[rand() % (SIZE - 1)] << endl;
    //5) 10th element by using at()
    cout << "5) 10th element by using at(): " << heights.at(10) << endl;
    //6) Random element by using at()
    cout << "6) Random element by using at(): " << heights.at(rand() % (SIZE - 1)) << endl;
    //7) Sum of all elements
    int sum;
    for (int i = 0; i < SIZE; i++)
        sum += heights[i];
    cout << "7) Sum of heights: " << sum << endl;
    //8) Average of all heights
    cout << "8) Average: " << sum / SIZE << endl;
    //9) Front of the array
    cout << "9) Front: " << heights.front() << endl;
    //10) Back of the array
    cout << "10) Back: " << heights.back() << endl;
    
    //11) Sort the array itself
    cout << "11) Sorted array: ";
    array<int, SIZE> sortArr = heights;
    sort(sortArr.begin(), sortArr.end());
    printArray(sortArr);

    //12) Reverse the array by reverse()
    cout << "12) Reversed array by reverse(): ";
    array<int, SIZE> reverseArr = heights;
    reverse(reverseArr.begin(), reverseArr.end());
    printArray(reverseArr);

    //13) Reverse the array manually
    cout << "13) Manually reversed array: ";
    array<int, SIZE> reverseArr2 = heights;
    for (int i = 0; i < (SIZE / 2); i++)
    {
        int last = SIZE - (i + 1);
        int temp = reverseArr2[last];
        reverseArr2[last] = reverseArr2[i];
        reverseArr2[i] = temp;
    }
    printArray(reverseArr2);
    
    return 0;
}

void printArray(array<int, SIZE> arr)
{
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << endl;
}