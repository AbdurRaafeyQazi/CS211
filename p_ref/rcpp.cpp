#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;


// class bsb250{

//     public:
    
//     bsb250(){
//         count = 0;
//         name = "Null";
//     }

//     void setNumStudent(int Snum); // Modifier
//     void setStudentName(string Sname); // Modifier

//     int getNumStudent()const; // Accessor
//     string getStudentName()const;  // Accessor

//     void print();

//     private:

//     int count;
//     string name;


// };



// void bsb250::setNumStudent(int Snum) {
//     count = Snum; // Assign Snum to count
// }

// void bsb250::setStudentName(string Sname){
//     name = Sname;

// }

// int bsb250::getNumStudent() const {
//     return count;
// }

// string bsb250::getStudentName() const {
//     return name;
// }

// void bsb250::print(){

//     cout << "BSB-250 has " << count << " number of students." << endl;
//     cout << "BSB-250 has " << name << " present." << endl;

// }



// int main(){

//     bsb250 Monday;

//     Monday.setNumStudent(500);
//     Monday.setStudentName("Monkey");
//     Monday.print();

//     return 0;
// }


class Student{

    public: 

    Student(){
        int id = 0;
        string name = "unknown";
        double gpa = 0.0;
    }

    Student(int Sid, string Sname, double Sgpa){

        id = Sid;
        name = Sname;
        gpa = Sgpa;
        
    }

    Student(const Student& other){
        id = other.id;
        name = other.name;
        gpa = other.gpa;
    }

    void setid(int Sid){
        id = Sid;
    }

    void setname(string Sname){
        name = Sname;
    }

    void setgpa(double Sgpa){
        gpa = Sgpa;
    }

    int getid() const {
        return id;
    }

    string setname() const{
        return name;
    }

    double setgpa() const {
        return gpa;
    }

    void print(){
        cout << id << name << gpa << endl;
    }

    ~Student(){
        // Delete something here

    }

    private:

    int id;
    string name;
    double gpa;

};