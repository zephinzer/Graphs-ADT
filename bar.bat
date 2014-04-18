echo Build and run Graphs
g++ ./src/graphs.cpp -o ./bin/graphs -static-libgcc -static-libstdc++ -s -Os
cd bin
graphs
pause