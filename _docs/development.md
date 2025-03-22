# Development Guide

This document serves as a guide for the syntax and conventions used in our projects.

## Table of Contents

1. [Variable Naming](#variable-naming)
2. [File Naming](#file-naming)
3. [Code Formatting](#code-formatting)
4. [Commits](#commits)
5. [Branching](#branching)

## Variable Naming

Variables should follow the `lowerCamelCase` style. Here are some examples:

```c++
int playerScore;
string gameTitle;
bool isGameOver;
```

## File Naming

Files should follow the `snake_case` style. Here are some examples:

```
player_score.cpp;
game_title.txt;
is_game_over.hpp;
```

## Code Formatting

To maintain consistency in the code, follow these formatting rules:

- Use 4-space tabs.
- Braces `{}` should be on the same line as the function or control block declaration.
- In languages like Python, specify the return type of functions using type hints.

Example function format in C++:

```c++
int example(int argument) {
    return argument;
}
```

Example function format in Python:

```python
def example(argument: int) -> int:
    return argument
```

## Commits

For commits, we follow the [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/) philosophy. Here are some examples:

```
feat(engine): add collision detection
fix(player): correct health decrement bug
chore(tests): add unit tests for new game feature
docs(readme): update setup instructions
```

## Branching

Never push directly to `main`. Always create a new branch to implement features or make changes. Branches should follow the `type/description` style. Here are some examples:

```
feature/add-new-level
fix/correct-score-calculation
refactor/update-variable-names
chore/update-build-script
```

Once you've finished working on your branch, you can merge it into `main`.
