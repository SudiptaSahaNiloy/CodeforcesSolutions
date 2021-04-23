#define    as(array)    (sizeof(array)/sizeof(array[0]))
#define    ll           long long
#define    dd           double
#define    mp           make_pair
#define    pb           push_back
#define    se           second
#define    fi           first
#define    mod          10000007
#define    sob(v)       v.begin(),v.end()
#define    sobr(v)      v.rbegin(),v.rend()
#define    fr(i,a,b)    for(int i=a;i<=b;++i)
#define    frr(i,a,b)   for(int i=a;i>=b;--i)
#define    pi           acos(-1.00)
#define    check        cout<<"*"<<endl
#define    ffix(x)      cout<<fixed<<setprecision(x)
#define    fast         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

// Ascending sort: sort(arra, arra+n)
// Descending sort: sort(arra, arra+n, greater<int>())

#include <bits/stdc++.h>

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

long long int fast_exp(int base, int exp){
    int M;
    if(exp == 1){
        return base;
    }else
    {
        if(exp % 2 == 0){
            long long int base1 = pow(fast_exp(base, exp/2), 2);
            if(base1 >= M){
                return base1 % M;
            }else
            {
                return base1;
            }
        }else
        {
            long long int ans = base * pow(fast_exp(base, (exp-1)/2), 2);
            if(ans >= M){
                return ans % M;
            }else
            {
                return ans;
            }
        }
    }
}

int isPrime(int n){
    if(n <= 1){
        return 0;
    }else
    {
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0)
                return 0;
        }
        return 1;
    }
    
}

vector <int> Prime;
int mark[mod];

void sieve(int n){
    int i, j, limit = sqrt(n);

    mark[1] = 1; // marking the non primes as 1 and primes as 0

    for(int i = 4; i <= n; i += 2){ //all the even are non prime
        mark[i] = 1;
    }

    Prime.push_back(2); //we know 2 is a prime number

    for(int i = 3; i <= n; i += 2){ // running loop for all odd numbers
        if(!mark[i]){
            Prime.push_back(i); // if i is not marked as 1 then i is a Prime

            if(i <= limit){ // marking all the 2*i, 3*i, 4*i... as non prime as i is Prime
                for(int j = 2 * i; j < n; j += i){
                    mark[j] = 1;
                }
            }
        }
    }
}

int NoOfDivisors(int n){
    int total = 1;

    for(int i = 0; i < Prime.size(); i++){
        if(n % Prime[i] == 0){
            int count = 0;
            while(n % Prime[i] == 0){
                n = n / Prime[i]; // loshagu kortesi
                count++; //kotogula same moulik utpadok ase oita count kortesi
            }
            total *= (count + 1); //theory hocche NOD = (moulik utapadok er power + 1) * (moulik utapadok er power + 1) .....
        }
    }

    return total;
}

vector <int> divisors[mod];

void Divisors(int n){
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            divisors[j].push_back(i);
        }
    }

    for(int i = 1; i <= n; i++){
        for(auto j = divisors[i].begin(); j != divisors[i].end(); j++){
            cout << *j << " ";
        }
        cout << endl;
    }
}

int main(){
    int t;

    cin >> t;

    while(t > 0){
        int n, k;

        cin >> n >> k;

        vector <int> arra;

        int x;

        for(int i = 0; i < n; i++){
            cin >> x;
            arra.push_back(x);
        }

        int max_index = max_element(arra.begin(), arra.end()) - arra.begin();
        int min_index = min_element(arra.begin(), arra.end()) - arra.begin();

        if(n == 2){
            while(k > 0){
                if(arra[min_index] < 0) 
                    break;
                else
                {
                    arra[max_index] = arra[max_index] - 1;
                    arra[min_index] += 1;
                    k--;
                }
            }
        }else
        {
            for(int i = 0; i < n; i++){
                if(arra[i] > 0){
                    while(k > 0 && arra[i] != -1){
                        arra[i] = arra[i] - 1;
                        arra[max_index] += 1;
                        k--;
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            cout << arra[i] << " ";
        }

        cout << endl;
        
        t--;
    }
}