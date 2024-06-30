.PHONY: all install uninstall clean dvi dist test check_mk gcov_report install_lcov brew lcov style_check style clang valgrind

CC = g++ -std=c++17 -g
FLAGS = -Wall -Wextra -Werror

FLAGS_TEST = -coverage -lgtest -lgtest_main -pthread

PROJECT = $(shell pwd)
SOURCE_BUILD = SimpleCalculMy
SOURCES = SimpleCalculMy/Model/model.cc
TEST_FILE = test/tests.cc
TEST_OUT = tests
INSTALL_FOLDER = Calcul_desktop

all: install dvi

install: uninstall
	mkdir ../../$(INSTALL_FOLDER)
	cd ../../$(INSTALL_FOLDER) && cmake $(PROJECT)/$(SOURCE_BUILD)/. -B . && cmake --build .

uninstall: 
	rm -rf ../../$(INSTALL_FOLDER)

dvi:
	open -a "Google Chrome" manual.html

dist: cleandist install
	cd ../../ && tar -cvf s21_SmartCalc.tar.gz $(INSTALL_FOLDER)

cleandist:
	rm -rf ../../s21_SmartCalc.tar.gz

clean:
	rm -rf ./$(TEST_OUT) *.gcno *.gcda *.a *.o

test: clean 
	g++ $(SOURCES) $(TEST_FILE) $(FLAGS_TEST) -o $(TEST_OUT)
	./$(TEST_OUT)

style_check: clang
	# clang-format -n $(SOURCE_BUILD)/*.h $(SOURCE_BUILD)/*.cc
	find . -type f -name ".h" -o -name "*.cc" | xargs clang-format -style=Google -n

style: clang
	# clang-format -i $(SOURCE_BUILD)/*.h $(SOURCE_BUILD)/*.cc
	find . -type f -name ".h" -o -name "*.cc" | xargs clang-format -style=Google -i
	
clang:
ifeq ("","$(wildcard ./.clang-format)")
	cp -f ../materials/linters/.clang-format ./.clang-format
endif

valgrind:
	g++ $(SOURCES) $(TEST_FILE) $(FLAGS_TEST) -o $(TEST_OUT)
	CK_FORK=no valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_OUT)
