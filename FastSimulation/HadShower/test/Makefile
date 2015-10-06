CLHEP_PATH=/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/clhep/2.2.0.4/
IDIR = ../interface/
CCDIR = ../src/
LIBDIR = ./lib/
BINDIR = ./bin/

HFILES = $(wildcard $(IDIR)*.h)
CLASSES = $(foreach hfile,$(HFILES),$(subst .h,,$(subst $(IDIR),,$(hfile))))
OFILES = $(foreach class,$(CLASSES),$(LIBDIR)$(class).o)

CFLAGS = -I$(CLHEP_PATH)include -I$(CMSSW_BASE)/src `root-config --cflags`
CC = g++ -std=c++11
LIBS =  `ls $(LIBDIR)*.o` `root-config --libs` -L$(CLHEP_PATH)/lib/ -lCLHEP-2.2.0.4

PROGRAMS = $(wildcard *.C)
BINARIES = $(foreach program,$(PROGRAMS),$(BINDIR)$(subst .C,,$(program)))

BINARY=$(subst .C,,$(program))

.PRECIOUS: $(LIBDIR)%.o

$(LIBDIR)%.o : $(CCDIR)%.cc $(HFILES) | $(LIBDIR) 
	$(CC) -c -o $@ $< $(CFLAGS)

$(BINDIR)% : ./%.C $(OFILES) | $(BINDIR)
	$(CC) -o $@ $< $(CFLAGS) $(LIBS)

all: $(BINARIES)

$(LIBDIR):
	mkdir -p $(LIBDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	@for file in $(wildcard $(LIBDIR)/*); do echo "rm $$file"; rm $$file; done
	@for file in $(wildcard $(BINDIR)/*); do echo "rm $$file"; rm $$file; done
	@for file in $(wildcard ./*.root); do echo "rm $$file"; rm $$file; done
