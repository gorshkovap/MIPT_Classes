#include <iostream>
#include <vector>
#include <set>
#include <cstring>

struct Lesson;

struct Student{
    std::string name;
    std::vector<Lesson*> ptr_lessons;
    Student(std::string n):
    name(n)
    {};
};

struct Lesson{
    std::string lesson;
    std::vector<Student*> ptr_students;
    Lesson(std::string l):
    lesson(l)
    {};
};

    std::set<size_t> rule(size_t size){
    int r = rand();
    std::set<size_t> Rule = {r%size, (r+3)%size, (r+4)%size, (r+6)%size};

    return Rule;
}

void Match(Student & student, std::vector<Lesson>& LessonsToStudents){
    std::set<size_t> Rule = rule(LessonsToStudents.size());
    for (auto i : Rule){
        student.ptr_lessons.push_back(&LessonsToStudents[i]);
        LessonsToStudents[i].ptr_students.push_back(&student);
   
    }
}
void PrintStudents(const std::vector<Student>& students){
    std::cout << "\nStudents\n";
    for (const auto& st : students) {
        std:: cout << st.name << " : ";
        for (const auto & l : st.ptr_lessons)
        {
            std::cout << l->lesson << " ";
        }
        std::cout << std::endl;
    }
}
void PrintLessons(const std::vector<Lesson>& lessons){
    std::cout << "\nLessons\n";
    for (const auto& l : lessons) {
        std:: cout << l.lesson << " : ";
        for (const auto & st : l.ptr_students)
        {
            std::cout << st->name << " ";
        }
        std::cout << std::endl;
    }
}
int main(int argc, const char * argv[]) {

    std::vector<std::string> baseLessons{"Matan", "Algebra", "Analit", "Chemistry"};
    std::vector <std::string> baseStudents{"Gorshkov", "Popov", "Smirnov"};
    std::vector<Lesson> LessonsToStudents;
    for (const auto & lesson: baseLessons)
    {
        LessonsToStudents.push_back(lesson);
    }
    std::vector<Student> StudentsToLessons;
    for (const auto &student_name : baseStudents){
        StudentsToLessons.push_back(student_name);
    }

    for (auto & student : StudentsToLessons){
        Match(student, LessonsToStudents);
    }

    PrintStudents(StudentsToLessons);
    PrintLessons(LessonsToStudents);
    return 0;
}
