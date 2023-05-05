CC = gcc
FLAGS = -Wall -Wextra -std=c11 -g
SRC_TESTS = main.c $(wildcard tests/*.c)
SRC_FILES=$(wildcard s21_arithmetic/*.c) $(wildcard s21_comparison/*.c) $(wildcard s21_convertors/*.c) $(wildcard helpers/*.c) $(wildcard s21_another/*.c)

GCOVFLAGS = -L. --coverage
TEST_FLAGS = -lcheck

ifeq ($(shell uname), Linux)
	TEST_FLAGS += -lpthread -lrt -lsubunit -lm
endif


all: clean check-style s21_decimal.a test #gcov_report

s21_decimal.a:
	$(CC) $(FLAGS) $(SRC_FILES) -c
	ar r s21_decimal.a *.o
	rm *.o

test: s21_decimal.a
	$(CC) $(FLAGS) -g $(SRC_TESTS) s21_decimal.a $(TEST_FLAGS) -o test

check-style:
	clang-format -n -style=Google *.h tests/*.h $(SRC_TESTS) $(SRC_FILES)
	
set-style:
	clang-format -i -style=Google *.h tests/*.h $(SRC_TESTS) $(SRC_FILES)

gcov_report: s21_decimal.a test
	$(CC) $(FLAGS) -w $(SRC_TESTS) $(SRC_FILES) s21_decimal.a $(TEST_FLAGS) $(GCOVFLAGS) -o test
	./test
	lcov -t s21_test -o test.info -c -d .
	genhtml -o test_html test.info
	open ./test_html/index.html

clean:
	rm -rf *.o *.a *.gch *.gcno *.gcna *.gcda *.info *.out test test_html test.dSYM report_make tests/*.o


# CC = gcc
# FLAGS = -g3 -Wall -Wextra -std=c11 -g
# SRC_TESTS = s21_arithmetic/main.c #$(wildcard tests/*.c)
# TEST_LIBS = -lcheck

# ifeq ($(shell uname), Linux)
#     TEST_LIBS += -lpthread -lrt -lsubunit -lm
# endif


# all: clean s21_decimal.a test #gcov_report

# s21_decimal.a:
# 	$(CC) $(FLAGS) s21_arithmetic/*.c s21_comparison/*.c s21_convertors/*.c helpers/*.c s21_another/*c -c
# 	ar r s21_decimal.a *.o
# 	rm *.o

# test: clean s21_decimal.a
# 	$(CC) $(FLAGS) -g $(SRC_TESTS) s21_decimal.a $(TEST_LIBS) -o test
    

# add_coverage_flag:
# 	$(eval FLAGS += --coverage)

# gcov_report:  add_coverage_flag test
# 	./test
# 	rm -rf test*.gcda test*.gcno
# 	lcov -t “gcov_test” -o test.info --rc lcov_branch_coverage=1 --no-external -c -d .
# 	genhtml -o report_make/ test.info --rc lcov_branch_coverage=1
# 	open ./report_make/index.html

# clean:
# 	rm -rf *.o *.a *.gch *.gcno *.gcna *.gcda *.info *.out test test_html test.dSYM report_make tests/*.o
