#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
// S0 = {1, 2, ..., n} input alphabet;
// S1 = {0, 1, 2, ..., n} symbols on tape, 0 is blank;     type: vi
// S2 is tape with symbols from S1;                             type: vi
// S3 = {0, 1} is used for{Left, Right} moves on tape;  type: int
// Q is set of states;                                                    type: vvi

// maps f : S1 -> Q and g: S1 -> S3 define change of 
// state; change depends on previous state and symbol in cell

int n = 5; // {0, 1, 2, 3, 4} are possible symbols on tape
    
vvi Q(int n) {
    // Q is set of all maps of set {0, 1, 2, ... ,n}, n = 4; Q(n).size() = n^n
    vi v1;
    int i;
    
    for (i = -1; i < n + 1; i++) v1.push_back(i + 1);
    vi v1a, v1b(n + 1, 0);
    vvi v2;
    
    do {
        for (i = n; i >= 0; --i) v1a.push_back(v1[v1b[i]]);
        
        v2.push_back(v1a);
        v1a.clear();
        
        for (i = 0; i < n + 1; ++i)
            if (++v1b[i] < n + 1) break;
            else v1b[i] = 0;
        }
    while (i < n + 1);
    
    return v2;
    }

vi f(int i) {
    // Choice of state by symbol i in cell
    int j = i*i - i + 123; 
    int k = (2*i - j%12 + 12*j)%Q(n).size(); 
    
    return Q(n - 1)[k];
    }

int g(int i) {
    // g(i) = 0 moves head left, g(i) = 1 moves head right
    int j = i*i - i + 123; 
    int k = 3*j - j/2; 
    return k % 2;
    }

void print_vi(vi v1) {
    // print elements of v1
    cout << "\n";
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << ' '; 
        }
    cout << "\n";
    }

void turing(vi S2, int i, vi v1, int j) {
    // S2 is tape; S2[i] is initial symbol on tape considered by automaton; 
    // v1 is initial state of automaton that should execute j times and stop
    cout << "Initial tape symbols:"; print_vi(S2);
    cout << "Initial state of automaton:"; print_vi(v1);
    cout << "==============" << endl;
    for (int k = 1; k <= j; k++) {
        cout << "step " << k << ", symbol in cell " 
        << i << " is handled:  ";
        // Automaton changes symbol S2[i] into v1[S2[i]]
        S2[i] = v1[S2[i]];  
        // New state of automaton: it depends on previous symbol S2[i] and 
        // previous state v1 implicitly since now is S2[i] = v1[S2[i]].
        // Halting state is not specified for the sake of analysis; or add
        // if (some_condition) break;
        v1 = f(S2[i]);    
        // moving tape left or right inside interval [0, 1, 2, ..., S2.size() - 1]
        if (i > 0 && g(S2[i]) == 0) i -= 1;             
        else if (i == 0 && g(S2[i]) == 0) i += 1;             
        else if (i < S2.size() - 1  && g(S2[i]) == 1) i += 1; 
        else  i -= 1; 
        // print current tape
        print_vi(S2);
        cout << "and automaton goes to state: "; print_vi(v1);
        cout << "----------------------" << endl;
        }
    }

int main() {
    // Choice of tape, initial symbols in cells and, length of tape
    vi S2(10, 0); S2[3] = 4; S2[4] = 2; S2[5] = 1; S2[6] = 4; S2[7] = 3;
    int i = 6;
    // Choice of state of automaton
    int a[] = {2, 0, 2, 4, 3};
    vi v1(a, a + sizeof(a) / sizeof(*a));
    // Automaton should execute 3 times
    turing(S2, i, v1, 3);
    }
