#include <bits/stdc++.h>
#define arraysize(array) (sizeof(array)/sizeof(array[0]))
#define loop(i,a,b) for (int i = a; i < b; i++)
#define loopData(array) (cout << array[i] << " ")

using namespace std;

bool binarySearch(int arra[],int arraySize, int key){
    int startPoint, endPoint;
    int location;

    startPoint = 0;
    endPoint = arraySize - 1;

    while(startPoint <= endPoint){
        int midPoint = (startPoint + endPoint) / 2;

        if(arra[midPoint] == key){
            return true;
            break;
        }
        else if(arra[midPoint] < key){
            startPoint = midPoint + 1;
        }
        else
        {
            endPoint = midPoint - 1;
        }   
    }
    return false;
}

void insert(int arra[], int arraySize, int position, int item){
    for(int i = arraySize - 1; i >= position-1; i--){
        arra[i+1] = arra[i];
    }
    arra[position-1] = item;
}

int main() {
    int N;

    cin >> N;

    int arra1[N][2];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            cin >> arra1[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            arra1[i + 1][j] = arra1[i + 1][j] + arra1[i][j];
        }
    } 

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < 2; j++){
    //         cout << arra1[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int max = 0, W;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 1; j++){
            if(abs(arra1[i][j+1]-arra1[i][j]) > max){
                max = abs(arra1[i][j+1]-arra1[i][j]);
                if(arra1[i][j]-arra1[i][j+1] > 0){
                    W = 1;
                }else
                {
                    W = 2;
                }
            }
        }
    }

    cout << W << " " << max; 
}