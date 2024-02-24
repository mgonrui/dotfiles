#!/bin/bash

# Source folder where you want to search for subfolders containing .mp4 and .flac files
source_folder="$HOME/downloads/nicotine"

# Destination folder where you want to move the subfolders
destination_folder="$HOME/media/audio/music"
#!/bin/bash


# Use the 'find' command to search for subfolders containing .mp4 or .flac files
# The '-type d' flag ensures that only directories (subfolders) are selected
# The '-exec' flag is used to perform a custom action on each subfolder found
# The '{}' is a placeholder for the found subfolder, and ';' indicates the end of the -exec option


find "$source_folder" -mindepth 1 -maxdepth 1 -type d -exec sh -c '
  for folder; do
    if [ -n "$(find "$folder" -type f \( -name "*.mp4" -o -name "*.flac" \) -print -quit)" ]; then
      destination_subfolder="$destination_folder/$(basename "$folder")"
      
      # Check if the destination subfolder already exists
      if [ -d "$destination_subfolder" ]; then
        # Move the contents of $folder into the existing destination subfolder
        mv "$folder"/* "$destination_subfolder/"
        echo "Merged: $folder into $destination_subfolder"
      else
        # Move the entire $folder to the destination folder
        mv "$folder" "$destination_folder/"
        echo "Moved: $folder"
      fi
    fi
  done
' sh {} +