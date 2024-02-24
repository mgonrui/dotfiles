#!/bin/sh

# Define the folder to monitor
folder_to_monitor="/home/mgr/downloads"

# Start an infinite loop
while true; do
    # Use inotifywait to monitor for new files in the folder
    file=$(inotifywait -q -e create "$folder_to_monitor" | sed -r 's/.*CREATE\s+(.*)$/\1/')

    # Replace this line with the command you want to run when a new file is added
    # For example, you can echo the filename
    echo "New file added: $file"
    # if [ -n "$(find "$item" -type f \( -name "*.mp3" -o -name "*.flac" \) -print -quit)" ]; then
done
