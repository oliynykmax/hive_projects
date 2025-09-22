# Hive Helsinki - My Overview

An overview of my programming experience as part of the studies at 42-network's Hive Helsinki 🐝

---

## Table of Contents

- [General Guidelines](#general-guidelines)
- [Solo Projects](#solo-projects)
- [Group Projects](#group-projects)

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

## Solo Projects

These are individual projects completed at Hive Helsinki.

| Name | Description | Link |
|------|-------------|------|
| 📚 | libft | Utility functions library | [View Project](./libft/docs/README.md) |
| 🖨️ | ft_printf | Variadic function for printing string templates with value conversions | [View Project](./ft_printf/docs/README.md) |
| 📏 | get_next_line | Buffer-based file reading - return single line per function call | [View Project](./get_next_line/README.md) |
| 🔃 | push_swap | Sorting lists with a specific and limited set of operations | [View Project](./push_swap/docs/README.md) |
| 🌀 | fract-ol | Simple programm that pictures 3 types of fractals using minimal windowing/graphics library [(MLX42)](https://github.com/codam-coding-college/MLX42) | [View Project](./fract-ol/README.md) |
| ➡️ | pipex | Replicating shell's piping and redirection using child processes | [View Project](./pipex/README.md) |
| 🧠 | philo | Project on the classic Dining Philosophers problem, involving the use of POSIX threads, mutexes, and atomic types. | [View Project](./philo/docs/README.md) |
| 💻 | CPP_modules | C++ modules projects | [View Project](./CPP_modules/) |

---

## Group Projects

These are collaborative projects completed at Hive Helsinki.

| Name | Description | Link |
|------|-------------|------|
| 🌟 | miniRT | Ray tracer using MLX42 | [View Project](https://github.com/oliynykmax/Mini-Ray-Tracer/blob/main/README.md) |
| 💬 | ft_irc | IRC server implementation | [View Project](https://github.com/oliynykmax/irc_hive/blob/main/README.md) |
| 🐚 | minishell | Custom shell implementation | [View Project](https://github.com/oliynykmax/minishell/blob/main/README.md) |