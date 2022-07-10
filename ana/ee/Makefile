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

Tasks:     clean ee_HT_half

SOURCE_FILES := $(shell ls -1 ee_HT_half.C)

# build object files 
objects       = $(patsubst %.C,%.o,$(SOURCE_FILES))

%.o: %.cc
	$(CXX) $(OPT) -Wno-unused-variable  -Wunused-but-set-variable $(CXXFLAGS) $(INCLUDE1) $(INCLUDE2) $(INCLUDE3) -o $@ -c $<

LIBOBJS = $(patsubst %.C,%.o,$(SOURCE_FILES))

ee_HT_half: $(objects)
	        $(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@

clean:
	        @rm -f *.o ee_HT_half *~ src/*.o;  echo "Clear.."


Tasks:     clean ee_Top_half

SOURCE_FILES := $(shell ls -1 ee_Top_half.C)

# build object files 
objects       = $(patsubst %.C,%.o,$(SOURCE_FILES))

%.o: %.cc
	$(CXX) $(OPT) -Wno-unused-variable  -Wunused-but-set-variable $(CXXFLAGS) $(INCLUDE1) $(INCLUDE2) $(INCLUDE3) -o $@ -c $<

LIBOBJS = $(patsubst %.C,%.o,$(SOURCE_FILES))

ee_Top_half: $(objects)
	        $(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@

clean:
	        @rm -f *.o ee_Top_half *~ src/*.o;  echo "Clear.."

Tasks:     clean ee_Diboson_half

SOURCE_FILES := $(shell ls -1 ee_Diboson_half.C)

# build object files 
objects       = $(patsubst %.C,%.o,$(SOURCE_FILES))

%.o: %.cc
	$(CXX) $(OPT) -Wno-unused-variable  -Wunused-but-set-variable $(CXXFLAGS) $(INCLUDE1) $(INCLUDE2) $(INCLUDE3) -o $@ -c $<

LIBOBJS = $(patsubst %.C,%.o,$(SOURCE_FILES))

ee_Diboson_half: $(objects)
	        $(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@

clean:
	        @rm -f *.o ee_Diboson_half *~ src/*.o;  echo "Clear.."

