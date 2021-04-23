#include <bits/stdc++.h>
#define arraysize(array) (sizeof(array)/sizeof(array[0]))
#define loop(i,a,b) for (int i = a; i < b; i++)
#define loopData(array) (cout << array[i] << " ")

typedef long long LL;

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

const int arrayMaxSize = int(1e5 + 3);

int main() {
    int n, m, position[arrayMaxSize];

    cin >> n;

    for(int i = 0; i < n; i++){
        int number;
        cin >> number;
        position[number] = i + 1;
    }

    cin >> m;

    LL vasyaCount = 0, petyaCount = 0;

    for(int i = 0; i < m; i++){
        int number;
        cin >> number;
        vasyaCount += position[number];
        petyaCount += n - position[number] + 1;
    }

    cout << vasyaCount << " " << petyaCount;
}