# pipex
#### 42 school project

The goal of the project is to implement a pipe functionality, using unix system calls `fork`, `pipe`, `execve` and `dup2`

See `subject.pfd` in the root of the repository to get more detailed info about the project
### How to build
```
$ make
```
The program handles multiple commands. Program execution 
```
$ ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
is equivalent to 
```
$ < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
I also implemented **heredoc syntax**. It works as follows
```
$ ./pipex cmd << LIMITER | cmd1 >> file | cmd2 | cmd3 
```
