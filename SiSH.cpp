/**
 * @file
 * @brief
 * @date 2022/09/17
 * @author SNMac
 */

#include <iostream>
#include <filesystem>
#include <string>
#include <sstream>

#include "SiSH.h"
#include "Process.h"

using namespace std;
namespace fs = filesystem;

const string home = getenv("HOME");
const string path = getenv("PATH");
const string user = getenv("USER");

int main() {
    fs::path p = home;
    fs::current_path(p);
    string input;
    int ch_argc;
    string ch_argv[ARGC_SIZE];

    while(inputPrompt(p.string(), input, ch_argc, ch_argv)) {
        if (ch_argv[0].empty()) {  // empty command
            continue;
        } else if (ch_argv[0] == CD) {  // cd
            ChangeDirectory(p, ch_argv[1]);
        } else {  // create child process
            ch_argv[0] = lookupPATH(ch_argv[0]);
            createChild(ch_argc, ch_argv);
        }
        cout << '\n';
    }
}

bool inputPrompt(const fs::path& p, string input, int& ch_argc, string ch_argv[]) {  // prompt user to input command
    ch_argc = 0;
    for (int i = 0; i < ARGC_SIZE; i++)
        ch_argv[i].clear();
    cout << GRN << user << NC << ':';
    if (fs::current_path().string().find(home) != string::npos)
        cout << fs::current_path().string().replace(0, home.length(), "~") << '$' << " >> ";
    else
        cout << fs::current_path().string() << '$' << " >> ";
    getline(cin, input);
    stringstream delim(input);
    string temp;
    while(getline(delim, temp, ' ')) {  // delete 2 <= space characters, and then tokenizing input by ' '
        if (temp.empty())
            continue;
        ch_argv[ch_argc++] = temp;
    }
    if (ch_argv[0] == FINISH)
        return false;
    return true;
}

void ChangeDirectory(fs::path& p, const string& cd_para) {  // cd
    if (cd_para.empty() || cd_para == "~") {  // parameter indicate HOME directory
        p = home;
        fs::current_path(p);
    } else if (cd_para[0] == '/') {  // parameter indicate absolute path
        if (fs::exists(cd_para)) {  // parameter exists (filename or directory name whatever)
            if (fs::is_directory(cd_para)) {  // parameter is directory
                p = cd_para;
                fs::current_path(p);
            } else {  // parameter is not directory
                cout << "cd: not a directory: " << cd_para << '\n';
            }
        } else {  // parameter not exists
            cout << "cd: no such file or directory: " << cd_para << '\n';
        }
    } else {  // parameter is relative path
        if (fs::exists(p / cd_para)) {  // parameter exists (filename or directory name whatever)
            if (fs::is_directory(p / cd_para)) {  // parameter is directory
                p = p / cd_para;
                fs::current_path(p);
            } else {  // parameter is not directory
                cout << "cd: not a directory: " << cd_para << '\n';
            }
        } else {  // parameter not exists
            cout << "cd: no such file or directory: " << cd_para << '\n';
        }
    }
}

string lookupPATH(const string& filename) {  // look up command's filename in PATH
    string pathTok[PATH_SIZE];
    int pathTokSize = 0;
    stringstream delim(path);
    string filepath;
    while(getline(delim, filepath, ':'))
        pathTok[pathTokSize++] = filepath + '/';
    for (int i = 0; i < pathTokSize; i++) {
        filepath = pathTok[i] + filename;  // concatenate PATH and filename
        if(fs::is_regular_file(filepath))  // if filename exists in PATH
            return filepath;  // return concatenated filepath
    }
    return filename;  // else return just filename
}