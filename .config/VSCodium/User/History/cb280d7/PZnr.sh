#!/bin/bash
adb shell content query --uri content://sms/inbox --projection address,body,date_sent | tail -n +2 | while read -r line; do
    address=$(echo "$line" | cut -d '|' -f 2)
    body=$(echo "$line" | cut -d '|' -f 3)
    echo "SMS from $address: $body"
    # Add logic to send the SMS to your Linux PC here
done
