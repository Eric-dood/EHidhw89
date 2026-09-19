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

//Define a prototype for printArray()
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

    file.close();

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
    for (int i = 0; i < SIZE; i++) sum += heights[i]; //Use a for-loop to add the sum
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
    printArray(sortArr); //use printArray() to print the reversed array

    //12) Reverse the array by reverse()
    cout << "12) Reversed array by reverse(): ";
    array<int, SIZE> reverseArr = heights;
    reverse(reverseArr.begin(), reverseArr.end());
    printArray(reverseArr); //use printArray() to print the reversed array

    //13) Reverse the array manually
    cout << "13) Manually reversed array: ";
    array<int, SIZE> reverseArr2 = heights;
    for (int i = 0; i < (SIZE / 2); i++)
    {
        //Use 'last' for the last element
        int last = SIZE - (i + 1);
        //Define temp as the last element
        int temp = reverseArr2[last];
        //Turn the last element to the first element's number
        reverseArr2[last] = reverseArr2[i];
        //The ith element becomes the last element's number
        reverseArr2[i] = temp;
    }
    printArray(reverseArr2); //use printArray() to print the new array

    //14) Find address for the array by data()
    cout << "14) Array address by using data(): " << heights.data() << endl;
    //15) Find address by using &
    cout << "15) Array address by using &: " << &heights << endl;
    //16) Find the max element
    cout << "16) Max: " << *max_element(heights.begin(), heights.end()) << endl;
    //17) Find the min element
    cout << "17) Min: " << *min_element(heights.begin(), heights.end()) << endl;
    //18) Check if the array is empty
    cout << "18) Check if empty: " << ((heights.empty()) ? "Is empty" : "Is NOT empty") << endl;

    //19) Reverse sort the array
    cout << "19) Reverse sorted array by using rbegin() & rend(): ";
    array<int, SIZE> sortArr2 = heights;
    sort(sortArr2.rbegin(), sortArr2.rend());
    printArray(sortArr2); //use printArray() to print the array

    //20) Search for an array by using find()
    int target = 157;
    cout << "20) Find for an array by using find(): ";
    auto t = find(heights.begin(), heights.end(), target); //Use find() to search for the target value
    cout << "Value " << target << " ";
    if (t != heights.end()) //If the target hasn't reached the end
        cout << "found at position " << (t - heights.begin()) << ".";
    else //Otherwise send a 'not found' message.
        cout << "not found.";
    cout << endl;

    //21) Create two empty arrays and fill 'em up
    array<int, 5> arr1, arr2;
    fill(arr1.begin(), arr1.end(), 1); //Fill up array 1 with ones
    fill(arr2.begin(), arr2.end(), 2); //Fill up array 2 with twos
    cout << "21) Create two arrays and use fill(): " << endl;
    cout << "Array 1: ";
    for (int i = 0; i < arr1.size(); i++) cout << arr1.at(i) << " "; //Print arr1
    cout << endl << "Array 2: ";
    for (int i = 0; i < arr2.size(); i++) cout << arr2.at(i) << " "; //Print arr2
    cout << endl;

    //22) Swap two of the arrays
    swap(arr1, arr2); //This function swaps the elements of arr1 and arr2
    cout << "21) Swap the two arrays by using swap(): " << endl;
    cout << "Array 1: ";
    for (int i = 0; i < arr1.size(); i++) cout << arr1.at(i) << " ";
    cout << endl << "Array 2: ";
    for (int i = 0; i < arr2.size(); i++) cout << arr2.at(i) << " ";
    cout << endl;

    //Create a 2D array
    array<int, 3> ar1 = { 1, 2, 3 }, ar2 = { 4, 5, 6 }; //Create ar1 & ar2 as separate 1D-arrays
    array<array<int, 3>, 3> arr2D = { ar1, ar2 }; //Then do a 2D-array with both ar1 and ar2
    for (int i = 0; i < (ar1.size() + ar2.size()); i++)
    {
        if (i == ar1.size()) cout << endl; //If the first array has been printed out, leave in space
        if (i < ar1.size()) cout << ar1[i] << " "; //Print out ar1 elements
        else cout << ar2[i - ar1.size()] << " "; //Print out ar2 elements
    }

    return 0;
}

//Define printArray() to print the list of elements an array has
//NOTE: this is to make the code more versatile and clean looking.
void printArray(array<int, SIZE> arr)
{
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << endl;
}