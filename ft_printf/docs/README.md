![score_picture](score.jpg)

# ft_printf – Rebuilding printf in C

**ft_printf** is a simplified reimplementation of the standard C `printf` function. It formats and prints data to the standard output using a limited set of conversion specifiers. This project is to learn variadic functions, memory handling, and string formatting in C.

---

## 📌 Supported Format Specifiers

Your `ft_printf` function must handle the following conversions:

| Specifier | Description                      |
|-----------|----------------------------------|
| `%c`      | Character                        |
| `%s`      | String                           |
| `%p`      | Pointer address                  |
| `%d`      | Signed decimal integer           |
| `%i`      | Signed decimal integer (alias)   |
| `%u`      | Unsigned decimal integer         |
| `%x`      | Lowercase hexadecimal integer    |
| `%X`      | Uppercase hexadecimal integer    |
| `%%`      | Literal percent sign             |

---

## 🛠️ Usage

### Compilation

```bash
make
then link libftprintf.a to the main.c
```

### Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! The answer is %d.\n", "world", 42);
    return 0;
}
```

---
