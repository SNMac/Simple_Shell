/**
 * @file
 * @brief
 * @date 2022/09/17
 * @author SNMac
 */

#ifndef INC_2022_OS_HW1_PROCESS_H
#define INC_2022_OS_HW1_PROCESS_H

#include <string>

using namespace std;

void newProcess(int ch_argc, const string ch_argv[]);  // begin new process
void createChild(int ch_argc, const string ch_argv[]);  // create child process

#endif //INC_2022_OS_HW1_PROCESS_H