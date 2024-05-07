//
// Created by Trong_Phuc on 03/07/2023.
//

#ifndef EMPLOYEE_MANAGER_STORAGE_H
#define EMPLOYEE_MANAGER_STORAGE_H

#include <fstream>
#include <string>
#include <list>
#include "Resume.h"

class Storage {
private:
    const string detailPath = "detailEmployee.txt";

public:
    void deleteFile(const string& data);
    void writeFile(list<Resume *> &data);
    string readFile();
};

#endif //EMPLOYEE_MANAGER_STORAGE_H
