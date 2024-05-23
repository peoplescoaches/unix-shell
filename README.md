# Unix Shell

Prerequisites:
- gcc
- make

Install and Run:
1. Clone this repository: `git clone https://github.com/peoplescoaches/unix-shell`
2. Navigate inside the directory and set up the shell PATH one-time: 
  - if running using a Bash terminal: `cd unix-shell && make setup_bash`
  - if running using a Zsh terminal: `cd unix-shell && make setup_zsh`
3. Run `make compile` to compile the C code into an executable called 'pcshell'.
4.  Run `pcshell` to start the shell (this command can be run from any directory once the above PATH setup is complete)


To run tests: `make test`
To remove the pcshell executable / dSYM folders: `make clean`. Note: `make compile` will need to be run to re-create the pcshell executable.
