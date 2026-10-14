#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Employee {
private:
    string cccd;
    string sdt;
    string address;

public:
    Employee() {
        cccd = "";
        sdt = "";
        address = "";
    }

    Employee(string c, string p, string a) {
        cccd = c;
        sdt = p;
        address = a;
    }

    string getCCCD() const { return cccd; }
    string getSDT() const { return sdt; }
    string getAddress() const { return address; }

    void setCCCD(string c) { cccd = c; }
    void setSDT(string p) { sdt = p; }
    void setAddress(string a) { address = a; }

    void displayInfo() const {
        cout << "CCCD: " << cccd << endl;
        cout << "SDT: " << sdt << endl;
        cout << "Address: " << address << endl;
    }
};

class HourlyEmployee : public Employee {
private:
    int soGioLamViec;
    double donGia;

public:
    HourlyEmployee() : Employee() {
        soGioLamViec = 0;
        donGia = 0.0;
    }

    HourlyEmployee(string c, string p, string a, int soGio, double dg)
        : Employee(c, p, a) {
        soGioLamViec = soGio;
        donGia = dg;
    }

    int getSoGioLamViec() const { return soGioLamViec; }
    double getDonGia() const { return donGia; }

    void setSoGioLamViec(int g) { soGioLamViec = g; }
    void setDonGia(double dg) { donGia = dg; }

    double tinhLuong() const {
        return soGioLamViec * donGia;
    }

    void displayInfo() const {
        Employee::displayInfo();
        cout << "So gio lam viec: " << soGioLamViec << endl;
        cout << "Don gia: " << fixed << setprecision(0) << donGia << endl;
        cout << "Luong: " << fixed << setprecision(0) << tinhLuong() << endl;
    }
};

class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;

public:
    MonthlyEmployee() : Employee() {
        luongCoBan = 0.0;
        phuCap = 0.0;
        heSoThuong = 0.0;
    }

    MonthlyEmployee(string c, string p, string a,
                    double lcb, double pc, double hs)
        : Employee(c, p, a) {
        luongCoBan = lcb;
        phuCap = pc;
        heSoThuong = hs;
    }

    double getLuongCoBan() const { return luongCoBan; }
    double getPhuCap() const { return phuCap; }
    double getHeSoThuong() const { return heSoThuong; }

    void setLuongCoBan(double lcb) { luongCoBan = lcb; }
    void setPhuCap(double pc) { phuCap = pc; }
    void setHeSoThuong(double hs) { heSoThuong = hs; }

    double tinhLuong() const {
        return luongCoBan + phuCap + (luongCoBan * heSoThuong);
    }

    void displayInfo() const {
        Employee::displayInfo();
        cout << "Luong co ban: " << fixed << setprecision(0) << luongCoBan << endl;
        cout << "Phu cap: " << fixed << setprecision(0) << phuCap << endl;
        cout << "He so thuong: " << fixed << setprecision(1) << heSoThuong << endl;
        cout << "Luong: " << fixed << setprecision(0) << tinhLuong() << endl;
    }
};

int main() {
    Employee e1;

    HourlyEmployee h1("079555666777", "0938123456",
                      "Hue", 175, 45000);

    MonthlyEmployee m1("079888999111", "0976234568",
                       "Nha Trang", 14000000, 1800000, 0.5);

    cout << "--- Employee e1 ---" << endl;
    e1.displayInfo();

    cout << "\n--- HourlyEmployee h1 ---" << endl;
    h1.displayInfo();

    cout << "\n--- MonthlyEmployee m1 ---" << endl;
    m1.displayInfo();

    return 0;
}