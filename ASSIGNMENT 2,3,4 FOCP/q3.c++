#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Person {
protected:
    string name;
    int age;
    string ID;
    string contactInfo;

public:
    Person() {}
    Person(string n, int a, string id, string contact) {
        name = n;
        age = a;
        ID = id;
        contactInfo = contact;
    }

    virtual ~Person() {}

    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age
             << ", ID: " << ID << ", Contact: " << contactInfo << endl;
    }

    virtual double calculatePayment() = 0;

    string getName() { return name; }  
};



class Student : public Person {
protected:
    string enrollmentDate;
    string program;
    double GPA;

public:
    Student(string n, int a, string id, string contact,
            string enroll, string prog, double gpa)
        : Person(n, a, id, contact) {
        enrollmentDate = enroll;
        program = prog;
        GPA = gpa;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Program: " << program << ", GPA: " << GPA << endl;
    }

    double calculatePayment() override {
        return 1000.0; 
    }
};

class UndergraduateStudent : public Student {
private:
    string major;
    string minor;
    string graduationDate;

public:
    UndergraduateStudent(string n, int a, string id, string contact,
                         string enroll, string prog, double gpa,
                         string maj, string min, string grad)
        : Student(n, a, id, contact, enroll, prog, gpa) {
        major = maj;
        minor = min;
        graduationDate = grad;
    }

    void displayDetails() override {
        Student::displayDetails();
        cout << "Major: " << major << ", Minor: " << minor
             << ", Graduation: " << graduationDate << endl;
    }

    double calculatePayment() override {
        return 1200.0;
    }
};


class Professor;

class GraduateStudent : public Student {
private:
    string researchTopic;
    Professor* advisor;
    string thesisTitle;

public:
    GraduateStudent(string n, int a, string id, string contact,
                    string enroll, string prog, double gpa,
                    string topic, Professor* adv, string thesis)
        : Student(n, a, id, contact, enroll, prog, gpa) {
        researchTopic = topic;
        advisor = adv;
        thesisTitle = thesis;
    }

    void displayDetails() override; 

    double calculatePayment() override {
        return 800.0; 
    }

    void trackAssistantships() {
        cout << name << " is working as a teaching assistant.\n";
    }
};


class Professor : public Person {
protected:
    string department;
    string specialization;
    string hireDate;
    int yearsOfService;
    double baseSalary;

public:
    Professor(string n, int a, string id, string contact,
              string dept, string spec, string hire, int years, double base)
        : Person(n, a, id, contact) {
        department = dept;
        specialization = spec;
        hireDate = hire;
        yearsOfService = years;
        baseSalary = base;
    }

    string getName() { return name; }

    virtual void displayDetails() override {
        Person::displayDetails();
        cout << "Dept: " << department << ", Specialization: "
             << specialization << ", Hired: " << hireDate << endl;
    }

    virtual double calculatePayment() override {
        return baseSalary + (yearsOfService * 100); 
    }
};

class AssistantProfessor : public Professor {
public:
    AssistantProfessor(string n, int a, string id, string contact,
                       string dept, string spec, string hire, int years)
        : Professor(n, a, id, contact, dept, spec, hire, years, 4000) {}

    double calculatePayment() override {
        return baseSalary + (yearsOfService * 150);
    }

    void displayDetails() override {
        Professor::displayDetails();
        cout << "Rank: Assistant Professor\n";
    }
};

class AssociateProfessor : public Professor {
public:
    AssociateProfessor(string n, int a, string id, string contact,
                       string dept, string spec, string hire, int years)
        : Professor(n, a, id, contact, dept, spec, hire, years, 6000) {}

    double calculatePayment() override {
        return baseSalary + (yearsOfService * 200);
    }

    void displayDetails() override {
        Professor::displayDetails();
        cout << "Rank: Associate Professor\n";
    }
};

class FullProfessor : public Professor {
private:
    double researchGrant;

public:
    FullProfessor(string n, int a, string id, string contact,
                  string dept, string spec, string hire, int years, double grant)
        : Professor(n, a, id, contact, dept, spec, hire, years, 8000) {
        researchGrant = grant;
    }

    double calculatePayment() override {
        return baseSalary + (yearsOfService * 300) + researchGrant;
    }

    void displayDetails() override {
        Professor::displayDetails();
        cout << "Rank: Full Professor, Research Grant: $" << researchGrant << "\n";
    }
};


void GraduateStudent::displayDetails() {
    Student::displayDetails();
    cout << "Research Topic: " << researchTopic
         << ", Thesis: " << thesisTitle << endl;
    if (advisor != nullptr)
        cout << "Advisor: " << advisor->getName() << endl;
}



int main() {
    AssistantProfessor ap("Dr. Lee", 35, "P101", "lee@uni.edu", "Physics", "Quantum Mechanics", "2018", 6);
    AssociateProfessor asp("Dr. Kim", 45, "P102", "kim@uni.edu", "Math", "Topology", "2010", 12);
    FullProfessor fp("Dr. Ray", 55, "P103", "ray@uni.edu", "CS", "AI", "2005", 20, 15000);

    UndergraduateStudent us("John Doe", 19, "U001", "john@uni.edu", "2023", "CS", 3.2, "CS", "Math", "2026");
    GraduateStudent gs("Jane Smith", 25, "G001", "jane@uni.edu", "2022", "CS", 3.8, "AI in Healthcare", &fp, "Deep Learning Models");

    vector<Person*> people = {&ap, &asp, &fp, &us, &gs};

    for (Person* p : people) {
        p->displayDetails();
        cout << "Payment: $" << p->calculatePayment() << "\n\n";
    }

    gs.trackAssistantships();

    return 0;
}
