#include <bits/stdc++.h>
using namespace std;

/*tuple<int, int, bool> lagrange_for_shortestpath(vector<int> Unassigned, int Capacity, vector<int> V, vector<int> W, int n_of_equation){
    int opt;
    vector<int> x(Unassigned.size(), 0);
    bool feasibility;
    float e = 0.01;
    vector<int> ld(n_of_equation, 1); //λ : ラグランジュ乗数．適当な値から始める．サイズn_of_equationの配列を全て1で初期化
    int reducedcost_of_x;
    vector<int> partial_grad(n_of_equation, 0);
    int iteration = 1;

    while(true){
        //あるラグランジュ乗数におけるラグランジュ問題解いて最適解xを求める．
        //(最大か問題の場合)式を整理してx_iの係数が正ならx_i = 1，さもなければ0
        for(auto&& i : Unassigned){
            reducedcost_of_x = V[i]-accumulate(ld.begin(), ld.end(), 0)*W[i];
            if(reducedcost_of_x >= 0){
                x[i] = 1;
            }
            //else if(reducedcost_of_x == 0){
            //    x[i];
            //}
            else{
                x[i] = 0;
            }
        }

        //最適解xにおける目的関数の最適値f(λ)の各ラグランジュ乗数についての偏微分df(λ)/dλを求める．
        //解xでの制約の値
        partial_grad

        //終了の判定．|(df(λ)/dλ)/iteration| < e

        //ラグランジュ乗数の更新

        //次のループへ
        iteration++;
    }

    return forward_as_tuple(opt, x, feasibility);
}*/

double Reducedcost(double ld, int v_i, int w_i){
    return v_i-ld*w_i;
}

//緩和問題の最適解が元の問題の実行可能解であれば，その解は元の問題の最適解になる．
//緩和問題の最適値，最適解，元の問題における実行可能性
int lagrange_for_knapsack(vector<int> Unassigned, int Capacity, vector<int> V, vector<int> W){
    float opt = 0;
    vector<int> x(Unassigned.size(), 0);
    double e = 0.001;
    double ld = 0.0; //λ : ラグランジュ乗数．適当な値から始める．
    double reducedcost_of_x;
    int grad;
    int iteration = 1;
    int n_of_assigned = V.size()-Unassigned.size();

    while(true){
        //あるラグランジュ乗数におけるラグランジュ問題解いて最適解xを求める．
        //(最大か問題の場合)式を整理してx_iの係数が正ならx_i = 1，さもなければx_i = 0．
        for(auto&& i : Unassigned){
            reducedcost_of_x = Reducedcost(ld, V[i], W[i]);//V[i]-ld*W[i];
            if(reducedcost_of_x > 0){
                x[i-n_of_assigned] = 1;
            }
            else{
                x[i-n_of_assigned] = 0;
            }
        }
            //for(auto&& i:x){cout << "x[i]=" << i << endl;}cout << endl;

        //最適解xにおける目的関数の最適値f(λ)の各ラグランジュ乗数についての偏微分df(λ)/dλを求める．
        //解xでの制約の値．
        int weight_of_assigned_items = 0;
        for(int i=0;i<x.size();i++){
            weight_of_assigned_items += x[i]*W[i+n_of_assigned];
        }
        grad = Capacity - weight_of_assigned_items;
            //cout << "grad=" << grad << endl;

        //終了の判定．|(df(λ)/dλ)/iteration| < e
        double step_size = grad/(double)iteration; //途中までキャストを忘れていた．
            //cout << "iteration=" << iteration << endl << "step_size=" << step_size << endl;
        if(abs(step_size) < e){
            break;
        }

        //ラグランジュ乗数の更新．
        ld = max(0.0, ld-step_size); //ld+step_sizeじゃない．
            //cout << "ld=" << ld << endl << endl;

        //次のループへ．
        iteration++;
    }
    //printf("final\tld=%f\n", ld);

    for(auto&& i : Unassigned){
        opt += V[i]*x[i-n_of_assigned];
        //cout << "i= " << i << "\t" << "V[i]= " << V[i] << "\t" << opt <<endl;
    }
    opt += ld*grad;


    return opt;
}

int main(){
    /*vector<int> l = {0,1,2,3};
    cout << accumulate(l.begin(), l.end(), 0, [&](int i, int j){
        cout << i << "\t" << j << "\t" << (i%2==0) << endl;
        if(i%2==0){return (i+j);}else{return 0;}
        }
    ) << endl;
    vector<int> v = {2,3};
    vector<int> a = {0,1,2,3};
    vector<int> b = {0,1,2,3};
    //cout << accumulate(next(l.begin(), (l.size()-v.size())), l.end(), 0, [](int i, int j, vector<int> a, vector<int> b){return a[i]*b[i];}) << endl;
    //cout << accumulate(*(l.begin()+2), l.end(), 0) << endl; これだとできない
    */
   
    int N = 3;
    vector<int> unassigned{0,1,2};
    vector<int> V{45,48,35};
    vector<int> W{5,8,3};
    int K = 10;

    cout << lagrange_for_knapsack(unassigned, K, V, W) << endl;
    //cout << lagrange_for_knapsack({1,2}, 5, V, W) << endl;
    return 0;
}