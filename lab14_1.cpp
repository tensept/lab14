#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double d[], int N, double a[] ){
    double max = d[0],min = d[0];
    double sum = 0, sum_sd = 0, sum_gm = 1, sum_hm = 0;
    for(int i=0;i<N;i++){
        sum += d[i];
        a[0] = sum/N;
        sum_sd += pow(d[i],2);
        a[1] = sqrt(((sum_sd)/N)-pow((sum/N),2));
        sum_gm *= d[i];
        a[2] = pow(sum_gm,(1.0/N));
        sum_hm += 1/d[i];
        a[3] = N/sum_hm;   
        for(int j=1;j<N;j++){
        if(d[j]>max) max = d[j];
        if(d[j]<min) min = d[j];
        }
        a[4] = max;
        a[5] = min;
    }
    
}
