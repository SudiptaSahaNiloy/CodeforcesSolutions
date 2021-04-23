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
    for(int i = arraySize - 1; i >= position; i--){
        arra[i + 1] = arra[i];
    }
    arra[position] = item;
    arraySize++;
}

int main() {
    int testCase;

    cin >> testCase;

    while(testCase > 0){
        int n;

        cin >> n;

        int arra[n];

        for(int i = 0; i < n; i++){
            cin >> arra[i];
        }

        sort(arra, arra+n);

        cout << arra[0] + arra[1] << endl;

        testCase--;
    }
}