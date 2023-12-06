![MARCEL_Shell](https://github.com/ThatsVie/holbertonschool-simple_shell/assets/143755961/ff7f0638-6fe2-4684-89cb-e83043ebef15)
<p align="center">
by <a href="https://github.com/ThatsVie/">Vie</a>
MARCEL Shell
MARCEL Shell (hsh) is a simple shell program written in C. It provides basic shell functionality, allowing users to execute commands, manage environment variables, and perform standard shell operations.
Usage
The MARCEL Shell supports standard shell commands and includes the following built-in commands:

exit: Exit the shell.
env: Display environment variables.

Features
Command Execution: The shell can execute commands provided by the user.

Environment Variable Display: Users can display the current environment variables using the env command.

Exit Command: The shell can be terminated using the exit command.

File Descriptions

main.c: The main entry point of the shell program, containing the main execution loop.

main.h: Header file containing function declarations and necessary includes.

tokenize_string.c: Source file with the implementation of the tokenize_string function.

check_path.c: Source file with the implementation of the check_path function.

child_process.c: Source file with the implementation of the child_process function.

duplicate_string.c: Source file with the implementation of the duplicate_string function.

Building the Shell
Compile the shell using a C compiler. For example, using gcc:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

How to Run
Execute the compiled binary hsh:

./hsh
Once in the shell, you can enter commands as you would in a typical shell environment.

![download](https://github.com/ThatsVie/holbertonschool-simple_shell/assets/143755961/323dd7cc-f155-4f4d-a9cc-590aacf34730)

