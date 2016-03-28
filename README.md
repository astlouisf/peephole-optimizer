Peephole Contest
================

Installation
-----------

Set environment variable `PEEPDIR` to refer to this directory permanently. Then

```
cd JOOSA-src/
make
```

Usage
-----

Example:
```
cd PeepholeBenchmarks/bench01/
$PEEPDIR/joosc *.java
```
or the following to enable optimization
```
$PEEPDIR/joosc -O *.java
```
`*.j` are the output Jasmin files that we analyze. To check the size of the Jasmin files in bytes, use
```
du -b *.j
```
