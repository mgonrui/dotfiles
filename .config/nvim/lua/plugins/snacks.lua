-- TODO make a one time exec to drop to 0 all frecency scores
-- TODO make a grep that searches both inside and outside rtp
return {
  {
    'folke/snacks.nvim', -- A collection of small QoL plugins
    priority = 1000,
    lazy = false,
    keys = {
      -- Grep inside git files
      {
        '<leader>gg',
        function()
          Snacks.picker.git_grep {
            finder = 'git_grep',
            untracked = false,
            need_search = false,
          }
        end,
        desc = 'Grep',
      },
      -- Grep
      {
        '<leader>gf',
        function()
          Snacks.picker.grep {
            -- Exclude results from grep picker
            -- I think these have to be specified in gitignore syntax
            finder = 'grep',
            exclude = { 'dictionaries/words.txt', 'Videos', 'Downloads', 'Audio', 'Pictures', 'syncthing', 'vms', '.cache', '.local', '.var' },
            rtp = false, -- Search in runtimepath
            search_dirs = { -- Also search these additional folders
              '~/', -- Config files
            },
          }
        end,
        desc = 'Grep',
      },
      -- Open git log in vertical view
      {
        '<leader>gl',
        function()
          Snacks.picker.git_log {
            finder = 'git_log',
            format = 'git_log',
            preview = 'git_show',
            confirm = 'git_checkout',
            layout = 'vertical',
          }
        end,
        desc = 'Git Log',
      },
      -- File picker
      {
        '<leader>sf',
        function()
          Snacks.picker.smart {
            finder = 'files',
            format = 'file',
            show_empty = true,
            supports_live = true,
            hidden = true, -- Show hidden files
            ignored = true, -- Show ignored files
            follow = false, -- Follow symlinks
            exclude = { 'dictionaries/words.txt', 'Videos', 'Downloads', 'Audio', 'Pictures', 'syncthing', 'vms', '.cache', '.local', '.var' },
            -- In case you want to override the layout for this keymap
            layout = 'ivy',
            matcher = {
              cwd_bonus = false,
              frecency = true,
              sort_emtpy = true,
            },
          }
        end,
        desc = 'Find Files',
      },
      -- Git picker
      {
        '<leader>sg',
        function()
          Snacks.picker.git_files {
            finder = 'git_files',
            show_empty = true,
            format = 'file',
            untracked = false,
            submodules = false,
            -- exclude = { 'dictionaries/words.txt', 'Videos', 'Downloads', 'Audio', 'Pictures', 'syncthing', 'vms', '.cache', '.local', '.var' },
            -- In case you want to override the layout for this keymap
            layout = 'ivy',
          }
        end,
        desc = 'Find Files',
      },
      {
        '<M-f>',
        function()
          Snacks.picker.keymaps {
            layout = 'vertical',
          }
        end,
        desc = 'Keymaps',
      },
      -- File picker
      {
        '<leader><space>',
        function()
          Snacks.picker.files {
            finder = 'files',
            format = 'file',
            show_empty = true,
            supports_live = true,
            -- In case you want to override the layout for this keymap
            -- layout = "vscode",
          }
        end,
        desc = 'Find Files',
      },

      -- Navigate my buffers
      {
        '<S-h>',
        function()
          Snacks.picker.buffers {
            -- I always want my buffers picker to start in normal mode
            on_show = function()
              vim.cmd.stopinsert()
            end,
            finder = 'buffers',
            format = 'buffer',
            hidden = false,
            unloaded = true,
            frecency = true,
            current = true,
            sort_lastused = true,
            win = {
              input = {
                keys = {
                  ['d'] = 'bufdelete',
                },
              },
              list = { keys = { ['d'] = 'bufdelete' } },
            },
            -- In case you want to override the layout for this keymap
            -- layout = "ivy",
          }
        end,
        desc = '[P]Snacks picker buffers',
      },
    },
    opts = {
      bigfile = { enabled = true },
      dashboard = { enabled = false },
      animations = { enabled = false },
      gitbrowse = { enabled = false },
      explorer = { enabled = false },
      indent = { enabled = true },
      lazygit = { enabled = false },
      input = { enabled = true },
      notifier = { enabled = false },
      quickfile = { enabled = true },
      image = { enabled = false },
      scope = { enabled = true },
      scroll = { enabled = false },
      statuscolumn = { enabled = true },
      words = { enabled = true },
      picker = {
        matcher = {
          frecency = true,
        },
        debug = {
          scores = true, -- show scores in the list
        },
        layout = {
          preset = 'ivy',
          cycle = false,
        },
        layouts = {
          ivy = {
            layout = {
              box = 'vertical',
              backdrop = false,
              row = -1,
              width = 0,
              height = 0.5,
              border = 'top',
              title = ' {title} {live} {flags}',
              title_pos = 'left',
              { win = 'input', height = 1, border = 'bottom' },
              {
                box = 'horizontal',
                { win = 'list', border = 'none' },
                { win = 'preview', title = '{preview}', width = 0.5, border = 'left' },
              },
            },
          },
          -- I wanted to modify the layout width
          --
          vertical = {
            layout = {
              backdrop = false,
              width = 0.8,
              min_width = 80,
              height = 0.8,
              min_height = 30,
              box = 'vertical',
              border = 'rounded',
              title = '{title} {live} {flags}',
              title_pos = 'center',
              { win = 'input', height = 1, border = 'bottom' },
              { win = 'list', border = 'none' },
              { win = 'preview', title = '{preview}', height = 0.4, border = 'top' },
            },
          },
        },
        win = {
          input = {
            keys = {
              -- to close the picker on ESC instead of going to normal mode,
              -- add the following keymap to your config
              ['<Esc>'] = { 'close', mode = { 'n', 'i' } },
              -- I'm used to scrolling like this in LazyGit
              ['J'] = { 'preview_scroll_down', mode = { 'i', 'n' } },
              ['K'] = { 'preview_scroll_up', mode = { 'i', 'n' } },
              ['H'] = { 'preview_scroll_left', mode = { 'i', 'n' } },
              ['L'] = { 'preview_scroll_right', mode = { 'i', 'n' } },
            },
          },
        },
        formatters = {
          file = {
            filename_first = true, -- display filename before the file path
            truncate = 80,
          },
        },
      },
    },
  },
}
