#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;


vi map_product(vi v1a, vi v1b) {
    // map map_product(v1a, v1b) is map defined as 
    // composition (or product) of maps v1a and v1b
    vi v1 = v1a;
    for (int i = 0; i < v1a.size(); i++) v1[i] = v1a[v1b[i] - 1];
    
    return v1;
    }

void print_vi(vi v1) {
    // prints elements of v1
    for (int i = 0; i < v1.size(); i++) cout << v1[i] << ' ';
    cout << endl << endl;
    }

int main() {
    int a[] = {1, 2, 1, 3};
    vi v1a(a, a + sizeof(a) / sizeof(*a));
    
    int b[] = {4, 1, 2, 2};
    vi v1b(b, b + sizeof(b) / sizeof(*b));
    
    print_vi(map_product(v1a, v1b));
    
    }
