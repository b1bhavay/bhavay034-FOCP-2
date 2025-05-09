#include <iostream>
#include <vector>
#include <string>
using namespace std;



class UniversitySystemException {
protected:
    string message;
public:
    UniversitySystemException(const string& msg) : message(msg) {}
    string what() const { return message; }
};

class EnrollmentException : public UniversitySystemException {
public:
    EnrollmentException(const string& msg) : UniversitySystemException("Enrollment Error: " + msg) {}
};

class GradeException : public UniversitySystemException {
public:
    GradeException(const string& msg) : UniversitySystemException("Grade Error: " + msg) {}
};

class PaymentException : public UniversitySystemException {
public:
    PaymentException(const string& msg) : UniversitySystemException("Payment Error: " + msg) {}
};



void logError(const string& msg) {
    cout << "[Error Log] " << msg << endl;
}



class Person {
protected:
    string name, id, contact;
    int age;

public:
    Person(string n, int a, string i, string c) {
        if (i == "") throw UniversitySystemException("Invalid ID.");
        if (c.find('@') == string::npos) throw UniversitySystemException("Invalid contact info.");
        name = n; age = a; id = i; contact = c;
    }

    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << id << ", Contact: " << contact << endl;
    }

    virtual double calculatePayment() = 0;
    virtual ~Person() {}

    string getID() { return id; }
    string getName() { return name; }
};

class Student : public Person {
protected:
    double gpa;

public:
    Student(string n, int a, string i, string c, double g)
        : Person(n, a, i, c), gpa(g) {}

    void displayDetails() override {
        Person::displayDetails();
        cout << "GPA: " << gpa << endl;
    }

    double calculatePayment() override {
        if (gpa < 0.0 || gpa > 4.0) throw PaymentException("Invalid GPA for payment.");
        return 1000.0;
    }
};

class Professor : public Person {
protected:
    string department;
    double salary;

public:
    Professor(string n, int a, string i, string c, string d, double s)
        : Person(n, a, i, c), department(d), salary(s) {}

    void displayDetails() override {
        Person::displayDetails();
        cout << "Department: " << department << endl;
    }

    double calculatePayment() override {
        if (salary <= 0) throw PaymentException("Salary must be positive.");
        return salary;
    }
};

class Course {
public:
    string code, title;
    int maxStudents;
    Professor* instructor;
    vector<Student*> enrolled;

    Course(string c, string t, int max) : code(c), title(t), maxStudents(max), instructor(NULL) {}

    void assignInstructor(Professor* p) {
        instructor = p;
    }

    void enrollStudent(Student* s) {
        if (enrolled.size() >= maxStudents)
            throw EnrollmentException("Course is full.");
        enrolled.push_back(s);
    }

    void showDetails() {
        cout << "Course: " << code << ", Title: " << title << ", Students Enrolled: " << enrolled.size() << endl;
        if (instructor)
            cout << "Instructor: " << instructor->getName() << endl;
    }
};



class UniversitySystem {
private:
    vector<Student*> students;
    vector<Professor*> professors;
    vector<Course*> courses;

public:
    void addStudent(Student* s) {
        students.push_back(s);
    }

    void addProfessor(Professor* p) {
        professors.push_back(p);
    }

    void addCourse(Course* c) {
        courses.push_back(c);
    }

    void enrollStudentInCourse(string studentID, string courseCode) {
        Student* stu = NULL;
        Course* course = NULL;

        for (int i = 0; i < students.size(); i++)
            if (students[i]->getID() == studentID)
                stu = students[i];

        for (int i = 0; i < courses.size(); i++)
            if (courses[i]->code == courseCode)
                course = courses[i];

        if (stu == NULL || course == NULL)
            throw EnrollmentException("Student or course not found.");

        course->enrollStudent(stu);
    }

    void showAll() {
        cout << "\n--- All Courses ---\n";
        for (int i = 0; i < courses.size(); i++) {
            courses[i]->showDetails();
        }
    }
};



int main() {
    UniversitySystem system;

    try {
        Student* s1 = new Student("Ali", 20, "S01", "ali@email.com", 3.5);
        Student* s2 = new Student("Sara", 21, "S02", "sara@email.com", 3.8);
        Professor* p1 = new Professor("Dr. Khan", 45, "P01", "khan@uni.edu", "CS", 5000);
        Course* c1 = new Course("CS101", "Intro to CS", 1);

        system.addStudent(s1);
        system.addStudent(s2);
        system.addProfessor(p1);
        system.addCourse(c1);

        c1->assignInstructor(p1);

        // Successful enrollment
        system.enrollStudentInCourse("S01", "CS101");

        
        system.enrollStudentInCourse("S02", "CS101");
    }
    catch (UniversitySystemException& e) {
        logError(e.what());
    }

    system.showAll();
    return 0;
}
