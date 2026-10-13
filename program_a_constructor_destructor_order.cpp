/******************************************************************************
 *                                PROGRAM A                                   *
 *      Constructor and Destructor Execution Order with Multiple Inheritance   *
 ******************************************************************************/
// This program illustrates the order of execution of constructors and destructors
// when a class is derived from more than one base class.

#include <iostream>
using namespace std;

// First Base Class
class Base1 {
public:
    Base1() {
        cout << "Constructor of Base1 is called" << endl;
    }
    ~Base1() {
        cout << "Destructor of Base1 is called" << endl;
    }
};

// Second Base Class
class Base2 {
public:
    Base2() {
        cout << "Constructor of Base2 is called" << endl;
    }
    ~Base2() {
        cout << "Destructor of Base2 is called" << endl;
    }
};

// Third Base Class
class Base3 {
public:
    Base3() {
        cout << "Constructor of Base3 is called" << endl;
    }
    ~Base3() {
        cout << "Destructor of Base3 is called" << endl;
    }
};

// Derived Class inheriting from multiple base classes
class Derived : public Base1, public Base2, public Base3 {
public:
    Derived() {
        cout << "Constructor of Derived is called" << endl;
    }
    ~Derived() {
        cout << "Destructor of Derived is called" << endl;
    }
};

int main() {
    cout << "========== Creating Derived Object ==========" << endl;
    Derived obj;
    
    cout << "\n========== Derived Object Destroyed ==========" << endl;
    return 0;
}

/*
Expected Output:
========== Creating Derived Object ==========
Constructor of Base1 is called
Constructor of Base2 is called
Constructor of Base3 is called
Constructor of Derived is called

========== Derived Object Destroyed ==========
Destructor of Derived is called
Destructor of Base3 is called
Destructor of Base2 is called
Destructor of Base1 is called

Explanation:
1. When an object of Derived class is created:
   - Constructors of base classes are called in the order they are inherited (Base1, Base2, Base3)
   - Then the constructor of Derived class is called

2. When the object is destroyed:
   - Destructor of Derived class is called first
   - Destructors of base classes are called in reverse order (Base3, Base2, Base1)

This ensures proper initialization and cleanup of resources.
*/
