# Check for OS Type
UNAME_S := $(shell uname -s)

# Linux
ifeq ($(UNAME_S), Linux)
	CC=g++
# Mac
else
	CC=clang++
	LIBS=-stdlib=libc++
endif

# Paths, use this to set Include directories, or library directories; uncomment in all: if used
#PATHI=-I/usr/local/include/ 
#PATHL=-L/usr/local/lib/

#Compiler Flags
CXXFLAGS=-g -Wall -std=c++0x

# .o Compilation
O_FILES=EdgeSampler.o Node.o NetworkTop.o Tuple.o

# Point to includes of local directories
INDLUDES=-I../include


all: $(O_FILES)
	$(CC) $(CXXFLAGS) -o Tutorial $(O_FILES) $(LIBS) #$(PATHI) $(PATHL)

NodeSampler.o: EdgeSampler.cpp
	$(CC) $(CXXFLAGS) -c NodeSampler.cpp -o NodeSampler.o $(INDLUDES)

Node.o: Node.cpp
	$(CC) $(CXXFLAGS) -c Node.cpp -o Node.o $(INDLUDES)

NetworkTop.o: NetworkTop.cpp
	$(CC) $(CXXFLAGS) -c NetworkTop.cpp -o NetworkTop.o $(INDLUDES)

Tuple.o: Tuple.cpp
	$(CC) $(CXXFLAGS) -c Tuple.cpp -o Tuple.o $(INDLUDES)


clean:
	-@if rm *.o Tutorial 2>/dev/null || true; then echo "Clean"; else echo "No Main"; fi
