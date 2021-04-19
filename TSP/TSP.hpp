#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pybind11/numpy.h>
#include <vector>
#include <tuple>
namespace py = pybind11;

//double distance(double c1_x,double c1_y,double c2_x,double c2_y);
double distance(std::tuple<double,double> c1,std::tuple<double,double> c2);
std::vector<int> NN(int n,std::vector<int> &notdone,std::vector<std::tuple<double,double>> &coordinate);
//int NN(int n,std::vector<int> &notdone,std::vector<std::tuple<double,double>> &coordinate);

int add(int i, int j );
void update1(std::vector<double> &x);
void update2(py::array_t<double> x);
double  update3(py::array_t<double> x , int len);
std::vector<int> append(std::vector<int> &v,int size);
std::vector<int> return_0(std::tuple<double,double> t);
std::vector<int> return_1(std::vector<std::tuple<double,double>> &multi_l);
int sum(int* arr, int arr_size);