// functions.cpp
#include "functions.hpp"
#include "office-hours-queue.hpp"
#include "staff.hpp"
#include "student.hpp"
#include <iostream>
#include <random>
#include <vector>

// Helper: return true if 'a' has higher priority than 'b' for student queue
static bool StudentHigherPriority(const Student& a, const Student& b) {
  if (a.attendance_percentage > b.attendance_percentage) return true;
  if (a.attendance_percentage < b.attendance_percentage) return false;
  // tie: earlier arrival_order (smaller) has higher priority
  return a.arrival_order < b.arrival_order;
}

// Helper: return true if 'a' has higher priority than 'b' for staff queue
static bool StaffHigherPriority(const Staff& a, const Staff& b) {
  if (a.encounter_count < b.encounter_count) return true;
  if (a.encounter_count > b.encounter_count) return false;
  if (a.total_help_time < b.total_help_time) return true;
  if (a.total_help_time > b.total_help_time) return false;
  // tie: earlier arrival_order (smaller) has higher priority
  return a.arrival_order < b.arrival_order;
}

void AddStudent(OfficeHoursQueue& queue, const Student& student) {
  // copy so we can set arrival_order
  Student s = student;
  s.arrival_order = queue.student_arrival_counter++;
  queue.student_queue.push_back(s);

  // bubble new student left until in correct position
  int i = static_cast<int>(queue.student_queue.size()) - 1;
  while (i > 0) {
    if (StudentHigherPriority(queue.student_queue[i], queue.student_queue[i - 1])) {
      // swap manually (allowed headers only)
      Student tmp = queue.student_queue[i - 1];
      queue.student_queue[i - 1] = queue.student_queue[i];
      queue.student_queue[i] = tmp;
      --i;
    } else {
      break;
    }
  }
}

void AddStaff(OfficeHoursQueue& queue, const Staff& staff) {
  Staff s = staff;
  s.arrival_order = queue.staff_arrival_counter++;
  queue.staff_queue.push_back(s);

  int i = static_cast<int>(queue.staff_queue.size()) - 1;
  while (i > 0) {
    if (StaffHigherPriority(queue.staff_queue[i], queue.staff_queue[i - 1])) {
      Staff tmp = queue.staff_queue[i - 1];
      queue.staff_queue[i - 1] = queue.staff_queue[i];
      queue.staff_queue[i] = tmp;
      --i;
    } else {
      break;
    }
  }
}

void HelpNextStudent(OfficeHoursQueue& queue) {
  // If either queue empty, nothing to do.
  if (queue.student_queue.empty() || queue.staff_queue.empty()) {
    return;
  }

  // Pop the student from the front (index 0)
  Student next_student = queue.student_queue.front();
