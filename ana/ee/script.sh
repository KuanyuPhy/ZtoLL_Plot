#!/usr/bin/env zsh
HT_list=("/mnt/c/Users/USER/Documents/root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root" $(find /mnt/c/Users/USER/Documents/root_file/Ztoee/2016BKGMC/DY -mindepth 1 -maxdepth 1 -name "ee_ht*.root")) 
Top_list=("/mnt/c/Users/USER/Documents/root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root")
SECONDS=0
for file in ${HT_list[*]}; do
    outputfile="$(basename -s ".root" "$file")"
    #echo $file
    ./ee_HT_half_test.o "$file" "./output/${outputfile}_1.root" "./output/${outputfile}_2.root" &
    #echo ./$outputfile;
done
echo $Top_list
Topoutputfile="$(basename -s ".root" "$Top_list")"
#echo $Topoutputfile
./ee_Top_half.o "$Top_list" "./${Topoutputfile}_1.root" "./${Topoutputfile}_2.root" &
wait
echo $SECONDS