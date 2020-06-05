//#include "knapsack.hpp"
#include <bits/stdc++.h>
using namespace std;

struct node{
    int name;
    int depth;
    int value;
    int room;
    struct node* left = NULL;
    struct node* right = NULL;
};

//木にノードを追加する
/*void insert(){
};*/

//ノードを数字として持つ用
/*int Node_depth(int node){
    int depth = 0;
    if(node==1){
        return 1;
    }
    else{
        while(!( ( pow(2,depth)-2<node )&&( node<=pow(2,depth+1)-2 ) )){
            depth += 1;
        }
    }
    return depth;
}*/

//ノードを数字として持つ用
/*vector<int> Restoration(int node){
    vector<int> x;
    while(!(node==0)){
        if(node%2==0){
            x.insert(x.begin(),0);
            node = (node-2)/2;
        }
        else{
            x.insert(x.begin(),1);
            node = (node-1)/2;
        }
    }
    return x;
}*/

//ノードを構造体で持つ用
vector<int> Restoration(int node){
    vector<int> x;
    while(node > 0){
        x.push_back(node%10);
        node = node/10;
    }
    return x;
}

int Simplex(vector<int> Unassigned, int Capacity, vector<int> V, vector<int> W){
    int x = 0;
    sort(Unassigned.begin(), Unassigned.end(), [&](const int i, const int j){
        return V[i]/W[i] > V[j]/W[j];
    });
    //for(auto&& i : Unassigned){
    //        cout << "V/W order " << i << " ";
    //}cout << endl;

    for(auto &&i : Unassigned){
        if(Capacity>0){
            if(W[i]<Capacity){
                x += V[i];
                Capacity -= W[i];
            }
            else{
                x += V[i]*(Capacity/W[i]);
            }
        }
        else{
            break;
        }
    }
    return x;
}

//ノードを数字として持つ用
/*int Relax(int now, int N, vector<int> V, vector<int> W, int K){
    int x = 0;
    int Capacity = K;
    vector<int> Assigned = Restoration(now);
    //cout << "割り当てずみのアイテムの個数は" << Assigned.size() << "個" << endl;
    vector<int> Unassigned;
    int node_index = 0;

    for(int i=Node_depth(now); i<N; i++){
        Unassigned.push_back(i);
    }

    for(int j : Assigned){
        if(j==1){
            x += V[node_index];
            //cout << "アイテム" << node_index << "を割り当て " << V[node_index] << endl;
            Capacity -= W[node_index];
        }
        node_index += 1;
    }

    if(Capacity<0){
        return 0; //実行不能解
    }
    else{
        x += Simplex(Unassigned, Capacity, V, W);
        return x;
    }
}*/

//ノードを構造体で持つ用
int Relax(struct node now, int N, vector<int> V, vector<int> W){
    int x = now.value;
    vector<int> Unassigned;

    for(int i=now.depth; i<N; i++){
        Unassigned.push_back(i);
    }

    if(now.room<0){
        return 0; //実行不能解
    }
    else{
        x += Simplex(Unassigned, now.room, V, W);
        return x;
    }
}

//ノードを数字として持つ
/*pair<vector<int>, int> branchandbound(int N, vector<int> V, vector<int> W, int K){
    vector<int> x;
    ////vector<int> now; 走査中のノードが対応する解を表す
    int now = 0;
    vector<int> Stack{0}; //走査する予定だが，まだ走査されていないノードを保管
    float relax = 0.0; //緩和解の値
    ////vector<int> solution; (暫定的な・最終的な)解に対応するノード名を保存する
    int solution = 0; //(暫定的な・最終的な)解に対応するノード名を保存する
    int solution_temp = 0; //暫定解・最適解
    int last_node = pow(2,N+1)-2; //exhaust treeの最後の(右端の)ノード

    //Stackが空でない限りループ *深さ優先探索*
    while (!Stack.empty())
    {
        //Stackの一番最後のアイテムを取り出す
        now = Stack.back();
        Stack.pop_back();

        //緩和問題の解を求める
        relax = Relax(now, N, V, W, K);

        //そのノードにおける解が実行不能
        if(!relax){
            continue;
        }
        //そのノードにおける解が実行可能
        else{
            //緩和問題の解 > 今まで見つかった最適解
            if(relax > solution_temp){
                //子がある(branching) → 葉でない
                if(2*now <= last_node){
                    //スタックに子を入れる
                    Stack.push_back(2*now+2);
                    Stack.push_back(2*now+1);
                }
                //子がない → 葉になる 緩和解と実際の解が同じになる
                else{
                    solution_temp = relax;
                    solution = now;
                    continue;
                }
            }
            //緩和問題の解 < 今まで見つかった最適解 → 走査をやめる(pruning)
            else{
                continue;
            }
        }
    }

    //解の復元
    x = Restoration(solution);

    return make_pair(x, solution_temp);
}*/

//ノードを構造体で持つ
pair<vector<int>, int> branchandbound(int N, vector<int> V, vector<int> W, int K){
    vector<int> x; //最適解を入れとくやつ

    //int now = 0; //走査中のノード名を表す
    struct node now; //走査中のノード
    struct node now_left;
    struct node now_right;

    //vector<int> Stack{0}; //走査する予定だが，まだ走査されていないノードを保管
    struct node root = {0, 0, 0, K};
    vector<struct node> Stack{root};

    float relax = 0.0; //緩和解の値
    int solution = 0; //(暫定的な・最終的な)解に対応するノード名を保存する
    int solution_temp = 0; //暫定解・最適解
    ////int last_parent = pow(2,N)-2; //exhaust treeの最後の(右端の)親ノード

    //Stackが空でない限りループ *深さ優先探索* + アイテムを入れるか決める順番はインデックス順
    while (!Stack.empty())
    {
        //Stackの一番最後のアイテムを取り出す
        now = Stack.back();
        Stack.pop_back();

        //緩和問題の解を求める
        relax = Relax(now, N, V, W);

        //そのノードにおける解が実行不能
        if(!relax){
            continue;
        }
        //そのノードにおける解が実行可能
        else{
            //緩和問題の解 > 今まで見つかった最適解
            if(relax > solution_temp){
                //子がある(branching) → 葉でない
                if(now.depth < N){ //if(now.name <= last_parent){
                    //スタックに子を入れる
                    now_left = {now.name*10+1, now.depth+1, now.value+V[now.depth], now.room-W[now.depth]}; //now_left = {now.name*2+2, now.depth+1};
                    now_right = {now.name*10, now.depth+1, now.value, now.room}; //now_right = {now.name*2+1, now.depth+1};
                    Stack.push_back(now_left);
                    Stack.push_back(now_right);
                    now.left = &now_left;
                    now.right = &now_right;
                }
                //子がない → 葉になる 緩和解と実際の解が同じになる
                else{
                    solution_temp = relax;
                    solution = now.name;
                    continue;
                }
            }
            //緩和問題の解 < 今まで見つかった最適解 → 走査をやめる(pruning)
            else{
                continue;
            }
        }
    }

    //解の復元 intをvectorにしてるだけ
    x = Restoration(solution);

    return make_pair(x, solution_temp);
}

pair<vector<int>, int> dynamic(int N, vector<int> V, vector<int> W, int K){
    int matrix[K+1][N+1];
    vector<int> x;

    //matrixの初期化
    for(int k=0; k<K+2; k++){
        for(int n=0; n<N+2; n++){
            matrix[k][n] = 0;
        }
    }

    //動的計画
    for(int n=1; n<N+1; n++){
        for(int k=0; k<K+1; k++){
            if (n==0){
                continue;
            }
            if(W[n]<K){
                matrix[k][n] = max(matrix[k][n-1], matrix[k-W[n]][n-1]+V[n]);
            }
            else{
                matrix[k][n] = matrix[k][n-1];
            }
        }
    }

    int now_k = K;
    int now_n = N;
    
    //ナップサックに入れたアイテムをxに入れていく
    for(int i=0; i<N; i++){
        if(matrix[now_k][now_n] == matrix[now_k][now_n-1]){
            now_n -= 1;
        }
        else{
            x.push_back(now_n);
            now_k -= W[now_n];
            now_n -= 1;
        }
    }

    return make_pair(x, matrix[K][N]);
}

int main(){
    
    int N = 3;
    vector<int> V{45,48,35};
    vector<int> W{5,8,3};
    int K = 10;
    //int x = Relax(0, N, V, W,K);

    pair<vector<int>, int> ans = branchandbound(N, V, W, K);

    for(auto&& i : ans.first){
        cout << i << "\t";
    }
    cout << endl << ans.second << endl;

    //for(auto&& i : ans.first){
    //    cout << i << endl;
    //}
    //cout << ans.second << endl;

    //struct node root = {0};
    //cout << root.name << endl;
    //struct node root_left = {2};
    //root.left = &root_left;
    //cout << root.left << endl;
    //cout << root.left->name << endl;

    //struct node* now = &root;
    //cout << now->name << endl;
    //scout << now.name << endl;

    return 0;
}

/*PYBIND11_MODULE(cpp_knapsack, m) {
    m.doc() = "solve Knapsack Problem.";
    m.def("dynamic", &dynamic, "A function which solve knapsack by dynamic programming.\nArguments :\nThe number of items N\nThe list of item`s value V\nThe weight of item`s weight W\nThe capacity of the knapsack K");
    m.def("branchandbound", &branchandbound, "A function which solve knapsack by branch and bound using depth-first search.\nArguments :\nThe number of items N\nThe list of item`s value V\nThe weight of item`s weight W\nThe capacity of the knapsack K");
}*/