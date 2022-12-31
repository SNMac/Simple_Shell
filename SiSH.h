/**
 * @file
 * @brief
 * @date 2022/09/17
 * @author SNMac
 */

#ifndef INC_2022_OS_HW1_SISH_H
#define INC_2022_OS_HW1_SISH_H

#include <iostream>
#include <string>

#define ARGC_SIZE 20  // max child argv size
#define PATH_SIZE 50  // max PATH element size
#define FINISH "quit"
#define CD "cd"
#define NC "\e[0m"
#define GRN "\e[0;32m"

using namespace std;
namespace fs = filesystem;

bool inputPrompt(const fs::path& p, string input, int& ch_argc, string ch_argv[]);  // prompt commands
void ChangeDirectory(fs::path& p, const string& cd_para);  // cd
string lookupPATH(const string& filename);  // look up command's filename in PATH

#endif //INC_2022_OS_HW1_SISH_H