# Module for optimization problems
* This is a Python module for solving some types of optimization problems.
<!--* C++でつくったPython用のモジュールです。-->

* This module is built in C++. And it has a Python interface.<!--インターフェースはPythonで、中身はC++です。-->

* You can use it by executing Python file(.py of .ipynb file) in the directory including a ".so file". And you can use this module by importing it. →　You can refer to the example.ipynb in each folder.
<!--* .soファイルと同じディレクトリにPythonの実行ファイルを置き、importにより読み込むことで使用可能です。　→　詳しくは各フォルダ内のexample.ipynbを参照-->

## Description
### 1. TSP
#### 1.1 Algorithms
	1.　Nearest-Neighborhood Algorithm

<!--1,のファイルと同じディレクトリに.py, .ipynbファイルを作成-->
<!--import TSPでモジュールをインポート-->
<!--help(TSP)でモジュールの概要-->
<!--メソッドの名前-->
<!--メソッドの引数-->
<!--メソッドの返り値-->
#### 1.2 How to use?　→　example.ipynbを参照
	1.　Download .so file.

 	2.　Create a .py or .ipynb file in the directory including .so file of 1.

 	3.　Execute "import TSP" for importing this TSP module. 
 	
 	4.　Execute "help(TSP)" for showing the outline of this module. You can get descriptions like below.
	
		- The method's name. (method means )
		
   		- The arguments of this methods.
	
  		- The return value of this method.

### 2. Knaosack
#### ALgorithms
	1.　Dynamic Programming
	
	2.　Branch and bound algorithm

#### How to use?　→　You may refer to the example.ipynb in Knapsack folder.
	1.　Download .so file.

 	2.　Create a .py or .ipynb file in the directory including .so file of 1.

 	3.　Execute "import Knapsack" for importing this TSP module. 
 	
 	4.　Execute "help(Knapsack)" for showing the outline of this module. You can get descriptions like below.
	
		- The method's name.
		
   		- The arguments of this methods.
	
  		- The return value of this method.
