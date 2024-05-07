//
// Created by Trong_Phuc on 21/04/2024.
//
#include "../headers/Employee.h"

/*WRITE & READ CONTENT IN FILE METHODS*/

void Storage::deleteFile(const string& data) {
    ofstream dataReplace(detailPath);
    if (!dataReplace) {
        cout << "This file \"" << detailPath << "\" is corrupted !\n";
    } else {
        if (dataReplace.fail() || dataReplace.bad()) {
            cout << "An error occurred during writing !\n";
        } else {
            for (auto& i :data) {
                if (i != '-') dataReplace << i;
                else dataReplace << endl;
            }
            cout << "Da xoa nhan vien thanh cong !\n";
            dataReplace.close();
        }
    }
}

void Storage::writeFile(list<Resume *> &data) {
    ofstream dataUpload(detailPath, ios::app);
    if (!dataUpload) {
        cout << "This file \"" << detailPath << "\" is corrupted !\n";
    } else {
        if (dataUpload.fail() || dataUpload.bad()) {
            cout << "An error occurred during writing !\n";
        } else {
            dataUpload << data.back()->get_id(false) << '/';
            dataUpload << data.back()->get_name() << '/';
            dataUpload << data.back()->get_status() << '/';
            dataUpload << data.back()->get_children() << '/';
            dataUpload << data.back()->get_eduLevel() << '/';
            dataUpload << data.back()->get_baseSalary() << '/';
            dataUpload << data.back()->get_timeKeeping()->get_daysoffAvailable() << '/';
            dataUpload << data.back()->get_timeKeeping()->get_daysoffUnavailable() << '/';
            dataUpload << data.back()->get_timeKeeping()->get_overTime() << '/';
            dataUpload << data.back()->get_timeKeeping()->get_result() << '/';
            dataUpload << (long)data.back()->get_totalSalary() << endl;
            dataUpload.close();
        }
    }
}

string Storage::readFile() {
    string des, dataRead;

    ifstream dataDownload(detailPath);
    if (!dataDownload) {
        cout << "This file \"" << detailPath << "\" is corrupted !\n";
    } else {
        if (dataDownload.fail() || dataDownload.bad()) {
            cout << "An error occurred during reading !\n";
        } else {
            while (getline(dataDownload, dataRead)) { des.append(dataRead.append(1, '-')); }
            dataDownload.close();
        }
    }
    return des; // tra ve toan bo thong tin
}