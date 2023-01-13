#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool img[][M]){
    cout << "------------------------------------------------------------------------\n";
    for(int i=0; i<30; i++){ 
        cout << "|";  
        for(int j=0; j<70 ;j++){   
            if(img[i][j]==1) cout << "*";
            else cout << " ";
        }
        
       cout << "|"; 
       cout << "\n"; 
       }
     
    cout << "------------------------------------------------------------------------\n";
}

void updateImage(bool img[][M],int x,int y,int s){
    for(int i=0;i<30;i++){
        for(int j=0;j<70;j++){
            if(sqrt(pow(i-y,2)+pow(j-s,2)) <= x-1){
                img[i][j] = 1;
            }
        }
    }
}