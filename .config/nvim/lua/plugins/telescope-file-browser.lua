-- File browser for telescope
return {
  'nvim-telescope/telescope-file-browser.nvim',
  dependencies = { 'nvim-telescope/telescope.nvim', 'nvim-lua/plenary.nvim' },
  config = function()
    local fb_actions = require 'telescope._extensions.file_browser.actions'
    require('telescope').setup {
      extensions = {
        file_browser = {

          -- Path & Directory Behavior
          path = false, -- Its dinamically assigned with the OilFB command each time the file browser is opened
          cwd_to_path = false, -- Don't force cwd as initial path

          -- Display & Filtering
          grouped = true, -- Don't group directories first
          hidden = true, -- Show hidden files (set to true to hide)
          respect_gitignore = vim.fn.executable 'fd' == 1, -- Use fd if available
          no_ignore = true, -- Don't force show gitignored files
          follow_symlinks = false, -- Follow symlinks
          hide_parent_dir = true, -- Hide ".." parent directory
          collapse_dirs = false, -- Don't collapse empty directories
          prompt_path = true,

          -- Icons & UI
          theme = 'ivy', -- open buffer in the bottom
          dir_icon = '', -- Folder icon
          dir_icon_hl = 'Default', -- Highlight group for folder icon
          display_stat = { date = true, size = true, mode = true }, -- Show file details

          -- Misc
          depth = 1, -- Initial scan depth
          auto_depth = false, -- Don't dynamically adjust depth
          use_fd = true, -- Prefer fd over find
          git_status = true, -- Show git status indicators
          hijack_netrw = false, -- Don't replace netrw by default

          -- Key mappings
          mappings = {
            ['i'] = { -- Insert mode
              ['<Tab>'] = require('telescope.actions').select_default,
              ['<C-j>'] = require('telescope.actions').move_selection_next,
              ['<C-k>'] = require('telescope.actions').move_selection_previous,
              ['<CR>'] = function(prompt_bufnr)
                local entry = require('telescope.actions.state').get_selected_entry()
                if entry == nil then -- if path does not exist
                  return fb_actions.create_from_prompt(prompt_bufnr) -- create it from prompt
                end
                for _, item in ipairs(entry) do
                  require('telescope.actions').close(prompt_bufnr)
                  item = item:gsub('/+$', ''):gsub('/[^/]+$', '') .. '/'
                  require('oil').open(item)
                end
              end,
            },
            ['n'] = { -- Normal mode
              ['h'] = fb_actions.goto_parent_dir,
              ['l'] = fb_actions.open_dir,
            },
          },
        },
      },
    }
    require('telescope').load_extension 'file_browser'
  end,
}
