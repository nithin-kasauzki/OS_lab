sum=0
for((i=0;i<5;i++))
    do
    read x
    sum=$(($sum+$x))
    done
echo $sum    
