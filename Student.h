#ifndef STUDENT_H
#define STUDENT_H

class Student
{
public:
    Student();
    Student(const unsigned int& w, const unsigned int& win, const unsigned int& a);
    ~Student();
    void setWindow(const unsigned int t);
    void setWait(const unsigned int t);
    void setArrival(const unsigned int& t);
    void increaseWait();
    void decreaseWindow();
    unsigned int getWait() const;
    unsigned int getWindow() const;    
    unsigned int getArrival() const;
    bool operator ==(const Student& other);
    bool operator !=(const Student& other);
    void operator =(const Student& stu);

private:
    unsigned int wait;
    unsigned int window;
    unsigned int arrival;
};

#endif //STUDENT_H
