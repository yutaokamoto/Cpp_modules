#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include "bits/stdc++.h"
using namespace std;
namespace py = pybind11;

pair<vector<int>, int> dynamic(int N, vector<int> V, vector<int> W, int K);
pair<vector<int>, int> branchandbound(int N, vector<int> V, vector<int> W, int K);