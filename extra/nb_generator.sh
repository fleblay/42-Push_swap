#!/bin/bash
INDEX=0
while [[ $INDEX < $1 ]]
do
RANDNB=$(( RANDOM % 2147483648))
echo $RANDNB
TAB[$INDEX]=${RANDNB}
(( INDEX++ ))
done

echo ${TAB[*]}
