#include "TSP.hpp"

struct cell
{
    int element; 
    struct cell *next;
};

double distance(std::tuple<double,double> c1,std::tuple<double,double> c2){
    return sqrt(pow(std::get<0>(c1)-std::get<0>(c2),2)+pow(std::get<1>(c1)-std::get<1>(c2),2));
}

struct cell *insert_element(int x,struct cell *p,struct cell *init)
{
    struct cell *q,*r;

    r=(struct cell*)malloc(sizeof(struct cell));

    if(p==NULL){
        q=init;
        init=r;
    }
    else{
        q=p->next;
        p->next=r;
    }

    r->element=x;
    r->next=q;
    return(init);
};

struct cell *delete_element(struct cell *p,struct cell *init){
    struct cell *q;

    if(init==NULL){
        exit(1);
    }
    if(p==NULL){
        q=init; init=init->next; free(q);
    }
    else{
        if(p->next==NULL){
            exit(1);
        }
        else{
            q=p->next; p->next=q->next; free(q);
        }
    }
    return(init);
}

std::vector<int> NN(int n,std::vector<int> &notdone,std::vector<std::tuple<double,double>> &coordinate){
    int i;
    struct cell *init=NULL;
    struct cell *p=init;
    struct cell *beforep;
    struct cell *beforedelcellptr;
    int now=notdone[0];
    int next;
    double min_distance=-1;
    double dist;
    std::vector<int> done{now}; //notdoneの最初のノードからスタート

    // notdoneの最初のノードをnotdoneから削除
    notdone.erase(notdone.begin());
    // 未走査のノード(notdone)の数(n)を1減らす
    n--;

    // 配列で実現したリストをポインタで実現したリストに組み替える
    for(i=1;i<n+1;i++){
        init=insert_element(i,p,init);
        if(i==1){
            p=init;
        }
        else{
            p=p->next;
        }
        //printf("%d\n",p->element);
    }

    while (n>1) //notdoneの長さが0ではない
    {
        p=init;
        while(p!=NULL){
            dist=distance(coordinate[now],coordinate[p->element]);
            if (min_distance>dist || min_distance<0){
                // nowとiの距離がmin_distanceよりも短ければ，min_distanceを更新
                min_distance=dist;
                // beforedelcellptrを更新
                if(p==init){
                    beforedelcellptr=NULL;
                }
                else{
                    beforedelcellptr=beforep;
                }
                // next(次に訪問する客の候補)を更新
                next=p->element;
            }
            // 次のセルへ
            beforep=p;
            p=p->next;
        }

        // doneにnextを追加
        done.push_back(next);
        // notdoneからnextを削除 このときpはnextの前のセルを指すポインタ
        init=delete_element(beforedelcellptr,init);
        // nowの更新
        now=next;
        // 未走査のノード(notdone)の数(n)を1減らす
        n--;
        // min_distanceを負の値にセット
        min_distance=-1;
    }

    done.push_back(init->element);
    return done;
}

PYBIND11_MODULE(TSP, m) {
    m.doc() = "solve Traveling Salesman Problem.";
    m.def("NN", &NN, "A function which solve TSP by NN algorithm.");
}