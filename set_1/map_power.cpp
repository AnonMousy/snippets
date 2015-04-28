#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi map_power(vi v1, int m) {
    // map map_power (v1, m) is m-th power of map v1
    int j = 1;
    vi v1a = v1, v1b = v1;
    
    while (j < m) {
        for (int i = 0; i < v1.size(); i++)
            v1a[i] = v1b[v1[i] - 1];
            
        v1 = v1a;
        j++;
        }
        
    return v1a;
    }

void print_vi(vi v1) {
    // prints elements of v1
    for (int i = 0; i < v1.size(); i++) cout << v1[i] << ' ';
    cout << "\t";
    }

int main() {
    int a[] = {4, 1, 4, 2, 1};
    vi v1(a, a + sizeof(a) / sizeof(*a));
    
    for (int i = 1; i < 10; i++)
       print_vi(map_power(v1, i));
        
    }
