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
            remove_path="${item/$path/}"
            echo  "$destination_folder/$remove_path"
        if [ -d "$destination_folder/$remove_path" ]; then
            mv "$item/*" "$destination_folder/$remove_path/"
            # mv "$destination_folder/$remove_path/"
            # mv "$folder"/* "$destination_subfolder/"
        fi

    fi
done



#   for folder; do
#       destination_subfolder="$destination_folder/$(basename "$folder")"
      
#       # Check if the destination subfolder already exists
#       if [ -d "$destination_subfolder" ]; then
#         # Move the contents of $folder into the existing destination subfolder
#         mv "$folder"/* "$destination_subfolder/"
#         echo "Merged: $folder into $destination_subfolder"
#       else
#         # Move the entire $folder to the destination folder
#         mv "$folder" "$destination_folder/"
#         echo "Moved: $folder"
#       fi
#     fi
#   done