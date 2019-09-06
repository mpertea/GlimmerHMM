BASEFLAGS  = -Wall -Wextra -D_REENTRANT -fno-exceptions -fno-rtti
CXX   := $(if $(CXX),$(CXX),g++)
LINKER  := $(if $(LINKER),$(LINKER),g++)

LDFLAGS := $(if $(LDFLAGS),$(LDFLAGS),-g)

CXXFLAGS := $(if $(CXXFLAGS),$(BASEFLAGS) $(CXXFLAGS),$(BASEFLAGS))

LIBS := -lm

ifneq (,$(filter %release, $(MAKECMDGOALS)))
  CXXFLAGS := -O2 -DNDEBUG $(CXXFLAGS)
else # debug build
  CXXFLAGS += -g -O0 -DDEBUG -D_DEBUG -DGDEBUG -std=c++0x
endif

%.o : %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

# C/C++ linker

LINKER    := g++

OBJS = glimmerhmm.o graph.o sites.o tree_util_prob.o util.o


.PHONY : all
all:    glimmerhmm
debug:  glimmerhmm
release: glimmerhmm

glimmerhmm: ${OBJS}
	${LINKER} ${LDFLAGS} -o $@ ${filter-out %.a %.so, $^} ${LIBS}

.PHONY : clean
clean:: 
	rm -f ${OBJS} glimmerhmm
