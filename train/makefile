# Copyright (c) 2003 by Mihaela Pertea.

# C compiler

C       = gcc 
CC      = g++ 
#CFLAGS  = -O1 ${SEARCHDIRS}
#CFLAGS  = -O3 -g -Wall
CFLAGS = -Wall -g
LIBS    = -lm

MAKEFILE= makefile

.PHONY : all
all:    build-icm build-icm-noframe build1 build2 falsecomp findsites karlin score score2 scoreATG scoreATG2 scoreSTOP scoreSTOP2 erfapp splicescore


misc.o: misc.c
	${C} ${CFLAGS} -c misc.c

build-icm.o: build-icm.c
	${C} ${CFLAGS} -c build-icm.c

build-icm: build-icm.o misc.o
	$(C) ${CFLAGS} -o $@ build-icm.o misc.o $(LIBS)

build-icm-noframe.o: build-icm-noframe.c
	${C} ${CFLAGS} -c build-icm-noframe.c

build-icm-noframe: build-icm-noframe.o misc.o
	$(C) ${CFLAGS} -o $@ build-icm-noframe.o misc.o $(LIBS)

build1: build1.o
	${CC} ${CFLAGS} build1.c -o build1 $(LIBS)

build2: build2.o
	${CC} ${CFLAGS} build2.c -o build2 $(LIBS)

falsecomp: falsecomp.o
	${CC} ${CFLAGS} falsecomp.c -o falsecomp $(LIBS)

findsites: findsites.o
	${CC} ${CFLAGS} findsites.c -o findsites $(LIBS)

karlin: karlin.o
	${CC} ${CFLAGS} karlin.c -o karlin $(LIBS)

score: score.o
	${CC} ${CFLAGS} score.c -o score $(LIBS)

score2: score2.o
	${CC} ${CFLAGS} score2.c -o score2 $(LIBS)

scoreATG: scoreATG.o
	${CC} ${CFLAGS} scoreATG.c -o scoreATG $(LIBS)

scoreATG2: scoreATG2.o
	${CC} ${CFLAGS} scoreATG2.c -o scoreATG2 $(LIBS)

scoreSTOP: scoreSTOP.o
	${CC} ${CFLAGS} scoreSTOP.c -o scoreSTOP $(LIBS)

escoreSTOP2: scoreSTOP2.o
	${CC} ${CFLAGS} scoreSTOP2.c -o scoreSTOP2 $(LIBS)

rfapp: erfapp.o
	${CC} ${CFLAGS} erfapp.c -o erfapp $(LIBS)

sites.o: sites.c
	${CC} ${CFLAGS} -c sites.c

utils.o: utils.c 
	${CC} ${CFLAGS} -c utils.c

splicescore.o: splicescore.c
	${CC} ${CFLAGS} -c splicescore.c

splicescore: splicescore.o sites.o utils.o
	${CC} splicescore.o sites.o utils.o -o splicescore $(LIBS)
.PHONY : clean
clean::
	/bin/rm -f core* splicescore *.o score build? build-icm \
build-icm-noframe erfapp falsecomp findsites karlin score2 scoreATG \
scoreATG2 scoreSTOP scoreSTOP2 trainGlimmerHMM