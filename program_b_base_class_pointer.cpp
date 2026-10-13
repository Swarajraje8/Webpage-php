/******************************************************************************
 *                                PROGRAM B                                   *
 *    Invoking Derived Class Members Through Base Class Pointer              *
 ******************************************************************************/
// This program demonstrates how to call derived class functions using a base class pointer.

#include <iostream>
using namespace std;

// Base Class
class Base {
public:
    virtual void display() {
        cout << "Display function of Base class" << endl;
    }
    virtual void greet() {
        cout << "Greet function of Base class" << endl;
    }
    virtual ~Base() {}  // Virtual destructor for proper cleanup
};

// Derived Class 1
class Derived1 : public Base {
public:
    void display() override {
        cout << "Display function of Derived1 class" << endl;
    }
    void greet() override {
        cout << "Greet function of Derived1 class" << endl;
    }
    void derivedSpecificMethod() {
        cout << "Derived1-specific method called" << endl;
    }
};

// Derived Class 2
class Derived2 : public Base {
public:
    void display() override {
        cout << "Display function of Derived2 class" << endl;
    }
    void greet() override {
        cout << "Greet function of Derived2 class" << endl;
    }
    void derivedSpecificMethod() {
        cout << "Derived2-specific method called" << endl;
    }
};

int main() {
    cout << "========== Using Base Class Pointer ==========" << endl;
    
    // Create objects
    Derived1 d1;
    Derived2 d2;
    
    // Base class pointers pointing to derived class objects
    Base* ptr1 = &d1;
    Base* ptr2 = &d2;
    
    cout << "\n--- Calling through ptr1 (pointing to Derived1 object) ---" << endl;
    ptr1->display();      // Calls Derived1::display()
    ptr1->greet();        // Calls Derived1::greet()
    
    cout << "\n--- Calling through ptr2 (pointing to Derived2 object) ---" << endl;
    ptr2->display();      // Calls Derived2::display()
    ptr2->greet();        // Calls Derived2::greet()
    
    // Alternative: Using dynamic_cast to call derived-specific methods
    cout << "\n========== Using Dynamic Cast for Derived Methods ==========" << endl;
    
    Base* basePtr = &d1;
    Derived1* derivedPtr = dynamic_cast<Derived1*>(basePtr);
    if (derivedPtr != nullptr) {
        derivedPtr->derivedSpecificMethod();  // Calls Derived1-specific method
    }
    
    cout << "\n--- Attempting cast to wrong derived class ---" << endl;
    basePtr = &d1;
    Derived2* derivedPtr2 = dynamic_cast<Derived2*>(basePtr);
    if (derivedPtr2 == nullptr) {
        cout << "Cast failed: basePtr does not point to Derived2 object" << endl;
    }
    
    return 0;
}

/*
Expected Output:
========== Using Base Class Pointer ==========

--- Calling through ptr1 (pointing to Derived1 object) ---
Display function of Derived1 class
Greet function of Derived1 class

--- Calling through ptr2 (pointing to Derived2 object) ---
Display function of Derived2 class
Greet function of Derived2 class

========== Using Dynamic Cast for Derived Methods ==========
Derived1-specific method called

--- Attempting cast to wrong derived class ---
Cast failed: basePtr does not point to Derived2 object

Explanation:
1. Base class pointers can point to derived class objects.
2. When you call a virtual function through a base class pointer:
   - The function of the actual derived class is called (polymorphism)
   - This is determined at runtime (dynamic dispatch)

3. Using dynamic_cast:
   - Safely checks if the pointer actually points to the target derived class
   - Returns nullptr if the cast is invalid
   - Allows access to derived-class-specific members

4. Key Benefits:
   - Code reusability and flexibility
   - Runtime polymorphism allows different objects to behave differently
   - Dynamic cast provides type safety
*/
