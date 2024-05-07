//
// Created by Trong_Phuc on 05/06/2023.
//

#ifndef DATA_ENCRYPTION_MYCARO_H
#define DATA_ENCRYPTION_MYCARO_H

#include <iostream>
#include <fstream>
#include <algorithm> // Tuy thuoc vao IDE, dung cho vector <dataType>::iterator variableName
//#include <vector>
#include <cmath>

using namespace std;

class myCaro {
private:
    vector <string> storedSteps;
    vector <string>::iterator samePos;
    string yourStep, dataReceived, dataFile;
    unsigned int xCount = 0, oCount = 0;

    static bool check_validData(const string& data);
    static string encrypt_data(vector <string>& data);
    static string decrypt_data(const string& data);
    // console_data: refreshing and showing turns of gamer

public:
    myCaro(const string& file_text) {
        dataFile = file_text + ".txt";
    }
    void in_turn(char first_turn);
    void out_turn() const;
    void up_encryptedData();
    void down_decryptedData();
    void renew_turn();
};

bool myCaro::check_validData(const string &data) {
    if (data.length() != 3) {
        if (data.length() != 2) {
            return false;
        } else {
            if (!isdigit(data[0]) || data[1] < 'a' || data[1] > 'o') return false;
        }
    } else {
        if (data[0] != '1') {
            return false;
        } else {
            if (data[1] < '0' || data[1] > '5') {
                return false;
            } else {
                if (data[2] < 'a' || data[2] > 'o') return false;
            }
        }
    }
    return true;
}

string myCaro::encrypt_data(vector <string> &data) {
    string processedData;
    unsigned int boundary, prefixNum = 0, suffixNum = 0;

    for (int i = 0; i < data.size(); i++) { // duyet tung phan tu ben trong vector data
        for (auto& j : data[i]) { // 5a, 6z, 12g ...
            if (j >= 'a' && j <= 'o') { // trich xuat ky tu Alphabet (a - o)
                if (prefixNum == 1) boundary = 1; // 5a
                else boundary = 2; // 12f
                prefixNum = stoi(data[i].substr(0, boundary));
                for (char Alphabet = 'a'; Alphabet <= 'o'; Alphabet++) { // vi tri tu 1 - 15
                    suffixNum++;
                    if (Alphabet == j) {
                        processedData += to_string(prefixNum * suffixNum); // hoan tat ma hoa lan luot du lieu
                        if (i != data.size() - 1) processedData += ',';
                        prefixNum = 0;
                        suffixNum = 0;
                        break;
                    }
                }
            } else {
                prefixNum++;
                processedData += j;
            }
        }
    }
    return processedData;
}

string myCaro::decrypt_data(const string &data) {
    string mainData;
    bool flag = true;
    unsigned int iPos, divisorNum, dividedNum, elementCheck, elementLength = 0, elementStep = 1, suffixCount = 0;

    for (int i = 0; i < data.length(); i++) {
        if (data[i] == ',' || i == data.length() - 1) {
            if (i == data.length() - 1) elementLength++;
            do {
                divisorNum = stoi(data.substr(iPos, elementLength)) / int(pow(10, elementLength - elementStep)); // so chia
                dividedNum = stoi(data.substr(iPos, elementLength)) % int(pow(10, elementLength - elementStep)); // so bi chia
                if (dividedNum == 0) return "error";
                elementCheck = dividedNum / divisorNum; // true neu thuoc doan [1; 15]
                if (elementCheck > 15 || float((dividedNum * 1.0 / divisorNum) - elementCheck) > 0) elementStep++;
            } while (elementCheck > 15 || float((dividedNum * 1.0 / divisorNum) - elementCheck) > 0);
            for (char Alphabet = 'a'; Alphabet <= 'o'; Alphabet++) {
                suffixCount++;
                if (suffixCount == elementCheck) {
                    mainData += to_string(divisorNum) + Alphabet; // hoan tat giai ma lan luot du lieu
                    flag = true;
                    elementLength = 0;
                    elementStep = 1;
                    suffixCount = 0;
                    break;
                }
            }
        } else {
            if (flag) {
                iPos = i;
                flag = false;
            }
            elementLength++;
        }
    }
    return mainData;
}

void myCaro::in_turn(char first_turn) {
    do {
        cout << "Moi ban nhap vao luot di cua " << first_turn << " (toa do \"xy\" (x: 1 - 15, y: a - o) hoac '/' => End Loop):";
        cin >> yourStep;
        if (yourStep.empty()) {
            cout << "Ban chua nhap du lieu. Moi ban nhap lai !\n";
        } else {
            if (yourStep != "/") {
                if (!check_validData(yourStep)) {
                    cout << "Ban nhap du lieu chua dung toa do !\n";
                } else {
                    samePos = find(storedSteps.begin(), storedSteps.end(), yourStep); // kiem tra luot di bi trung lap
                    if (samePos != storedSteps.end()) {
                        cout << "Ban da nhap nuoc di nay roi !\n" ;
                    } else {
                        storedSteps.push_back(yourStep);
                        if (first_turn == 'O') {
                            first_turn = 'X';
                            oCount++;
                        } else {
                            first_turn = 'O';
                            xCount++;
                        }
                        // GUI of Caro
                    }
                }
            } else {
                if (xCount != oCount) cout << "Ban van con thieu luot di cua " << first_turn << " !\n"; // vi X di truoc nen bat buoc O phai la luot di ket thuc
                else break;
            }
        }
    } while (yourStep.empty() || !check_validData(yourStep) || xCount != oCount || samePos != storedSteps.end());
}

void myCaro::out_turn() const {
    cout << "- Luot di cua X: " << xCount << endl;
    cout << "- Luot di cua O: " << oCount << endl;
    // Tra ve ket qua: X hoac O thang, hoa nhau
}

void myCaro::up_encryptedData() {
    ofstream dataUpload(dataFile); // tai du lieu da xu li len file.txt
    if (!dataUpload) {
        cout << "Failed to upload !\n";
    } else {
        for (auto& i : encrypt_data(storedSteps)) dataUpload << i;
        cout << "=> Du lieu da duoc ma hoa va tai len " << dataFile << ": " << encrypt_data(storedSteps) << endl;
        dataUpload.close();
    }
}

void myCaro::down_decryptedData() {
    ifstream dataDownload(dataFile); // tai du lieu goc xuong man hinh console tu file.txt
    if (!dataDownload) {
        cout << "Failed to download !\n";
    } else {
        while (dataDownload >> dataReceived); // Truyen du lieu xuong dataReceived
        if (decrypt_data(dataReceived) == "error") cout << "Du lieu trong " << dataFile << " bi loi !" << endl;
        else cout << "=> Du lieu da duoc giai ma va tai xuong tu " << dataFile << ": " << decrypt_data(dataReceived) << endl;
        dataDownload.close();
    }
}

void myCaro::renew_turn() {
    xCount = 0;
    oCount = 0;
    system("cls");
}

#endif //DATA_ENCRYPTION_MYCARO_H
