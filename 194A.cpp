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
    int milkSolids, milkFat, milkSolidNotFat = 0;

    cin >> milkSolidNotFat >> milkFat;

    milkSolids = milkFat + milkSolidNotFat;

    if(milkSolids >= 15 && milkFat >= 8){
        cout << 1;
    }else if(milkSolids >= 10 && milkFat >= 3){
        cout << 2;
    }else if(milkSolids >= 3){
        cout << 3;
    }else{
        cout << 4;
    }
}