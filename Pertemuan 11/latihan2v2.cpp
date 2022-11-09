#include <iostream>
using namespace std;

class Mahasiswa {
    public:
    void printName() {
        cout << "My name is " << Name << "NRP " << NRP << endl;
    }

    string getName() {
        return Name;
    }

    Mahasiswa(string Nama, string NoID) { //constructor
        Name = Nama;
        NRP = NoID;
    }

    private:
    string Name;
    string NRP;
};


int main() {
    Mahasiswa mhs1("Muhammad Ali", "1412047120");
    mhs1.printName();
    cout << mhs1.getName();
}
