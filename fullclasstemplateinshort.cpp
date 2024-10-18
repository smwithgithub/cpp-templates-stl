#include <iostream>
using namespace std;

// Single datatype class template
template <typename T>
class SimpleBox {
    private:
        T value;

    public:
        // Constructor
        SimpleBox(T val) : value(val) {}

        // Method to display the value
        void display() {
            cout << "Value: " << value << endl;
        }
};

// Multiple datatype class template
template <typename T, typename U>
class PairBox {
    private:
        T first;
        U second;

    public:
        // Constructor
        PairBox(T f, U s) : first(f), second(s) {}

        // Method defined outside the class
        void display();
};

// Outside class: method definition
template <typename T, typename U>
void PairBox<T, U>::display() {
    cout << "First: " << first << ", Second: " << second << endl;
}

// Class template with default type
template <typename T = int>
class DefaultBox {
    private:
        T value;

    public:
        // Constructor
        DefaultBox(T val) : value(val) {}

        // Method to display the value
        void display() {
            cout << "Value (with default type): " << value << endl;
        }
};

// Partial specialization of class template
template <typename T>
class SimpleBox<T*> {   // Specialization for pointer types
    private:
        T* value;

    public:
        // Constructor
        SimpleBox(T* val) : value(val) {}

        // Method to display the dereferenced pointer value
        void display() {
            cout << "Pointer value: " << *value << endl;
        }
};

// Class template with non-type parameter and variadic template
template <typename T, int size>
class ArrayBox {
    private:
        T array[size];  // Array of a fixed size

    public:

        // Variadic template method to set values
        template <typename... Args>
        void setValues(Args... args) {
            static_assert(sizeof...(args) == size, "Number of arguments must match array size.");
            T values[] = { args... };
            for (int i = 0; i < size; i++) {
                array[i] = values[i];
            }
        }

        // Method to display the array values
        void display() {
            cout << "Array values: ";
            for(int i = 0; i < size; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    // Single datatype class template usage
    //SimpleBox<int> intBox(5);
    //intBox.display();   // Output: Value: 5

    //SimpleBox<double> doubleBox(10.5);
    //doubleBox.display();  // Output: Value: 10.5

    // Multiple datatype class template usage
    //PairBox<int, double> pairBox(3, 4.5);
    //pairBox.display();   // Output: First: 3, Second: 4.5

    // Class template with default type usage
    //DefaultBox<> defaultBox(7);  // Uses default int type
    //DefaultBox<> defaultBox(7.5);  // also be 7 because of Uses default int type
    //defaultBox.display();   // Output: Value (with default type): 7

    //DefaultBox<float> floatBox(3.5f);  // Overrides default type with float
    //floatBox.display();  // Output: Value (with default type): 3.5

    // Partial specialization of class template usage
    //int num = 42;
    //SimpleBox<int*> pointerBox(&num);
    //pointerBox.display();  // Output: Pointer value: 42

    // Class template with non-type parameter usage
    ArrayBox<int, 5> arrayBox;
    arrayBox.setValues(1, 2, 3, 4, 5);  // Set all values
    arrayBox.display();
    arrayBox.setValues(1, 2, 3, 4.5, 5);  // Set all values
    arrayBox.display();

    return 0;
}
