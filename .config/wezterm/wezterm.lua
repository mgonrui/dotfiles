local wezterm = require("wezterm") -- Pull in the wezterm API
local config = wezterm.config_builder() -- This will hold the configuration.
local act = wezterm.action
local colors, metadata = wezterm.color.load_scheme("/home/deckard/.config/wezterm/colorscheme.toml") -- Get scheme from toml

-- UI
config.detect_password_input = true -- Censor text when typing a password
config.enable_tab_bar = true -- Enable tab bar
config.use_fancy_tab_bar = false -- Disable fancy tab bar
config.tab_bar_at_bottom = false -- Display tab bar at bottom
config.show_new_tab_button_in_tab_bar = false -- Disable new tab button
config.enable_scroll_bar = false -- Disable scroll bar
config.colors = colors -- Load scheme
config.window_padding = { -- Window padding
	left = 6,
	right = 2,
	top = 6,
	bottom = 0,
}

-- Text rendering
config.harfbuzz_features = { "calt = 0", "clig = 0", "liga = 0" } -- Disable ligatures
config.font = wezterm.font("Iosevka Nerd Font")
-- config.font = wezterm.font("VictorMono Nerd Font")
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
config.term = "wezterm" -- Set TERM
config.automatically_reload_config = true -- Automatically reload config when changes are made
config.alternate_buffer_wheel_scroll_speed = 1
config.anti_alias_custom_block_glyphs = true -- Anti-aliasing makes lines look smoother but may not look so nice at smaller font sizes.
config.mouse_wheel_scrolls_tabs = false -- Disable mouse scrolling for tabs
config.window_close_confirmation = "NeverPrompt" -- Disable confirmation prompt when trying to close wezterm
config.bypass_mouse_reporting_modifiers = "ALT" -- Key to prevent mouse events from being passed to programs.
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

config.leader = { key = "RightAlt", mods = "NONE", timeout_milliseconds = 2000 }

wezterm.on("update-right-status", function(window, pane)
	local leader = ""
	if window:leader_is_active() then
		leader = wezterm.format({
			{ Attribute = { Intensity = "Bold" } },
			{ Foreground = { Color = "#E67E80" } },
			{ Text = "LEADER" },
			"ResetAttributes",
			{
				Text = "                                                                                                                                                                   ",
			},
		})
	end
	window:set_right_status(leader)
end)

config.keys = {
	{
		mods = "LEADER",
		key = "t",
		action = wezterm.action.SpawnTab("CurrentPaneDomain"),
	},
	{
		mods = "LEADER",
		key = "w",
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

return config
