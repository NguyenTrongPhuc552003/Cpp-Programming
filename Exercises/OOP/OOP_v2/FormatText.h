//
// Created by Trong_Phuc on 19/02/2023.
//

#ifndef OOP_V2_FORMATTEXT_H
#define OOP_V2_FORMATTEXT_H

#include <iostream>
#include "string"

using namespace std;

class Format {
private:
    unsigned int lowerPos = 0, upperPos = 0;
    bool flag = true;
public:
    string tolower_all(string text);
    string toupper_all(string text);
    string upper_FirstChar(string text);
};

string Format::tolower_all(string text) {
    for (auto& i : text) {
        if (i != ' ' && (i >= 'A' && i <= 'Z')) {
            for (char g = 'A'; g <= 'Z'; g++) { // tim vi tri chu cai in hoa trong text
                upperPos++;
                if (i == g) break;
            }
            for (char h = 'a'; h <= 'z'; h++) { // doi chu in hoa thanh chu thuong
                lowerPos++;
                if (lowerPos == upperPos) {
                    i = h;
                    break;
                }
            }
        }
        lowerPos = 0;
        upperPos = 0;
    }
    return text; // tra ve text moi
}

string Format::toupper_all(string text) {
    for (auto& i : text) {
        if (i != ' ' && (i >= 'a' && i <= 'z')) {
            for (char g = 'a'; g <= 'z'; g++) { // tim vi tri chu cai thuong trong text
                lowerPos++;
                if (i == g) break;
            }
            for (char h = 'A'; h <= 'Z'; h++) { // doi chu thuong thanh chu in hoa
                upperPos++;
                if (upperPos == lowerPos) {
                    i = h;
                    break;
                }
            }
        }
        lowerPos = 0;
        upperPos = 0;
    }
    return text;
}

string Format::upper_FirstChar(string text) { // " nGuyEN TRonG pHUc" => " Nguyen Trong Phuc"
    for (auto& i : text) {
        if (!flag) {
            if (i >= 'A' && i <= 'Z') {
                for (char g = 'A'; g <= 'Z'; g++) {
                    upperPos++;
                    if (i == g) break;
                }
                for (char h = 'a'; h <= 'z'; h++) {
                    lowerPos++;
                    if (lowerPos == upperPos) {
                        i = h;
                        break;
                    }
                }
            } else {
                if (i == ' ') flag = true;
            }
        } else {
            if ((i >= 'a' && i <= 'z') || i != ' ') {
                if (i >= 'a' && i <= 'z') {
                    for (char g = 'a'; g <= 'z'; g++) {
                        lowerPos++;
                        if (i == g) break;
                    }
                    for (char h = 'A'; h <= 'Z'; h++) {
                        upperPos++;
                        if (upperPos == lowerPos) {
                            i = h;
                            break;
                        }
                    }
                }
                flag = false;
            }
        }
        lowerPos = 0;
        upperPos = 0;
    }
    return text;
}

#endif //OOP_V2_FORMATTEXT_H
