# 42Ft_printf
## Introduction
Welcome to **ft_printf**! The goal of this project is to reimplement the `printf()` function from the C standard library. This exercise introduced me to variadic functions in C and helped me structure extensible and efficient code.

## Mandatory Requirements
- Must be written in C and adhere to the 42 coding norm.
- All heap-allocated memory must be properly freed to avoid leaks.
- The project must compile with `cc` using the flags: `-Wall -Wextra -Werror`.
- Makefile must support the following rules: `all`, `clean`, `fclean` and `re`.
- The final library must be named `libftprintf.a` and be created using `ar` (not `libtool`).
- The function `ft_printf()` will be compared against the standard `printf()`.

## Installation
To set up and use **ft_printf**, follow these steps:
```
# Clone the repository
git clone https://github.com/ejarvinen/42Ft_printf.git
cd 42Ft_printf

# Compile library
make

# Include ft_printf in your project
gcc -Wall -Wextra -Werror your_program.c -L. -lftprintf -o your_program
```
## Features
**ft_printf** supports the following conversions:
| **Specifier** | **Description** |
| :-----: | :-----|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a decimal (base 10) integer |
| `%i` | Prints an integer (base 10) |
| `%u` | Prints an unsigned decimal number |
| `%x` | Prints a number in lowercase hexadecimal (base 16) |
| `%X` | Prints a number in uppercase hexadecimal (base 16) |
| `%%` | Prints a percent sign |

## Compilation & Usage
To use `ft_printf()` in your project:
```
#include "libftprintf.h"

int main()
{
    ft_printf("Hello, %s! You have %d new messages.\n", "User", 5);
    return 0;
}
```
Compile and link against the library:
```
cc main.c -L. -lftprintf -o test_printf
./test_printf
```
