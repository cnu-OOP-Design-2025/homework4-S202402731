#include "student.h"

#include <iostream>

/* StudentRecord */

StudentRecord::StudentRecord(float midterm, float final) 
/* TODO: Initializer list 사용해 초기화 해보기 */
    : midterm(midterm), final(final)
{ }

float StudentRecord::getTotal() const {
    /* TODO */
    return (midterm + final) / 2.0f;
}

void StudentRecord::updateScores(float midterm, float final) {
    /* TODO: this keyword 사용해 보기 */
    this->midterm = midterm;
    this->final = final;
}


/* Student */
int Student::last_student_id = 1000;

Student::Student() 
/* TODO: Initializer list 사용해 초기화 해보기 */
    : name(""), id(-1), record(0.0f, 0.0f)
{ }

Student::Student(const char *name, int id, float midterm, float final)
/* TODO: Initializer list 사용해 초기화 해보기 */
    : name(name), id(id), record(midterm, final)
{  }

void Student::updateRecord(const char *name, float midterm, float final) {
    /* TODO */
    this->name = name;
    this->record.updateScores(midterm, final);
}