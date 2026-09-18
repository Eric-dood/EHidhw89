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
    for (int i = 0; i < SIZE; i++)
        cout << heights[i] << " ";
    cout << endl;
    //2) Array size
    cout << "2) Size: " << heights.size() << endl;
    //3) 15th element
    cout << "3) 15th element: " << heights[14] << endl;
    //4) Random element
    cout << "4) Random element: " << heights[rand() % (SIZE - 1)] << endl;
    //5) Sum of all elements
    int sum;
    for (int i = 0; i < SIZE; i++)
        sum += heights[i];
    cout << "5) Sum of heights: " << sum << endl;
    //6) Average of all heights
    cout << "6) Average: " << sum / SIZE << endl;
    return 0;
}