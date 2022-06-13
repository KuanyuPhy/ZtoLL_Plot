#!/usr/bin/env zsh

HT_list=("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root" $(find /home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY -mindepth 1 -maxdepth 1 -name "ee_ht*.root")) 
Top_list=( $(find /home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top -mindepth 1 -maxdepth 1 -name "top_*.root"))
SECONDS=0
for file in ${HT_list[*]}; do
    outputfile="$(basename -s ".root" "$file")"
    echo $file
    ./ee_HT_half "$file" "/home/kuanyu/Documents/root_file/BgEstimation/${outputfile}_1.root" "/home/kuanyu/Documents/root_file/BgEstimation/${outputfile}_2.root" &
    #echo ./$outputfile;
done
#echo $Top_list
for file in ${Top_list[*]}; do
    Topoutputfile="$(basename -s ".root" "$file")"
    echo $Topoutputfile
    ./ee_Top_half "$file" "/home/kuanyu/Documents/root_file/BgEstimation/${Topoutputfile}_1.root" "/home/kuanyu/Documents/root_file/BgEstimation/${Topoutputfile}_2.root" 
    #echo ./$outputfile;
done
wait
echo $SECONDS