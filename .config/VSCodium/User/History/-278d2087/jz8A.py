import os
import subprocess
from libqtile import bar, layout, widget, hook, qtile 
from libqtile.config import Click, Drag, Group, Match, Key, Screen, ScratchPad, DropDown
from libqtile.lazy import lazy
from libqtile.command import lazy
from libqtile.log_utils import logger


mod = "mod4"  # super key
alt = "mod1"
terminal = "kitty"
# colors
bone         = "#c5aa7f"
bg0          = "#282828" 
bg0_h        = "#1d2021" 
bg0_s        = "#32302f" 
bg1          = "#3c3836" 
bg2          = "#504945" 
bg3          = "#665c54" 
bg4          = "#7c6f64" 
fg           = "#ebdbb2" 
fg0          = "#fbf1c7" 
fg1          = "#ebdbb2" 
fg2          = "#d5c4a1" 
fg3          = "#bdae93" 
fg4          = "#a89984" 
red_hard     = "#cc241d" 
red_soft     = "#fb4934" 
green_hard   = "#98971a" 
green_soft   = "#b8bb26" 
yellow_hard  = "#d79921" 
yellow_soft  = "#fabd2f" 
blue_hard    = "#458588" 
blue_soft    = "#83a598" 
purple_hard  = "#b16286" 
purple_soft  = "#d3869b" 
aqua_hard    = "#689d6a" 
aqua_soft    = "#8ec07c" 
orange_hard  = "#d65d0e" 
orange_soft  = "#FE8019" 
gray         = "#a89984" 
gray_bg      = "#928374" 


# run script for setting configurations and opening programs at start
@hook.subscribe.startup_once
def autostart():
    logger.warning("In autostart function")
    home = os.path.expanduser('/home/mgr/.scripts/autostart.sh')
    subprocess.call([home])

@lazy.window.function 
def resize_floating_window(window, width: int = 0, height: int = 0): 
    window.cmd_set_size_floating(window.width + width, window.height + height),


keys = [

#______programs hotkeys______
Key([mod], "l", resize_floating_window(width=10), desc='increase width by 10'),
Key([mod], "h", resize_floating_window(width=-10), desc='decrease width by 10'), 
Key([mod], "j", resize_floating_window(height=10), desc='increase height by 10'), 
Key([mod], "k", resize_floating_window(height=-10), desc='decrease height by 10'),
# scratchpad shortcuts
Key([mod], "Return", lazy.group["scratchpad"].dropdown_toggle(terminal)),
Key([mod], "x",lazy.spawn("xterm -class float -geometry 80x40 -e sh .scripts/menu/menu.sh")),
Key([mod], "y", lazy.group["scratchpad"].dropdown_toggle("clipgrab")),
# print screen
Key([], "Print", lazy.spawn("flameshot gui")),


#______system_____

# control volume up and down
Key([mod], "equal", lazy.spawn("amixer set Master 5%+")),
Key([mod], "minus", lazy.spawn("amixer set Master 5%-")),
Key([mod, "shift"], "equal", lazy.spawn("strawberry -f")),
Key([mod, "shift"], "minus", lazy.spawn("strawberry -r")),
Key([mod, "shift"], "space", lazy.spawn("strawberry -t")),
# switch between monitors and laptop screen
Key([mod, "control"], "s", lazy.spawn("/home/mgr/.scripts/switch_screens.sh")),
# switch keyboard layout between us and spanish
Key([mod, "shift"], "l", lazy.spawn("sh /home/mgr/.scripts/switch_keyboard_layout.sh")),
# reload qtile config
Key([mod, "control"], "r", lazy.reload_config()),
# lock screen 
Key([mod, "control"], "l", lazy.spawn("xscreensaver-command -lock")),
# quit qtile
Key([mod, "control"], "q", lazy.shutdown()),

# ______EXEC_SCRIPTS______


# ______WINDOW_MANAGEMENT_______

# kill focused window
Key([mod], "d", lazy.window.kill()),
# move focus to next screen
# Key([mod], "k", lazy.layout.next()),
# switch between monitors
Key([mod], "space", lazy.next_screen()),
# switch between layouts
Key([mod], "Tab", lazy.next_layout()),

# # A list of available commands that can be bound to keys can be found
# # at https://docs.qtile.org/en/latest/manual/config/lazy.html
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
# floating_layout = layout.Floating(**layout_theme,
#     float_rules=[  # Define float rules here
#         # Example rule: Open kitty terminals with name "floating_term" as floating windows
#         Match(title="floating_term"),
#         Match(wm_class="small_popup"),
#     ],
# )

default_layout = "max"
# use xprop to see the WM_CLASS
groups = [
    ScratchPad("scratchpad",[
        # DropDown("kitty","kitty",x=0.025,y=0.025,width=0.99,height=0.99,opacity=1,on_focus_lost_hide=False,),
        # DropDown("fzf",terminal,x=0.025,y=0.025,width=0.95,height=0.95,opacity=1,on_focus_lost_hide=False,),
        # DropDown("kitty","kitty",opacity=1,on_focus_lost_hide=False,),
        DropDown("xterm", "xterm -class float -e sh .scripts/menu/menu.sh",x=0.15,y=0.1,width=0.7,height=0.7,opacity=1,on_focus_lost_hide=True, warp_pointer=True),
        DropDown("kitty","kitty",x=-0,y=0.002,width=0.996,height=0.994,opacity=1,on_focus_lost_hide=False),
        DropDown("clipgrab","clipgrab",x=0.5,y=0,width=0.5,height=0.5,opacity=1,on_focus_lost_hide=False,),
    ],),
    # calendar
    # Group("s", label="   ", matches=[Match(wm_class="chromium-browser")], layout=default_layout),
    # web browser
    Group("w",label=" 󰖟  ", matches=[Match(wm_class="firefox" "librewolf" "brave-browser" "Tor Browser" "liferea")],layout=default_layout),
    # text editor
    Group("i", label="   ", matches=[Match(wm_class="vscodium" "emacs" "ghidra-Ghidra")], layout=default_layout),
    # notes 
    Group("n", label=" 󰠮  ", matches=[Match(wm_class="trilium notes" "joplin-desktop" "qownnotes" "libreoffice")], layout=default_layout),
    # file manager
    Group("f", label="   ", matches=[Match(wm_class="nemo" "dolphin"  "calibre" "Zathura" "okular" "mpv")], layout=default_layout),
    # email & chat
    Group("e", label="   ", matches=[Match(wm_class= "tutanota-desktop" "thunderbird" "hexchat" "signal")], layout=default_layout),
    # password manager
    Group("p", label=" 󰌾  ", matches=[Match(wm_class= "bitwarden" "authenticator" "seahorse" "keepassxc")], layout=default_layout),
    # music
    Group("m",label="   ",matches=[Match(wm_class="spotify" "strawberry" ".nicotine-wrapped" "easyeffects")], layout=default_layout),
    # virtual machines
    Group("v", label=" 󰟀  ", matches=[Match(wm_class="virt-manager" "chromium-browser" "virtualbox")], layout=default_layout),
    # torrents
    Group("t", label="   ", matches=[Match(wm_class="qbittorrent" "amule" )], layout=default_layout),
    # misc
    Group("q", label=" 󰛄  ", matches=[Match(wm_class=0)], layout=default_layout),
]


for i in groups:
    # set hotkeys switch to groups so they use the first letter of their name
    keys.append(
        Key([mod], i.name[0], lazy.group[i.name].toscreen())
    )
    # move selected window to certain group
    keys.append(
        Key([mod, "shift"], i.name[0], lazy.window.togroup(i.name))
    )


# borders colors and margins
def init_layout_theme():
    return {
        "margin": 3,
        "border_width": 2,
        # "border_focus": "#b57614",
        "border_focus": bone,
        "border_normal": "#282828",
    }


layout_theme = init_layout_theme()


layouts = [
    layout.Max(**layout_theme),
    layout.VerticalTile(**layout_theme),
    # interesting layouts
    #layout.MonadTall(**layout_theme),

    # not so interesting layouts
    # layout.Columns(border_focus_stack=["#d75f5f", "#8f3d3d"], border_width=4),
    # layout.TreeTab(**layout_theme), 
    # layout.Zoomy(**layout_theme),
    #  layout.Floating(**layout_theme),
    # floating_layout,
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





# default widget settings
widget_defaults = dict(
    font="3270 Nerd Font",
    fontsize=21,
    padding=3,
    background= "#2a2a28" ,
    foreground=bone,
    this_current_screen_border=bone,
    this_screen_border=bone,
    other_current_screen_border=bg1,
    other_screen_border=bg1,
    mouse_callbacks={
            "Button1":lazy.spawn(),    # left click
            "Button2":lazy.spawn(),    # middle click
            "Button3":lazy.spawn(),    # right click
            "Button4":lazy.spawn(),    # scroll up
            "Button5":lazy.spawn(),    # scroll down
            "Button6":lazy.spawn(),    # scroll left
            "Button7":lazy.spawn(),    # scroll right
    },
)
extension_defaults = widget_defaults.copy()


screens = [
    # vga monitor
    Screen(
        wallpaper="~/media/images/desktop_wallpapers/gruvbox/orbits_cropped.jpg",
        wallpaper_mode="fill",
        top=bar.Bar(
            [
                widget.GroupBox(
                    fontsize=22,
                    # bar alignment
                    margin_y=3,
                    margin_x=3,
                    padding_y=5,
                    # separation between groups
                    padding_x=5,
                    spacing=3,
                    center_aligned=True,
                    borderwidth=0,
                    active=fg0,
                    inactive=bg4,
                    rounded=True,
                    use_mouse_wheel=False,
                    disable_drag=True,
                    mouse_callbacks={
                        "Button1":lazy.spawn(),    # left click
                        "Button2":lazy.spawn(),    # middle click
                        "Button3":lazy.spawn(),    # right click
                        "Button4":lazy.spawn(),    # scroll up
                        "Button5":lazy.spawn(),    # scroll down
                        "Button6":lazy.spawn(),    # scroll left
                        "Button7":lazy.spawn(),    # scroll right
                    },
                    #highlight_color=yellow_hard,
                    highlight_method="block",
                    # this_current_screen_border='#b57614',
                    # this_screen_border=bg1,
                    # other_current_screen_border=bg1,
                    # other_screen_border=bg1,
                ),
                # widget.TaskList(
                #     padding_y=3,
                #     padding_x=12,
                #     margin_y=9,
                #     margin_x=3,
                #     spacing=6,
                #     borderwidth=9,
                #     # max_title_width=10,
                #     center_aligned=True,
                #     fontsize=0,
                #     icon_size=22,
                #     foreground=green_hard,
                #     border=bg0,
                #     # margin=3,
                #     # padding=3,
                #     highlight_color=bg0,
                #     highlight_method="block",
                #     rounded=True,
                # ),
                widget.Spacer(
                ),
                widget.Volume(
                    fmt='{} 󰕾 ',
                ),
                widget.Spacer(
                    length=15,
                ),
                widget.KeyboardLayout (
                    fmt = "{} 󰌓 ",
                ),
                # widget.Spacer(
                # ),
                # widget.Bluetooth(
                #     hci0='/org/bluez/hci0/dev_20_74_CF_95_6D_8D',
                #     padding=10,
                #     linewidth=0,
                #     background=bg0,
                #     foreground=green_hard,
                # ),
                # widget.Wlan(
                #
                #     format='{essid} {percent:2.0%}',
                # ),
                # widget.Net(
                #     format='{down} 󰤨 ',
                #     background=bg0,
                #     foreground=green_hard,
                # ),
                widget.Spacer(
                    length=14,
                ),
                widget.Battery(
                    format='{percent:2.0%} {char}',
                    charge_char ='󰂄 ', 
                    discharge_char ='󰁹 ',
                    full_char ='󰁹 ',
                    unknown_char ='󰂄 ',
                    update_interval = 1,
                ),
                widget.Spacer(
                    length=5,
                ),

                widget.Memory(
                    fmt=' {}  ',
                    measure_mem='G',
                    format='{MemUsed:.0f}{mm}',
                    padding=4,
                ),
                
                widget.Spacer(
                    length=10,
                ),

                widget.Clock(
                    format=" %a, %b %d 󰃵   %H:%M 󱑂  ",
                ),
                widget.Spacer(
                    length=10,
                ),
                
                # widget.CurrentLayoutIcon(
                #     scale=1,
                #     background=bg0,
                # ),

            ],
            40, #bar size
        ),
    ),
    # hdmi monitor
    Screen(
        wallpaper="~/media/images/desktop_wallpapers/gruvbox/orbits_cropped.jpg",
        wallpaper_mode="fill",
        top=bar.Bar(
            [
                widget.GroupBox(
                    fontsize=21,
                    # bar alignment
                    margin_y=3,
                    margin_x=3,
                    padding_y=5,
                    # separation between groups
                    padding_x=5,
                    spacing=3,
                    center_aligned=True,
                    borderwidth=0,
                    active=fg0,
                    inactive=bg4,
                    rounded=True,
                    use_mouse_wheel=False,
                    disable_drag=True,
                    mouse_callbacks={
                        "Button1":lazy.spawn(),    # left click
                        "Button2":lazy.spawn(),    # middle click
                        "Button3":lazy.spawn(),    # right click
                        "Button4":lazy.spawn(),    # scroll up
                        "Button5":lazy.spawn(),    # scroll down
                        "Button6":lazy.spawn(),    # scroll left
                        "Button7":lazy.spawn(),    # scroll right
                    },
                    #highlight_color=yellow_hard,
                    highlight_method="block",
                    # this_current_screen_border='#b57614',
                    # this_screen_border=bg1,
                    # other_current_screen_border=bg1,
                    # other_screen_border=bg1,
                ),
                # widget.TaskList(
                #     padding_y=3,
                #     padding_x=12,
                #     margin_y=9,
                #     margin_x=3,
                #     spacing=6,
                #     borderwidth=9,
                #     # max_title_width=10,
                #     center_aligned=True,
                #     fontsize=0,
                #     icon_size=22,
                #     foreground=green_hard,
                #     border=bg0,
                #     # margin=3,
                #     # padding=3,
                #     highlight_color=bg0,
                #     highlight_method="block",
                #     rounded=True,
                # ),
                widget.Spacer(
                ),
                # Spotify(
                #     max_chars=40,
                #     play_icon=' ',
                #     pause_icon=' ',
                #     format="{icon} {artist}:{track}",
                # ),
                widget.KeyboardLayout (
                    fmt = "{} 󰌓 ",
                ),
                # widget.Bluetooth(
                #     hci0='/org/bluez/hci0/dev_20_74_CF_95_6D_8D',
                #     padding=10,
                #     linewidth=0,
                #     background=bg0,
                #     foreground=green_hard,
                # ),
                # widget.Wlan(
                #
                #     format='{essid} {percent:2.0%}',
                # ),
                # widget.Net(
                #     format='{down} 󰤨 ',
                #     background=bg0,
                #     foreground=green_hard,
                # ),
                # widget.Battery(
                #     format='{percent:2.0%} {char}',
                #     charge_char ='󰂄 ', 
                #     discharge_char ='󰁹 ',
                #     full_char ='󰁹 ',
                #     unknown_char ='󰂄',
                #     update_interval = 1,
                #     max_chars=5,
                # ),
                widget.Spacer(
                    length=10,
                ),
                widget.Volume(
                    fmt='{} 󰕾 ',
                ),
                widget.Spacer(
                    length=10,
                ),
                widget.Memory(
                    fmt=' {}  ',
                    measure_mem='G',
                    format='{MemUsed:.0f}{mm}',
                    padding=4,
                ),
                
                widget.Spacer(
                    length=10,
                ),

                widget.Clock(
                    format=" %a, %b %d 󰃵   %H:%M 󱑂  ",
                ),
                widget.Spacer(
                    length=10,
                ),
                
                # widget.CurrentLayoutIcon(
                #     scale=1,
                #     background=bg0,
                # ),

            ],
            40, #bar size
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
    border_focus=bone,
    border_normal=bg0,
    float_rules=[
        # Run the utility of `xprop` to see the wm class and name of an X client.
        Match(wm_class="confirmreset"),  # gitk
        Match(wm_class="makebranch"),  # gitk
        Match(wm_class="maketag"),  # gitk
        Match(wm_class="ssh-askpass"),  # ssh-askpass
        Match(title="branchdialog"),  # gitk
        Match(title="pinentry"),  # GPG key password entry
        Match(wm_class="float-term"),
    ],
)
auto_fullscreen = True
focus_on_window_activation = "smart"
reconfigure_screens = True

# If things like steam games want to auto-minimize themselves when losing
# focus, should we respect this or not?
auto_minimize = False

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
