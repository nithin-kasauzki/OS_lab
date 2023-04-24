echo "enter X" 
read x
echo "enter n"
read n
p=1
for((i=0;i<n;i++))
    do
    p=$(($x*$p))
    done
echo $p    