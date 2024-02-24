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