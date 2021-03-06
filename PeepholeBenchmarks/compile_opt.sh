rm -rf bench0*/*.class bench0*/*.j bench0*/*.optdump bench0*/*.dump bench0*/*.size bench0*/*~

for benchmark in bench01 bench02 bench03 bench04 bench05 bench06 bench07
do
cd $benchmark
if [ $benchmark == bench03 ]
then
  $PEEPDIR/joosc -O *.java *.joos
else
  $PEEPDIR/joosc -O *.java
fi
cd ..
done

echo ""
echo "Total size for optimized code:"
awk '{sum += $3} END {print sum}' bench0*/optdump.size
