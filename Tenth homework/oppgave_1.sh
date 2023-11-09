# if who | grep -q 'edg'
# then
#    echo "Hacker alert!"
# fi

# if [ $# -ne 1 ]
# then
#    echo "usage: $0 name"
#    exit 1
# fi

# until who | grep -q $1
# do
#   echo "Waiting..."
#   sleep 10
# done

# echo "$(date): Hacker alert! $1 has logged on!"
# hacker 
# hacker

# function check_extension {
#     local file=$1
#     local extension="${file##*.}"
    
#     if [ -z "$file" ]; then
#         echo "No file provided"
#         return 1
#     elif [ ! -f "$file" ]; then
#         echo "File does not exist"
#         return 1
#     else
#         echo "The extension of the file is: $extension"
#         return 0
#     fi
# }

function move_mp3_files {
    local source_dir=$1
    local target_dir=$2
    local count=0

    if [ -z "$source_dir" ] || [ -z "$target_dir" ]; then
        echo "Source or target directory not provided"
        return 1
    fi

    if [ ! -d "$source_dir" ] || [ ! -d "$target_dir" ]; then
        echo "Source or target directory does not exist"
        return 1
    fi

    for file in "$source_dir"/*.html; do
        if [ -f "$file" ]; then
            mv "$file" "$target_dir"
            ((count++))
        fi
    done

    echo "Moved $count .mp3 files from $source_dir to $target_dir"
}

move_mp3_files mappe1 mappe2