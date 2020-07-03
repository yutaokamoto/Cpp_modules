#include <bits/stdc++.h>
using namespace std;

//緩和問題の最適解が元の問題の実行可能解であれば，その解は元の問題の最適解になる．
//緩和問題の最適値，最適解，元の問題における実行可能性
int lagrange_for_knapsack(vector<int> Unassigned, int Capacity, vector<int> V, vector<int> W){
    float opt = 0;
    vector<int> x(Unassigned.size(), 0);
    double e = 0.001;
    double ld = 0.0; //λ : ラグランジュ乗数．適当な値から始める．
    double coefficient_of_x;
    int deriative;
    int iteration = 1;
    int n_of_assigned = V.size()-Unassigned.size();

    while(true){
        //あるラグランジュ乗数におけるラグランジュ問題解いて最適解xを求める．
        //(最大か問題の場合)式を整理してx_iの係数が正ならx_i = 1，さもなければ0
        for(auto&& i : Unassigned){
            coefficient_of_x = V[i]-ld*W[i];
            if(coefficient_of_x > 0){
                x[i-n_of_assigned] = 1;
            }
            else{
                x[i-n_of_assigned] = 0;
            }
        }
            //for(auto&& i:x){cout << "x[i]=" << i << endl;}cout << endl;

        //最適解xにおける目的関数の最適値f(λ)の各ラグランジュ乗数についての偏微分df(λ)/dλを求める．
        //解xでの制約の値
        int weight_of_assigned_items = 0;
        for(int i=0;i<x.size();i++){
            weight_of_assigned_items += x[i]*W[i+n_of_assigned];
        }
        deriative = Capacity - weight_of_assigned_items;
            //cout << "deriative=" << deriative << endl;

        //終了の判定．|(df(λ)/dλ)/iteration| < e
        double step_size = deriative/(double)iteration; //途中までキャストを忘れていた
            //cout << "iteration=" << iteration << endl << "step_size=" << step_size << endl;
        if(abs(step_size) < e){
            break;
        }

        //ラグランジュ乗数の更新
        ld = max(0.0, ld-step_size); //ld+step_sizeじゃない
            //cout << "ld=" << ld << endl << endl;

        //次のループへ
        iteration++;
    }
    //printf("final\tld=%f\n", ld);

    for(auto&& i : Unassigned){
        opt += V[i]*x[i-n_of_assigned];
        //cout << "i= " << i << "\t" << "V[i]= " << V[i] << "\t" << opt <<endl;
    }
    opt += ld*deriative;


    return opt;
}