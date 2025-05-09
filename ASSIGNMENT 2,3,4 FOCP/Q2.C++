#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Person {
private:
    string name;
    int age;
    string ID;
    string contactInfo;

public:
    Person() {}
    Person(string n, int a, string id, string contact) {
        setName(n);
        setAge(a);
        ID = id;
        contactInfo = contact;
    }
    virtual ~Person() {}
    string getName() { return name; }
    void setName(string n) { if (!n.empty()) name = n; }

    int getAge() { return age; }
    void setAge(int a) { if (a > 0 && a < 120) age = a; }

    string getID() { return ID; }
    void setID(string id) { ID = id; }

    string getContactInfo() { return contactInfo; }
    void setContactInfo(string c) { contactInfo = c; }
    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age
             << ", ID: " << ID << ", Contact: " << contactInfo << endl;
    }

    virtual double calculatePayment() {
        return 0.0;
    }
};

class Student : public Person {
private:
    string enrollmentDate;
    string program;
    double GPA;

public:
    Student(string n, int a, string id, string contact,
            string enroll, string prog, double gpa)
        : Person(n, a, id, contact) {
        enrollmentDate = enroll;
        program = prog;
        setGPA(gpa);
    }

    void setGPA(double g) { if (g >= 0.0 && g <= 4.0) GPA = g; }
    double getGPA() { return GPA; }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Program: " << program << ", GPA: " << GPA
             << ", Enrollment: " << enrollmentDate << endl;
    }

    double calculatePayment() override {
        return 1000.0; 
    }
};

class Professor : public Person {
private:
    string department;
    string specialization;
    string hireDate;

public:
    Professor(string n, int a, string id, string contact,
              string dept, string spec, string hire)
        : Person(n, a, id, contact) {
        department = dept;
        specialization = spec;
        hireDate = hire;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Department: " << department << ", Specialization: "
             << specialization << ", Hire Date: " << hireDate << endl;
    }

    double calculatePayment() override {
        return 5000.0; 
    }
};

class Course {
private:
    string code;
    string title;
    int credits;
    string description;

public:
    Course(string c, string t, int cr, string d) {
        code = c;
        title = t;
        setCredits(cr);
        description = d;
    }

    void setCredits(int c) { if (c > 0) credits = c; }
    int getCredits() { return credits; }
};

class Department {
private:
    string name;
    string location;
    double budget;

public:
    Department(string n, string l, double b) {
        if (!n.empty()) name = n;
        location = l;
        budget = b;
    }
};



class GradeBook {
private:
    vector<pair<string, double>> grades; // studentID, grade

public:
    void addGrade(string studentID, double grade) {
        if (grade >= 0 && grade <= 100)
            grades.push_back({studentID, grade});
    }

    double calculateAverageGrade() {
        double total = 0;
        for (auto &g : grades)
            total += g.second;
        return grades.empty() ? 0 : total / grades.size();
    }

    double getHighestGrade() {
        double maxGrade = 0;
        for (auto &g : grades)
            if (g.second > maxGrade)
                maxGrade = g.second;
        return maxGrade;
    }

    void getFailingStudents() {
        cout << "Failing Students (Grade < 50):\n";
        for (auto &g : grades)
            if (g.second < 50)
                cout << "Student ID: " << g.first << ", Grade: " << g.second << endl;
    }
};

class EnrollmentManager {
private:
    vector<pair<string, string>> enrollments;

public:
    void enrollStudent(string studentID, string courseCode) {
        enrollments.push_back({studentID, courseCode});
    }

    void dropStudent(string studentID, string courseCode) {
        for (auto it = enrollments.begin(); it != enrollments.end(); ++it) {
            if (it->first == studentID && it->second == courseCode) {
                enrollments.erase(it);
                break;
            }
        }
    }

    int getEnrollmentCount(string courseCode) {
        int count = 0;
        for (auto &e : enrollments)
            if (e.second == courseCode)
                count++;
        return count;
    }
};


void testPolymorphism(Person *p) {
    p->displayDetails();
    cout << "Payment: $" << p->calculatePayment() << "\n\n";
}


int main() {
    
    Student s1("Alice", 20, "S1001", "alice@email.com", "2022-09-01", "CS", 3.5);
    Student s2("Bob", 21, "S1002", "bob@email.com", "2023-01-15", "Math", 2.8);

    Professor p1("Dr. Smith", 45, "P2001", "smith@uni.edu", "CS", "AI", "2010-08-01");
    Professor p2("Dr. Brown", 50, "P2002", "brown@uni.edu", "Math", "Statistics", "2005-05-10");

    Course c1("CS101", "Intro to CS", 3, "Basic computing course");
    Department d1("Computer Science", "Building A", 50000);

   
    GradeBook gb;
    gb.addGrade("S1001", 85.0);
    gb.addGrade("S1002", 45.0);
    gb.addGrade("S1001", 90.0);
    cout << "Average Grade: " << gb.calculateAverageGrade() << endl;
    cout << "Highest Grade: " << gb.getHighestGrade() << endl;
    gb.getFailingStudents();

    
    EnrollmentManager em;
    em.enrollStudent("S1001", "CS101");
    em.enrollStudent("S1002", "CS101");
    cout << "Enrollment Count for CS101: " << em.getEnrollmentCount("CS101") << endl;
    em.dropStudent("S1002", "CS101");
    cout << "After drop, Enrollment Count: " << em.getEnrollmentCount("CS101") << endl;

    
    vector<Person*> people = {&s1, &s2, &p1, &p2};
    for (Person* p : people) {
        testPolymorphism(p);
    }

    return 0;
}