# pipex
#### 42 school project

The goal of the project is to implement a pipe functionality, using dup2(), pipe(), execve() and fork(). 
## What have I learned
- Redirect operators in bash
- The concept of a pipe
- Signals
## How to build
```
$> make
```
## How to launch
My program handles **multiple** commands. Program execution 
```
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
is equivalent to 
```
$> < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
I also implemented **heredoc syntax**. It works as follows:
```
$> cmd << LIMITER | cmd1 >> file | cmd2 | cmd3 ...
```
