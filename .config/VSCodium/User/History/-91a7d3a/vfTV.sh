#!/bin/sh

# Define the folder to monitor
folder_to_monitor="$HOME/downloads"

# Delay in seconds before considering the file complete

function checksize(){
    initial_size=$(stat -c %s "$folder_to_monitor/$file")
    sleep 30 
    current_size=$(stat -c %s "$folder_to_monitor/$file")
}
function movedownload(){
    # Use inotifywait to monitor for new files in the folder
    file=$(inotifywait -q -e create "$folder_to_monitor" | sed -r 's/.*CREATE\s+(.*)$/\1/')
    extension="${file##*.}"

    if [[ "$file" == *.part ]]; then
        echo "Skipping incomplete file: $file"
    else
        echo "valid file found: $file"
        checksize
        while [ -f "$folder_to_monitor/$file" ] && [ "$initial_size" != "$current_size" ]; do 
            checksize
        done
        case "$extension" in
            pdf|epub|mobi|djvu)
                mv "$folder_to_monitor/$file" "$HOME/documents/library/"
                ;;
            iso|img)
                mv "$folder_to_monitor/$file" "$HOME/downloads/os_images/"
                ;;
            torrent)
                mv "$folder_to_monitor/$file" "$HOME/downloads/torrents/.torrentfiles/"
                ;;
            *)
                echo "Unknown file extension: $extension"
                ;;
        esac
    fi
}

while true; do
    movedownload
done
