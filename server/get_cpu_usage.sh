while true
do
    USAGE=$(NUMCPUS=`grep ^proc /proc/cpuinfo | wc -l`; FIRST=`cat /proc/stat | awk '/^cpu / {print $5}'`; sleep 1; SECOND=`cat /proc/stat | awk '/^cpu / {print $5}'`; USED=`echo 2 k 100 $SECOND $FIRST - $NUMCPUS / - p | dc`; echo ${USED})

    for file in $(ls /dev/ttyACM*)
    do
        if [ -e $file ]
        then
            echo $USAGE
            echo $USAGE > $file
            break
        fi
    done
    sleep 10
done
