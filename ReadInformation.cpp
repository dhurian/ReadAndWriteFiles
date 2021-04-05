// ReadInformation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include "Simple_window"

class Point {
public:   
    void getPoints(float *point);
    void setPoints(float x, float y, float z);

private:
    float _x, _y, _z;
    
};

void Point:: getPoints(float* point) {
    point[0] = _x;
    point[1] = _y;
    point[2] = _z;

}


void Point::setPoints(float x, float y, float z) {
    _x=x;
    _y=y;
    _z=z;

}



void WriteFile(std::vector<Point> points, std::string path) {

    std::fstream outputPath;
    float pointsDetailed[3];
    
    outputPath.open(path, std::ifstream::out);

    for (int i = 0; i < points.size(); i++) {

        points.at(i).getPoints(pointsDetailed);
        outputPath<< pointsDetailed[0] <<" "<< pointsDetailed[1]<<" "<< pointsDetailed[2] <<std::endl;

    }
    outputPath.close();

}
int main()
{
    std::string path;
    std::fstream fs;
    std::string line;
    std::string outputPath;
    float number=0;
    std::vector<float> allNumbers;
    std::vector<Point> points;
   // std::cout << "Introduce path" << std::endl;
    //std::cin >> path;
    outputPath = "C:/Users/dhuri/OneDrive/CppProgramming/ReadInformation/Data/output.txt";

    path = "C:/Users/dhuri/OneDrive/CppProgramming/ReadInformation/Data/Data.x3d";

    std::ifstream ist( path);
    if (!ist) {
        std::cout << "file doesn't exist" << std::endl;
    }
    
    while (std::getline(ist,line, ' ')) {
        std::cout << line << std::endl;
        allNumbers.push_back(stof(line));
    };

    for (int i = 0; i < allNumbers.size() / 3; i++) {

        Point* point = new Point();
        point->setPoints(allNumbers.at(i * 3), allNumbers.at(i * 3 + 1), allNumbers.at(i * 3 + 2));
        points.push_back(*point);

    }


    WriteFile(points, outputPath);
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
