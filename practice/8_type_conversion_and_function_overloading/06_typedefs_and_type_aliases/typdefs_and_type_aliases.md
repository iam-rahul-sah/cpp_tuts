# Typedefs and type aliases

**using** is a keyword that creates an alias for an existing data type. 


**Syntax:**
```cpp
using alias_name = type;
using Distance = double; // defines Distance as an alias for type double.

// once defined we can use the type alias as if it were the original type
Distance milesToDestination{3.4};
```
The compiler automatically substitutes the type alias for the original type when it sees it. This is called **type substitution**.

## Common Naming convenetion for type aliases
- Type aliases that end in a "_t" suffix. Used for the standard library types for globally scoped type names(e.g. size_t, ptrdiff_t, etc)
Note: the `POSIX` reserves the "_t" suffix for globally scoped type name, so using it for type aliases type naming confilict on POSIX systems.

- Type aliases that end in a "_type" suffix. Used for user-defined types.
- Type aliases that use no suffix.

In moder C++, the convention is to name type aliases(or any other type) that you define yourself starting with a capital letter, and using no suffix.
e.g.(Distance)

## Type aliases are not distinct types
An alias does not actually define a new, distinct type. It is just and alternative name for an existing type.

Hence care must be taken not to mix values of aliases that are intended to be semantically distinct.

## The scope of a type alias
Becausee type aliases are identifiers for existing data types. type alias identifier follow the same scoping rules as variable identifiers: a type alias defined inside a block has a block scoope and is usable only within that block, whereas a type alias defined in the global namespace has file scope and is usable to the end of the file.


Note: It is also common to define type aliases in header file, if the type aliases are used in mulitple files in your project.

# Typedefs
A **typedef**(which is short for type definition) is an older way of creating an alias for a type.

**syntax:**
```cpp
typdef type alias_name;
typedef long Distance; // defines Distance as an alias for type long.
```

## Situations when we should use type aliases?

1. Using type aliases for platform independent coding.
We can define a consistent alias for a type that is different on different platforms. e.g. `long` is 4 bytes on 32-bit platforms and 8 bytes on 64-bit platforms. We can define a type alias for `long` that is always 8 bytes long, regardless of the platform.
2. Using type aliases to make complex type easier to read.
In advance C++, types can be complicated and lengthy to manually enter on your keyboard. So we can use type aliases to make the code easier to read.
3. Using type aliases to make code more self-documenting.
for e.g. if we have multiple functions passing or returning such a type, creating a type alias might be wortwhile.

## Using type aliases for easier code maintenance
for e.g we can use type aliases to make it easier to change the type of a variable or function parameter in the future. By just changing the type in one place.