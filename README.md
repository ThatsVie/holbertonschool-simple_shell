![MARCEL_Shell](https://github.com/ThatsVie/holbertonschool-simple_shell/assets/143755961/ff7f0638-6fe2-4684-89cb-e83043ebef15)
<p align="center">
by <a href="https://github.com/ThatsVie/">Vie</a>
</p>
<br>
<br>
MARCEL Shell is a simple shell program written in C. It provides basic shell functionality, allowing users to execute commands, manage environment variables, and perform standard shell operations.
<br>
<br>
Usage
<br>
<br>
The MARCEL Shell supports standard shell commands and includes the following built-in commands:
<br>
<br>
exit: Exit the shell.
<br>
env: Display environment variables.
<br>
<br>
Features:
<br>
<br>
Basic shell prompt (MARCEL $).
<br>
Command execution, including built-in commands like exit and env.
<br>
Tokenization of user input.
<br>
Handling of environment variables, specifically the PATH variable.
<br>
Execution of commands from specified directories.
<br>
<br>
Files:
<br>
<br>
main.c
<br>
The main entry point of the shell.
Handles user input, executes commands, and manages the shell's main loop.
<details>
<summary>Function</summary>
<ul><li>
main(int argc, char **argv, char **env): The main function that orchestrates the shell's execution.
</details>
main.h
  <br>
Header file containing function prototypes and necessary header inclusions for the shell.
<details>
<summary>Functions</summary>
<ul>
<li>void tokenize_string(char *string, char *delimiters, char **tokens): Tokenizes a string into an array of tokens.</li>
<li>int check_path(char *path, char **p_array, char **t_array): Searches for and executes a command in specified directories.</li>
<li>int child_process(char *path, char *c_path, char **c_args): Creates a child process and executes a command.</li>
<li>char *duplicate_string(char *string): Duplicates a string and returns a copy.</li>
</details>
tokenize_string.c
  <br>
Source file implementing the tokenize_string function.

  <details>
<summary>Function</summary>
<ul><li>
void tokenize_string(char *string, char *delimiters, char **tokens): Tokenizes a string into an array of tokens.
</li>
</details>
check_path.c
  <br>
Source file implementing the check_path function.
<details>
<summary>Function</summary>
<ul><li>
int check_path(char *path, char **p_array, char **t_array): Searches for and executes a command in specified directories.</li>
</details>
child_process.c
<br>
Source file implementing the child_process function.
<details>
<summary>Function</summary>
<ul><li>
int child_process(char *path, char *c_path, char **c_args): Creates a child process and executes a command.
</li>
</details>
duplicate_string.c
  <br>
Source file implementing the duplicate_string function.
<details>
<summary>Function</summary>
<ul>
<li>
char *duplicate_string(char *string): Duplicates a string and returns a copy. </li>
</details>
<br>
Building the Shell
<br>
Compile the shell using a C compiler. For example, using gcc:
  <br>
  <br>
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
<br>
  <br>
How to Run
  <br>
Execute the compiled binary hsh:
<br>
./hsh
  <br>
  <br>
Once in the shell, you can enter commands as you would in a typical shell environment.
  
![download](https://github.com/ThatsVie/holbertonschool-simple_shell/assets/143755961/323dd7cc-f155-4f4d-a9cc-590aacf34730)

