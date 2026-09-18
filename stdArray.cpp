//COMSC-210 | Lab 9 (Part 1) | Eric-Giulio Hedes
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 30;

int main()
{
    array<string, SIZE> heights;

    ifstream file;
    int line, i = 0;
    file.open("test.txt");
    if (!file.good()) throw "I/O error";
    if (file.is_open())
    {
        while (cin >> line)
        {
            heights[i] = line;
            i++;
        }
    }
    
    file.close();
    return 0;
}