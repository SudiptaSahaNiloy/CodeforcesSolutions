#define as(array) (sizeof(array) / sizeof(array[0]))
#define ll long long
#define dd double
#define mp make_pair
#define pb push_back
#define se second
#define fi first
#define mod 10000007
#define sob(v) v.begin(), v.end()
#define sobr(v) v.rbegin(), v.rend()
#define fr(i, a, b) for (int i = a; i <= b; ++i)
#define frr(i, a, b) for (int i = a; i >= b; --i)
#define pi acos(-1.00)
#define check cout << "*" << endl
#define ffix(x) cout << fixed << setprecision(x)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

// Ascending sort: sort(arra, arra+n)
// Descending sort: sort(arra, arra+n, greater<int>())

#include <bits/stdc++.h>

using namespace std;

bool binarySearch(int arra[], int arraySize, int key)
{
    int startPoint, endPoint;
    int location;

    startPoint = 0;
    endPoint = arraySize - 1;

    while (startPoint <= endPoint)
    {
        int midPoint = (startPoint + endPoint) / 2;

        if (arra[midPoint] == key)
        {
            return true;
            break;
        }
        else if (arra[midPoint] < key)
        {
            startPoint = midPoint + 1;
        }
        else
        {
            endPoint = midPoint - 1;
        }
    }
    return false;
}

void insert(int arra[], int arraySize, int position, int item)
{
    for (int i = arraySize - 1; i >= position - 1; i--)
    {
        arra[i + 1] = arra[i];
    }
    arra[position - 1] = item;
}

int main()
{
    int n;

    string s;

    cin >> n;

    // if(n % 4 == 0 || n % 7 == 0){
    //     cout << "YES";
    //     return 0;
    // }else{
    //     s = to_string(n);
    //     for(char x : s){
    //         if(x == '4' || x == '7'){
    //             count++;
    //         }
    //     }
    // }

    // if(count == s.size()){
    //     cout << "YES";
    // }else
    // {
    //     cout << "NO";
    // }

    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        s = to_string(i);
        for (char x : s)
        {
            if (x == '4' || x == '7')
            {
                count++;
            }
        }
        if (count == s.size() && n % i == 0)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}