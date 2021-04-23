#include <bits/stdc++.h>
#define arraysize(array) (sizeof(array)/sizeof(array[0]))
#define loop(i,a,b) for (int i = a; i < b; i++)
#define loopData(array) (cout << array[i] << " ")

using namespace std;

int binarySearch(int arra[],int arraySize, int key, int highestKey){
    int startPoint, endPoint;
    int midPoint;
    int location;

    startPoint = 1;
    endPoint = arraySize;

    int minimum = highestKey;
    int totalMinimum = 0;

    for(int i = 1; i <= arraySize; i++){
        if(arra[i] < minimum){
            minimum = arra[i];
        }
    }

    for(int i = 1; i <= arraySize; i++){
        if(arra[i] == minimum){
            totalMinimum++;
        }
    }

    while(startPoint <= endPoint){
        midPoint = (startPoint + endPoint) / 2;

        if(arra[midPoint] == minimum && totalMinimum == 1){
            return midPoint;
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
    return 0;
}

int main() {
    int n, m;

    cin >> n >> m;

    int buskets[m];

    for(int i = 1; i <= m; i++){
        buskets[i] = 0;
    }

    int balls[n];

    for(int i = 1; i <= n; i++){
        balls[i] = i;
    }

    for(int i = 1; i <= n; i++){
        binarySearch(buskets, m, balls[i], n);
    }
}