#include <iostream>
#include <map>

/*
 * set: chen va sap xep cac phan tu KHAC NHAU
 * - insert, find, size, erase, count, empty, clear, ...
 * - lower_bound(key): phan tu >= key
 * - upper_bound(key): phan tu > key
 * - pair<data_type: first, data_type: second> abc, abc.first, abc.second
 *
 * multiset: chen va sap xep cac phan tu co the TRUNG LAP
 * - same above
 * - equal_range(key): do tim so luong phan bi trung lap, tra ve cap du lieu itr1 va itr2
 * (itr1: key dau tien xuat hien, itr2: phan tu cuoi cung xuat hien sau itr1)
 * - NOTE: pair<data_type: first, data_type: second> abc, abc.first, abc.second
 * - multiset<data_type> a(b): sao chep b sang a
 * => Ho tro luu tru tokens, luu tru events on realtime
 *
 * unordered_set: tuong tu set nhung KHONG SAP XEP thu tu cac phan tu
 * */

/*
 * map: mot danh sach bao gom nhieu key - value
 * - insert(make_pair(key, val)): automatically determine the data type against pair
 * - insert(pair <int, string> (key, val), emplace(key, val)
 * - myMap[key] = val, myMap.at(key) = val
 *
 * multimap: giong nhau key, key vao truoc thi xuat hien truoc
 * */

using namespace std;

int main() {
    map <int, string> myMap;
    int keys[] = {-1, 5, 2, 9, -25}, amount = 5;
    string vals[] = {"Hello World", "Holyshit", "XinChoAeCon", "CongSo8", "QuaGheGom"};

//    myMap.insert(make_pair(9, "Hello"));
//    myMap.emplace(4, "HolyShit");
//    cout << myMap[9] << ' ' << myMap[4] << endl;
//    myMap[4] = "XinChoAeCon";
//    cout << myMap.at(4) << ' ' << myMap.at(9) << endl;
    for (int i = 0; i < amount; i++) myMap.emplace(keys[i], vals[i]); // them cac phan tu vao myMap
    for (auto &i : myMap) cout << i.first << " : " << i.second << endl;

    /*typedef multiset <int>::iterator It;
    multiset <int> myMap;
    pair <multiset <int>::iterator, multiset <int>::iterator> b;
    int arrs[] = {-1, 8, 2, 0, 7, 4};

    for (int &i : arrs) myMap.insert(i);
    for (auto &i : myMap) cout << i << ' ';
    cout << endl;
//    b = myMap.equal_range(10);

    It it1, it2;
    it1 = myMap.lower_bound(2);
    it2 = myMap.upper_bound(7);

    myMap.erase(it1, it2);
    for (auto &i : myMap) cout << i << ' ';*/
    return 0;
}
