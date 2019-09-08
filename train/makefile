# Copyright (c) 2003 by Mihaela Pertea.


BASEFLAGS  = -Wall -Wextra -D_REENTRANT -fno-exceptions -fno-rtti
CXX   := $(if $(CXX),$(CXX),g++)
LINKER  := $(if $(LINKER),$(LINKER),g++)

LDFLAGS := $(if $(LDFLAGS),$(LDFLAGS),-g)

CXXFLAGS := $(if $(CXXFLAGS),$(BASEFLAGS) $(CXXFLAGS),$(BASEFLAGS))

LIBS := -lm

ifneq (,$(filter %release, $(MAKECMDGOALS)))
  CXXFLAGS := -O3 -g -DNDEBUG $(CXXFLAGS)
else # debug build
  CXXFLAGS += -g -O0 -D_DEBUG -DGDEBUG
endif

%.o : %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

# C/C++ linker

LINKER    := g++

TARGETS = build-icm build-icm-noframe build1 build2 falsecomp findsites karlin score score2 scoreATG scoreATG2 scoreSTOP scoreSTOP2 erfapp splicescore

.PHONY : all
all:  ${TARGETS}

build-icm: build-icm.o misc.o
	${LINKER} ${LDFLAGS} -o $@ ${filter-out %.a %.so, $^} ${LIBS}

build-icm-noframe: build-icm-noframe.o misc.o
	${LINKER} ${LDFLAGS} -o $@ ${filter-out %.a %.so, $^} ${LIBS}

build1: build1.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LIBS}

build2: build2.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LIBS}

falsecomp: falsecomp.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LIBS}

findsites: findsites.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LIBS}

karlin: karlin.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LIBS}

score: score.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LIBS}

score2: score2.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LIBS}

scoreATG: scoreATG.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LIBS}

scoreATG2: scoreATG2.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LIBS}

scoreSTOP: scoreSTOP.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LIBS}

scoreSTOP2: scoreSTOP2.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LIBS}

erfapp: erfapp.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LIBS}

splicescore: splicescore.o sites.o utils.o
	${LINKER} ${LDFLAGS} -o $@ ${filter-out %.a %.so, $^} ${LIBS}

.PHONY : clean
clean::
	/bin/rm -f core* *.o ${TARGETS}
