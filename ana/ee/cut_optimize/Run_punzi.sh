#!/usr/bin/env zsh
g++ -o ee_HT_inclusive.o $(root-config --cflags) ee_HT_inclusive.C $(root-config --glibs)
g++ -o ee_HT3D.o $(root-config --cflags) ee_HT3D.C $(root-config --glibs)
HT_inclusive="/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root"
HT_list=($(find /home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY -mindepth 1 -maxdepth 1 -name "ee_ht*.root")) 
#./ee_HT_inclusive.o "$HT_inclusive" "./DY_inclus_emjet.root" &

root -l ee_HT_inclusive.C
wait
for file in ${HT_list[*]}; do
    outputfile="$(basename -s ".root" "$file")"
    echo $outputfile
    ./ee_HT3D.o "$file" "${outputfile}.root"  &
done
wait
rm ee_ht70.root
hadd DY_emjet.root ee_ht*.root
rm ee_ht*.root



#echo $HT_inclusive


