CXX=clang++
CXX_FLAGS=-std=c++20 -I includes -Wall -Wextra -Werror -O0 -g

exec: bin/exec

bin/exec: ./src/driver.cc ./includes/functions.hpp ./src/functions.cc ./includes/student.hpp ./includes/staff.hpp ./includes/office-hours-queue.hpp
	$(CXX) $(CXX_FLAGS) ./src/driver.cc ./src/functions.cc -o $@

.DEFAULT_GOAL := exec
.PHONY: exec clean

clean:
	rm -rf bin/*