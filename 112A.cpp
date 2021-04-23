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
    string str1, str2;

    cin >> str1 >> str2;

    for(int i = 0; i < str1.size(); i++){
        str1[i] = (char) tolower(str1[i]);
        str2[i] = (char) tolower(str2[i]);
    }

    for(int i = 0; i < str1.size(); i++){
        if(str1[i] < str2[i]){
            cout << "-1";
            break;
        }else if(str1[i] > str2[i]){
            cout << "1";
            break;
        }
    }

    if(!str1.compare(str2)){
        cout << '0';
    }
}