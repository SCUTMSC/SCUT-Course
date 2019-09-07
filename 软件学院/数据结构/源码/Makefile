# Makefile for compiling the sample code from the textbook
# "A Practical Introduction to Data Structures and Algorithm Analysis,
# Third Edition (C++)" by Clifford A. Shaffer.
# Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

# Standard UNIX
CFLAGS= -s -Wall -O -DUNIX
# Debugging
#CFLAGS= -g -Wall -DUNIX
CC= g++

# Imlicit pattern rule for making .o files from .cpp files
%.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

#### Do the chapters #######################################################

all: c2 c3 c4 c5 c6 c7 c8 c9 c10 c11 c12 c14 c15 c16 c17

c2: fact toh fib terminate

c3: largest ch3 bsearch flags binsimp collatz

c4: swaptest alist llist llistFL freetest1 freetest2 dlist astack lstack aqueue lqueue Payroll UALdict SALdict ch4

c5: preorder varnodei varnodec BST heap huffman travtest

c6: gentree ufmain ufsmain

c7: comptest slowsort shellsort qsort sort ch7

slowsort: inssort bubsort selsort

shellsort: shsort shsort2

qsort: qsort1 qsort2 qsort3 qsort4

sort: mrgsort1 mrgsort2 mrgsort3 heapsort heapsort2 heapsort3 radix

c8: genfile printout exmrg1 exmrg2 exmrg3 excheck

c9: hashsim testhash hashdict

c10: ttmain BPmain

c11: c11m c11l

c11m: grtestm grdfsm grtsdm grbfsm grtsbm grdijkm1 grdijkm2 grprimm1 grprimm2 grkruskm

c11l: grtestl grdfsl grtsdl grbfsl grtsbl grdijkl1 grdijkl2 grpriml1 grpriml2 grkruskl

c12: MemMan

c13: KDmain

c14: grconcomm grconcoml ch14

c15: minmax

c16: grfloydm grfloydl skipmain

c17: phalt

### Cleanup Section ########################################################

clean: cleanjunk clean2 clean3 clean4 clean5 clean6 clean7 clean8 clean9 clean10 clean11 clean12 clean13 clean14 clean15 clean17

cleanjunk:
	rm -f *~ *.core core

clean2:
	rm -f fact.o fact toh.o toh fib.o fib terminate.o terminate

clean3:
	rm -f largest.o largest ch3.o ch3 bsearch.o bsearch flags.o\
                flags binsimp.o binsimp collatz.o collatz

clean4:
	rm -f swaptest swaptest.o alist Alistmain.o llist Llistmain.o\
		 llistFL LlistFLmain.o \
		 dlist Dlistmain.o freetest1 freetest1.o freetest2\
		 freetest2.o astack Astackmain.o lstack Lstackmain.o\
		 aqueue Aqueuemain.o lqueue Lqueuemain.o ch4 ch4.o\
		 Payroll Payroll.o SALdict SALdictmain.o UALdict UALdictmain.o\
		 SAlistmain.o SAlist

clean5:
	rm -f preorder.o preorder varnodei varnodei.o varnodec varnodec.o\
		 BST BSTmain.o heap heapmain.o huffman huffman.o\
		 travtest travtest.o

clean6:
	rm -f gentree genmain.o ufmain ufmain.o ufsmain ufsmain.o

clean7:
	rm -f bubsort bubsort.o heapsort heapsort.o heapsort2 heapsort2.o\
		 heapsort3 heapsort3.o inssort inssort.o mrgsort1 mrgsort1.o\
		 mrgsort2 mrgsort2.o mrgsort3 mrgsort3.o qsort1 qsort1.o\
		 qsort2 qsort2.o qsort3 qsort3.o qsort4 qsort4.o radix\
		 radix.o selsort selsort.o shsort shsort.o shsort2 shsort2.o\
		 comptest comptest.o ch7.o ch7

clean8:
	rm -f genfile genfile.o printout printout.o exmrg1 exmrg1.o exmrg2\
		 exmrg2.o exmrg3 exmrg3.o excheck excheck.o

clean9:
	rm -f hashsim hashsim.o testhash testhash.o hashdict hashdict.o

clean10:
	rm -f ttmain ttmain.o BPmain BPmain.o

clean11:
	rm -f grtestm grtestm.o grdfsm grdfsm.o grtsdm grtsdm.o grbfsm\
		 grbfsm.o grtsbm grtsbm.o grdijkm1 grdijkm1.o grdijkm2\
		 grdijkm2.o grprimm1 grprimm1.o grprimm2\
		 grprimm2.o grkruskm grkruskm.o grtestl grtestl.o grdfsl\
		 grdfsl.o grtsdl grtsdl.o grbfsl grbfsl.o grtsbl grtsbl.o\
		 grdijkl1 grdijkl1.o grdijkl2 grdijkl2.o\
		 grpriml1 grpriml1.o grpriml2 grpriml2.o grkruskl grkruskl.o

clean12:
	rm -f MemMan MemMan.o

clean13:
	rm -f KDmain KDmain.o

clean14:
	rm -f grconcomm grconcomm.o grconcoml grconcoml.o ch14 ch14.o

clean15:
	rm -f minmax minmaxmain.o


clean 16:
	rm -f grfloydm grfloydm.o grfloydl grfloydl.o skipmain skipmain.o

clean17:
	rm -f phalt phalt.o

### Chapter 2 #########################################################

fact: fact.o
	$(CC) $(CFLAGS) fact.o -o fact

fact.o: fact.cpp book.h stack.h astack.h

toh: toh.o
	$(CC) $(CFLAGS) toh.o -o toh

toh.o: toh.cpp book.h stack.h astack.h

fib: fib.o
	$(CC) $(CFLAGS) fib.o -o fib

fib.o: fib.cpp book.h

terminate: terminate.o
	$(CC) $(CFLAGS) terminate.o -o terminate

terminate.o: terminate.cpp

### Chapter 3 #########################################################

largest: largest.o
	$(CC) $(CFLAGS) largest.o -o largest

largest.o: largest.cpp permute.h book.h compare.h

ch3: ch3.o
	$(CC) $(CFLAGS) ch3.o -o ch3

ch3.o: ch3.cpp book.h

bsearch: bsearch.o
	$(CC) $(CFLAGS) bsearch.o -o bsearch

bsearch.o: bsearch.cpp book.h  compare.h

flags: flags.o
	$(CC) $(CFLAGS) flags.o -o flags

flags.o: flags.cpp book.h

binsimp: binsimp.o
	$(CC) $(CFLAGS) binsimp.o -o binsimp

binsimp.o: binsimp.cpp permute.h list.h book.h

collatz: collatz.o
	$(CC) $(CFLAGS) collatz.o -o collatz

collatz.o: collatz.cpp book.h

### Chapter 4 #########################################################

swaptest: swaptest.o
	$(CC) $(CFLAGS) swaptest.o -o swaptest

swaptest.o: swaptest.cpp book.h

alist: Alistmain.o
	$(CC) $(CFLAGS) Alistmain.o -o alist

Alistmain.o: Alistmain.cpp book.h alist.h ListTest.h compare.h

llist: Llistmain.o
	$(CC) $(CFLAGS) Llistmain.o -o llist

Llistmain.o: Llistmain.cpp book.h link.h list.h llist.h ListTest.h compare.h

llistFL: LlistFLmain.o
	$(CC) $(CFLAGS) LlistFLmain.o -o llistFL

LlistFLmain.o: LlistFLmain.cpp book.h linkFL.h list.h llist.h ListTest.h compare.h

freetest1: freetest1.o
	$(CC) $(CFLAGS) freetest1.o -o freetest1

freetest1.o: freetest1.cpp book.h freetest.h link.h

freetest2: freetest2.o
	$(CC) $(CFLAGS) freetest2.o -o freetest2

freetest2.o: freetest2.cpp book.h freetest.h linkFL.h

dlist: Dlistmain.o
	$(CC) $(CFLAGS) Dlistmain.o -o dlist

Dlistmain.o: Dlistmain.cpp book.h dlinkFL.h list.h dlist.h llist.h ListTest.h compare.h

astack: Astackmain.o
	$(CC) $(CFLAGS) Astackmain.o -o astack

Astackmain.o: Astackmain.cpp book.h stack.h astack.h StackTest.h

lstack: Lstackmain.o
	$(CC) $(CFLAGS) Lstackmain.o -o lstack

Lstackmain.o: Lstackmain.cpp book.h stack.h lstack.h link.h StackTest.h

aqueue: Aqueuemain.o
	$(CC) $(CFLAGS) Aqueuemain.o -o aqueue

Aqueuemain.o: Aqueuemain.cpp book.h queue.h aqueue.h QueueTest.h

lqueue: Lqueuemain.o
	$(CC) $(CFLAGS) Lqueuemain.o -o lqueue

Lqueuemain.o: Lqueuemain.cpp book.h queue.h lqueue.h link.h QueueTest.h

UALdict: UALdictmain.o
	$(CC) $(CFLAGS) UALdictmain.o -o UALdict

UALdictmain.o: UALdictmain.cpp book.h list.h alist.h dictionary.h KVpair.h UALdict.h DictTest.h

Payroll: Payroll.o
	$(CC) $(CFLAGS) Payroll.o -o Payroll

Payroll.o: Payroll.cpp book.h dictionary.h alist.h list.h UALdict.h

SAlist: SAlistmain.o
	$(CC) $(CFLAGS) SAlistmain.o -o SAlist

SAlistmain.o: SAlistmain.cpp book.h list.h alist.h salist.h


SALdict: SALdictmain.o
	$(CC) $(CFLAGS) SALdictmain.o -o SALdict

SALdictmain.o: SALdictmain.cpp book.h list.h alist.h dictionary.h KVpair.h SALdict.h DictTest.h salist.h

ch4: ch4.o
	$(CC) $(CFLAGS) ch4.o -o ch4

ch4.o: book.h alist.h list.h


### Chapter 5 #########################################################

preorder: preorder.o
	$(CC) $(CFLAGS) preorder.o -o preorder

preorder.o: preorder.cpp bnadt.h BinNode.h book.h

varnodei: varnodei.o
	$(CC) $(CFLAGS) varnodei.o -o varnodei

varnodei.o: varnodei.cpp book.h

varnodec: varnodec.o
	$(CC) $(CFLAGS) varnodec.o -o varnodec

varnodec.o: varnodec.cpp book.h

BST: BSTmain.o
	$(CC) $(CFLAGS) BSTmain.o -o BST

BSTmain.o: BSTmain.cpp book.h dictionary.h BST.h bnadt.h BinNode.h

heap: heapmain.o
	$(CC) $(CFLAGS) heapmain.o -o heap

heapmain.o: heapmain.cpp book.h permute.h heap.h compare.h

huffman: huffman.o
	$(CC) $(CFLAGS) huffman.o -o huffman

huffman.o: huffman.cpp book.h huffnode.h hufftree.h heap.h

travtest: travtest.o
	$(CC) $(CFLAGS) travtest.o -o travtest

travtest.o: travtest.cpp book.h bnadt.h

### Chapter 6 #########################################################

gentree: genmain.o
	$(CC) $(CFLAGS) genmain.o -o gentree

genmain.o: genmain.cpp book.h

ufmain: ufmain.o
	$(CC) $(CFLAGS) ufmain.o -o ufmain

ufmain.o: ufmain.cpp book.h uf.h

ufsmain: ufsmain.o
	$(CC) $(CFLAGS) ufsmain.o -o ufsmain

ufsmain.o: ufsmain.cpp book.h uf.h

### Chapter 7 #########################################################

comptest: comptest.o
	$(CC) $(CFLAGS) comptest.o -o comptest

comptest.o: comptest.cpp book.h

inssort: inssort.o
	$(CC) $(CFLAGS) inssort.o -o inssort

inssort.o: inssort.cpp book.h compare.h sortmain.cpp

bubsort: bubsort.o
	$(CC) $(CFLAGS) bubsort.o -o bubsort

bubsort.o: bubsort.cpp book.h compare.h sortmain.cpp

selsort: selsort.o
	$(CC) $(CFLAGS) selsort.o -o selsort

selsort.o: selsort.cpp book.h compare.h sortmain.cpp

shsort: shsort.o
	$(CC) $(CFLAGS) shsort.o -o shsort

shsort.o: shsort.cpp book.h compare.h sortmain.cpp

shsort2: shsort2.o
	$(CC) $(CFLAGS) shsort2.o -o shsort2

shsort2.o: shsort2.cpp book.h compare.h sortmain.cpp

qsort1: qsort1.o
	$(CC) $(CFLAGS) qsort1.o -o qsort1

qsort1.o: qsort1.cpp book.h compare.h sortmain.cpp

qsort2: qsort2.o
	$(CC) $(CFLAGS) qsort2.o -o qsort2

qsort2.o: qsort2.cpp book.h compare.h sortmain.cpp

qsort3: qsort3.o
	$(CC) $(CFLAGS) qsort3.o -o qsort3

qsort3.o: qsort3.cpp book.h compare.h sortmain.cpp

qsort4: qsort4.o
	$(CC) $(CFLAGS) qsort4.o -o qsort4

qsort4.o: qsort4.cpp book.h compare.h sortmain.cpp

mrgsort1: mrgsort1.o
	$(CC) $(CFLAGS) mrgsort1.o -o mrgsort1

mrgsort1.o: mrgsort1.cpp book.h compare.h sortmain.cpp

mrgsort2: mrgsort2.o
	$(CC) $(CFLAGS) mrgsort2.o -o mrgsort2

mrgsort2.o: mrgsort2.cpp book.h compare.h sortmain.cpp

mrgsort3: mrgsort3.o
	$(CC) $(CFLAGS) mrgsort3.o -o mrgsort3

mrgsort3.o: mrgsort3.cpp book.h compare.h sortmain.cpp

heapsort: heapsort.o
	$(CC) $(CFLAGS) heapsort.o -o heapsort

heapsort.o: heapsort.cpp heap.h book.h compare.h sortmain.cpp

heapsort2: heapsort2.o
	$(CC) $(CFLAGS) heapsort2.o -o heapsort2

heapsort2.o: heapsort2.cpp heap2.h book.h compare.h sortmain.cpp

heapsort3: heapsort3.o
	$(CC) $(CFLAGS) heapsort3.o -o heapsort3

heapsort3.o: heapsort3.cpp book.h sortmain.cpp compare.h

radix: radix.o
	$(CC) $(CFLAGS) radix.o -o radix

radix.o: radix.cpp book.h compare.h sortmain.cpp

ch7: ch7.o
	$(CC) $(CFLAGS) ch7.o -o ch7

ch7: ch7.cpp

### Chapter 8 #########################################################

genfile: genfile.o
	$(CC) $(CFLAGS) genfile.o -o genfile

genfile.o: genfile.cpp

printout: printout.o
	$(CC) $(CFLAGS) printout.o -o printout

printout.o: printout.cpp

exmrg1: exmrg1.o
	$(CC) $(CFLAGS) exmrg1.o -o exmrg1

exmrg1.o: exmrg1.cpp book.h

exmrg2: exmrg2.o
	$(CC) $(CFLAGS) exmrg2.o -o exmrg2

exmrg2.o: exmrg2.cpp book.h compare.h

exmrg3: exmrg3.o
	$(CC) $(CFLAGS) exmrg3.o -o exmrg3

exmrg3.o: exmrg3.cpp book.h compare.h

excheck: excheck.o
	$(CC) $(CFLAGS) excheck.o -o excheck

excheck.o: excheck.cpp


### Chapter 9 ########################################################

hashsim: hashsim.o
	$(CC) $(CFLAGS) hashsim.o -o hashsim

hashsim.o: hashsim.cpp

testhash: testhash.o
	$(CC) $(CFLAGS) testhash.o -o testhash

testhash.o: testhash.cpp book.h compare.h

hashdict: hashdict.o
	$(CC) $(CFLAGS) hashdict.o -o hashdict

hashdict.o: hashdict.cpp dictionary.h hashdict.h KVpair.h book.h

### Chapter 10 #######################################################

ttmain: ttmain.o
	$(CC) $(CFLAGS) ttmain.o -o ttmain

ttmain.o: ttmain.cpp book.h ttnode.h tt.h tttree.h dictionary.h

BPmain: BPmain.o
	$(CC) $(CFLAGS) BPmain.o -o BPmain

BPmain.o: BPmain.cpp book.h BPnode.h

### Chapter 11 #######################################################

grtestm: grtestm.o
	$(CC) $(CFLAGS) grtestm.o -o grtestm

grtestm.o: grtestm.cpp graph.h grmat.h graphutil.cpp book.h

grdfsm: grdfsm.o
	$(CC) $(CFLAGS) grdfsm.o -o grdfsm

grdfsm.o: grdfsm.cpp graph.h grmat.h graphutil.cpp book.h

grtsdm: grtsdm.o
	$(CC) $(CFLAGS) grtsdm.o -o grtsdm

grtsdm.o: grtsdm.cpp graph.h grmat.h graphutil.cpp book.h

grbfsm: grbfsm.o
	$(CC) $(CFLAGS) grbfsm.o -o grbfsm

grbfsm.o: grbfsm.cpp queue.h aqueue.h graph.h grmat.h graphutil.cpp book.h

grtsbm: grtsbm.o
	$(CC) $(CFLAGS) grtsbm.o -o grtsbm

grtsbm.o: grtsbm.cpp queue.h aqueue.h graph.h grmat.h graphutil.cpp book.h

grdijkm1: grdijkm1.o
	$(CC) $(CFLAGS) grdijkm1.o -o grdijkm1

grdijkm1.o: grdijkm1.cpp graph.h grmat.h graphutil.cpp book.h

grdijkm2: grdijkm2.o
	$(CC) $(CFLAGS) grdijkm2.o -o grdijkm2

grdijkm2.o: grdijkm2.cpp heap.h graph.h grmat.h graphutil.cpp book.h

grprimm1: grprimm1.o
	$(CC) $(CFLAGS) grprimm1.o -o grprimm1

grprimm1.o: grprimm1.cpp graph.h grmat.h graphutil.cpp book.h

grprimm2: grprimm2.o
	$(CC) $(CFLAGS) grprimm2.o -o grprimm2

grprimm2.o: grprimm2.cpp heap.h graph.h grmat.h graphutil.cpp book.h

grkruskm: grkruskm.o
	$(CC) $(CFLAGS) grkruskm.o -o grkruskm

grkruskm.o: grkruskm.cpp uf.h heap.h graph.h grmat.h graphutil.cpp book.h


grtestl: grtestl.o
	$(CC) $(CFLAGS) grtestl.o -o grtestl

grtestl.o: grtestl.cpp graph.h grlist.h link.h list.h llist.h graphutil.cpp book.h

grdfsl: grdfsl.o
	$(CC) $(CFLAGS) grdfsl.o -o grdfsl

grdfsl.o: grdfsl.cpp graph.h grlist.h link.h list.h llist.h graphutil.cpp book.h

grtsdl: grtsdl.o
	$(CC) $(CFLAGS) grtsdl.o -o grtsdl

grtsdl.o: grtsdl.cpp graph.h grlist.h link.h list.h llist.h graphutil.cpp book.h

grbfsl: grbfsl.o
	$(CC) $(CFLAGS) grbfsl.o -o grbfsl

grbfsl.o: grbfsl.cpp queue.h aqueue.h grlist.h link.h list.h llist.h graph.h graphutil.cpp book.h

grtsbl: grtsbl.o
	$(CC) $(CFLAGS) grtsbl.o -o grtsbl

grtsbl.o: grtsbl.cpp queue.h aqueue.h grlist.h link.h list.h llist.h graph.h graphutil.cpp book.h

grdijkl1: grdijkl1.o
	$(CC) $(CFLAGS) grdijkl1.o -o grdijkl1

grdijkl1.o: grdijkl1.cpp grlist.h link.h list.h llist.h graph.h graphutil.cpp book.h

grdijkl2: grdijkl2.o
	$(CC) $(CFLAGS) grdijkl2.o -o grdijkl2

grdijkl2.o: grdijkl2.cpp heap.h grlist.h link.h list.h llist.h graph.h graphutil.cpp book.h

grpriml1: grpriml1.o
	$(CC) $(CFLAGS) grpriml1.o -o grpriml1

grpriml1.o: grpriml1.cpp grlist.h graph.h link.h list.h llist.h graphutil.cpp book.h

grpriml2: grpriml2.o
	$(CC) $(CFLAGS) grpriml2.o -o grpriml2

grpriml2.o: grpriml2.cpp heap.h grlist.h link.h list.h llist.h graph.h graphutil.cpp book.h

grkruskl: grkruskl.o
	$(CC) $(CFLAGS) grkruskl.o -o grkruskl

grkruskl.o: grkruskl.cpp uf.h heap.h grlist.h link.h list.h llist.h graph.h graphutil.cpp book.h

### Chapter 12 #######################################################

MemMan: MemMan.o
	$(CC) $(CFLAGS) MemMan.o -o MemMan

MemMan.o: MemMan.cpp MemMan.h

### Chapter 13 #######################################################

KDmain: KDmain.o
	$(CC) $(CFLAGS) KDmain.o -o KDmain

KDmain.o: KDmain.cpp kdtree.h binnode.h book.h

### Chapter 14 #######################################################

grconcomm: grconcomm.o
	$(CC) $(CFLAGS) grconcomm.o -o grconcomm

grconcomm.o: grconcomm.cpp grmat.h graph.h graphutil.cpp graphutil.cpp book.h

grconcoml: grconcoml.o
	$(CC) $(CFLAGS) grconcoml.o -o grconcoml

grconcomm.o: grconcomm.cpp graph.h grlist.h link.h list.h llist.h graphutil.cpp graphutil.cpp book.h

ch14: ch14.o
	$(CC) $(CFLAGS) ch14.o -o ch14


ch14.o: ch14.cpp

### Chapter 15 #######################################################

minmax: minmaxmain.o
	$(CC) $(CFLAGS) minmaxmain.o -o minmax

minmaxmain.o: minmaxmain.cpp permute.h

### Chapter 16 #######################################################

grfloydm: grfloydm.o
	$(CC) $(CFLAGS) grfloydm.o -o grfloydm

grfloydm.o: grfloydm.cpp graph.h grmat.h graphutil.cpp book.h

grfloydl: grfloydl.o
	$(CC) $(CFLAGS) grfloydl.o -o grfloydl

grfloydl.o: grfloydl.cpp graph.h grlist.h link.h list.h llist.h graphutil.cpp book.h

skipmain: skipmain.o
	$(CC) $(CFLAGS) skipmain.o -o skipmain

skipmain.o: skipmain.cpp dictionary.h skiplist.h book.h


### Chapter 17 #######################################################

phalt: phalt.o
	$(CC) $(CFLAGS) phalt.o -o phalt

phalt.o: phalt.cpp
