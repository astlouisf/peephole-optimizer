cd bench01
echo "**** bench01 ****"
java Benchmark < in1
echo ""
cd ..
cd bench02
echo "**** bench02 ****"
java Main < in1
echo ""
cd ..
cd bench03
echo "**** bench03 ****"
cd lib/; javac -cp $PEEPDIR/jooslib.jar: JoosBitwise.java; cd ..
java -cp $PEEPDIR/jooslib.jar: Main < in1
echo ""
cd ..
echo "**** bench05 ****"
cd bench05
java DungeonGenerator < in1
echo ""
cd ..
echo "**** bench06 ****"
cd bench06
java Main < in1
echo ""
cd ..
echo "**** bench07 ****"
cd bench07
java GrueHunt < in1
echo ""
cd ..
