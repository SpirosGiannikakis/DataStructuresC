
#ifndef UTILFUNC_H
#define UTILFUNC_H
#pragma once


#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include "LinkedList.h"


class Vec2{
public:
    double x;
    double y;

  public:
    Vec2(){

    }
    void log(Vec2 &obj);

  public:
    static double distance(Vec2 obj1, Vec2 obj2);


};

std::ostream& operator<<(std::ostream& stream, const Vec2& other){
  stream << other.x << " , " << other.y;
  return stream;
}

double Vec2::distance(Vec2 obj1, Vec2 obj2){
  std::cout << "The distance between the two points is: " << std::setprecision(4) << sqrt(pow(obj1.x - obj2.x, 2) + pow(obj1.y - obj2.y, 2)) << '\n';
  return sqrt(pow(obj1.x - obj2.x, 2) + pow(obj1.y - obj2.y, 2));
}









#endif
