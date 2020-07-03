# cpp_modules
C++でつくったPythonモジュール

.soファイルと同じディレクトリにPythonの実行ファイルを置き，importにより読み込むことで使用可能

## Pybind11を使ったPyhotnモジュール
### TSP
#### 使用しているアルゴリズム
1. Nearest-Neighborhood アルゴリズムにより求解

#### 使用方法　→　example.ipynbを参照
1. .soファイルをダウンロード

2. 1,のファイルと同じディレクトリに.py, .ipynbファイルを作成

3. import TSPでモジュールをインポート

4. help(TSP)でモジュールの概要

  ** メソッドの名前
  
  ** メソッドの引数
  
  ** メソッドの返り値

### Knaosack
#### 使用しているアルゴリズム
1. 動的計画法により求解
2. 分枝限定法により求解

#### 使用方法　→　example.ipynbを参照
1. .soファイルをダウンロード

2. 1,のファイルと同じディレクトリに.py, .ipynbファイルを作成

3. import cpp_knapsackでモジュールをインポート

4. help(cpp_knapsack)でモジュールの概要

  ** メソッドの名前
  
  ** メソッドの引数
  
  ** メソッドの返り値
  
