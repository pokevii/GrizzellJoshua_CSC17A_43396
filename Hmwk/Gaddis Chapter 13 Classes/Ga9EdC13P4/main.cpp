#include <iostream>
#include <iomanip>
using namespace std;

class Patient{
    private:
        string fName, mName, lName;
        string address, state, city;
        int zip, phone;
        //Emergency contact
        string eName;
        int ePhone;
    public:
    //Constructor
        Patient(
        string fn, string mn, string ln, string addr, string st, 
        string ct, int z, int phn, string en, int ephn){
          fName = fn;
          mName = mn;
          lName = ln;
          address = addr;
          state = st;
          city = ct;
          zip = z;
          phone = phn;
          eName = en;
          ePhone = ephn;
        }
      
    //Mutators
    void setFNam(string n){ fName = n; }
    void setMNam(string n){ mName = n; }
    void setLNam(string n){ lName = n; }
    void setAddr(string a) { address = a; }
    void setState(string s) { state = s; }
    void setCity(string c) { city = c; }
    void setZip(int z) { zip = z; }
    void setPhone(int p) { phone = p; }
    void setENam(string n) { eName = n; }
    void setEPhn(int p) { ePhone = p; }
    //Accessors
    string getFNam(){ return fName; }
    string getMNam(){ return mName; }
    string getLNam(){ return lName; }
    string getAddr(){ return address; }
    string getState(){ return state; }
    string getCity(){ return city; }
    int getZip(){ return zip; }
    int getPhone(){ return phone; }
    string getENam(){ return eName; }
    int getEPhn(){ return ePhone; }
};

class Procedure{
    private:
    string name, date, pract;
    float charges;
    public:
    Procedure(string n, string d, string p, float c){
      name = n; date = d; pract = p; charges = c;
    }

    //Mutators
    void setName(string n) {name = n;}
    void setDate(string d) {date = d;}
    void setPrac(string s) {pract = s;}
    void setChrg(float f) {charges = f;}
    //Accessors
    string getName(){ return name; }
    string getDate(){ return date; }
    string getPrac(){ return pract; }
    float getChrg(){ return charges; } 
};

int main() {
    float total = 0;
    Patient p(
      "Homer", "J", "Simpson", "742 Evergreen Terrace", "Missouri", 
      "Springfield", 65619,5550113, "Moe Szyslak", 5551239
    );
    cout << "=========PATIENT=========\n";
    cout << "Name: " << p.getFNam() << " " << p.getMNam() << " " << p.getLNam() << endl;
    cout << "Address: " << p.getAddr() << endl;
    cout << p.getCity() << ", " << p.getState() << " " << p.getZip() << endl;
    cout << "Phone No.: " << p.getPhone() << endl;
    cout << "====EMERGENCY CONTACT====\n";
    cout << "Name: " << p.getENam() << endl;
    cout << "Phone No.: " << p.getEPhn() << "\n\n"; 
    Procedure pro1("Physical Exam", "5/13/2021", "Dr. Irvine", 250.00);
    Procedure pro2("X-ray", "5/13/2021", "Dr. Jamison", 500.00);
    Procedure pro3("Blood test", "5/13/2021", "Dr. Smith", 200.00);

    cout << fixed << setprecision(2);
    cout << "Procedure 1____________________\n";
    cout << "Procedure name: " << pro1.getName() << endl;
    cout << "Date: " << pro1.getDate() << endl;
    cout << "Practitioner: " << pro1.getPrac() << endl;
    cout << "Charge: " << pro1.getChrg() << "\n\n";

    cout << "Procedure 2____________________\n";
    cout << "Procedure name: " << pro2.getName() << endl;
    cout << "Date: " << pro2.getDate() << endl;
    cout << "Practitioner: " << pro2.getPrac() << endl;
    cout << "Charge: " << pro2.getChrg() << "\n\n";

    cout << "Procedure 3____________________\n";
    cout << "Procedure name: " << pro3.getName() << endl;
    cout << "Date: " << pro3.getDate() << endl;
    cout << "Practitioner: " << pro3.getPrac() << endl;
    cout << "Charge: " << pro3.getChrg() << "\n\n";

    total += pro1.getChrg();
    total += pro2.getChrg();
    total += pro3.getChrg();
    cout << "Total charge: " << total << endl;
}