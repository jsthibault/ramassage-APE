#!/bin/bash
## get_depot.sh for get_content in /home/mowgli/cminar/ramassage
## 
## Made by mowgli
## Login   <mowgli@epitech.net>
## 
## Started on  Tue Feb 14 10:45:08 2017 mowgli
## Last update Tue Feb 14 15:08:42 2017 mowgli
##

rm -rf ./$2/errors;
cat $1 | tr -d '\r' > .tmp-test-42;
rm -f $1;
cat .tmp-test-42 > $1;
rm -f .tmp-test-42;

for line in $(cat $1);
do
    STR=$line;
    IFS=';' read -ra NAMES <<< "$STR" echo ${NAMES[1]};
    mkdir -p "./$2/${NAMES[0]}/";
    echo $'\n'${NAMES[0]};
    git clone git@git.epitech.eu:/${NAMES[1]}/$2 ./$2/${NAMES[0]};
    ret=$?
    if ! test "$ret" -eq 0
    then
	echo  ${NAMES[0]}';' >> ./$2/errors;
    fi
    sleep 0.1;
done 

