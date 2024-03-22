#include <iostream>
using namespace std;

int main() {
    int *ptr = nullptr; // Initialize ptr as a null pointer

    cout << "Before dereferencing:" << endl;
    cout << "Address of ptr: " << &ptr << endl;
    cout << "Value of ptr: " << ptr << endl;

    try {
        int i = *ptr; // Attempt to dereference a null pointer
    } catch (bad_alloc& e) {
        cout << "A bad_alloc exception occurred." << endl;
    } catch (...) {
        cout << "An unknown exception occurred." << endl;
    }

    cout << "\nAfter dereferencing:\n";
    cout << "Address of ptr: " << &ptr << endl;
    cout << "Value of ptr: " << ptr << endl;

    return 0;
}
