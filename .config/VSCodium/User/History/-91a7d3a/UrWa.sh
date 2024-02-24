#!/bin/sh

# Define the folder to monitor
folder_to_monitor="$HOME/downloads"

# Delay in seconds before considering the file complete
completion_delay=30

# Start an infinite loop
while true; do
    # Use inotifywait to monitor for new files in the folder
    file=$(inotifywait -q -e create "$folder_to_monitor" | sed -r 's/.*CREATE\s+(.*)$/\1/')
    extension="${file##*.}"

    # Capture the initial size of the file
    initial_size=$(stat -c %s "$folder_to_monitor/$file")

    # Sleep for a specified time to allow the download to potentially complete
    sleep "$completion_delay"

    # Check if the file still exists, and its size remains constant
    current_size=$(stat -c %s "$folder_to_monitor/$file")
    if [ -f "$folder_to_monitor/$file" ] && [ "$initial_size" -eq "$current_size" ]; then
        # File size has not changed; assume download is complete
        case "$extension" in
            pdf|epub|mobi|djvu)
                # Move the file to the library folder
                mv "$folder_to_monitor/$file" "$HOME/documents/library/"
                ;;
            iso|img)
                # Move the file to the os_images folder
                mv "$folder_to_monitor/$file" "$HOME/downloads/os_images/"
                ;;
            torrent)
                # Move the file to the torrents folder
                mv "$folder_to_monitor/$file" "$HOME/downloads/torrents/.torrentfiles/"
                ;;
            *)
                echo "Unknown file extension: $extension"
                ;;
        esac
    fi
done
