#include <bits/stdc++.h>

using namespace std;

// Accepted
int main() {
    int n, l;

    cin >> n >> l;

    int arra[n];

    for(int i = 0; i < n; i++){
        cin >> arra[i];
    }

    sort(arra, arra + n);

    float maxdist = 0;

    for(int i = 0; i < n - 1; i++){
        if(arra[i + 1] - arra[i] > maxdist){
            maxdist = arra[i + 1] - arra[i]; 
        }
    }

    float k = max(arra[0] - 0, l - arra[n-1]);
    cout << setprecision(9) << max(maxdist/2, k);
}