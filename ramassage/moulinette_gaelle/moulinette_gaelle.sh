#!/bin/bash
## moulinette_gaelle.sh for moulinette_gaelle in /home/mowgli/cminar/ramassage
## 
## Made by mowgli
## Login   <mowgli@epitech.net>
## 
## Started on  Wed Feb 15 10:37:47 2017 mowgli
## Last update Wed Feb 15 12:12:13 2017 mowgli
##

studentFile=$1;
repo=$2;
exo="ex"$3;

rm -f ../correction_"$repo"_"$exo";

for line in $(cat $studentFile);
do
    STR=$line;
    IFS=';' read -ra NAMES <<< "$STR" echo ${NAMES[1]};
    rm -rf ../.tmp;
    mkdir ../.tmp;
    cp ./* .tmp/ ;
    mkdir -p "../res/$repo/$exo/${NAMES[0]}/";
    echo $'\n'${NAMES[0]};
    cp ../$repo/${NAMES[0]}/$exo/* ./;

    rm ./.tmpfile;

    echo "reader";
    while read -r fileline
    do
	if [[ "$fileline" =~ "define	NB_BY_ROW" ]]; then
	    echo "Deleted";
	elif [[ "$fileline" =~ "define NB_BY_ROW" ]]; then
	    echo "Deleted";
	else
	    echo "$fileline" >> ./.tmpfile; 
	fi
    done < str_to_int_tab.c;
    echo "end reader";
    rm str_to_int_tab.c;
    mv ./.tmpfile str_to_int_tab.c;

    echo "test.sh"; 
    echo "./test.sh str_to_int_tab.c > ../res/$repo/$exo/${NAMES[0]}/output${NAMES[0]}";
    timeout 5 ./test.sh str_to_int_tab.c > ../res/$repo/$exo/${NAMES[0]}/output${NAMES[0]} ;
    echo "diff" 
    if diff ../res/$repo/$exo/${NAMES[0]}/output${NAMES[0]} output;
    then
	echo  ${NAMES[0]}";SUCCESS" >> ../correction_"$repo"_"$exo";
    else
	echo  ${NAMES[0]}";FAILED" >> ../correction_"$repo"_"$exo";
    fi
done 
