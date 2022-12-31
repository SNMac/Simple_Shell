/**
 * @file
 * @brief
 * @date 2022/09/17
 * @author SNMac
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <sys/wait.h>

#include "Process.h"

using namespace std;

extern char** environ;

void newProcess(int ch_argc, const string ch_argv[]) {
    char* execArgv[ch_argc + 1];
    // convert string array to char* array
    for (int i = 0; i < ch_argc; i++)
        execArgv[i] = const_cast<char*>(ch_argv[i].c_str());
    execArgv[ch_argc] = nullptr;

    // begin new process using execve()
    if (execve(execArgv[0], execArgv, environ) == -1) {
        cerr << "execve: " << strerror(errno) << '\n';
        exit(EXIT_FAILURE);
    }
}

void createChild(int ch_argc, const string ch_argv[]) {
    int status;
    pid_t ch_pid;
    // create child process using fork()
    if ((ch_pid = fork()) == -1) {  // fork failed
        cerr << "fork: " << strerror(errno) << '\n';
    } else if (ch_pid == 0) {  // fork success, child process
        newProcess(ch_argc, ch_argv);
    } else {  // fork success, parent process
        waitpid(ch_pid, &status, 0);
        if (WIFSIGNALED(status))  // child process terminated by signal
            cerr << "Child process terminated by signal : " << WTERMSIG(status) << '\n';
    }
}