import os
import subprocess
from libqtile import bar, layout, widget, hook, qtile 
from libqtile.config import Click, Drag, Group, Match, Key, Screen, ScratchPad, DropDown
from libqtile.lazy import lazy
from spotify import Spotify
from libqtile.log_utils import logger
mod = "mod4"  # windows key
myTerm = "kitty"
alt = "mod1"


# run script for setting configurations and opening programs at start
@hook.subscribe.startup_once
def autostart():
    logger.warning("In autostart function")
    home = os.path.expanduser('/home/mgr/.config/qtile/autostart.sh')
    subprocess.call([home])


keys = [
    # scratchpad shortcuts
#    Key([mod], "Return", lazy.group["scratchpad"].dropdown_toggle("kitty")),
    Key([mod], "y", lazy.group["scratchpad"].dropdown_toggle("clipgrab")),

    Key([mod], "z", lazy.spawn("/home/mgr/.config/rofi/powermenu.sh")) ,
    # open terminal
    Key([mod], "Return", lazy.spawn("kitty")),
    # open rofi
    Key([mod], "x", lazy.spawn("rofi -show run")),

    # print screen
    Key([], "Print", lazy.spawn("flameshot gui")),

    # control volume up and down
    Key([mod], "equal", lazy.spawn("amixer set Master 5%+")),
    Key([mod], "minus", lazy.spawn("amixer set Master 5%-")),

    # switch between monitors
    Key([mod], "space", lazy.next_screen()),

    # kill focused window
    Key([mod], "d", lazy.window.kill()),

    # lock screen 
    Key([mod, "control"], "l", lazy.spawn("betterlockscreen -l dimblur --display 1 --off 60")),

    # reload qtile config
    Key([mod, "control"], "r", lazy.reload_config()),

    # shutdown qtile
    Key([mod, "control"], "q", lazy.shutdown()),


# ______EXEC SCRIPTS______
# open keepassxc database
Key([mod],"p",lazy.spawn(["/home/mgr/projects/code/sh/shell_scripts/keepassxc.sh"]),),
# start white noise
Key([mod],"n",lazy.spawn(["/home/mgr/projects/code/sh/shell_scripts/whitenoise.sh"]),),
# switch keyboard layout between us and spanish
Key([mod, "shift"],"l",lazy.spawn(["/home/mgr/projects/code/sh/shell_scripts/switch_keyboard_layout.sh"]),),


    # # A list of available commands that can be bound to keys can be found
    # # at https://docs.qtile.org/en/latest/manual/config/lazy.html
     # Switch between windows
     #Key([mod], "h", lazy.layout.left(), desc="Move focus to left"),
    # Key([mod], "l", lazy.layout.right(), desc="Move focus to right"),
     #Key([mod], "j", lazy.layout.down(), desc="Move focus down"),
     #Key([mod], "k", lazy.layout.up(), desc="Move focus up"),
    #  Key([mod], "p", lazy.layout.next(), desc="Move window focus to other window"),
    # # Move windows between left/right columns or move up/down in current stack.
    # # Moving out of range in Columns layout will create new column.
    # Key([mod, "shift"], "h", lazy.layout.shuffle_left(), desc="Move window to the left"),
    # Key([mod, "shift"], "l", lazy.layout.shuffle_right(), desc="Move window to the right"),
    # Key([mod, "shift"], "j", lazy.layout.shuffle_down(), desc="Move window down"),
    # Key([mod, "shift"], "k", lazy.layout.shuffle_up(), desc="Move window up"),
    # # Grow windows. If current window is on the edge of screen and direction
    # # will be to screen edge - window would shrink.
    # Key([mod, "control"], "h", lazy.layout.grow_left(), desc="Grow window to the left"),
    # Key([mod, "control"], "l", lazy.layout.grow_right(), desc="Grow window to the right"),
    # Key([mod, "control"], "j", lazy.layout.grow_down(), desc="Grow window down"),
    # Key([mod, "control"], "k", lazy.layout.grow_up(), desc="Grow window up"),
     Key([mod], "Tab", lazy.next_layout(), desc="Toggle between layouts"),
    # Key([mod], "n", lazy.layout.normalize(), desc="Reset all window sizes"),
    # # Toggle between split and unsplit sides of stack.
    # # Split = all windows displayed
    # # Unsplit = 1 window displayed, like Max layout, but still with multiple stack panes
    # Key(
    #     [mod, "shift"],
    #     "Return",
    #     lazy.layout.toggle_split(),
    #     desc="Toggle between split and unsplit sides of stack",
    # ),
]

# use xprop to see the WM_CLASS
groups = [
    ScratchPad("scratchpad",[DropDown("kitty","kitty",x=0.025,y=0.025,width=0.95,height=0.95,opacity=1,on_focus_lost_hide=False,),
    DropDown("clipgrab","clipgrab",x=0.5,y=0,width=0.5,height=0.5,opacity=1,on_focus_lost_hide=False,),],),
    # letters used: N/C/W/I/F/P/M/V/T
    # notes 
    Group("n", label=" 󰠮 ", matches=[Match(wm_class="obsidian")], layout="monadtall"),
    # calendar
    Group("c", label="  ", matches=[Match(wm_class="chromium-browser")], layout="monadtall"),
    # web browser
    Group("w",label=" 󰈹 ",matches=[Match(wm_class="firefox" "brave-browser" "Tor Browser")],layout="max"),
    # terminal
    Group("t", label="   ", matches=[Match(wm_class="kitty" "emacs")], layout="monadtall"),
    # text editor
    Group("i", label=" 󰅩 ", matches=[Match(wm_class="vscodium" "emacs")], layout="monadtall"),
    # file manager
    Group("f", label="  ", matches=[Match(wm_class="nemo" "dolphin" "calibre")], layout="monadtall"),
    # document viewer
    Group("p", label=" 󰈙 ", matches=[Match(wm_class="sioyek" "okular" "Zathura")], layout="monadtall"),
    # password manager
    Group("b", label=" 󰌾 ", matches=[Match(wm_class= "bitwarden" "keepassxc")], layout="monadtall"),
    # music
    Group("m",label="  ",matches=[Match(wm_class="spotify" "easyeffects")], layout="monadtall"),
    # virtual machines
    Group("v", label=" 󰟀 ", matches=[Match(wm_class="virt-manager")], layout="monadtall"),
    # torrents
    Group("q", label="  ", matches=[Match(wm_class="qbittorrent")], layout="monadtall"),
]


for i in groups:
    keys.append(
        Key([mod], i.name[0], lazy.group[i.name].toscreen())
    )
    keys.append(
        Key([mod, "shift"], i.name[0], lazy.window.togroup(i.name))
    )


# borders colors and margins
def init_layout_theme():
    return {
        "margin": 3,
        "border_width": 2,
        "border_focus": "#b57614",
        "border_normal": "#282828",
    }


layout_theme = init_layout_theme()


layouts = [
    layout.Max(**layout_theme),
    layout.MonadTall(**layout_theme),
    # interesting layouts
    #layout.VerticalTile(**layout_theme),
    # layout.TreeTab(**layout_theme), 
    # not so interesting layouts
    # layout.Columns(border_focus_stack=["#d75f5f", "#8f3d3d"], border_width=4),
    # layout.Zoomy(**layout_theme),
    # layout.Floating(**layout_theme),
    # layout.MonadWide(**layout_theme),
    # layout.MonadThreeCol(**layout_theme),
    # layout.Spiral(**layout_theme),
    # layout.Slice(**layout_theme),
    # layout.RatioTile(**layout_theme),
    # layout.Tile(**layout_theme),
    # layout.Stack(num_stacks=2, **layout_theme),
    # layout.Bsp(**layout_theme),
    # layout.Matrix(**layout_theme),
]
colors = [
    ["#282828", "#282828"],  # 0  # bg
    ["#282828", "#282828"],  # 1  # bg0
    ["#1d2021", "#1d2021"],  # 2  # bg0_h
    ["#32302f", "#32302f"],  # 3  # bg0_s
    ["#3c3836", "#3c3836"],  # 4  # bg1
    ["#504945", "#504945"],  # 5  # bg2
    ["#665c54", "#665c54"],  # 6  # bg3
    ["#7c6f64", "#7c6f64"],  # 7  # bg4
    ["#ebdbb2", "#ebdbb2"],  # 8  # fg
    ["#fbf1c7", "#fbf1c7"],  # 9  # fg0
    ["#ebdbb2", "#ebdbb2"],  # 10 # fg1
    ["#d5c4a1", "#d5c4a1"],  # 11 # fg2
    ["#bdae93", "#bdae93"],  # 12 # fg3
    ["#a89984", "#a89984"],  # 13 # fg4
    ["#cc241d", "#cc241d"],  # 14 # red hard
    ["#fb4934", "#fb4934"],  # 15 # red soft
    ["#98971a", "#98971a"],  # 16 # green hard
    ["#b8bb26", "#b8bb26"],  # 17 # green soft
    ["#d79921", "#d79921"],  # 18 # yellow hard
    ["#fabd2f", "#fabd2f"],  # 19 # yellow soft
    ["#458588", "#458588"],  # 20 # blue hard
    ["#83a598", "#83a598"],  # 21 # blue soft
    ["#b16286", "#b16286"],  # 22 # purple hard
    ["#d3869b", "#d3869b"],  # 23 # purple soft
    ["#689d6a", "#689d6a"],  # 24 # aqua hard
    ["#8ec07c", "#8ec07c"],  # 25 # aqua soft
    ["#d65d0e", "#d65d0e"],  # 26 # orange hard
    ["#FE8019", "#FE8019"],  # 27 # orange soft
    ["#a89984", "#a89984"],  # 28 # gray
    ["#928374", "#928374"],  # 29 # gray bg
]  # window name#

# Define functions for bar

widget_defaults = dict(
    font="Fira Code, NotoSans Nerd Font",
    fontsize=14,
    padding=3,
)
extension_defaults = widget_defaults.copy()


screens = [
    # vga monitor
    Screen(
        wallpaper="~/pictures/wallpapers/gruvbox/orbits.jpg",
        wallpaper_mode="fill",
        bottom=bar.Bar(
            [
                widget.Sep(
                    linewidth=0, padding=2, foreground=colors[2], background=colors[0]
                ),
                widget.Sep(  # Separator between image and group box.
                    linewidth=0, padding=0, foreground=colors[2], background=colors[0]
                ),
                widget.GroupBox(
                    fontsize=18,
                    margin_y=3,
                    margin_x=3,
                    padding_y=5,
                    padding_x=3,
                    spacing=0,
                    center_aligned=True,
                    borderwidth=0,
                    active=colors[8],
                    inactive=colors[5],
                    rounded=True,
                    highlight_color=colors[5],
                     highlight_method="block",
                    this_current_screen_border=colors[5],
                    this_screen_border=colors[5],
                    other_current_screen_border=colors[5],
                    other_screen_border=colors[5],
                    foreground=colors[8],
                    background=colors[0],
                ),
                widget.Sep(  # Separator between Groupbox and Window name.
                    linewidth=0, padding=0, foreground=colors[2], background=colors[0]
                ),
                widget.TaskList(
                    fontsize=12,
                    foreground=colors[8],
                    background=colors[0],
                    border=colors[5],
                    center_aligned=True,
                    # borderwidth=2,
                    spacing=6,
                    # margin=3,
                    margin_y=5,
                    margin_x=3,
                    # padding=3,
                    padding_y=0,
                    padding_x=3,
                    max_title_width=300,
                    highlight_color=colors[5],
                    highlight_method="block",
                    rounded=True,
                ),
                widget.Sep(  # Separator between Window name and widgets.
                    linewidth=0, padding=20, foreground=colors[2], background=colors[0]
                ),
                Spotify(
                    play_icon='',
                    pause_icon='',
                    format="{icon} {artist}:{track}",
                ),
                widget.Memory(
                    foreground=colors[8],
                    background=colors[0],
                    mouse_callbacks={
                        "Button1": lambda qtile: qtile.cmd_spawn(myTerm  )#+ " -e bpytop")
                    },
                    fmt='Mem:{}',
                    measure_mem='G',
                    padding=4,
                ),
                widget.TextBox(
                    text="󰕾", foreground=colors[8], background=colors[4], padding=0
                ),
                widget.Volume(
                    volume_up_command="amixer -q sset Master 5%+",
                    volume_down_command="amixer -q sset Master 5%-",
                    foreground=colors[8],
                    background=colors[4],
                    padding=5,
                ),
                widget.Clock(
                    foreground=colors[8],
                    background=colors[0],
                    format=" %a, %b %d %H:%M ",
                ),
                # widget.CurrentLayout(
                # foreground=colors[8], background=colors[0], padding=5
                # ),
                widget.CurrentLayoutIcon(
                    scale=True, foreground=colors[8], background=colors[0]
                ),
                widget.TextBox(
                    text="⏻",
                    foreground=colors[13],
                    font="Font Awesome 6 Free Solid",
                    fontsize=14,
                    padding=20,
                  #  mouse_callbacks={"Button1": open_powermenu},
                ),
            ],
            24,
        ),
    ),
    # hdmi monitor
        Screen(
        wallpaper="~/pictures/wallpapers/gruvbox/orbits.jpg",
        wallpaper_mode="fill",
        bottom=bar.Bar(
            [
                widget.Sep(
                    linewidth=0, padding=2, foreground=colors[2], background=colors[0]
                ),
                widget.Sep(  # Separator between image and group box.
                    linewidth=0, padding=0, foreground=colors[2], background=colors[0]
                ),
                widget.GroupBox(
                    #font="Ubuntu Bold",
                    #font="Liberation Mono Nerd",
                    fontsize=18,
                    margin_y=3,
                    margin_x=3,
                    padding_y=5,
                    padding_x=3,
                    spacing=0,
                    center_aligned=True,
                    borderwidth=7,
                    active=colors[8],
                    inactive=colors[5],
                    rounded=True,
                    highlight_color=colors[5],
                     highlight_method="block",
                    this_current_screen_border=colors[5],
                    this_screen_border=colors[5],
                    other_current_screen_border=colors[5],
                    other_screen_border=colors[5],
                    foreground=colors[8],
                    background=colors[0],
                ),
                widget.Sep(  # Separator between Groupbox and Window name.
                    linewidth=0, padding=20, foreground=colors[2], background=colors[0]
                ),
                widget.TaskList(
                    fontsize=12,
                    foreground=colors[8],
                    background=colors[0],
                    border=colors[5],
                    center_aligned=True,
                    # borderwidth=2,
                    spacing=6,
                    # margin=3,
                    margin_y=5,
                    margin_x=3,
                    # padding=3,
                    padding_y=0,
                    padding_x=3,
                    max_title_width=300,
                    highlight_color=colors[5],
                    highlight_method="block",
                    rounded=True,
                ),
                widget.Sep(  # Separator between Window name and widgets.
                    linewidth=0, padding=20, foreground=colors[2], background=colors[0]
                ),
                widget.ThermalSensor(
                    tag_sensor="Package id 0",
                    threshold=70.0,
                    foreground=colors[8],
                    background=colors[4],
                ),
                widget.Net(
                    # format=" {down} ↓↑{up}",
                    format = '  {down} ↓',
                    foreground=colors[8],
                    background=colors[0],
                ),
                widget.TextBox(
                    text=" CPU",
                    padding=2,
                    foreground=colors[8],
                    background=colors[4],
                    fontsize=14,
                ),
                widget.CPU(
                    foreground=colors[8],
                    background=colors[4],
                    padding=5,
                    format="{load_percent}%",
                    mouse_callbacks={
                        "Button1": lambda qtile: qtile.cmd_spawn(myTerm + " -e bpytop")
                    },
                ),
                widget.TextBox(
                    text=" RAM",
                    foreground=colors[8],
                    background=colors[0],
                    padding=0,
                    fontsize=14,
                ),
                widget.Memory(
                    foreground=colors[8],
                    background=colors[0],
                    mouse_callbacks={
                        "Button1": lambda qtile: qtile.cmd_spawn(myTerm + " -e bpytop")
                    },
                    padding=4,
                ),
                widget.TextBox(
                    text=" VOL", foreground=colors[8], background=colors[4], padding=0
                ),
                widget.Volume(
                    volume_up_command="amixer -q sset Master 5%+",
                    volume_down_command="amixer -q sset Master 5%-",
                    foreground=colors[8],
                    background=colors[4],
                    padding=5,
                ),
                widget.Clock(
                    foreground=colors[8],
                    background=colors[0],
                    format=" %a, %b %d %H:%M ",
                ),
                widget.CurrentLayoutIcon(
                    scale=True, foreground=colors[8], background=colors[0]
                ),
            ],
            24,
        ),
    ),


       
]


# Drag floating layouts.
mouse = [
    Drag(
        [mod],
        "Button1",
        lazy.window.set_position_floating(),
        start=lazy.window.get_position(),
    ),
    Drag(
        [mod], "Button3", lazy.window.set_size_floating(), start=lazy.window.get_size()
    ),
    Click([mod], "Button2", lazy.window.bring_to_front()),
]

dgroups_key_binder = None
dgroups_app_rules = []  # type: list
follow_mouse_focus = True
bring_front_click = False
cursor_warp = False
floating_layout = layout.Floating(
    margin=5,
    border_width=2,
    border_focus="#458588",
    border_normal="#458588",
    float_rules=[
        # Run the utility of `xprop` to see the wm class and name of an X client.
        *layout.Floating.default_float_rules,
        Match(wm_class="confirmreset"),  # gitk
        Match(wm_class="makebranch"),  # gitk
        Match(wm_class="maketag"),  # gitk
        Match(wm_class="ssh-askpass"),  # ssh-askpass
        Match(title="branchdialog"),  # gitk
        Match(title="pinentry"),  # GPG key password entry
    ],
)
auto_fullscreen = True
focus_on_window_activation = "smart"
reconfigure_screens = True

# If things like steam games want to auto-minimize themselves when losing
# focus, should we respect this or not?
auto_minimize = True

# When using the Wayland backend, this can be used to configure input devices.
wl_input_rules = None

# XXX: Gasp! We're lying here. In fact, nobody really uses or cares about this
# string besides java UI toolkits; you can see several discussions on the
# mailing lists, GitHub issues, and other WM documentation that suggest setting
# this string if your java app doesn't work correctly. We may as well just lie
# and say that we're a working one by default.
#
# We choose LG3D to maximize irony: it is a 3D non-reparenting WM written in
# java that happens to be on java's whitelist.
wmname = "LG3D"









































