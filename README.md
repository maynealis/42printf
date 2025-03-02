# ft_printf

A custom implementation of the printf function from the C standard library, developed as part of the 42 School curriculum. The implementation handles various format specifiers and optional flags, closely mimicking the behavior of the original printf function.

> [!IMPORTANT]
> When using this library, it also contains the [`libft`](https://github.com/maynealis/42libft) functions.

**Table of contents**
- [Features](#-Features)
- [Installation](#-Installation)
- [Usage](#-Usage)
- [Implementation Approach](#-Implementation-Approach)
- [Key learnings](#-Key-learnings)
- [Technical challenges](#-Technical-challenges)
- [References](#-References)

## 🎯 Features

### Format Specifier Syntax
```
%[arg-number$][flags][width][.precision][length]conversion
```
- `arg-number` : Specifies the position of the argument in the argument list. Example: %2$d would print the second argument as a decimal integer. *(Not done in this project)*
- `flags` : Modifies the output format.
- `width`: Specifies the minimum number of characters the output should occupy.
- `precision` : Controls precision for decimal numbers and the number of characters for strings
- `length` : Modifies the size of the argument*(Not done in this project)*
- `conversion` : Specifies the type of data to be printed

> [!NOTE]
> The `width` and `precision` can also be provided dynamically as arguments using `*` in the original function; but this implementation is outside of this project.

### Basic Conversions
| Conversion | Description |
|------------|-------------|
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer address |
| `%d` | Decimal (base 10) integer |
| `%i` | Integer |
| `%u` | Unsigned decimal integer |
| `%x` | Hexadecimal (base 16) integer lowercase |
| `%X` | Hexadecimal (base 16) integer uppercase |
| `%%` | Percentage sign |

### Bonus Features - Supported Flags
| Flag | Applies to | Description |
|------|------------|-------------|
| `-` | All | Left-justifies the output within the given field width |
| `0` | Numeric | Zero-pads the number to fill the field width. If the  0  and - flags both appear, the 0 flag is ignored. If a precision is given, the 0 flag is ignored. |
| `.` | d, i, u, x, X, s | Sets precision for numeric conversions. If the precision is given as just '.', the precision is taken to be zero. This gives the minimum number of digits to appear for d, i, u, x, and X conversions, or the maximum number of characters to be printed from a string for s |
| `#` | x, X | Prepends "0x" or "0X" to non-zero hexadecimal values |
| ` ` (space) | d, i | Adds a space before positive numbers |
| `+` | d, i | Always shows sign (+ or -) for numeric values |

## ⚙️ Installation

Clone this repository and compile it.
```bash
make
```

## 🛠 Usage

Include the library in your project
```c
#include "ft_pintf.h"
```
And use `ft_printf` as `printf`

Examples:

```c
ft_printf("Hello, %s!\n", "world");      //Output: "Hello, world!"
ft_printf("Number: %d\n", 42);           //Output: "Number: 42"
ft_printf("Hexadecimal: %#x\n", 255);    //Output: "Hexadecimal: 0xff" 
ft_printf("%10s\n", "hello");            //Output: "     hello"
ft_printf("%-10s\n", "hello");           //Output: "hello     "
```

## 🏛️ Implementation Approach
### Core Architecture
The implementation follows a modular design pattern with distinct components:

- **Parser**: Analyzes format strings to identify conversions and flags
- **Flags Manager**: Processes flags
- **Type Handlers**: Specialized functions for each conversion type
- **Utility Functions**: Support functions for memory management and string operations

### Conversion handlers

|Conversion|Handler function|
|----------|-----------------|
|c         |write_char       |
|s         |write_str        |
|p         |write\_hexa or write_str|
|d         |write_int (uses write\_str)|
|i         |write_int (uses write\_str)|
|u         |write_uint (uses wite\_str)|
|x         |write_hexa       |
|X         |write_hexa       |
|%         |write_char       | 


> [!NOTE]
> In this context there is no difference between `i` and `d` conversion.

## 🧠 Key Learnings

- Variadic functions
- String Parsing Techniques
- Structure for flags

### Argument Promotion
In C, the va_arg macro is designed to work with the type of argument that is passed to the variadic function, and it uses the promoted types of the arguments as part of its implementation. When you use va_arg with a char type, it will not work directly due to how argument promotion works in C.

In C, when you pass a char (or short) to a variadic function, it is **promoted to int** before being passed. This promotion rule is part of the C standard and is necessary because char and short types are usually too small to be reliably passed across function boundaries. The promotion to int ensures the correct handling of values and is consistent with the calling convention of most platforms.

Here’s how argument promotion works for char and short types in variadic functions:

    1. char and short values are promoted to int when passed to a function with ... (variadic function).
    2. float values are promoted to double.
    3. For types like int, long, double, etc., no promotion happens.

When you call va_arg to extract a char from the argument list, the argument has been promoted to int. Therefore, when you request va_arg to give you a char, you're essentially trying to fetch a promoted int as a char, which could lead to undefined behavior or an incorrect value.

To correctly retrieve a char from a variadic function, you should cast the result of va_arg to char. This is because va_arg always retrieves the type in its promoted form (which will be int), but you can explicitly cast it back to a char after retrieving it.

## 👩🏻‍💻 Technical Challenges

### Flag Priority and Conflicts
Determining the correct order of flag application was challenging due to:

- Some flags having precedence over others
- Certain combinations requiring special handling

### Precision vs. Width
Managing the interaction between precision and width required careful implementation:

- Precision affects the minimum number of digits displayed
- Width affects the total field size including padding
- Their combined effect varies by conversion type

### Memory Management
Creating and freeing temporary strings in the correct order was essential for avoiding memory leaks, especially with:

- Multiple flag applications requiring multiple string transformations
- Error handling that must free all allocated memory before returning

## 🔗 References
- [variadic functions](https://onepunchcoder.medium.com/variadic-functions-explained-fd3b4ab6fd84)
- [Format in printf](https://www.ibm.com/docs/en/i/7.5?topic=functions-printf-print-formatted-characters)

[Back to TOP](#ft_printf)
