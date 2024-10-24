#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>

#include "office-hours-queue.hpp"
#include "staff.hpp"
#include "student.hpp"

void AddStudent(OfficeHoursQueue& queue, const Student& student);
void AddStaff(OfficeHoursQueue& queue, const Staff& staff);
void HelpNextStudent(OfficeHoursQueue& queue);
bool IsStudentQueueEmpty(const OfficeHoursQueue& queue);
bool IsStaffQueueEmpty(const OfficeHoursQueue& queue);

#endif