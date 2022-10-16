CXXFLAGS = -std=c++11
LIBPATH = /opt

abc_datatypes.abc: abc_datatypes
	./abc_datatypes

abc_datatypes: abc_datatypes.C
	g++ -O3 -o $@ abc_datatypes.C \
	$(CXXFLAGS) \
	-I$(LIBPATH)/alembic/include \
	-I$(LIBPATH)/imath/include/Imath \
	-L$(LIBPATH)/alembic/lib \
	-lAlembic -lImath -lIex -lIlmThread -lHalf \
	-Wl,-rpath=$(LIBPATH)/alembic/lib

.phony: clean
clean:
	rm -fv ./abc_datatypes abc_datatyeps.abc

.phony: test
test:
	./abc_datatypes
	abcecho abc_datatypes.abc
