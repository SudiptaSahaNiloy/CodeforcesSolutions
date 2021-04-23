#include <bits/stdc++.h>

using namespace std;

//ACCEPTED
int binarySearch(int arra[],int arraySize, int key){
    int startPoint, endPoint;

    startPoint = 0;
    endPoint = arraySize - 1;

    while(startPoint <= endPoint){
        int midPoint = (startPoint + endPoint) / 2;

        if(arra[midPoint-1] < key && key <= arra[midPoint]){
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
    long int n, m;
    
    cin >> n;

    int arra1[n];

    for(int i = 0; i < n; i++){
        cin >> arra1[i];
    }

    cin >> m;

    int arra2[m];

    for(int i = 0; i < m; i++){
        cin >> arra2[i];
    }

    int arra3[n+1];
    arra3[0] = 0;

    for(int i = 1; i < n; i++){
        arra1[i] = arra1[i - 1] + arra1[i];
    }

    for(int i = 1; i <= n; i++){
        arra3[i] = arra1[i - 1];
    }

    for(int i = 0; i < m; i++){
        cout << binarySearch(arra3, n+1, arra2[i]) <<endl;
    }
}

