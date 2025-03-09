#!/bin/bash

value=$(ddccontrol -r 0x10 dev:/dev/i2c-2 2>/dev/null | grep Brightness | awk '{print $3}' | awk -F/ '{print $2}')
echo "{\"percentage\": $value}"
