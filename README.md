# Hive Helsinki - My Overview

An overview of my programming experience as part of the studies at 42-network's Hive Helsinki 🐝

---

## Table of Contents

- [General Guidelines](#general-guidelines)
- [Projects](#projects)

---

## General Guidelines

- To complete projects, students needs to pass code reviews by multiple peers. The evaluatee needs to be able to explain their code and its validity - since students have varying levels of perfectionism, we often defer to the restrictions imposed by assignment instructions (and the discuss any implicit leeways).
- For all projects using the C programming language, students are required to follow the "Norm" - a set of code style and linting rules. Some of these can be validated with the ["norminette"](https://github.com/42school/norminette) program and some are left for human review.  
  These rules include, but are not limited to:
  - No comments inside functions
  - No `for` loops, or `switch` statements, or ternary statements
  - Variable declarations at the beginning of functions, single declaration per line
  - No assignments in declarations (except for `const`/`static`/`global` variables)
  - Up to:
    - 80 characters per line
    - 25 lines per function
    - 4 function parameters
    - 5 variable declarations per function
    - 5 functions per file

---

## Projects

|                                                 | Name            | Description                                                                 | Grade            |
| ---------------------------------------------------- | --------------- | --------------------------------------------------------------------------- | ---------------- |
| 📚      | [`libft`](./libft/docs/README.md)            | Utility functions library                                                   | 125              |
| 🖨️     | [`ft_printf`](./ft_printf/docs/README.md)    | Variadic function for printing string templates with value conversions      | 100              |
| 📏 | [`get_next_line`](./get_next_line/README.md) | Buffer-based file reading - return single line per function call            | 125              |
| 🚫                                                   | `born2beroot`   | Virtual machine security & monitoring configurations                        | 100              |
| 🔃     | [`push_swap`](./push_swap/docs/README.md)     | Sorting lists with a specific and limited set of operations                 | 96               |
| 🌀      | [`fract-ol`](./fract-ol/README.md)       | Simple programm that pictures 3 types of fractals using minimal windowing/graphics library [(MLX42)](https://github.com/codam-coding-college/MLX42)             | 116              |
| ➡️         | [`pipex`](./pipex/README.md)         | Replicating shell's piping and redirection using child processes            | 100              |
|  🧠        | [`philo`](./philo/docs/README.md)         | Project on the classic Dining Philosophers problem, involving the use of POSIX threads, mutexes, and atomic types.           | 100              |
| 💻      | [`CPP_modules`](./CPP_modules/)            | C++ modules projects                                                        | -                |
| 🌟      | [`miniRT`](https://github.com/oliynykmax/Mini-Ray-Tracer/blob/main/README.md)       | Ray tracer using MLX42                                                      | -                |
| 💬      | [`ft_irc`](https://github.com/oliynykmax/irc_hive/blob/main/README.md)         | IRC server implementation                                                    | -                |
| 🐚      | [`minishell`](https://github.com/oliynykmax/minishell/blob/main/README.md)         | Custom shell implementation                                                  | -                |

#### Misc

|                                                   | Name         | Description                                              |
| ------------------------------------------------------- | ------------ | -------------------------------------------------------- |
| 👶 | [`piscine`](https://github.com/oliynykmax/Piscine42/blob/main/README.md)    | All the code written during Hive Helsinki pool - 1 month of intensive studies which determined if students got in        |