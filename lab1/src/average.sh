#!/bin/bash
read N
sum=0
for ((i=0;i<N;i++))
do
o="$(od -An -N1 -i /dev/random)"
echo "$o"
sum=$(($sum+$o))
done
arif=$(($sum/$N))
echo "${arif}"