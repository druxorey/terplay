
<h1 align="center">termplay</h1>

<p align="center">
<a href="#repository-structure"><img src="https://img.shields.io/badge/structure-BD93F9?style=for-the-badge"></a>
<a href="#how-to-execute-games"><img src="https://img.shields.io/badge/how%20to%20run-BD93F9?style=for-the-badge"></a>
</p>

<p align="center">A collection of simple games in various programming languages to help you practice and improve your skills.</p>

This is a dedicated space where we house a collection of simple games written in various programming languages. These games serve a dual purpose: they are designed to provide fun and engaging ways to practice programming, and they also serve as learning resources for those interested in getting to grips with different programming languages.

## Repository Structure

There is a directory for each programming language, and within each directory, there are different subdirectories for different game projects.

## How To Execute Games

### C++

To execute a C++ game, navigate to the directory containing the game's Makefile and use the following commands:

- To compile the game:

  ```sh
  make compile
  ```

- To start the game:

  ```sh
  make start
  ```

- To clean the build directory:

  ```sh
  make clear
  ```

- To clean, compile, and start the game in order:

  ```sh
  make all
  ```

### Python

To execute a Python game, navigate to the directory containing the game's `requirements.txt` file and use the following commands:

- To create a virtual environment:

  ```sh
  python3 -m venv venv
  ```

- To activate the virtual environment:

  ```sh
  source venv/bin/activate
  ```

- To install the required dependencies:

  ```sh
  pip install -r requirements.txt
  ```

- To start the game:

  ```sh
  python3 game_name.py
  ```

## Contribute

If you want to add new games or improve existing ones, follow these steps:

1. Open an issue to discuss the changes.
2. Fork this repository.
3. Create a new branch for your contribution: `git checkout -b your-branch-name`.
4. Make your changes.
5. Commit your changes, for example: `git commit -m 'feat(game): add new tic-tac-toe game.'`.
6. Push your changes to your forked repository: `git push origin your-branch-name`.
7. Open a Pull Request in this repository and reference the original issue.

## License

This project is licensed under the GPL-3.0 License. See the [LICENSE](LICENSE) file for more details.
