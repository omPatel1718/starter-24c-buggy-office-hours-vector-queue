#ifndef OFFICE_HOURS_QUEUE_HPP
#define OFFICE_HOURS_QUEUE_HPP

#include <vector>

#include "staff.hpp"
#include "student.hpp"

struct OfficeHoursQueue {
  std::vector<Student> student_queue;
  std::vector<Staff> staff_queue;
  int student_arrival_counter = 0;
  int staff_arrival_counter = 0;
};

#endif