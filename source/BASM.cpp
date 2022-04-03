#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <bits.h>
#include <list>

using namespace std;

int main(int argc, char const* argv[]) {
    string line;
    
    ifstream input_f(argv[1]);

    ifstream file_fr("boot.asm");
    ofstream file_fw("boot.asm");
    
    //org 0x7c00
    while (getline(input_f, line))
    {
        line.substr(0, line.find(" "));

        //PARSING

        if (line.substr(0, line.find(" ")) == "bits") {
            int start = 5;
            string znach;
            for (int i = start; i < line.size(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                znach.push_back(line[i]);
            }
            file_fw << "use" << znach << endl;
        }

        if (line.substr(0, line.find(" ")) == "proc") {
            int start = 5;
            string znach;
            for (int i = start; i < line.size(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                znach.push_back(line[i]);
            }
            file_fw << znach << ":" << endl;
        }

        if (line.substr(0, line.find(" ")) == "data") {
            int start = 5;
            string name;
            string znach;
            for (int i = 5; i < line.size(); i++) {
                if (line[i] == ' ') {
                    break;
                }
                start += 1;
                name.push_back(line[i]);
            }
            for (int i = start; i < line.size(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                znach.push_back(line[i]);
            }
            if (name == "byte") {
                file_fw << "db" << znach << endl;
            } else if (name == "word") {
                file_fw << "dw" << znach << endl;
            } else if (name == "dword") {
                file_fw << "dd" << znach << endl;
            }
        }

        if (line.substr(0, line.find(" ")) == "org") {
            int start = 4;
            string znach;
            for (int i = start; i < line.size(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                znach.push_back(line[i]);
            }
            file_fw << "org " << znach << endl;
        }

        if (line.substr(0, line.find(" ")) == "sec") {
            int start = 4;
            string znach;
            for (int i = start; i < line.size(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                znach.push_back(line[i]);
            }
            file_fw << "section ." << znach << endl;
        }

        if (line.substr(0, line.find(" ")) == "sout") {
            file_fw << "mov ah, 0x0E" << endl;
            file_fw << "mov al, " << line.substr(5, line.find(" ")) << endl;
            file_fw << "int 10h" << endl;
        }

        if (line.substr(0, line.find(" ")) == "finish") {
            file_fw << "finish:" << endl;
            file_fw << "    times 510+start-finish db 0" << endl;
            file_fw << "    db 0x55, 0xAA" << endl;
        }

        if (line.substr(0, line.find(" ")) == "rb") {
            file_fw << "int 19h" << endl;
        }

        if (line.substr(0, line.find(" ")) == "inter") {
            int start = 6;
            string znach;
            for (int i = start; i < line.size(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                znach.push_back(line[i]);
            }
            file_fw << "int " << znach << endl;
        }

        if (line.substr(0, line.find(" ")) == "jump") {
            int start = 5;
            string znach;
            for (int i = start; i < line.size(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                znach.push_back(line[i]);
            }
            file_fw << "jmp " << znach << endl;
        }

        if (line.substr(0, line.find(" ")) == "cond") {
            int start = 5;
            string znach;
            for (int i = start; i < line.size(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                znach.push_back(line[i]);
            }
            file_fw << "cmp " << znach << endl;
        }

        if (line.substr(0, line.find(" ")) == "else") {
            int start = 5;
            string znach;
            for (int i = start; i < line.size(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                znach.push_back(line[i]);
            }
            file_fw << "jmp " << "." << znach << endl;
        }

        if (line.substr(0, line.find(" ")) == "do") {
            int start = 3;
            string znach;
            for (int i = start; i < line.size(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                znach.push_back(line[i]);
            }
            file_fw << "." << znach << endl;
        }

        if (line.substr(0, line.find(" ")) == "if") {
            int start = 3;
            string znach;
            for (int i = start; i < line.size(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                znach.push_back(line[i]);
            }
            file_fw << "jz " << "." << znach << endl;
        }

        if (line.substr(0, line.find(" ")) == "yasm") {
            int start = 5;
            string znach;
            for (int i = start; i < line.size(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                znach.push_back(line[i]);
            }
            file_fw << znach << endl;
        }

        if (line.substr(0, line.find(" ")) == "goto") {
            int start = 5;
            string znach;
            for (int i = start; i < line.size(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                znach.push_back(line[i]);
            }
            file_fw << "call " << znach << endl;
        }

        if (line.substr(0, line.find(" ")) == "move") {
            int start = 5;
            string name;
            string znach;
            for (int i = 5; i < line.size(); i++) {
                if (line[i] == ' ') {
                    break;
                }
                start += 1;
                name.push_back(line[i]);
            }
            for (int i = start; i < line.size(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                znach.push_back(line[i]);
            }
            file_fw << "mov " << name << "," << znach << endl;
        }

        if (line.substr(0, line.find(" ")) == "cls") {
            file_fw << "mov ax, 3" << endl;
            file_fw << "int 10h" << endl;
        }

        if (line.substr(0, line.find(" ")) == "sd") {
            file_fw << "mov ax, 5307h" << endl;
            file_fw << "xor bx, bx" << endl;
            file_fw << "inc bx" << endl;
            file_fw << "mov cx, 3" << endl;
            file_fw << "int 15h" << endl;
        }
    }

    //if (file_fw.is_open())
    //{
    //   file_fw << "jmp $" << std::endl;
    //}

    file_fw.close();
    file_fr.close();
    string command = "yasm -f bin -o " + string(argv[2]) + " " + string("boot.asm");
    std::system(command.c_str());
    getchar();
    return 0;
}