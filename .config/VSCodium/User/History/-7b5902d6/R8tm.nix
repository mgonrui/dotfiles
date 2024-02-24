# Edit this configuration file to define what should be installed on
# your system.  Help is available in the configuration.nix(5) man page
# and in the NixOS manual (accessible by running ‘nixos-help’).

{ config, lib, pkgs, ... }:




{
imports =
    [ # Include the results of the hardware scan.
    ./hardware-configuration.nix
#      ./packages.nix
    /home/mgr/.config/hosts.nix
    <home-manager/nixos>
    ];
boot.blacklistedKernelModules = [
"amdgpu"
"radeon"
];
boot.kernelParams = ["amdgpu.blacklist=1"];
boot = {
    supportedFilesystems = [ "ntfs" ]; # enable ntfs
    loader = {
    # EFI bootloader
		efi.canTouchEfiVariables = true;
        systemd-boot = {
		enable =true;
		configurationLimit = 10; # limit the latest config files saved
	};
    timeout = 5;	
    };
};
	
	nix = {
		settings.auto-optimise-store = true;
		gc = {
			automatic = true;
			dates = "weekly";
			options = "--delete-older-than-7d";
		};
	};

	system.autoUpgrade = {
	enable = true;
	channel= "https://nixos.org/channels/nixos-23.05";
	};

hardware.bluetooth.enable = true;
services = {
    locate.enable = true;
    power-profiles-daemon.enable = false;
    tlp.enable = true; 
    blueman.enable = true; # Enable bluetooth
    printing.enable = true; # Enable CUPS to print documents.
    logind.lidSwitchExternalPower = "ignore"; # dont suspend the laptop when closing the lid with AC power on
    xserver = {
		layout = "us"; # keymap in x11
		xkbVariant = ""; # keymap in x11
	enable = true;
	videoDrivers = [ "intel" ];
	deviceSection = ''
		Option "DRI" "2"
		Option "TearFree" "true"
	'';
	windowManager = {
		qtile = {
			enable = true;
			backend = "x11";
			# backend = "wayland";
		};
	};
	displayManager = {
		defaultSession = "none+qtile";
		#sddm.enable = true;
		lightdm.enable = true;
	};
	desktopManager = {
		plasma5.enable = true;
		xfce.enable = true;
	};
    };
};


networking = {
	hostName = "nixos"; # Define your hostname.
	# wireless.enable = true;  # Enables wireless support via wpa_supplicant.
	networkmanager.enable = true;
	# interfaces = {
	# };
	# defaultGateway = "";
	# nameservers = [""];
	# Configure network proxy if necessary
	# proxy = {
	# default = "http://user:password@proxy:port/";
	# noProxy = "127.0.0.1,localhost,internal.domain";
	# };
	firewall = {
	enable = true;
	};
};


# Set your time zone.
time.timeZone = "Europe/Madrid";

# Select internationalisation properties.
i18n.defaultLocale = "en_US.UTF-8";

i18n.extraLocaleSettings = {
    LC_ADDRESS = "es_ES.UTF-8";
    LC_IDENTIFICATION = "es_ES.UTF-8";
    LC_MEASUREMENT = "es_ES.UTF-8";
    LC_MONETARY = "es_ES.UTF-8";
    LC_NAME = "es_ES.UTF-8";
    LC_NUMERIC = "es_ES.UTF-8";
    LC_PAPER = "es_ES.UTF-8";
    LC_TELEPHONE = "es_ES.UTF-8";
    LC_TIME = "es_ES.UTF-8";
};

# mount external drives
fileSystems."/run/media/mgr/toshiba1Tb" ={ 
	device = "/dev/disk/by-uuid/c404f546-ed1d-4c12-80f4-7d8dc30aa5cb";
	fsType = "ext4";
	options = [ "nofail" ];
};


environment.plasma5.excludePackages = with pkgs.libsForQt5; [
elisa
gwenview
oxygen
khelpcenter
konsole
plasma-browser-integration
print-manager
];

    # Enable sound with pipewire.
sound.enable = true;
hardware.pulseaudio.enable = false;
security.rtkit.enable = true;
services.pipewire = {
    enable = true;
    alsa.enable = true;
    alsa.support32Bit = true;
    pulse.enable = true;
    # If you want to use JACK applications, uncomment this
    #jack.enable = true;

    # use the example session manager (no others are packaged yet so this is enabled by default,
    # no need to redefine it in your config for now)
    #media-session.enable = true;
};

# Enable touchpad support (enabled default in most desktopManager).
# services.xserver.libinput.enable = true;

# Set up zsh 
programs.zsh.enable = true;
users.defaultUserShell = pkgs.zsh;
programs.wireshark.enable = true;

virtualisation = {
	libvirtd.enable = true; # enable qemu 
	docker.enable = true; # enable docker
};
programs.dconf.enable = true; # enable qemu


users.groups.mlocate.gid =1000;
users.groups.plocate.gid =1001;
# Define a user account. Don't forget to set a password with ‘passwd’.
users.users.mgr = {
    isNormalUser = true;
    extraGroups = [ "networkmanager" "plocate" "libvirtd" "docker" "mlocate" "wheel" "wireshark" "video" "audio" "lp" "scanner" ];
    };

# programs installed
environment.systemPackages = with pkgs; [ 
# langs
	python3
	nodejs_20
	perl
	perl536Packages.CPAN
	rubyPackages_3_2.gdk_pixbuf2
	php
	julia_18-bin
	luajitPackages.luarocks
	luajitPackages.jsregexp
	rubyPackages_3_2.glib2
	ruby
	rustc
	python310Packages.pip
	go
	glib
# c compiler
	llvmPackages_rocm.clang-unwrapped
	clang-tools
	gccgo13
# terminal
	zsh # shell
	kitty # terminal emulator 
	alacritty # terminal emulator
	rxvt-unicode-unwrapped-emoji # terminal emulator
# cli programs
	qmk # keyboard configuration
	p7zip # decompress 7zip files
	python310Packages.dbus-next
	lm_sensors # Tools for reading hardware sensors
	vim # text editor
	neovim # text editor
	autoconf
	bear # clangd compilation database generator
	libtool
	inotify-tools # monitor filesystem events
	gvfs
	fzf # standard output fuzzy finder
	findutils # find utilities
	xss-lock # timer lock utility
	coreutils # gnu core utilities
	util-linux # linux utilities
	lnch # processor launcer
	newsboat # rss client
	gnupg # gnu pgp encryption tool
	czkawka # identify duplicate files
	# fdupes # identify duplicate files
	libglibutil
	speedtest-cli # net speed test
	surfraw # cli browser utility
	browsh # graphical cli web browser
	w3m # web browser
	lynx # web browser
	wmctrl
	xorg.xhost
	distrobox # make linux system containers
	plocate
	xkbd # keyboard management
	xorg.xkbcomp # keyboard management
	dfeet
	lshw
	pciutils
	xorg.xbacklight
	cmake
	xdg-ninja # script for checking unwanted files in homedir
	xdg-utils
	powertop
	zip # basic zip utility
	unzip # basic unzip utility
	screen
	sysfsutils
	killall # basic killall utility
	xcolor #  hex code viewer
	docker # make containers
#	nur.repos.vanilla.fastfetch
	git
	file
	android-tools # adb 
	appimage-run # run appimages
	imagemagick # basic image manipulator
	libsecret
	htop # basic proccessing monitor
	calc # calculator
	bc
	eww
	cargo
	bitwarden-cli # password manager
	ripgrep
	curl
	tlp
	neofetch # the most essential program in any linux distro
	dpkg
# qtile
	python310Packages.qtile-extras
	python310Packages.pytest
	python310Packages.pygobject3
	python310Packages.pyvirtualdisplay
	libnotify
	gtk-layer-shell
	mypy
# gui programs
	emacs 
	ventoy-full # usb booting tool
	firefox # web browser
	#chromium # web browser
	ungoogled-chromium # web browser
	drawio # create diagrams
	palemoon-bin  # web browser
	midori # web browser
	tor-browser-bundle-bin #web browser
	brave # web browser
	librewolf # web browser
	nomacs # image viewer
	darktable # image manipulator
	gimp # image manipulator
	ghidra-bin # reverse engineering software
	wireshark # packet analyzer
	gparted # disk management
	libreoffice-still # office suite
	okular # pdf viewer
	zathura # minimal pdf viewer
	girara
	meson 
	poppler
	tabbed # add tabs to zathura
	nextcloud27 # cloud suite
	nextcloud-client # nextcloud lient (duh)
	#quiterss # rss client
	mupdf # pdf viewer
	vscodium # text editor
	cpufrequtils 
	strawberry # music player
	nicotine-plus # soulseek client
	amule # p2p file sharing
	hexchat # IRC client
	spotifywm # music streaming platform
	thunderbird # mail client
	gtk2fontsel # font viewer
	wlroots
	python310Packages.xkbcommon
	python310Packages.pywayland
	virt-manager # virtual machine manager
	virtualbox # virtual machine manager and hypervisor
	arduino # arduino software
	libgnome-keyring # system password management
	signal-desktop # messaging 
	python310Packages.pywlroots
	mpv # media player
	obsidian # note-taking 
	qownnotes # note taking 
	logseq # note-taking 
	redshift # warm monitor light
	clipgrab # grab videos from the web
	flameshot # screenshots
	dmenu # standard output fuzzy finder
	#dmenu-rs #dmenu built in rust
	xprompt # standard output fuzzy finder
	#rofi # program launcher
	rofi-power-menu # power options launcher
	calibre # ebook management 
	keepassxc # offline password manager
	bitwarden # online password manager
	betterlockscreen # screen locker
	i3lock-color # screen locker
	syncthing # sync between devices
	anki # flashcards
	#easyeffects # audio manipulation
	qbittorrent # torrent client
# neovim dependencies
	xclip
	lazygit
	vimPlugins.nvim-treesitter-parsers.regex
#idk
	fd
	gnumake
	automake
	dunst
	python310Packages.pytest
	xvfb-run
	gtk-layer-shell
	dbus
	python310Packages.pygobject3
	hexyl
	nix-index
	python310Packages.pyvirtualdisplay
	#picom
	gtk3
	gtk-layer-shell
	pango
	pkg-config
	libgccjit
	glibc
	ntfs3g
	libsForQt5.dolphin
	cairo
	bitwarden-menu
	rofi-rbw
	xdotool
	lsof
	libsForQt5.qt5ct
	libsForQt5.kde-cli-tools
    ];

# enviroment variables
environment.sessionVariables = rec {
	BROWSER = "firefox"; # default browser
	GNUPGHOME = "$HOME/.config/gnupg"; # gnupg config path
	EDITOR = "codium"; # default editor
	QT_QPA_PLATFORMTHEME = "qt5ct";  #qt theming
	XDG_DATA_HOME = "$HOME/.local/share"; 
	XDG_CONFIG_HOME ="$HOME/.config"; # set default config path
	XDG_CACHE_HOME = "$HOME/.cache"; # set default cache path
	XDG_STATE_HOME = "$HOME/.local/state"; # set default cache path
	# changing variables for config files
	CARGO_HOME = "$XDG_DATA_HOME/cargo";
	ANDROID_HOME = "$XDG_DATA_HOME/android";
	GTK2_RC_FILES = "$XDG_CONFIG_HOME/gtk-2.0/gtkrc";
	_JAVA_OPTIONS="-Djava.util.prefs.userRoot=$XDG_CONFIG_HOME/java";
	XCOMPOSECACHE = "$XDG_CACHE_HOME/X11/xcompose";
	ERRFILE = "$XDG_CACHE_HOME/X11/xsession-errors";
	HISTFILE="$XDG_STATE_HOME/zsh/history";
	ZDOTDIR="$HOME/.config/zsh";
};
# enable graphical interface for distrobox
environment.shellInit = ''
    [ -n "$DISPLAY" ] && xhost +si:localuser:$USER || true
'';

# fonts
fonts.fonts = with pkgs; [
cascadia-code
fira-code
fira-code-symbols
noto-fonts
noto-fonts-cjk
noto-fonts-emoji
liberation_ttf
mplus-outline-fonts.githubRelease
dina-font
proggyfonts
nerdfonts
ultimate-oldschool-pc-font-pack
terminus_font
cozette
fixedsys-excelsior
#   (nerdfonts.override { fonts = [ "FiraCode" "DroidSansMono" ]; })
];


# Allow unfree packages
nixpkgs.config = {
	# allow nonfree packages
	allowUnfree = true;
	# allow nur packages
	packageOverrides = pkgs: rec{
		nur = import (builtins.fetchTarball "https://github.com/nix-community/NUR/archive/master.tar.gz") {
			inherit pkgs;
		};
	};
};
# List packages installed in system profile. To search, run:
# $ nix search <package>

# Some programs need SUID wrappers, can be configured further or are
# started in user sessions.
# programs.mtr.enable = true;
# programs.gnupg.agent = {
#   enable = true;
#   enableSSHSupport = true;
# };

# List services that you want to enable:

# Enable the OpenSSH daemon.
# services.openssh.enable = true;

# Open ports in the firewall.
# networking.firewall.allowedTCPPorts = [ ... ];
# networking.firewall.allowedUDPPorts = [ ... ];
# Or disable the firewall altogether.
# networking.firewall.enable = false;

# This value determines the NixOS release from which the default
# settings for stateful data, like file locations and database versions
# on your system were taken. It‘s perfectly fine and recommended to leave
# this value at the release version of the first install of this system.
# Before changing this value read the documentation for this option
# (e.g. man configuration.nix or on https://nixos.org/nixos/options.html).
system.stateVersion = "23.05"; # Did you read the comment?

}
