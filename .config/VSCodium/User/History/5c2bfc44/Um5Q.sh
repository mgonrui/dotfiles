# Launch bar on each monitor, tray on primary
polybar --list-monitors | while IFS=$'\n' read line; do
  monitor=$(echo $line | cut -d':' -f1)
  primary=$(echo $line | cut -d' ' -f3)
  MONITOR=$monitor polybar -c $HOME/.config/polybar/bar01.ini --reload "top${primary:+"-primary"}" &
done