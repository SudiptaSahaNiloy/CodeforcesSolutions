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

int main() {
    string givenString;

    cin >> givenString;

    for(int i = 0; i < givenString.size(); i++){
        givenString[i] = (char) tolower(givenString[i]);
        if(givenString[i] == 'a' || givenString[i] == 'o' || givenString[i] == 'y' || givenString[i] == 'e' || givenString[i] == 'u' || givenString[i] == 'i'){
            continue;
        }else{
            cout << '.' << givenString[i];
        }
    }
}