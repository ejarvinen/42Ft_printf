# 42Ft_printf

A recode of the `printf()` function from C Standard Library with the following features:

* `%c` prints a single character
* `%s` prints a string as defined by the common C convention
* `%p` prints `void *` pointer argument in hexadecimal format
* `%d` prints a base 10 decimal number
* `%i` prints a base 10 integer
* `%u` prints a base 10 unsigned decimal number
* `%x` prints a base 16 number in hexadecimal lowercase format
* `%X` prints a base 16 number in hexadecimal uppercase format
* `%%` prints a percent sign

There is no implementation for the buffer management of the original `printf()`.

This project is designed to be an add-on to [Libft library](https://github.com/ejarvinen/42Libft).

### Compilation

`git clone` to desired directory. `cd` into that directory. Run `git submodule init` and `git submodule update` in the same directory and then `make`. Use `.a` file in other work.
