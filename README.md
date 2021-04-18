# Module for optimization
* This is a module for Python made by C++.
* C++でつくったPython用のモジュールです。

* Locate exec file of Python in the directory including .so file of C++. And you can use this module by importing it.　→　More detail is descrived in example.ipynb in each folder.
* .soファイルと同じディレクトリにPythonの実行ファイルを置き、importにより読み込むことで使用可能です。　→　詳しくは各フォルダ内のexample.ipynbを参照

## Description
### 1. TSP
#### 1.1 Algorithms
	1.　Nearest-Neighborhood Algorithm

#### 1.2 How to use?　→　example.ipynbを参照
	1.　.soファイルをダウンロード

 	2.　1,のファイルと同じディレクトリに.py, .ipynbファイルを作成

 	3.　import TSPでモジュールをインポート

 	4.　help(TSP)でモジュールの概要
	
		- メソッドの名前  
		
   		- メソッドの引数  
	
  		- メソッドの返り値  

### 2. Knaosack
#### 使用しているアルゴリズム
	1.　動的計画法
	
	2.　分枝限定法

#### 使用方法　→　example.ipynbを参照
	1.　.soファイルをダウンロード

 	2.　1,のファイルと同じディレクトリに.py、.ipynbファイルを作成

 	3.　import cpp_knapsackでモジュールをインポート

 	4.　help(cpp_knapsack)でモジュールの概要
	
		- メソッドの名前  
		
   		- メソッドの引数  
	
  		- メソッドの返り値  
