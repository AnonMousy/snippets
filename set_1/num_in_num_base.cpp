#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

vi num_in_num_base(int i, int j) {
    // num_in_num_base (i, j) is vi vector of number i 
    // in number base j (i and j are in number base 10)
    vi v1;
    
    if (i < j)
        v1.push_back(i);
    else {
        div_t d;
        while (i >= j) {
            d = div(i, j);
            v1.push_back(d.rem);
            i = d.quot;
            }
        v1.push_back(i);
        }
    reverse(v1.begin(), v1.end());
    return v1;
    }

        void print_vi (vi v1) {
            // print elements of v1
            for (int i = 0; i < v1.size(); i++)
                cout << v1[i] << ' ';
            cout << "\t";
            }

int main() {
    for (int i = 1234565; i <= 1234570; i++) {
        cout << "number " << i << " in base " << 10 << " is: ";
        print_vi(num_in_num_base(i, 10));
        cout << endl;
        }
    cout << endl;
    int j = 321;
    for (int i = 1234565; i <= 1234570; i++) {
        cout << "number " << i << " in base " << j << " is: ";
        print_vi(num_in_num_base(i, j));
        cout << endl;
        }   
    }
