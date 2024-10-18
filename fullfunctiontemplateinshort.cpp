#include <iostream>
using namespace std;

// Same datatype
template <typename T>
void sPrintAdd(T a, T b){
    cout << "Addition is: " << a + b << endl;
}

// Multiple datatypes
template <typename T, typename Q>
void mPrintAdd(T a, Q b){
    cout << "Addition is: " << a + b << endl;
}

// Same datatype with return
template <typename T>
T sReturnAdd(T a, T b){
    return a + b;
}

// Multiple datatypes with return
template <typename T, typename Q, typename S>
T mReturnAdd(Q a, S b){
    return a + b;
}

// Multiple datatypes with return as auto
template <typename Q, typename S>
auto mAReturnAdd(Q a, S b) {
    return a + b;
}

// Default template argument (new case)
template <typename T = int>
T defaultAdd(T a, T b) {
    return a + b;
}

// Variadic templates for arbitrary arguments (new case)
template <typename... Args>
auto variadicAdd(Args... args) {
    return (args + ...);  // Fold expression to add all arguments
}

int main() {
    int a = 5;
    double b = 10.5;
    double z = 2.5;
    float c = 2.5;
    int d = 4;

    // Same datatype print template calling
    // sPrintAdd(a, d);
    // sPrintAdd(z, b);

    // Multiple datatype print template calling
    // mPrintAdd(a, b);  // Multiple types

    // Same datatype return template calling
    // cout << sReturnAdd(a, d) << endl;
    // cout << sReturnAdd(b, z) << endl;

    // Multiple datatype return template calling
    // cout << mReturnAdd<int, int, int>(a, d) << endl;
    // cout << mReturnAdd<double, double, double>(b, z) << endl;

    // Multiple datatype return auto template calling
    // cout << mAReturnAdd(a, d) << endl;
    // cout << mAReturnAdd(b, z) << endl;

    // Default template argument
    cout << defaultAdd(5, 10) << endl;  // Uses int as default type

    // Variadic templates
    cout << variadicAdd(1, 2.5, 3, 4, 5) << endl;  // Sum of multiple arguments
}
