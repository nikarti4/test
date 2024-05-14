CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
TESTFLAGS = -lcheck -lm

SRCPATH = source_code
SRCFILES = *.c
SRCOBJ = $(SRCFILES:%.c=%.o)

TESTPATH = test_code
TESTFILES = *_test.c tests_main.c
TESTOBJ = $(TESTFILES:%.c=%.o)

# also can use quadratic_equation module on Mac
OS:=$(shell uname -s)
ifeq ($(OS), Linux)
	TESTFLAGS += -lsubunit -lrt
endif

.PHONY: all rebuild check quadratic_equation.a gcov_report clean

all: quadratic_equation.a

quadratic_equation.a: $(SRCOBJ)
	ar rcs $@ $(SRCOBJ)
	ranlib $@
	rm -rf $(SRCOBJ)

$(SRCOBJ):  $(addprefix $(SRCPATH)/,$(SRCFILES))
	$(CC) $(CFLAGS) -c $^

check: quadratic_equation.a $(TESTOBJ)
	$(CC) $(CFLAGS) -o $@ $(TESTOBJ) quadratic_equation.a $(TESTFLAGS)
	rm -rf $(TESTOBJ) quadratic_equation.a
	./$@

$(TESTOBJ):
	$(CC) $(CFLAGS) -c $(addprefix $(TESTPATH)/,$(TESTFILES))

gcov_report:
	$(CC) $(CFLAGS) --coverage $(addprefix $(SRCPATH)/,$(SRCFILES)) $(addprefix $(TESTPATH)/,$(TESTFILES)) $(TESTFLAGS) -o quadratic_equation.a
	./quadratic_equation.a
	lcov -t "quadratic_equation" -o quadratic_equation.info -c -d .
	genhtml -o report quadratic_equation.info
	open report/index.html

rebuild: clean all

clean:
	rm -rf quadratic_equation.a report check *.gcda *.gcno *.info *.o