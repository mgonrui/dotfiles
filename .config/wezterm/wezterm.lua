local wezterm = require("wezterm") -- Pull in the wezterm API
local config = wezterm.config_builder() -- This will hold the configuration.
local act = wezterm.action

-- UI
config.detect_password_input = true -- Censor text when typing a password
config.enable_tab_bar = true -- Enable tab bar
config.use_fancy_tab_bar = false -- Disable fancy tab bar
config.tab_bar_at_bottom = true -- Display tab bar at bottom
config.show_new_tab_button_in_tab_bar = false -- Disable new tab button
config.enable_scroll_bar = false -- Disable scroll bar
config.window_padding = { -- Window padding
	left = 6,
	right = 2,
	top = 6,
	bottom = 0,
}

-- Text rendering
config.harfbuzz_features = { "calt = 0", "clig = 0", "liga = 0" } -- Disable ligatures
config.font = wezterm.font("Iosevka Nerd Font")
config.font_size = 20
config.cell_width = 0.8
config.cursor_thickness = 1
config.underline_thickness = 2
config.line_height = 0.95
config.cell_widths = {
	{ first = 0xe000, last = 0xf8ff, width = 2 },
	{ first = 0xf0000, last = 0xf1fff, width = 2 },
}

-- Behavior
config.enable_wayland = true -- Use wayland protocol
config.term = "wezterm" -- Set TERM
config.automatically_reload_config = true -- Automatically reload config when changes are made
config.alternate_buffer_wheel_scroll_speed = 1
config.anti_alias_custom_block_glyphs = true -- Anti-aliasing makes lines look smoother but may not look so nice at smaller font sizes.
config.mouse_wheel_scrolls_tabs = false -- Disable mouse scrolling for tabs
config.mouse_bindings = {
	{
		event = { Down = { streak = 1, button = { WheelUp = 1 } } },
		action = wezterm.action.ScrollByLine(-4),
	},
	{
		event = { Down = { streak = 1, button = { WheelDown = 1 } } },
		action = wezterm.action.ScrollByLine(4),
	},
}

-- Multiplexer
config.mux_enable_ssh_agent = true
config.default_mux_server_domain = "local"
config.leader = { key = "m", mods = "CTRL", timeout_milliseconds = 2000 }
config.keys = {
	{
		mods = "LEADER",
		key = "c",
		action = wezterm.action.SpawnTab("CurrentPaneDomain"),
	},
	{
		mods = "LEADER",
		key = "x",
		action = wezterm.action.CloseCurrentPane({ confirm = true }),
	},
	{
		mods = "LEADER",
		key = "b",
		action = wezterm.action.ActivateTabRelative(-1),
	},
	{
		mods = "LEADER",
		key = "n",
		action = wezterm.action.ActivateTabRelative(1),
	},
	{
		mods = "LEADER",
		key = "/",
		action = wezterm.action.SplitHorizontal({ domain = "CurrentPaneDomain" }),
	},
	{
		mods = "LEADER",
		key = "-",
		action = wezterm.action.SplitVertical({ domain = "CurrentPaneDomain" }),
	},
	{
		mods = "LEADER",
		key = "h",
		action = wezterm.action.ActivatePaneDirection("Left"),
	},
	{
		mods = "LEADER",
		key = "j",
		action = wezterm.action.ActivatePaneDirection("Down"),
	},
	{
		mods = "LEADER",
		key = "k",
		action = wezterm.action.ActivatePaneDirection("Up"),
	},
	{
		mods = "LEADER",
		key = "l",
		action = wezterm.action.ActivatePaneDirection("Right"),
	},
	{
		mods = "LEADER",
		key = "LeftArrow",
		action = wezterm.action.AdjustPaneSize({ "Left", 5 }),
	},
	{
		mods = "LEADER",
		key = "RightArrow",
		action = wezterm.action.AdjustPaneSize({ "Right", 5 }),
	},
	{
		mods = "LEADER",
		key = "DownArrow",
		action = wezterm.action.AdjustPaneSize({ "Down", 5 }),
	},
	{
		mods = "LEADER",
		key = "UpArrow",
		action = wezterm.action.AdjustPaneSize({ "Up", 5 }),
	},
}

for i = 0, 9 do -- leader + number to activate that tab
	table.insert(config.keys, {
		key = tostring(i),
		mods = "LEADER",
		action = wezterm.action.ActivateTab(i - 1),
	})
end

-- Change behavior inside neovim
local is_in_nvim = false

local function change_behavior_inside_nvim(window) -- Function to change behavior inside neovim
	if is_in_nvim then
		config.mouse_bindings = {} -- Set default mouse bindings
	else
		config.mouse_bindings =
			{ -- Set scrolling sensitivity for Wezterm. (This will break horizontal scrolling in Neovim, that's why it must not be loaded inside it)
				{
					event = { Down = { streak = 1, button = { WheelUp = 1 } } },
					action = wezterm.action.ScrollByLine(-4),
				},
				{
					event = { Down = { streak = 1, button = { WheelDown = 1 } } },
					action = wezterm.action.ScrollByLine(4),
				},
			}
	end
	window:set_config_overrides(config) -- Apply the updated config
end

wezterm.on("update-status", function(window, pane) -- Listen for pane events to detect Neovim
	local new_nvim_state = pane:get_foreground_process_name():find("n?vim") ~= nil -- Check if the current pane is running Neovim
	if new_nvim_state ~= is_in_nvim then -- Only update if state changed
		is_in_nvim = new_nvim_state
		change_behavior_inside_nvim(window)
	end
end)

-- Color scheme (Everforest)
config.colors = {
	foreground = "#d3c6aa",
	background = "#272e33",
	cursor_bg = "#D3C6AA",
	cursor_fg = "#272E33",
	cursor_border = "#D3C6AA",
	selection_bg = "#464E53",
	ansi = {
		"#343f44", -- black
		"#E67E80", -- red
		"#A7C080", -- green
		"#DBBC7F", -- yellow
		"#7FBBB3", -- blue
		"#D699B6", -- magenta
		"#83C092", -- cyan
		"#859289", -- white
	},
	brights = {
		"#868D80", -- bright black (gray)
		"#E67E80", -- bright red
		"#A7C080", -- bright green
		"#DBBC7F", -- bright yellow
		"#7FBBB3", -- bright blue
		"#D699B6", -- bright magenta
		"#83C092", -- bright cyan
		"#9DA9A0", -- bright white
	},
	tab_bar = {
		background = "#272e33",
		active_tab = {
			fg_color = "#a7c080",
			bg_color = "#2e383c",
			intensity = "Normal",
			underline = "None",
			strikethrough = false,
		},
		inactive_tab = {
			bg_color = "#272e33",
			fg_color = "#808080",
		},
		inactive_tab_hover = {
			bg_color = "#272e33",
			fg_color = "#808080",
		},
	},
}

return config
