CXXFLAGS = -std=c++11

abc_datatypes.abc: abc_datatypes
	./abc_datatypes

abc_datatypes: abc_datatypes.C
	g++ -O3 -o $@ abc_datatypes.C \
	$(CXXFLAGS) \
	-I/opt/alembic/alembic-1.7.12/include \
	-I/opt/openexr/openexr-2.4.0/include/OpenEXR \
	-L/opt/alembic/alembic-1.7.12/lib \
	-L/opt/openexr/openexr-2.4.0/lib64 \
	-lAlembic -lImath -lIex -lIlmThread -lHalf

.phony: clean
clean:
	rm -fv ./abc_datatypes abc_datatyeps.abc

.phony: test
test:
	./abc_datatypes
	abcecho abc_datatypes.abc
