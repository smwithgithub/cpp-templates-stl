#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Declare a vector of integers
    vector<int> vec;

    // Add elements to the vector using push_back()
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // Access elements using index
    cout << "Vector elements: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // Insert an element at a specific position (at the beginning)
    vec.insert(vec.begin(), 5);

    // Remove an element at the end using pop_back()
    vec.pop_back();

    // Print updated vector
    cout << "Updated Vector elements: ";
    for (auto val : vec) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
