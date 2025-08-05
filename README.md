## **what is OOP :**

**OOP** stands for **Object-Oriented Programming** — a programming paradigm based on the concept of **objects**, which are instances of **classes**.

- **Class**: a blueprint or user-defined type that groups data (attributes) and functions (methods).
- **Object**: an actual instance of a class, created at runtime.

## **Four Key Principles of OOP :**

- **Encapsulation**
    - Bundles data and functions together in a class
    - Hides internal details from outside code using access specifiers (`private`, `public`)
    - ✅ Protects and organizes data
- **Abstraction**
    - Shows only essential features and hides complexity
    - ✅ Makes code cleaner and easier to use
- **Inheritance**
    - Allows one class (child) to inherit properties/methods from another (parent)
    - ✅ Promotes code reuse and hierarchy
- **Polymorphism**
    - Means “many forms”: the same function behaves differently for different objects
    - Achieved using **function overloading** or **virtual functions**
    - ✅ Makes code flexible and extensible

# **CPP 01 :**

- **Namespace :**
    1. Prevent name conflicts between functions, variables, etc.
    
    ```cpp
    namespace name {
    // type1 mamber1
    // type2 mamber2
    // type3 mamber3
    .    .     .
    .    .     .
    }
    // Define a namespace called 'first_space'
    namespace first_space {
        void func() {
            cout << "Inside first_space" << endl;
        }
    }
    ```
    
    1. We can access the members of namespace using scope resolution [**operator(::)**](https://www.geeksforgeeks.org/scope-resolution-operator-in-c/).
    
    ```cpp
    namespace_name::member_name;
    ```
    

- **Initialization list :**
    
    an initialization list (also known as a constructor member initializer list) is a mechanism used within a class constructor to initialize its data members before the constructor's body executes.
    
    ```cpp
    class MyClass {
    private:
        int member1;
        double member2;
        const int constMember;
        AnotherClass memberObject;
    
    public:
        MyClass(int val1, double val2, int constVal, AnotherClass obj)
            : member1(val1), member2(val2), constMember(constVal), memberObject(obj)
        {
            // Constructor body (optional)
        }
    };
    ```
    
- **Static :**
    - Shared between all instances of the class.
    - Can be used to track class-wide data.
    - Syntax:
        
        ```cpp
        static int count;
        ```
        
- **Const :**
    
    Prevents changes to variables or methods:
    
    - `const int x = 42;` — value cannot change.
    - `void func() const;` — method won’t modify object state.
- **This pointer :**
    
    The **`this` pointer** is an **implicit pointer** available in all **non-static** member functions of a class.
    
    - It points to the **current object** that invoked the member function.
    - Its type is: `ClassName* const this`
    - It is **not available in static functions**, because they don't belong to an object.
    
    ```cpp
    class Person {
    private:
        std::string name;
    
    public:
        Person(std::string name) {
            this->name = name; // 'this' distinguishes member from parameter
        }
    
        void introduce() {
            std::cout << "Hi, I'm " << this->name << std::endl;
        }
    };
    
    ```
    
- **The** `::` Operator**:**
    
     the `::` operator is called the **scope resolution operator**. It is used to define or access the scope of classes, namespaces, and global variables or functions.
    
- **Summary of Execution Flow in ex02:**
    
    
    | Step | What Happens |
    | --- | --- |
    | Create accounts | `Account` objects are initialized with balances |
    | Display 1 | Show initial account and system-wide stats |
    | Deposit loop | Each account gets a corresponding deposit |
    | Display 2 | Updated balances and deposit counters |
    | Withdrawal loop | Attempt to withdraw from each account |
    | Display 3 | Final balances and withdrawal counters |

# **IOSTREAM :**
`<iostream>` is a **standard C++ header** used for **input and output operations**. It provides access to stream objects like `cin`, `cout`, `cerr`, and `clog`, enabling interaction with the keyboard and screen.

- Handles **stream-based** I/O — treats data as a flow of bytes.
- Abstracts devices like **console**, **files**, etc., using **stream classes**.

---

## **Main Stream Types :**

| Type | Class | Description |
| --- | --- | --- |
| Input | `std::istream` | From device to program (e.g. `cin`) |
| Output | `std::ostream` | From program to device (e.g. `cout`) |

---

## **Standard Stream Objects :**

- `std::cin` → Standard input (keyboard)
- `std::cout` → Standard output (console)
- `std::cerr` → Standard error (unbuffered)
- `std::clog` → Standard error log (buffered)

---

## **Stream Operators :**

- `<<` → **Insertion operator** (used with `cout`)
    - Sends data *into* the output stream
    - Example: `std::cout << "Hello";`
- `>>` → **Extraction operator** (used with `cin`)
    - Extracts data *from* the input stream
    - Example: `std::cin >> age;`

Both operators are **overloaded** for built-in types and can be overloaded for user-defined types.

---

## **Chaining Operators :**

Because both `<<` and `>>` return the stream object, we can chain operations:

```cpp
std::cout << "Name: " << name << ", Age: " << age << std::endl;
std::cin >> x >> y;

```

---

## **endl vs `\n` :**

| Usage | Description |
| --- | --- |
| `std::endl` | Inserts newline **and flushes buffer** |
| `\n` | Inserts newline only |
- Use `"\n"` for better performance unless flushing is required.

---

## **Stream State Functions :**

| Function | Meaning |
| --- | --- |
| `.fail()` | Last input failed (bad format, etc.) |
| `.eof()` | Reached end of input stream |
| `.good()` | Stream is OK and ready to use |
| `.clear()` | Clears error state of the stream |

---

## **Custom Input/Output for Classes :**

You can define how your own class is printed or read by overloading `<<` and `>>`.

```cpp
class Point {
public:
    int x, y;
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

```

---

## **How it All Connects :**

- `cin`, `cout`, etc. are **objects** of stream classes (`istream`, `ostream`)
- `<<` and `>>` are overloaded to work with **multiple data types**
- Streams simplify input/output and work consistently across:
    - **Console**
    - **Files** (via `fstream`)
    - **Strings** (via `stringstream`)

---

## **Summary Table :**

| Component | Purpose |
| --- | --- |
| `#include <iostream>` | Access I/O stream classes and objects |
| `std::cin` | Input stream from keyboard |
| `std::cout` | Output stream to console |
| `<<` operator | Send data into a stream |
| `>>` operator | Extract data from a stream |
| `std::endl` | Newline + flush stream |
