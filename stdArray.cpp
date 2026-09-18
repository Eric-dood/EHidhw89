//COMSC-210 | Lab 9 (Part 1) | Eric-Giulio Hedes
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <string>
using namespace std;

//SIZE is the maximum size for the array, and in this case, it will be 30.
const int SIZE = 30;

int main()
{
    //Declare the array with the maximum size and the data type
    //This array will most likely be based on human heights, averaging from 120 to 200 cm.
    array<int, SIZE> heights;

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
    for (int i = 0; i < SIZE; i++)
        cout << heights[i] << " ";
    cout << endl;
    //2) Array size
    cout << "2) Size: " << heights.size() << endl;
    return 0;
}