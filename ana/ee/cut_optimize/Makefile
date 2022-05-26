# Makefile example for ROOT
ifndef ROOTSYS 
$(error ROOTSYS env variable is not set. Install ROOT first)
endif

include ${ROOTSYS}/etc/Makefile.arch

# Root variables
ROOTCFLAGS    = $(shell root-config --nonew --cflags)
ROOTLIBS      = $(shell root-config --nonew --libs)
ROOTGTTLIBS   = $(shell root-config --nonew --glibs)
# Assign or add variables
CXXFLAGS     += $(ROOTCFLAGS)
LIBS         += $(ROOTLIBS)
LIBS         += $(ROOTGTTLIBS)

Tasks:     clean ee_HT_inclusive

SOURCE_FILES := $(shell ls -1 ee_HT_inclusive.C)

# build object files 
objects       = $(patsubst %.C,%.o,$(SOURCE_FILES))

%.o: %.cc
	$(CXX) $(OPT) -Wno-unused-variable  -Wunused-but-set-variable $(CXXFLAGS) $(INCLUDE1) $(INCLUDE2) $(INCLUDE3) -o $@ -c $<

LIBOBJS = $(patsubst %.C,%.o,$(SOURCE_FILES))

ee_HT_half: $(objects)
	        $(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@

clean:
	        @rm -f *.o ee_HT_inclusive *~ src/*.o;  echo "Clear.."
