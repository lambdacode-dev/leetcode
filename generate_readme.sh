#!/bin/bash

files=`ls -lcrt *cpp | sed 's/.* //'`
echo "# leetcode" > README.md
echo "| Leetcode # | Leetcode Link | Algorithm | Time Complexity | Space Complexity |" >> README.md
echo "| --- | --- | --- | --- | --- |" >> README.md
for f in $files; do
    algorithm=`sed -n -e's/\/\/ *\[\([ a-zA-Z0-9,&]*\)\].*/\1/p' $f`
    timespace=`sed -n -e's/\/\/ *(time, *space) =//p' $f`
    read -a timespacearr <<< "$timespace"
    digits=`expr "$f" : '[0-9]*'`
    problemid=${f:0:$digits}
    let sz="${#f}-$digits-5" #without problem id and cpp ext
    problem=${f:$digits+1:$sz}
    url=`echo $problem | tr '[:upper:]' '[:lower:]'`
    problem=`echo $problem | tr '-' ' '`
    echo "| $problemid | [$problem](https://leetcode.com/problems/$url/) | $algorithm | ${timespacearr[0]} |${timespacearr[1]} |" >> README.md
done
