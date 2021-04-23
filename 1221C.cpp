#include <bits/stdc++.h>
#define arraySize(array) (sizeof(array)/sizeof(array[0]))

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
    int q;

    cin >> q;

    for(int i = 0; i < q; i++){
        int c, m, x;

        cin >> c >> m >> x;

        if(c != m){
            if(x == 0){
                if(c > m){
                    if(m * 2 > c) 
                    {
                        cout << (c + m) / 3 << endl;
                    }
                    else{
                        cout << min(c, m) << endl;
                    }
                }
                else{
                    if(c * 2 > m) 
                    {
                        cout << (c + m) / 3 << endl;
                    }
                    else{
                        cout << min(c, m) << endl;
                    }
                }
            }
            else{
                cout << min(c, m) << endl;
            }
        }
        else{
            if(x >= 0){
                c = c - x;
                m = m - x;
                cout << x + ((c + m) / 3) << endl;
                x = 0;
            }
        }
    }
}