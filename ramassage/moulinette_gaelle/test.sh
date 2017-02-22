#!/bin/bash

set -e

CC=gcc

STUDENT_FILE=$1

function compile()
{
    local nb_by_row=$1
    local target=$2

    $CC -std=gnu11 -DNB_BY_ROW=$nb_by_row $STUDENT_FILE str_to_int_tab_own.c memstream.c test.c -o $target
}

function run_test()
{
    local nb_by_row=$1
    local teststring=$2

    filename=$(mktemp)

    compile $nb_by_row $filename

    if $filename $teststring
    then
        echo $nb_by_row,\"$teststring\",\"OK\"
    else
        echo $nb_by_row,\"$teststring\",\"KO\"
    fi
    rm $filename
}

echo NB_BY_ROW,TESTSTRING,RESULT
run_test 5 "1 2 3 4 5"
run_test 4 "4 8 15 16 23 42"
run_test 3 "5 5 8 0 45 33 22"
run_test 7 "44 6666 733 8221 93"
run_test 1 "987521 123456789 456 567"
run_test 20 "22 33 44 55 66 77 88 99 11 42"
run_test 1 "1 2"
run_test 23 "1337 101 7327 645115 8417"
run_test 100 "100 200 300 400 500 600 700 800 999"
