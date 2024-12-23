import os
import subprocess
from libqtile import bar, layout, widget, hook, qtile 
from libqtile.config import Click, Drag, Group, Match, Key, Screen, ScratchPad, DropDown
from libqtile.lazy import lazy
from libqtile.log_utils import logger
from xcffib.xproto import EventMask

#_____variables________
mod = "mod4"
ctrl = "control"
alt = "mod1"
terminal = "kitty"
desktop_wallpaper="~/media/images/desktop_wallpapers/gruvbox/nature/forest-hut.png"
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
    home = os.path.expanduser('~/.scripts/init.sh')
    subprocess.call([home])

keys = [

#______programs hotkeys______
Key([mod], "Return", lazy.group["scratchpad"].dropdown_toggle(terminal)),
Key([mod], "r",lazy.spawn("rofi -show drun")),
Key([mod], "e",lazy.spawn("emacsclient -c")),
Key([mod], "y", lazy.group["scratchpad"].dropdown_toggle("clipgrab")),
Key([mod], "o", lazy.group["scratchpad"].dropdown_toggle("fzfmenu")),
# print screen
Key([], "Print", lazy.spawn("flameshot gui")),
# control volume
Key([mod], "equal", lazy.spawn("amixer set Master 5%+")),
Key([mod], "minus", lazy.spawn("amixer set Master 5%-")),
# control screen brightness
Key([mod, ctrl], "equal", lazy.spawn("light -A 5")),
Key([mod, ctrl], "minus", lazy.spawn("light -U 5")),
# control music player
Key([mod, "shift"], "equal", lazy.spawn("strawberry -f")),
Key([mod, "shift"], "minus", lazy.spawn("strawberry -r")),
Key([mod, "shift"], "space", lazy.spawn("strawberry -t")),
# switch between monitors and laptop screen
Key([mod, ctrl], "s", lazy.spawn("/home/mgr/.scripts/switch_screens.sh")),
# switch keyboard layout between us and spanish
Key([mod, "shift"], "l", lazy.spawn("sh /home/mgr/.scripts/switch_keyboard_layout.sh")),
Key([mod], "l", lazy.spawn("sh /home/mgr/.scripts/fzfmenu/emacsrestart.sh")),
# reload qtile config
Key([mod, ctrl], "r", lazy.reload_config(), lazy.spawn("sh /home/mgr/.scripts/keyboard_layout.sh")),
# lock screen 
Key([mod, ctrl], "l", lazy.spawn("xscreensaver-command -lock")),
# quit qtile
Key([mod, ctrl], "q", lazy.shutdown()),

# ______WINDOW_MANAGEMENT_______

# kill focused window
Key([mod], "d", lazy.window.kill()),
# move focus to next screen
# Key([mod], "k", lazy.layout.next()),
# switch between monitors
Key([mod], "space", lazy.next_screen()),
# switch between layouts
Key([mod], "Tab", lazy.next_layout()),
]

# floating_layout = layout.Floating(**layout_theme,
#     float_rules=[  # Define float rules here
#         # Example rule: Open kitty terminals with name "floating_term" as floating windows
#         Match(title="floating_term"),
#         Match(wm_class="small_popup"),
#     ],
# )

default_layout = "max"
# use xprop to see the WM_CLASS on X11
groups = [
    ScratchPad("scratchpad",[
        DropDown("fzfmenu",
                 "alacritty -e sh .scripts/fzfmenu/fzfmenu.sh",
                 x=0.045,
                 y=0.04,
                 width=0.906,
                 height=0.904,
                 opacity=0.3,
                 on_focus_lost_hide=False,
                 warp_pointer=True),
        DropDown("kitty",
                 "kitty",
                 x=0.045,
                 y=0.04,
                 width=0.906,
                 height=0.904,
                 opacity=1,
                 on_focus_lost_hide=False),
        DropDown("clipgrab",
                 "clipgrab",
                 x=0.5,
                 y=0.6,
                 width=0.5,
                 height=0.5,
                 opacity=1,
                 on_focus_lost_hide=False,),],),
    # ide
    Group("1", label="   ", layout=default_layout, matches=[
              Match(wm_class="emacs"),
              Match(wm_class="darktable")]),
    # browser
    Group("2",label=" 󰖟  ", layout=default_layout, matches=[
        Match(wm_class="brave-browser"),
        Match(wm_class="firefox-esr")]),
    # email & chat
    Group("3", label="   ", layout=default_layout, matches=[
        Match(wm_class="tutanota-desktop"),
        Match(wm_class="thunderbird"),
        Match(wm_class="whatsapp-for-linux"),
        Match(wm_class="hexchat"),
        Match(wm_class="signal"),
        Match(wm_class="net.sourceforge.liferea")]),
    Group("4", label="   ", layout=default_layout, matches=[
        Match(wm_class="freetube"),
        Match(wm_class="vlc"),
        Match(wm_class="mpv")]),
    # document viewer
    Group("5", label=" 󰈙  ", layout=default_layout, matches=[
        Match(wm_class= "calibre"),
        Match(wm_class="okular"),
        Match(wm_class="Zathura")]),
    # gui file manager
    Group("6", label="   ", layout=default_layout, matches=[
        Match(wm_class= "nemo"),
        Match(wm_class= "dolphin")]),
    # downloads
    Group("7", label="   ", layout=default_layout, matches=[
        Match(wm_class="qbittorrent"),
        Match(wm_class=".nicotine-wrapped"),
        Match(wm_class="amule" )]),
    # music
    Group("8",label="   ", layout=default_layout, matches=[
        Match(wm_class="spotify"),
        Match(wm_class="strawberry"),
        Match(wm_class="easyeffects")]),
    # virtual machines
    Group("9", label=" 󰟀  ",  layout=default_layout, matches=[
        Match(wm_class="virt-manager"),
        Match(wm_class="chromium-browser"),
        Match(wm_class="virtualbox")]),
    # misc
    Group("0", label=" 󰛄  ", layout=default_layout, matches=[
        Match(wm_class=0)]),
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
    font="Agave Nerd Font",
    fontsize=19,
    padding=3,
    # background= "#2a2a28" ,
    background= "#202020" ,
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
        wallpaper=desktop_wallpaper,
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
                    #highlight_color=yellow_hard,
                    highlight_method="block",
                    # this_current_screen_border='#b57614',
                    # this_screen_border=bg1,
                    # other_current_screen_border=bg1,
                    # other_screen_border=bg1,
                ),
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
                    length=6,
                ),

                widget.Memory(
                    fmt=' {}  ',
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
            ],
            40, #bar size
        ),
    ),
    # hdmi monitor
    Screen(
        wallpaper = desktop_wallpaper,
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
                widget.Battery(
                    format=' {percent:2.0%} {char} ',
                    charge_char ='󰂄 ',
                    discharge_char =' 󰂄 ',
                    full_char ='󰂄  ',
                    unknown_char ='󰂄',
                    update_interval = 1,
                    max_chars=60,
                ),
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
                    fmt=' {}  ',
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
            ],
            40, #bar size
        ),
    ),
]


# Drag floating layouts.
# mouse = [
#     Drag(
#         [mod],
#         "Button1",
#         lazy.window.set_position_floating(),
#         start=lazy.window.get_position(),
#     ),
#     Drag(
#         [mod], "Button3", lazy.window.set_size_floating(), start=lazy.window.get_size()
#     ),
#     Click([mod], "Button2", lazy.window.bring_to_front()),
# ]

dgroups_key_binder = None
dgroups_app_rules = []  # type: list
follow_mouse_focus = True
bring_front_click = False
cursor_warp = False

floating_layout = layout.Floating(
    margin=5,
    border_width=2,
    border_focus=green_hard,
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


auto_fullscreen = True # block/allow programs that want to be opened in full screen mode
focus_on_window_activation = "focus"
follow_mouse_focus = True;
cursor_warp = True;
reconfigure_screens = True
auto_minimize = False # block programs that want to minimize themselves when focus is lost
wl_input_rules = None
wmname = "LG3D"
