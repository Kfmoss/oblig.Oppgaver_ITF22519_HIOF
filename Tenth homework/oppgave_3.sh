function change_size {
    local source_dir=$1
    local time_=0
    local size=0
    local minutt=60
    
    if [ -z "$source_dir" ]; then
        echo "Source directory not provided"
        return 1
    fi
    if [ ! -d "$source_dir" ]; then
        echo "Source directory does not exist"
        return 1
    fi
    size=$(stat -c "%s" $source_dir)
    temp=$size
   
    while true
    do 
        ((time_++))
        sleep 1
        echo "time: $time_"
        if [ "$time_" = "$minutt" ];then
            while ((time_>0))
            do
                size=$(stat -c "%s" $source_dir)
                if [ $size -eq $temp ];then
                    echo "Checking size... apparently there's no chnages"
                    sleep 1
                    ((time_--))
                    echo "time: $time_"
                fi
                if [ $size -ne $temp ];then

                    echo "The size of the directory has changed in the last minute"
                    break
                fi
            done
        
        fi   
    done

    

}
change_size "mappe2"