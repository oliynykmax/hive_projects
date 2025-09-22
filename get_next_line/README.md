
![Score](score.jpg)

# get_next_line – Line-by-line File Reading in C

**get_next_line** is a C library function that reads from a file descriptor, returning one line at a time per call. It’s built to handle input efficiently and safely, managing memory without using global variables or `lseek()`.

## 🧠 Goals

- Develop a custom line-reading function similar to `fgets()`
- Learn how to manage persistent state using **static variables**
- Handle varying buffer sizes with compile-time configuration
- Support multiple file descriptors concurrently (bonus)

## 🛠 Compilation
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```
