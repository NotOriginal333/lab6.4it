#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>

using namespace std;

int CountElementsLessThanC(double* r, const int size, double C) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (r[i] < C) {
            count++;
        }
    }
    return count;
}

int FindLastNegativeIndex(double* r, const int size) {
    int lastNegativeIndex = -1;
    for (int i = 0; i < size; i++) {
        if (r[i] < 0) {
            lastNegativeIndex = i;
        }
    }
    return lastNegativeIndex;
}

int SumIntPartsAfterLastNegative(double* r, const int size, int lastNegativeIndex) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (i > lastNegativeIndex) {
            sum += (int)(r[i]);
        }
    }
    return sum;
}

int FindMaxIndex(double r[], const int size) {
    int maxIndex = 0;
    for (int i = 0; i < size; i++) {
        if (r[i] > r[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void TransformArray(double r[], const int size) {
    int maxIndex = FindMaxIndex(r, size);
    int lessThan20PercentCount = 0;

    for (int i = 0; i < size; i++) {
        if (i != maxIndex && abs(r[i] - r[maxIndex]) / r[maxIndex] <= 0.2) {
            lessThan20PercentCount++;
        }
    }

    int pos = 0;
    for (int i = 0; i < size; i++) {
        if (i != maxIndex && abs(r[i] - r[maxIndex]) / r[maxIndex] <= 0.2) {
            double temp = r[i];
            r[i] = r[pos];
            r[pos] = temp;
            pos++;
        }
    }
}

void Input(double* r, const int size) {
    for (int i = 0; i < size; i++) {
        cout << "a[" << i << "] = ";
        cin >> r[i];
    }
    cout << endl;
}

void Print(double* r, const int size) {
    for (int i = 0; i < size; i++)
        cout << setw(4) << r[i] << " ";
    cout << endl;
}

int main() {
    srand((unsigned)time(NULL));
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    double C;
    cout << "Enter the value of C: ";
    cin >> C;

    double* r = new double[n]; 

    Input(r, n);
    Print(r, n);

    int count = CountElementsLessThanC(r, n, C);
    cout << "Less than C: " << count << endl;

    int sum = SumIntPartsAfterLastNegative(r, n, FindLastNegativeIndex(r, n));
    cout << "Sum: " << sum << endl;
    TransformArray(r, n);

    Print(r, n);

    delete[] r;

    return 0;
}
