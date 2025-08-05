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
config.color_scheme = "Everforest Dark Hard (Gogh)" -- Color scheme
config.window_padding = { -- Window padding
	left = 6,
	right = 2,
	top = 6,
	bottom = 0,
}

-- Text rendering
config.font = wezterm.font("Iosevka Nerd Font")
config.font_size = 20
config.cell_width = 0.8
config.cursor_thickness = 1
config.underline_thickness = 2
config.line_height = 1
config.cell_widths = {
	{ first = 0xe000, last = 0xf8ff, width = 2 },
	{ first = 0xf0000, last = 0xf1fff, width = 2 },
}

-- Behavior
config.enable_wayland = true -- Use wayland protocol
config.term = "wezterm" -- Set TERM env var
config.automatically_reload_config = true -- Automatically reload config when changes are made
config.alternate_buffer_wheel_scroll_speed = 1
config.anti_alias_custom_block_glyphs = true -- Anti-aliasing makes lines look smoother but may not look so nice at smaller font sizes.

-- Mux
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

-- Mouse bindings
config.mouse_bindings = {
	{
		event = { Down = { streak = 1, button = { WheelUp = 1 } } },
		mods = "NONE",
		action = act.ScrollByLine(-4), -- Change the scroll down sensitivity to move 4 rows each step
	},
	{
		event = { Down = { streak = 1, button = { WheelDown = 1 } } },
		mods = "NONE",
		action = act.ScrollByLine(4), -- Change the scroll up sensitivity to move 4 rows each step
	},
}

config.colors = {
	tab_bar = {
		background = "#272e33",
		active_tab = {
			bg_color = "#272e33",
			fg_color = "#d3c6aa",
			intensity = "Normal",
			underline = "None",
			italic = false,
			strikethrough = false,
		},
		inactive_tab = {
			bg_color = "#1e2326",
			fg_color = "#808080",
		},
		inactive_tab_hover = {
			bg_color = "#374145",
			fg_color = "#909090",
			italic = true,
		},
	},
}
return config
