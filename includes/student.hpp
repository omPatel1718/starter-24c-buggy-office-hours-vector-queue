#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

struct Student {
  std::string name;
  int student_id = 0;                  // Unique for each student
  double attendance_percentage = 0.0;  // Between 0 and 100
  int arrival_order = 0;  // The order in which the student joined the queue
};

#endif