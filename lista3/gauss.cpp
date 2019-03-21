#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int n;

void gauss(vector< vector<double> > A) {
    for (int j=0; j<n; j++) {
        for(int i = j + 1; i < n; i++){
            if (A[j][j] != 0) {
                double m = (A[i][j] / A[j][j]);
                A[i][j] = m;
                for (int k = j + 1; k <= n; k++) {
                        A[i][k] = A[i][k] - (A[j][k] * m);
                }
            }
        }
    }

    cout << "Final Matrix \n";

    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            cout << fixed << setprecision(4) << A[i][j] << " ";
        }
        cout << endl;
    }
}

void gauss_pivoting(vector< vector<double> > A) {
 for (int j=0; j<n; j++) {
        double max = 0;
        int pivot_max = -1;

        for(int x = j; x < n; x++) {
            if (abs(A[x][j]) > max) {
                max = abs(A[x][j]);
                pivot_max = x;
            }
        }
        
        if(pivot_max != -1) {
            for(int c = j; c <= n; c++) {
                swap(A[j][c], A[pivot_max][c]);
            }
        }    
    
        // Continue with gauss elimination
        for(int i = j + 1; i < n; i++){
            if (A[j][j] != 0) {
                double m = (A[i][j] / A[j][j]);
                A[i][j] = m;
                for (int k = j + 1; k <= n; k++) {
                        A[i][k] = A[i][k] - (A[j][k] * m);
                }
            }
        }
    }

    cout << "Final Matrix \n";

    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            cout << fixed << setprecision(4) << A[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    cin >> n;
    vector< vector<double> > A(n, std::vector<double>(n+1));
    vector< vector<double> > B(n, std::vector<double>(n+1));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            cin >> A[i][j];
        }
    }

    gauss(A);
    //gauss_pivoting(A);
    cout << endl;
}