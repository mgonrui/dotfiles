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


 


while IFS= read -r -d $'\0' file; do
  result+=("$file") # Append each line to the array
done < <( find "$source_folder" -mindepth 1 -maxdepth 1 -type d-print0)

# Print the elements of the array (you can also use them as needed in your script)
for item in "${result[@]}"; do
  echo "$item"
done