./ex2_body.sh &
while true; do
    if ! ln numbers.txt numbers.txt.lock
    then
      ./ex2_body.sh
        rm numbers.txt.lock;
        break
    else
        sleep 2
    fi
done
