#include <bits/stdc++.h>
using namespace std;

struct node{
    int name;
    struct node* left = NULL;
    struct node* right = NULL;
};

int main(){
    int l[3] = {0,1,2};
    cout << l << endl;
    
    struct node root = {0};
    cout << root.name << endl;

    struct node root_left;
    root_left = {root.name*2+2};
    root.left = &root_left;
    cout << root.left->name << endl;

    struct node now;
    struct node now_left;
    struct node now_right;
    vector<struct node> Stack{root};
    now = Stack.back();
    Stack.pop_back();
    cout << now.name << endl;
    now_left = {now.name*2+2};
    now_right = {now.name *2+1};
    cout << now_left.name << endl;
    cout << now_right.name << endl;

    vector<int> x;
    int node = 10110;
    while(node > 0){
        x.push_back(node%10);
        node = node/10;
    }
    for(auto&& i:x){
        cout << i << endl;
    }
    
    return 0;
}