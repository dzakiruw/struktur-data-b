#include <iostream>
using namespace std;

class MHS {
    private:
        string MHSname;

	public:
	    void setName(string n){
	        MHSname = n;
	    }
        void getName(){
            cout << "MHS name is : " << MHSname << "\n";
        }
};

int main(){
    MHS mhs1;
    mhs1.setName("tes");
    mhs1.getName();
    return 0;
}
