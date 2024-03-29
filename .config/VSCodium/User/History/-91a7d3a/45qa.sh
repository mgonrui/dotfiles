#!/bin/sh

# Define the folder to monitor
folder_to_monitor="$HOME/downloads"

# Delay in seconds before considering the file complete
completion_delay=30

function checksize(){
    initial_size=$(stat -c %s "$folder_to_monitor/$file")
    sleep "$completion_delay"
    current_size=$(stat -c %s "$folder_to_monitor/$file")
}
function movedownload(){
    # Use inotifywait to monitor for new files in the folder
    file=$(inotifywait -q -e create "$folder_to_monitor" | sed -r 's/.*CREATE\s+(.*)$/\1/')
    extension="${file##*.}"

    if [[ "$file" == *.part ]]; then
        echo "Skipping incomplete file: $file"
    else

        checksize
        while [ -f "$folder_to_monitor/$file" ] && [ "$initial_size" != "$current_size" ] 
            checksize
        if [ -f "$folder_to_monitor/$file" ] && [ "$initial_size" -eq "$current_size" ]; then
            # File size has not changed; assume download is complete
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
            echo "moved"
        fi
    fi
}

while true; do
    movedownload
done
