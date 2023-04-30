## Function Templates

```cpp
template <typename T>   // This is a template parameter declaration
T max(T x, T y)         // This is template definition
{
    return (x > y) ? x : y;
}                       // We can also use `class` keyword instead of typename
```