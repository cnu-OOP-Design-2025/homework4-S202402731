#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    if (num_of_students >= MAX_STUDENTS) {
        std::cout << "Error: Cannot add more students.\n";
        return;
    }
    int id = ++last_student_id;
    /* TODO */
    students[num_of_students++] = Student(name, id, midterm, final);
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int idx = findStudentByID(id);
    if (idx == -1) {
        std::cout << "Student ID " << id << " not found.\n";
        return;
    }
    for (int i = idx; i < num_of_students - 1; i++)
        students[i] = students[i + 1];
    num_of_students--;
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    int idx = findStudentByID(student.getID());
    if (idx == -1) {
        std::cout << "Student ID " << student.getID() << " not found.\n";
        return;
    }
    students[idx] = student;
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for (int i = 0; i < num_of_students; i++)
        if (students[i].getID() == id)
            return i;
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    if (num_of_students == 0) return -1;
    int bestIdx = 0;
    float bestScore = students[0].getRecord().getMidterm();
    for (int i = 1; i < num_of_students; i++) {
        if (students[i].getRecord().getMidterm() > bestScore) {
            bestScore = students[i].getRecord().getMidterm();
            bestIdx = i;
        }
    }
    return students[bestIdx].getID();
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    if (num_of_students == 0) return -1;
    int bestIdx = 0;
    float bestScore = students[0].getRecord().getFinal();
    for (int i = 1; i < num_of_students; i++) {
        if (students[i].getRecord().getFinal() > bestScore) {
            bestScore = students[i].getRecord().getFinal();
            bestIdx = i;
        }
    }
    return students[bestIdx].getID();
}

int StudentManager::findBestStudent() const {
    /* TODO */
    if (num_of_students == 0) return -1;
    int bestIdx = 0;
    float bestScore = students[0].getRecord().getTotal();
    for (int i = 1; i < num_of_students; i++) {
        if (students[i].getRecord().getTotal() > bestScore) {
            bestScore = students[i].getRecord().getTotal();
            bestIdx = i;
        }
    }
    return students[bestIdx].getID();
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    if (num_of_students == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < num_of_students; i++)
        sum += students[i].getRecord().getMidterm();
    return sum / num_of_students;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    if (num_of_students == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < num_of_students; i++)
        sum += students[i].getRecord().getFinal();
    return sum / num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    if (num_of_students == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < num_of_students; i++)
        sum += students[i].getRecord().getTotal();
    return sum / num_of_students;
}