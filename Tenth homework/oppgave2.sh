

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

