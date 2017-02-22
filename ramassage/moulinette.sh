#!/bin/bash
## moulinette.sh for moulinette.sh in /home/mowgli/cminar/ramassage
## 
## Made by mowgli
## Login   <mowgli@epitech.net>
## 
## Started on  Tue Feb 14 10:44:05 2017 mowgli
## Last update Thu Feb 16 16:30:13 2017 mowgli
##

studentFile=$1;
repo=$2;
exo="ex"$3;
type=$4;
av=$5;

ext="c";
cc="gcc";

if [ "$type" == "cpp" ]
then
    ext="*pp";
    cc="g++";
fi

add="";

if [ "$av" == "args" ]
then
    add="Epitech Astek School Pool Malloc Koala Voltaire Pasteur Exercise Tmp";
fi


rm -f correction_"$repo"_"$exo";

for line in $(cat $studentFile);
do
    STR=$line;
    IFS=';' read -ra NAMES <<< "$STR" echo ${NAMES[1]};
    rm -rf .tmp;
    mkdir .tmp;
    cp ./correction/$repo/$exo/* .tmp/ ;
    mkdir -p "./res/$repo/$exo/${NAMES[0]}/";
    echo $'\n'${NAMES[0]};
    echo "cp ./$repo/${NAMES[0]}/$exo/* .tmp/;";
    cp ./$repo/${NAMES[0]}/$exo/* .tmp/;
    $cc .tmp/*.$ext -std=gnu++11 -o ./res/$repo/$exo/${NAMES[0]}/$exo${NAMES[0]};
    ./res/$repo/$exo/${NAMES[0]}/$exo${NAMES[0]} $add > ./res/$repo/$exo/${NAMES[0]}/output${NAMES[0]} ;

    if diff ./res/$repo/$exo/${NAMES[0]}/output${NAMES[0]} .tmp/output;
    then
	echo  ${NAMES[0]}";SUCCESS" >> correction_"$repo"_"$exo";
    else
	echo  ${NAMES[0]}";FAILED" >> correction_"$repo"_"$exo";
    fi
done 
