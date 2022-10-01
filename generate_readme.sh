#!/bin/bash

stringZ=abcABC123ABCabc
#       |------|
#       12345678

echo `expr "$stringZ" : 'abc[A-Z]*.2'`       # 8


files=`ls -lcrt *cpp | sed 's/.* //'`
echo "# leetcode" > README.md
echo "| Leetcode # | Leetcode Link |" >> README.md
echo "| --- | --- |" >> README.md
for f in $files; do
    echo
    echo $f
    digits=`expr "$f" : '[0-9]*'`
    problemid=${f:0:$digits}
    let sz="${#f}-$digits-5" #without problem id and cpp ext
    problem=${f:$digits+1:$sz}
    url=`echo $problem | tr '[:upper:]' '[:lower:]'`
    problem=`echo $problem | tr '-' ' '`
    echo "| $problemid | [$problem](https://leetcode.com/problems/$url/) |" >> README.md
done

