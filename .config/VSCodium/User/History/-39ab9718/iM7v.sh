#!/bin/bash

# Source folder where you want to search for subfolders containing .mp4 and .flac files
source_folder="$HOME/downloads/nicotine"

# Destination folder where you want to move the subfolders
destination_folder="$HOME/media/audio/music"
#!/bin/bash
path="/home/mgr/downloads/nicotine/"
while IFS= read -r -d $'\0' file; do
  result+=("$file") # Append each line to the array
done < <( find "$source_folder" -mindepth 1 -maxdepth 1 -type d -print0)

# Print the elements of the array (you can also use them as needed in your script)
for item in "${result[@]}"; do
    if [ -n "$(find "$item" -type f \( -name "*.mp4" -o -name "*.flac" \) -print -quit)" ]; then
            echo "found mp3 in $item"
            remove_path="${$item/$path}
            echo  "$destination_folder$remove_path"
        if [ -d "$destination_folder$item" ]; then
        fi

    fi
done
