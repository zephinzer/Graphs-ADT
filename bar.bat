echo Build and run Graphs
g++ -S ./src/graphs.cpp -o ./bin/graphs.s
g++ ./src/graphs.cpp -o ./bin/graphs.exe -Wall -v -s -Os  -static-libgcc -static-libstdc++
cd bin
graphs
pause