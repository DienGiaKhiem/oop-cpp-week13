
#include <iostream>
#include <string>
using namespace std;

class People {
private:
    string ID;
    string name;
    string address;

public:
    People() {
        ID = "00000000000000";
        name = "Unknown";
        address = "Unknown";
    }

    People(string c, string n, string a) {
        ID = c;
        name = n;
        address = a;
    }

    string getCCCD() const { return ID; }
    string getName() const { return name; }
    string getAddress() const { return address; }

    void setCCCD(string c) { ID = c; }
    void setName(string n) { name = n; }
    void setAddress(string a) { address = a; }

    void display() const {
        cout << "CCCD: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }
};

class Student : public People {
private:
    string mssv;
    int yearEntrance;

public:
    Student() : People() {
        mssv = "Unknown";
        yearEntrance = 0;
    }

    Student(string c, string n, string a, string m, int y)
        : People(c, n, a) {
        mssv = m;
        yearEntrance = y;
    }

    string getMSSV() const { return mssv; }
    int getYearEntrance() const { return yearEntrance; }

    void setMSSV(string m) { mssv = m; }
    void setYearEntrance(int y) { yearEntrance = y; }

    void display() const {
        People::display();
        cout << "MSSV: " << mssv << endl;
        cout << "Year Entrance: " << yearEntrance << endl;
    }
};

class FIEstudents : public Student {
private:
    int credits;

public:
    FIEstudents() : Student() {
        credits = 0;
    }

    FIEstudents(string c, string n, string a, string m, int y, int cr)
        : Student(c, n, a, m, y) {
        credits = cr;
    }

    int getCredits() const { return credits; }
    void setCredits(int cr) { credits = cr; }

    void display() const {
        Student::display();
        cout << "Credits: " << credits << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    People p1;
    People p2("4923754925", "Dien Gia K", "HCM");

    Student s1;
    Student s2("935898420", "Tran Thi Thu Ha", "HCMC",
               "B12345", 2020);

    FIEstudents f1;
    FIEstudents f2("45678901234567", "DUNGSENPAI",
                   "Da Nang", "C67890", 2021, 90);

    cout << "=== THONG TIN DOI TUONG p1 ===" << endl;
    p1.display();

    cout << "\n=== THONG TIN DOI TUONG p2 ===" << endl;
    p2.display();

    cout << "\n=== THONG TIN DOI TUONG s1 ===" << endl;
    s1.display();

    cout << "\n=== THONG TIN DOI TUONG s2 ===" << endl;
    s2.display();

    cout << "\n=== THONG TIN DOI TUONG f1 ===" << endl;
    f1.display();

    cout << "\n=== THONG TIN DOI TUONG f2 ===" << endl;
    f2.display();

    return 0;
}
