CMP = g++
CMP_FLAGS = -O2
INC_DIR = -I/home/jp/local/include
OBJS = main.o
LIB_FLAGS = -L. -L/home/jp/local/lib -L/usr/local/lib
LIBS = -lOpenThreads -lProducer -losg -losgUtil -losgDB -losgGA -losgProducer -losgOde -lode
EXE = example_osgode 

$(EXE): $(OBJS) libosgOde.so
	$(CMP) $(CMP_FLAGS) $(LIB_FLAGS) $(OBJS) $(LIBS) -o $(EXE)

main.o: main.cpp
	$(CMP) $(CMP_FLAGS) $(INC_DIR) -Iinclude/ -c main.cpp

clean:
	rm -rf *.o core *~ src/*~ include/*~ include/osgOde/*~
distclean: clean
	rm -rf *.so* $(EXE)
libosgOde.so: Functions.o World.o Geometry.o Body.o Joint.o
	g++ -shared -W1,-soname,libosgOde.so.1 -o libosgOde.so.1.0.1 Functions.o World.o Geometry.o Body.o Joint.o
	ln -s libosgOde.so.1.0.1 libosgOde.so
Functions.o: ./src/Functions.cpp
	g++ -fPIC -c -Wall ./src/Functions.cpp -Iinclude/ $(INC_DIR)
World.o: ./src/World.cpp
	g++ -fPIC -c -Wall ./src/World.cpp -Iinclude/ $(INC_DIR)
Geometry.o: ./src/Geometry.cpp
	g++ -fPIC -c -Wall ./src/Geometry.cpp -Iinclude/ $(INC_DIR)
Body.o: ./src/Body.cpp
	g++ -fPIC -c -Wall ./src/Body.cpp -Iinclude/ $(INC_DIR)
Joint.o: ./src/Joint.cpp
	g++ -fPIC -c -Wall ./src/Joint.cpp -Iinclude/ $(INC_DIR)
