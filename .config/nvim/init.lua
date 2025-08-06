require 'core.options'
require 'core.mappings'
require 'core.autocmd'

local function show_diagnostic_float()
  local diagnostics = vim.diagnostic.get(0, { lnum = vim.api.nvim_win_get_cursor(0)[1] - 1 })
  if #diagnostics == 0 then
    return
  end

  vim.diagnostic.open_float {
    scope = 'line',
    focusable = false,
    border = 'rounded',
    header = '',
    prefix = function(diagnostic, i, total)
      -- Safely handle the severity conversion
      local severity = diagnostic.severity and vim.diagnostic.severity[diagnostic.severity] or nil

      local icons = {
        [vim.diagnostic.severity.ERROR] = ' ',
        [vim.diagnostic.severity.WARN] = ' ',
        [vim.diagnostic.severity.INFO] = ' ',
        [vim.diagnostic.severity.HINT] = ' ',
      }

      -- Default to empty string if severity is unknown
      return icons[severity] or ''
    end,
  }
end
vim.api.nvim_create_autocmd('CursorHold', {
  callback = show_diagnostic_float,
})

-- Also show when we first move to a line with diagnostic
vim.api.nvim_create_autocmd('CursorMoved', {
  callback = function()
    -- Small delay to prevent flickering
    vim.defer_fn(show_diagnostic_float, 50)
  end,
})

vim.api.nvim_create_user_command('OilFB', function()
  require('telescope').extensions.file_browser.file_browser {
    path = vim.fn.expand('%:p:h'):gsub('^oil://', ''),
  }
end, {})

-- Create undo directory if it doesn't exist
local undodir = vim.fn.expand '~/.cache/nvim/undodir'
if vim.fn.isdirectory(undodir) == 0 then
  vim.fn.mkdir(undodir, 'p')
end

-- Install lazy.nvim plugin manager
local lazypath = vim.fn.stdpath 'data' .. '/lazy/lazy.nvim' -- Search for lazy/lazy.nvim inside data path
if not (vim.uv or vim.loop).fs_stat(lazypath) then -- If it does not exist
  local lazyrepo = 'https://github.com/folke/lazy.nvim.git'
  local out = vim.fn.system { 'git', 'clone', '--filter=blob:none', '--branch=stable', lazyrepo, lazypath } -- Git clone lazy
  if vim.v.shell_error ~= 0 then -- If git clone fails
    error('Error cloning lazy.nvim:\n' .. out) -- Return error
  end
end

vim.opt.runtimepath:prepend(lazypath) -- Add lazy to Neovim's runtime path

-- Configure and install plugins
require('lazy').setup {
  require 'plugins.treesitter', -- Highlight, edit, and navigate code
  require 'plugins.guess-indent', -- Detect tabstop and shiftwidth automatically
  require 'plugins.gitsigns', -- Adds git related signs to the gutter, as well as utilities for managing changes
  require 'plugins.rainbow-delimiters', -- Rainbow delimiters
  require 'plugins.telescope-file-browser', -- File browser
  require 'plugins.oil', -- File browser
  require 'plugins.arrow', -- Switch fast between bookmarked files
  require 'plugins.conform', -- Autoformat
  require 'plugins.blink-cmp', -- Autocompletion
  require 'plugins.todo-comments', -- Highlight todo, notes, etc in comments
  require 'plugins.which-key', -- Useful plugin to show you pending keybinds.
  require 'plugins.mini', -- Collection of various small independent plugins/modules
  require 'plugins.lazydev', -- configures Lua LSP for your Neovim config, runtime and plugins
  require 'plugins.nvim-lspconfig', -- Main LSP Configuration
  require 'plugins.autopairs', -- Autopairs for neovim
  require 'plugins.snacks', -- A collection of small QoL plugins
  require 'plugins.nvim-dap', -- Integrated debugger
  require 'plugins.orgmode', -- Org mode
  require 'plugins.nvim-dap-ui', -- Prettier UI for debugger
  -- require 'plugins.mason-nvim-dap',
  -- require 'plugins.projectmarks',
  -- require 'plugins.indent-blankline', -- Add indentation guides even on blank lines
  -- require 'plugins.telescope', -- Fuzzy Finder (files, lsp, etc)
  -- require 'plugins.lint',
  -- themes
  require 'plugins.colorschemes.everforest',
}
vim.cmd.colorscheme 'everforest' -- Load colorscheme (If it's a plugin it needs to be loaded after them)
vim.api.nvim_set_hl(0, 'Visual', { bg = '#464E53' }) -- Change bg in visual selection (It needs to be loaded after the colorscheme)
