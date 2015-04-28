#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
// Setup without set of all states:
// S0 = {1, 2, ..., n} input alphabet;
// S1 = {0, 1, 2, ..., n} symbols on tape, 0 is blank;     type: vi
// S2 is tape with symbols from S1;                             type: vi
// S3 = {0, 1} is used for{Left, Right} moves on tape;  type: int

int n = 5; // {0, 1, 2, 3, 4} are symbols on tape

vi f(vi v1, int i) {
    // Automaton in state v1 is above cell with symbol i
    // Symbol i is changed into v1[i] 
    // Automaton new state is f(v1, i) 
    int k = 0;
    for (int j = 0; j < v1.size(); j++) {
        k = v1[j];
        v1[j] = (j*k + i + k + 2)%n;
        }
    return v1;
    }

int g(int i) {
    // g(i) = 0 moves head left, g(i) = 1 moves head right
    return ((i*i) % (i + 1) + 2*i + 15) % 2;
    }

void print_vi(vi v1) {
    // print elements of v1
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << ' ';
        }
    cout << "\n";
    }

void turing(vi S2, int i, vi v1, int j) {
    // S2 is tape; S2[i] is initial symbol on tape considered by head of automaton;
    // v1 is initial state of automaton that should execute j times and stop
    cout << "Initial tape S2: "; print_vi(S2);
    cout << "Initial state of automaton: "; print_vi(v1);
    int i1;
    for (int k = 1; k <= j; k++) {
        i1 = S2[i];
        cout << "step " << k << ", new is symbol S2[" << i << "]:  ";
        // type new symbol in i-th cell on the tape
        S2[i] = v1[i1];
        // New state of automat: it depends on previous symbol i1 = S2[i] 
        // and current state v1. Halting state is not specified for the sake of analysis,
        //  or add: if (some_condition) break;
        v1 = f(v1, i1);
        // moving tape left or right inside interval [0, 1, 2, ..., S2.size() - 1]
        if (i > 0 && g(S2[i]) == 0) i -= 1;
        else if (i == 0 && g(S2[i]) == 0) i += 1;
        else if (i < S2.size() - 1  && g(S2[i]) == 1) i += 1;
        else  i -= 1;
        // print current tape
        print_vi(S2);
        cout << "new state of automaton: "; print_vi(v1);
        }
    
    }

int main() {
    vi S2(10, 0); S2[3] = 4; S2[4] = 2; S2[5] = 1; S2[6] = 4; S2[7] = 3;
    int i = 6;
    int a[] = {2, 3, 1, 4, 3};
    vi v1(a, a + sizeof(a) / sizeof(*a));
    turing(S2, i, v1, 10);
    }
