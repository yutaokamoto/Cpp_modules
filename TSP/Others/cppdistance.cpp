#include<pybind11/pybind11.h>
#include <stdio.h>
#include <math.h>

double distance(double c1_x,double c1_y,double c2_x,double c2_y){
    return sqrt(pow(c1_x-c2_x,2)+pow(c1_y-c2_y,2));
}

PYBIND11_MODULE(cppdistance, m) {
    m.doc() = "please input the coordinates of 2 points.";
    m.def("distance", &distance, "A function which returns distance between 2 points.");
}