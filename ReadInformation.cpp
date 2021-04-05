// ReadInformation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include "Data/ExtraFiles/Simple_window.h"
#include "Data/ExtraFiles/Graph.h"

class Point3d{
public:   
    void getPoints(float *point);
    void setPoints(float x, float y, float z);

private:
    float _x, _y, _z;
    
};

void Point3d:: getPoints(float* point) {
    point[0] = _x;
    point[1] = _y;
    point[2] = _z;

}


void Point3d::setPoints(float x, float y, float z) {
    _x=x;
    _y=y;
    _z=z;

}



void WriteFile(vector<Point3d> points, std::string path) {

    std::fstream outputPath;
    float pointsDetailed[3];
    
    outputPath.open(path, std::ifstream::out);

    for (int i = 0; i < points.size(); i++) {

        points.at(i).getPoints(pointsDetailed);
        outputPath<< pointsDetailed[0] <<" "<< pointsDetailed[1]<<" "<< pointsDetailed[2] <<std::endl;

    }
    outputPath.close();

}


vector<Point3d> ReadFile(std::string path) {
    std::string line;
    std::ifstream ist(path);
    vector<Point3d> points;
    vector<float> allNumbers;

    if (!ist) {
        std::cout << "file doesn't exist" << std::endl;
    }

    while (std::getline(ist, line, ' ')) {
        std::cout << line << std::endl;
        allNumbers.push_back(stof(line));
    };

    for (int i = 0; i < allNumbers.size() / 3; i++) {

        Point3d* point = new Point3d();
        point->setPoints(allNumbers.at(i * 3), allNumbers.at(i * 3 + 1), allNumbers.at(i * 3 + 2));
        points.push_back(*point);

    }
    return points;

}
int main()
{
    std::string path;
    std::fstream fs;
    std::string line;
    std::string outputPath;
    float number=0;
    vector<Point3d> points;
   // std::cout << "Introduce path" << std::endl;
    //std::cin >> path;
    outputPath = "C:/Users/dhuri/OneDrive/CppProgramming/ReadInformation/Data/output.txt";

    path = "C:/Users/dhuri/OneDrive/CppProgramming/ReadInformation/Data/Data.x3d";

    points = ReadFile(path);


    WriteFile(points, outputPath);

    return 0;
}
