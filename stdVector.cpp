//COMSC-210 | Lab 9 (Part 1) | Eric-Giulio Hedes
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//SIZE is the maximum size for the array, and in this case, it will be 30.
const int SIZE = 30;

//Define a prototype for printVector()
void printVector(vector<int>);

int main()
{
    //Declare the array with the maximum size and the data type
    //This array will most likely be based on human adult heights, averaging from 120 to 200 cm.
    vector<int> heights;

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
            heights.push_back(line);
        }
    }

    file.close();

    //Start doing certain functions with the vector
    //1) Print out the elements of the vector
    cout << "1) Elements: ";
    printVector(heights);
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
    //9) Front of the vector
    cout << "9) Front: " << heights.front() << endl;
    //10) Back of the vector
    cout << "10) Back: " << heights.back() << endl;
    
    //11) Sort the vector itself
    cout << "11) Sorted vector: ";
    vector<int> sortVec = heights;
    sort(sortVec.begin(), sortVec.end());
    printVector(sortVec); //use printVector() to print the reversed vector

    //12) Reverse the array by reverse()
    cout << "12) Reversed array by reverse(): ";
    vector<int> reverseVec = heights;
    reverse(reverseVec.begin(), reverseVec.end());
    printVector(reverseVec); //use printVector() to print the reversed vector

    //13) Reverse the vector manually
    cout << "13) Manually reversed array: ";
    vector<int> reverseVec2 = heights;
    for (int i = 0; i < (SIZE / 2); i++)
    {
        //Use 'last' for the last element
        int last = SIZE - (i + 1);
        //Define temp as the last element
        int temp = reverseVec2[last];
        //Turn the last element to the first element's number
        reverseVec2[last] = reverseVec2[i];
        //The ith element becomes the last element's number
        reverseVec2[i] = temp;
    }
    printVector(reverseVec2); //use printVector() to print the new array

    //14) Find address for the vector by data()
    cout << "14) Vector address by using data(): " << heights.data() << endl;
    //15) Find address by using &
    cout << "15) Vector address by using &: " << &heights << endl;
    //16) Find the max element
    cout << "16) Max: " << *max_element(heights.begin(), heights.end()) << endl;
    //17) Find the min element
    cout << "17) Min: " << *min_element(heights.begin(), heights.end()) << endl;
    //18) Check if the vector is empty
    cout << "18) Check if empty: " << ((heights.empty()) ? "Is empty" : "Is NOT empty") << endl;

    //19) Reverse sort the vector
    cout << "19) Reverse sorted vector by using rbegin() & rend(): ";
    vector<int> sortVec2 = heights;
    sort(sortVec2.rbegin(), sortVec2.rend());
    printVector(sortVec2); //use printVector() to print the vector

    //20) Search for an vector by using find()
    int target = 157;
    cout << "20) Find for an vector by using find(): ";
    auto t = find(heights.begin(), heights.end(), target); //Use find() to search for the target value
    cout << "Value " << target << " ";
    if (t != heights.end()) //If the target hasn't reached the end
        cout << "found at position " << (t - heights.begin()) << ".";
    else //Otherwise send a 'not found' message.
        cout << "not found.";
    cout << endl;

    //21) Create two empty vector and fill 'em up
    vector<int> vec1(4), vec2(4);
    fill(vec1.begin(), vec1.end(), 1); //Fill up vector 1 with ones
    fill(vec2.begin(), vec2.end(), 2); //Fill up vector 2 with twos
    cout << "21) Create two vectors and use fill(): " << endl;
    cout << "Vector 1: ";
    for (int i = 0; i < vec1.size(); i++) cout << vec1.at(i) << " "; //Print arr1
    cout << endl << "Vector 2: ";
    for (int i = 0; i < vec2.size(); i++) cout << vec2.at(i) << " "; //Print arr2
    cout << endl;

    //22) Swap two of the vectors
    swap(vec1, vec2); //This function swaps the elements of vec1 and vec2
    cout << "21) Swap the two arrays by using swap(): " << endl;
    cout << "Vector 1: ";
    for (int i = 0; i < vec1.size(); i++) cout << vec1.at(i) << " ";
    cout << endl << "Vector 2: ";
    for (int i = 0; i < vec2.size(); i++) cout << vec2.at(i) << " ";
    cout << endl;

    return 0;
}

//Define printVector() to print the list of elements a vector has
//NOTE: this is to make the code more versatile and clean looking.
void printVector(vector<int> vec)
{
    for (int i = 0; i < SIZE; i++) cout << vec[i] << " ";
    cout << endl;
}