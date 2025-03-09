#!/bin/bash

# Directory to save screenshots
SCREENSHOT_DIR="$HOME/Pictures/screenshots"

# Create the directory if it doesn't exist
mkdir -p "$SCREENSHOT_DIR"

# Generate a timestamp for the filename
TIMESTAMP=$(date +"%Y-%m-%d_%H-%M-%S")

# Filename for the screenshot
FILENAME="$SCREENSHOT_DIR/screenshot_$TIMESTAMP.png"

# Use slurp to select an area and grim to take the screenshot
slurp | grim -g - "$FILENAME"

# Check if the screenshot was successfully taken
if [ $? -eq 0 ]; then
    echo "Screenshot saved as $FILENAME"
else
    echo "Failed to take screenshot."
fi
