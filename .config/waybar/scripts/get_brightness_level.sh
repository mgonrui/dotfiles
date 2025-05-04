#!/bin/bash

value=$(ddccontrol -r 0x10 dev:/dev/i2c-2 2>/dev/null | grep Brightness | awk '{print $3}' | cut -f2 -d "/")
echo "{\"percentage\": $value}"
