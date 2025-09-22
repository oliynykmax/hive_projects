![Score](score.jpg)

# libft – custom C Standard Library

**libft** is a personal implementation of key standard C library functions. It covers memory, string, character, and linked list utilities.

---

## ✅ Included Features

### Mandatory

- Character checks: `isalpha`, `isdigit`, ...
- Memory handling: `memset`, `bzero`, `memcpy`, ...
- String functions: `strlen`, `strchr`, `strlcpy`, `strjoin`, `split`, ...
- Conversion: `atoi`, `itoa`
- File output: `putchar_fd`, `putstr_fd`, ...

### Bonus

- Linked list utilities: `lstnew`, `lstadd_front`, `lstsize`, `lstmap`, ...

## 🔍 Example

```c
#include "libft.h"

int main(void)
{
    char *s = ft_strjoin("Hello, ", "libft!");
    ft_putendl_fd(s, 1);
    free(s);
}
```

