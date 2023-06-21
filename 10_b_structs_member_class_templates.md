# Compound datatypes struct and class templates

## Introduction to structs, members and member selection.
A struct(short for structure) is a program-defined data type that allows us to bundle multiple variable together into a single type, thus making management of related set of variable much simpler.

**Defining struct**: Since struct is a program-defined data type, we need to define it before using it. The `struct` keyword is used to define a struct followed by a pair of curly braces and finally ending the type definition with a semicolon. Inside the curly braces we define the variables that each struct will contain. The variable that are part of the struct are called **"data member"**(or **"member variable"**).

**Note**: Declaring the member variable is similar to declaring a variable of any other type. Thus providing the data member with empty parenthesis will initialize the value initalize the variables.
```cpp
// Defining a struct

struct Employee           // struct definition
{
    int employee_id{};
    std::string employee_name{};
    DOB employee_DOB{};
};
```

**Defining struct objects/variable**: Defining an object of a structure is similar as declaring a variable of any other type. 
```cpp
// Defining a struct object
Employee joe;             // joe is an object of type Employee
Employee frank;           // frank is also an object of type employee
```

**Accessing a data member**: To access a data member of a struct object we use the **member selection operator**(`.`). The operator is placed between struct variable name and the member variable name. Struct member variable works just like normal variables.

## Struct aggregate initialization**

**Note**: Data members are not initalized by default.

**What is an aggregate**: In general terms, an aggregate data type(also called an aggregate) is any type that can contain data members. Some type can have data members of different types(like struct) and some can have data members of same type(like array).

**Aggregate in C++**: In C++, the definition of aggregate is narrower and quite specific. In C++, an aggregate is a class type(class, struct or union) that has no private or protected non-static data members, no user-provided, inherited, or explicit constructors, no base classes, and no virtual functions.

**Note:** structs with only data members are aggregate in C++.

**Aggregate initialization of a struct:** Aggregates(structs) have multiple variable so to initialize its data member we need to pass multiple value at once. Aggregate use a form of initalization called **"aggregate initialization"**, which allows us to directly initalize the members of aggregate. To do this, we provide an initalizer list(list of comma seperated value) as an initializer. Similar to normal initialization, aggregate initialization can be of copy, list or direct form.

```cpp
// Aggregate initialization of a struct
Employee joe{1, "Joe", {11, 11, 1990}}; // aggregate list initialization
Employee frank = {2, "Frank", {12, 12, 1991}}; // aggregate copy initialization
Employee steve(3, "Steve", {13, 13, 1992}); // aggregate direct initialization
```

Aggregate initialization does a **"memberwise initialization"**(i.e. every memeber is initalized in the order of declearation). If we don't provide an initializer for a member, that member is value initialized. If we provide more initializers than there are members, the extra initializers are ignored.

**Best practice**: Prefer the brace list form when initializing aggregates.

**Const struct:** Variable/object of const datatypes can be declared const. But need to be initialized at the time of declaration. 

```cpp
// Const struct

const Employee steve{3, "Steve", {13, 13, 1992}}; 
```

**Designated Initializer:** Consider you have a struct with two data member and you have numerous object of that struct. Suddently you were needed to added another data member in between now the initialization of the object using initialization list will be a problem. To solve this problem C++20 introduced **"Designated Initializer"**. Using this we can initialize the data member of the struct by specifying the name of the data member in the initialization list. This will allow us to add new data member in between without affecting the initialization of the object.

```cpp

Employee rahul{.employee_id = 4, .employee_name = "Rahul", .employee_DOB = {14, 14, 1993}};
```

**Best practice:** When adding a new member to an aggregate, it's safest to add it to the bottom of the definition list so the initializer for other member don't shift.

**Assignment with initializer list:** We can also use initializer list to assign value to the data member of the struct. This is called **"aggregate assignment"**.

**Assignment with designated initializer(C++20):** Designated initializer can also be used for assignment(via list assignment).

```cpp
// Example

Employee joe{1, "Joe", {11, 11, 1990}}; // aggregate list initialization
joe = {2, "Frank", {12, 12, 1991}}; // aggregate assignment


joe{.employee_id = 1, .employee_name = "Joe", .employee_DOB = {11, 11, 1990}}; // aggregate list initialization
```

### Default member initialization
When we define a struct(or class) type, we provide a default initialization value for each member as part of the type definition. This process is called **"non-static member initialization"**, and the initial value is called a default member initializer.

**All initialization possibilities for a struct**
- If an aggregate is defined with an initializer list: {}
    - If an explict initlization value exists for a member, that value is used.
    - If an initializer is missing and a default member initializer exists, the default is used.
    - If an initializer is missing and theres no default member initializer, the member is value initialized.
- If an aggregate is defined without an initializer list: 
    - If a default member initializer exists, the default is used.
    - If no default member initializer exists, the member remains uninitialized.
    
```cpp
// Example

struct Something
{
    x;        // no default initialization
    y{};      // value initialization by default
    z{5};     // Default initialization
}

int main()
{
    Something s1; // x is uninitialized, y is 0, z is 5
    Something s2{5,6,7}; // x is 5, y is 6, z is 7
    Something s3{}; // x is value initalized and y and z use default values
}
```

**Best practice**: Always provide a default value for all members. This ensures that your member will be initalized even if the variable definition doen't include an initializer list.

**Best practice**: If no explicit initializer value will be provided for an aggregate, prefer value initialization(with an empty brace initializer) over default initialization(with no braces).

### Struct passing and miscellany

**Passing structs using references**:  
Consider three variables describing about an employee, now for passing these three variables to a function we need to pass all these variable to the function which is not a good practice. To solve this problem we can use struct. We can create a struct with three data member and pass the single struct to the function. Structs are generally passed by const reference to avoid making copies.

```cpp
// Example

struct Employee
{
    int employee_id{};
    std::string employee_name{};
    DOB employee_DOB{};
};

void printEmployeeDetails(Employee& employee)
{
    std::cout << Employee.employee_name << '\n';
    std::cout << Employee.employee_id << '\n';
    std::cout << Employee.employee_DOB << '\n';
}
int main()
{

    Employee joe{1, "Joe", {11, 11, 1990}}; // aggregate list initialization
    Employee rahul{2, "Rahul", {12,10,2002}};
    printEmployeeDetails(joe);
    printEmployeeDetails(rahul);

    // here in this case for printing all the details of the employee we only need to pass one struct variable to the function instead of passing all the variable to the function.

    return 0;
}


```

**Returning structs from functions**: Consider when we want a function to return RGB value after calculating a value. We can use struct to return the RGB value from the function. Structs are usually returned by value, so as not to return a dangling reference. We can also return unnamed structs from functions and in case if the function has an explicit return turn instead of using return type deduction we can directly return the struct without even declaring the return type in the return statement of the unnamed struct.

```cpp
// Example

struct RGB
{
    int r{};
    int g{};
    int b{};
};

RGB getRGB{int hexValue}
{
    // code to convert hex value to RGB value
    // returning using a temp variable
    RGB temp{5,8,3};
    return temp;
}

// returning using unnamed struct
RGB getRGB(int hexValue)
{
    // code to convert hex value to RGB value
    return RGB {5,8,3};
    
    // in this case the function has an explicit return type so we can directly return the unnamed struct
    return {5,8,3};
}
```

**Structs with program defined types(other struct, etc):**  
In C++, structs and classes can have members that are other program defined types. There are two ways to do this:

First, we can define one program-defined type in global namespace and then use it as memeber of another program-defined type.
```cpp
// Example

struct Employee
{
    int employee_id{};
    std::string employee_name{};
    int wage{};
};

struct Company
{
    int numberOfEmployees{};
    Employee CEO{};
}

int main()
{
    Company myCompany{100, {1, "Rahul", 10000000}};   // Nested initializer list for initializing employee
    std::cout << Company.CEO.wage << '\n';  // using selection operator twice to access the wage of the CEO of the company
    
    return 0;
}

```

Second, types can also be nested inside other types, so as only Employee existed as part of the company. This approach is more often used with classes

```cpp

struct Company
{
    struct Employee
    {
        int employee_id{};
        std::string employee_name{};
        int wage{};
    };

    int numberOfEmployees{};
    int CEO{};
}

int main()
{
    Company myCompany{100, {1, "Rahul", 10000000}};   // Nested initializer list for initializing employee
    std::cout << Company.CEO.wage << '\n';  // using selection operator twice to access the wage of the CEO of the company
}
```

**Struct size and data structure alignement:** Typically the size of structure is the sum of the size of all the data members, but not always. We can only say that the size of the struct will be at least as large as the size of sum of all the variable it contains. But it could be larger! for performance reasons, the compiler will sometimes add gaps into structures this is called **"padding"**.

```cpp
// Example

struct Foo1
{
    short a{};  // 2 bytes is added as padding after a
    int b{};
    short c{};  // 2 bytes is added as padding after c
    // ideally the size of the structure should be 2 + 4 + 2 = 8 bytes, but it turns out it is 12 bytes
};

struct Foo2
{
    int a{};
    short b{};
    short c{};
// here the size of the struct is 8 bytes
}

int main()
{
    std::cout << sizeof(Foo1) << '\n';  // prints 12
    std::cout << sizeof(Foo2) << '\n';  // prints 8
    return 0;
}
```

### Accessing struct members using pointers and references.

We can access a member of a struct using a member selection operator(.). Since reference to any object is the object itself, so we can directly access the member of referenced struct using a member selection operator(.). Whereas in case of a pointer(that does not point to a struct direclty but stores it address) we would need to first dereference the pointer and then use the member selection operator(.) which is not the best solution. C++ offers a **"member selection from pointer operator(->)"** also know as the **"arrow operator"** that can be used to select members from a pointer to an object. We can use the arrow operator and the member selection operator to access the members of a struct object through a pointer to that struct object(i.e. for nested structs).


```cpp
struct DOB
{
    int date{};
    int month{};
    int year{};
};
struct Employee
{
    std::string employeeName{};
    int employeeID{};
    DOB employeeDOB{};
};

int main()
{
    Employee rahul{"rahul", 01, {10,12,2002}};   // A struct object

    // creating a reference to a struct object
    Employee& refRahul = rahul;

    // Accessing the data member of struct using "member selection operator"
    std::cout << "Employee name is " << refRahul.employeeName << '\n';
    std::cout << "Employee ID is " << refRahul.employeeID << '\n';
    std::cout << "Employee DOB is " << refRahul.employeeDOB.date << '/' << refRahul.employeeDOB.month << '/' << refRahul.employeeDOB.year << '\n';

    // creating a pointer to a struct object
    Employee* ptr{&rahul};

    // std::cout << "/Employee name is " << ptr.employeeName << '\n'; // This gives an error as ptr is address to the struct and not the struct itself we can
    // something like this
    std::cout << "Employee name is" << (*ptr).employeeName << '\n'; // this would work but it ambigious 

    // Instead C++ provides us with 
    std::cout << "Employee name is " << ptr->employeeName << '\n';
    std::cout << "Employee ID is " << ptr->employeeID << '\n';

    // Also we can use the arrow operator and the member selection operator in combination
    std::cout << "Employee DOB is " << ptr->employeeDOB.date << '/' << ptr->employeeDOB.month << '/' << ptr->employeeDOB.year << '\n';

    return 0;
}
```

**Best practice:** When using a pointer to access thee value of a member, use the member selection from pointer operator(->) instead of the member selection operator(.).

---

### Class templates

### Class template argument deduction and deduction guide