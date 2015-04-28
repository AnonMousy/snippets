#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<vi> svi;
typedef vector<svi> vsvi;

vsvi ordered_power_set(int n) {
    /*
      ordered_power_set(n) is power set of {1,...,n} ordered in collections
      according to size of subsets in a collection; 0 represents empty set
      */
    int k = 0;
    vi v1(n + 1), v1a(1);
    svi s1;
    vsvi v3(n + 1, s1);
    (v3[0]).insert(v1a);
    v1a.clear();
    
    while (1) {
        if (v1[k] < n) {
            v1[k + 1] = v1[k] + 1;
            ++k;
            }
        else {
            v1[k - 1]++;
            k--;
            }
        if (k == 0) break;
        
        for (int i = 1; i <= k; i++)
            v1a.push_back(v1[i]);
        v3[v1a.size()].insert(v1a);
        v1a.clear();
        }
        
    return v3;
    }

void print_svi(svi s1) {
    // print elements of s1
    int j = 1;
    for (auto t = s1.begin(); t != s1.end(); t++) {
        for (int i = 0; i < (*t).size(); i++)
            cout << (*t)[i] << ' ';
        cout << "   ";
        j++;
        }
    }

int main() {
    int j = 4;
    for (int i = 0; i < ordered_power_set(j).size(); i++) {
        cout << "subsets of order " << i << ": ";
        print_svi(ordered_power_set(j)[i]);
        cout << endl;
        }
    }
