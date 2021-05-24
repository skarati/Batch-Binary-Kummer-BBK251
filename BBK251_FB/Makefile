CPP=g++ -O3 -fomit-frame-pointer

all: accuracy_core2.out speed_core2.out accuracy_gates.out speed_gates.out

accuracy_gates.out: accuracy_gates
	time ./accuracy_gates > accuracy_gates.out

accuracy_core2.out: accuracy_core2
	time ./accuracy_core2 > accuracy_core2.out

accuracy_gates: accuracy.o gates.o bbk251.o
	$(CPP) -o accuracy_gates accuracy.o gates.o bbk251.o

accuracy_core2: accuracy.o core2.o bbk251.o swap.s
	$(CPP) -o accuracy_core2 accuracy.o core2.o bbk251.o swap.s

speed_gates.out: speed_gates
	time ./speed_gates > speed_gates.out

speed_core2.out: speed_core2
	time ./speed_core2 > speed_core2.out

speed_gates: speed.cpp gates.o bbk251.o \
Makefile vec.h fieldelement.h bbk251.h
	$(CPP) -o speed_gates speed.cpp gates.o bbk251.o

speed_core2: speed.cpp core2.o bbk251.o \
Makefile vec.h fieldelement.h bbk251.h \
swap.s
	$(CPP) -DTIMEINDIVIDUALMULTS -o speed_core2 speed.cpp core2.o bbk251.o \
	swap.s

accuracy.o: accuracy.cpp Makefile bbk251.h
	$(CPP) -c accuracy.cpp

bbk251.o: bbk251.cpp Makefile vec.h fieldelement.h bbk251.h
	$(CPP) -c bbk251.cpp

gates.o: gates.cpp Makefile vec.h fieldelement.h
	$(CPP) -DVEC_COUNTBITOPS -c gates.cpp

core2.o: core2.s Makefile vec.h fieldelement.h
	$(CPP) -c core2.s

core2.s: core2.cpp Makefile vec.h fieldelement.h
	$(CPP) -Winline -S core2.cpp
	sed 's/pxor/xorps/' < core2.s > core22.s
	sed 's/pand/andps/' < core22.s | sed 's/movdqa/movaps/' > core2.s
