#ifndef STAFF_HPP
#define STAFF_HPP

#include <string>

struct Staff {
  std::string name;
  int staff_id = 0;         // Unique for each staff member
  int encounter_count = 0;  // Number of students helped
  int arrival_order =
      0;  // The order in which the staff member joined the queue
  int total_help_time = 0;  // Total time spent helping students (in minutes)
};

#endif