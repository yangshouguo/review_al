#include<iostream>
using namespace std;
#define N 1000

//int database1[N] = { 10,21,34,44,54,78,93 },database2[N] = {9,28,61,64,79,91,100};
int database1[N] = { 4,5,6 },database2[N] = {1,2,3};

//数据库查询
int query(int k, int whichdb){
    if (whichdb == 1){
        return database1[k];
    }

    return database2[k];
}

int main(){

    int n = 3; //数据库大小
    int a = 0 ,b = n-1;
    int nf = 1;
    int first = 1;
    int k ;
    while (a <= b){

        k = a+b;
        k/=2;
        int k2 = n-k-1; //

        int d1 = query(k,1);
        int d2 = query(k2,2);
        //cout<<d1<<" "<<d2<<endl;

        if (a == b){
            cout<< min(d1,d2);
            break;
        }


        if (d1 > d2){
            if (d1<query(k2+1,2)){ //此时d1为第n大的数
                cout<<d2<<endl;
                break;
            }
            b = k;

        }else{
            if (d2 < query(k+1,1))
                {
                    cout << d1 <<endl;
                    break;
                }
                a = k+1;
            }
    }

}
