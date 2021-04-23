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
    int N, W, L;

    // N = the number of trees in the farm 
    // W = the amount of wood (in meters) that have to be gathered
    // L =  the minimum allowed height of the tree to cut.

    cin >> N >> W >> L;

    int arra1[N];
    int arra2[N];

    for(int i = 0; i < N; i++){
        cin >> arra1[i];
        cin >> arra2[i];
    }

    int x = 1; 

    int arra3[N];

    while(1){
        int totalWood = 0; 

        for(int i = 0; i < N; i++){
            if(arra1[i] + (arra2[i] * x) >= L){
                totalWood += arra1[i] + (arra2[i] * x);
            }
        }

        if(totalWood >= W){
            break;
        }
        x++;
    }

    cout << x ;
}