# Arrays

## Introduction

**Arrary:** An **Array** is an aggregate data type that let us access many variable of the same type through a single identifier. In an array declaration, we use square brackets([]) to tell the compiler both that this is an array variable(instead of a normal variable), as well as how many variable to allocate(called array length).

```cpp
int studentScore[30]{};   // fixed-length array, as the array length is know at the compile time
```

**Array element and subscripting:** Each of the variables in an array is called an "element". Elements do not have their own unique names. Instead, to access individual element of an array. We use the array name, along with the **"subscript operator([])"**, and a parameter called an "index" that tells the comiler which element we want. This process is called "subscripting" or "indexing" the array.

**Note:** For an array of length N, the array index are numbered 0 through N-1. This is called an array's range.

**Array Datatypes:** Array can be made from any data types. Array can also be made from structs. Arrays can also be made up of arrays.

```cpp

#include<iostream>
#include<string>

int main()
{
    int firstFivePrimeNum[5]{};   // Array declaration and value initialization

    firstFivePrimeNum[0] = 2;   // initialization of elements using subscript
    firstFivePrimeNum[1] = 3;    // array index starts from zero till N-1(i.e. 4)
    firstFivePrimeNum[2] = 5;
    firstFivePrimeNum[3] = 7;
    firstFivePrimeNum[4] = 11;

    double testPercentage[3]{58.2,83.6,92.4}; // An array of double data type, initialize using list initialization.

    std::string rahulSibling[3]{"kamini", "rohan", "rohit"};  // an array of string data type

    struct Fraction
    {
        int numerator{};
        int denomenator{};
    };

    Fraction someFraction[2]{};

    someFraction[0].numerator = 5;
    someFraction[0].denomenator = 8;

    // Accessing the values using subscript operator and index

    std::cout << "The sum of first five natural numbers are: " << firstFivePrimeNum[0] + firstFivePrimeNum[1] + firstFivePrimeNum[2] + firstFivePrimeNum[3] + firstFivePrimeNum[4] << '\n';

    std::cout << "The name of rahul's sibling are: " << rahulSibling[0] << ',' << rahulSibling[1] << ','<< rahulSibling[2] << ',' << '\n';

    // Accessing struct variable using subscript operator, index and memeber selection operator

    std::cout << "The ratio is: " << someFraction[0].numerator << '/' << someFraction[0].denomenator << '\n';

    return 0;
}
```

**Array subscript:** In C++ array subscript, must always be an "integral data type". This includes char, short, int, long, long long, bool(where false is 0 and true is 1). An array subscript can be a literal value, a variable or an expression to evaluate to an integral type. Enum are also integral values that can be used to index elements of an array.

**Fixed array declaration:** When declaring a fixed array, the length of the array must be a compile-time constant. This is becuare teh length of a fixed array must be know at compile time.

```cpp
// Valid length for a fixed array

// using a literal constant
int numberOfLessonPerDay[7]{}; 

// using constexpr symbolic const
constexpr int daysPerWeek{ 7 };
int numberOfLessonsPerDay[daysPerWeek]{};

// Using an enumerator
enum DaysOfWeek
{
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday,

    maxDaysOfWeek,
};

int numberOfLessonsPerDay[maxDaysOfWeek]{};


// Invalid length for a fixed array
int dayPerWeek{};
std::cin >> dayPerWeek >> '\n';

int numberOfLessonsPerDay[dayPerWeek];  // days-per-week is not a compile time constant

int temp{ 5 };  // 
const int daysPerWeek{temp}; // this is runtime time constant variable

int numberOfLessonPerDay[daysPerWeek]{};  // Not ok, not a compile time constant.
```

**Limitations of fixed length array:**
- Memory for fixed length array is allocated at compile time and hence the lenght of fixed array cannot be changed.
- Fixed array cannot have a length based on either user input or some other value calculated at runtime.


**Initializing fixed arrays:** C++ provides a way to initialize entire arrays via use of an **initializer list({})**. If there are more initializers in the list than the array length, the compiler will generate an error. If there are less initializers in the list then array can hold, the remaining elements are initialized to 0 or whatever value 0 converts to for a non-fundamental types. This is called zero initialization.

**Best practice:** Explicitly initialize your arrays(even when the element type is self-initializing.(like string))
```cpp
int someIntArr[5]{};  // not self - initialized, hence zero intializing
double someDoubArr[5]{};  // nof self - initialized, hence zero intializing
std::string someStrArr[5]{}; // self initialized to empty string, still zero initalizing.
```

**Omitted length:** If you are initializng a fixed array of elements using an initializer list, the compiler can figure cout the length of the array for us, and we can omit explicitly declaring the length of the array.

```cpp
// omitted length
int someIntArr[5]{5,2,4,6,8};  // length is provided, so an array of length 5 is created
int someIntArr2[]{5,6,2,4,8}; // length is not provided, but the compiler is able to determine the length using the initializer list and creates an array of length 5.
```

**Arrays and enums:** One of the big documentation problems with arrays is that integer indices do not provide any information to the program about the meaning of the index. This can be solved by setting up an enumeration where one enumerator maps to each of the possible array indices.

```cpp
struct StudentName
{
    rahul,
    rohit,
    rohan

    maxNumberOfStudent;
};

int main()
{
    int testScore[maxNumbereOfstudent]{};  // if number or student increases the length of array will also increase automatically.
    testScore[rohit] = 20;  // using enumerator for better readabitlity of the program

    return 0;
}
```

**Note:** This trick only workd if you do not changes the enumerator values manually.

**Array and enum classes:** Enum classes don't have an implicit conversion to integer. So index an array using enumarator of enum classes gives an error. Though we can use explict type conversion(static_cast) for converting the value but it is not that useful instead we should use normal enum inside a namespace.

**Passing arrays to functions:** In C++, when a normal variable is passed by value, C++ copies the value of the argument into the function parameter. Becuase the parameter is a copy, changing the value of the parameter does not changes the value of the original arguement. However, because copying large arrays can be very expensive, C++ does not copy an array when an array is passed into a function. Instead, the actual array is passed. This has the side effect of allowiing the functions to directly changes the value of array elements.

**Determing the length of an array:** The **"std::size()"**(since C++17) function from the `<iterator>` header can be used to determing the length of the arrays.

```cpp

int array[]{5,8,25,3,4};
std::cout << "The array has: " << std::size(array) << "element\n";   // returns 5

return 0;
```

**Note:** Due to the way C++ passes arrays to function, this will not work for arrays that have been passed to functions. std::size works with other kinds of objects(sucha as std::array or std::vector).

**Note:** `std::size()` returns a value of unsigned integer to get an return value of signed integer we can use `std::ssize()`(stands for signed size, since C++20).

**Indexing an array out of range:** When we try to access an array with a subscript outside that range, C++ does not do any checking to make sure that your indices are valid for the length of your array. It will inserted the value into the memory where the supposed index would have been had it existed. When this happens, we will get an undefined behaviour.

**Rule:** When using arrays, ensure that your indices are valid for the range of your array!


## Array and loops

Loops are typically used with arrays to do one of the three things:
1. Calculate a value(e.g. average value, total value)
1. Search for a value(e.g. highest value, lowest value)
1. Reorganize the array.(e.g. ascending order)

- When caluculaiting a value, a variable is typically used to hold an intermediate result that is used to calculate the final value.
- When searching for a value, a variable is typically used to hold the best candidate value seen so far(or the index of the best candidate)
- Sorting involves nested loops.

**Array and off by one error:** One of the trickest parts of using loops with arrays is making sure the loop iterates the proper number of times. Off-by-one error are easy to make(example using, <=, instead of <), and trying to access an element that is larger than the length of the array can have dire consequences. 


**Note:** `std::cin.clear()` resets any error flags. `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')` ignore any extra character in the input buffer.

## Sorting an array using selection sort.

**How does sorting works:** Sorting is generally performed by repeatedly comparing pairs of array elements, and swapping them if they meet some predefined criteria. The order in which these elements are compared differ depending on which sorting algorithm is used. 
**Note:** `std::sort(x,y)` in the *utility* header is used for swapping two number.

**Selection sort working:** Selection sort performs the following steps to sort an array fromo smallest to largest
1. starting at array index 0, search the entire array to find the smallest value.
1. Swap the smallest value found in the array with the value at index 0.
1. Repeat step 1 & 2 for the next index.
```cpp
#include<iostream>
#include<utility>


int main()
{
    int arr[]{52,448,71,23,42,94,021,165,412,778};
    int length{static_cast<int>(std::size(arr))};

    for (int startIndex{0}; startIndex < length; ++startIndex)
    {
        int smallestIndex{startIndex};
        for (int currentIndex{startIndex + 1}; currentIndex < length; ++currentIndex)
        {
            if (arr[currentIndex] < arr[smallestIndex])
            {
                smallestIndex = currentIndex;
            }
        }
        std::swap(arr[startIndex], arr[smallestIndex]);
        
    }
    
    for (int i = 0; i < length; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    
    return 0;
}
```

**std::sort**: Becuase sorting arrays is common, the C++ standard library includes a sorting function named `std::sort`. This function lives in the `<algorith>` header and can be invoked on an array like so.
```cpp
int array[]{30,50,20,10,40};
std::sort(std::begin(array), std::end(array));
// Note: here std::begin return the pointer to the first element of the array(i.e. 0).
// and std::end return the pointer to the last + 1 element of the array which is out of range(i.e. here the last index is 4 but std::end returns the pointer to 5 index.)
```

**Bubble sort**
```cpp
#include <iostream>
#include <iterator> // for std::size
#include <utility>

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length{ static_cast<int>(std::size(array)) }; // C++17

    for (int iteration{ 0 }; iteration < length-1; ++iteration)
    {
        int endOfArrayIndex{ length - iteration };

        bool swapped{ false }; 

        for (int currentIndex{ 0 }; currentIndex < endOfArrayIndex - 1; ++currentIndex)
        {
            if (array[currentIndex] > array[currentIndex + 1])
            {
                std::swap(array[currentIndex], array[currentIndex + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            std::cout << "Early termination on iteration: " << iteration+1 << '\n';
            break;
        }
    }

    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';

    return 0;
}
```

## Multi dimensional array
The element of an array can be of any data type, including array. An array of an array is called a multi-dimensional array. In a two-dimensional array, it is convenient to think of the first(left) subscript being the row, and the second(right) subscript being  the column. This is called row-major order. To access the element of a two-dimensional array we need to use to subscripts like `array[1][3]`(i.e. first row and third colum)

**Initializing two-dimensional array:** The easiest way to initialize a two-dimensional array is by using nested braces, with each set expressing a row.

```cpp
int array[3][5]
{
    {1,2,0},
    {5,4,7,3,2},
    {2,4,6,}
};  // This is the best way to initialize a 2D array

// note: We can omit inner braces and the compiler will automatically assigne value using the length of the array. But this is not recommended as in case if you wish to have some uninitialzed value in the first row it won't work. And if the length is not provided then also it will not work.

// also, a 2d array with initializer list can omit(only) the leftmost specification.
int arr[][5]
{
    {1,2,3},
    {1,2,3},
    {1,2,3},
}  // this is okay

// but
int arr2[][]; // this won't work

// initializer can also be initialized with zero using an empty initializer list like this
int arr[3][8]{};
```

**Accessing elements of a 2D array:** Accesing all the elements of a 2D array requires two loop: one for the row and one for the column. Since 2D array are typically accessed row by row, the row index is typically used as the outer loop. From C++11 onwards we can make use of `for-each` loop for iterating over a 2D array.

```cpp
for(int row{0}; row < numRows; )
```

**Note:** Multi-dimensional array may be larger than two dimensions.

## C-style strings
C++ supports two different types of string `std::string`(as part of standard library) and `C-style string`(inherited from C).

- C-style string
    - A C-style string is simply an array of character that uses a null-terminator. A *"null terminator"* is a special character(i.e. \0) used to indicate the end of the string. A C-style string is also called a *"null-terminated string"*

**Declaring a C-style string**
```cpp
// declaring a c-style string is simple just like an array of character
char string[]{"Hello"};

// here the string has 5 character but C++ automatically adds an extra character as null-terminator for the string, so the total length of the string is 5
// in case of c-style string it is always best to let the compiler decided the length of the array based on the initialization string.
```