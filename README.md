# Peephole Contest
## Installation
Set environment variable `PEEPDIR` to refer to this directory permanently.

Also `export CLASSPATH=.:../../jooslib.jar` to be able to run the benchmark programs.

Go to `JOOSA-src/` directory, then
```
make
```
## Usage
### Compile
Example: Go to `PeepholeBenchmarks/bench01/` directory, then
```
$PEEPDIR/joosc *.java
```
or the following to enable optimization
```
$PEEPDIR/joosc -O *.java
```
For `bench03`, use the following:
```
$PEEPDIR/joosc -O *.java *.joos
```
### Compute Size
Go to `PeepholeBenchmarks/` directory, then
```
awk '{sum += $3} END {print sum}' bench0*/dump.size
```
or the following for optimized code
```
awk '{sum += $3} END {print sum}' bench0*/optdump.size
```
### Run
Benchmark 1:
```
java Benchmark < in1
```
Benchmark 2:
```
java Main < in1
```
Benchmark 3:
```
???
```
Benchmark 4:
```
java Game
```
Benchmark 5:
```
java DungeonGenerator < in1
```
Benchmark 6:
```
java Main < in1
```
Benchmark 7:
```
java GrueHunt < in1
```

### Clean
Go to `PeepholeBenchmarks/` directory, then
```
rm -rf bench0*/*.class bench0*/*.j bench0*/*.optdump bench0*/*.dump bench0*/*.size bench0*/*~
```
To clean individual benchmark folder:
```
rm -rf *.class *.j *.optdump *.dump *.size *~
```
