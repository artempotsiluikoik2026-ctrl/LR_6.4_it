// ЛР 6.4 іт

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void Create(double* x, const int size, const double Low, const double High);
void Print(double* x, const int size);
int MinAbsIndex(double* x, const int size);
int FirstNegativeIndex(double* x, const int size);
double SumAbsAfterFirstNegative(double* x, const int size);
int Compress(double* x, const int size, const double a, const double b);
void FillZeros(double* x, const int from, const int size);

int main()
{
    srand((unsigned)time(NULL));
    cout << fixed << setprecision(2);

    int n;
    cout << "n = ";
    cin >> n;
    double a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    if (n <= 0)
    {
        cout << "n must be positive." << endl;
        return 1;
    }

    double* x = new double[n];
    double Low = -10;
    double High = 10;

    Create(x, n, Low, High);
    cout << "Array:" << endl;
    Print(x, n);

    cout << "Index of the minimum by modulus = " << MinAbsIndex(x, n) << endl;
    cout << "Sum of moduli after the first negative = " << SumAbsAfterFirstNegative(x, n) << endl;

    int k = Compress(x, n, a, b);
    FillZeros(x, k, n);
    cout << "Array after compressing:" << endl;
    Print(x, n);

    delete[] x;

    return 0;
}

void Create(double* x, const int size, const double Low, const double High)
{
    for (int i = 0; i < size; i++)
        x[i] = Low + (High - Low) * rand() / RAND_MAX;
}

void Print(double* x, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(8) << x[i];
    cout << endl;
}

int MinAbsIndex(double* x, const int size)
{
    int minIndex = 0;
    for (int i = 1; i < size; i++)
        if (fabs(x[i]) < fabs(x[minIndex]))
            minIndex = i;
    return minIndex;
}

int FirstNegativeIndex(double* x, const int size)
{
    for (int i = 0; i < size; i++)
        if (x[i] < 0)
            return i;
    return -1;
}

double SumAbsAfterFirstNegative(double* x, const int size)
{
    double s = 0;
    int k = FirstNegativeIndex(x, size);
    if (k != -1)
        for (int i = k + 1; i < size; i++)
            s += fabs(x[i]);
    return s;
}

int Compress(double* x, const int size, const double a, const double b)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (x[i] < a || x[i] > b)
        {
            x[k] = x[i];
            k++;
        }
    return k;
}

void FillZeros(double* x, const int from, const int size)
{
    for (int i = from; i < size; i++)
        x[i] = 0;
}