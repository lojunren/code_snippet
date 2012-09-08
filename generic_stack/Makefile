CXX = gcc
CXXFLAGS += -g -Wall -Wextra

TARGETS = main
TARGETS_C_FILE = $(TARGETS).c

CLEANUP = rm -f excute

all: $(TARGETS)

clean:
	$(CLEANUP)

CORE_INCS = -I. \
	-I ./stack/ \

STACK = ./stack/stack.o

$(TARGETS): $(TARGETS_C_FILE)
	$(CXX) $(CXXFLAGS) $(CORE_INCS) $(STACK) $^ -o excute
