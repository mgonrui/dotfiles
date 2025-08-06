-- Highlight when yanking (copying) text
vim.api.nvim_create_autocmd('TextYankPost', {
  desc = 'Highlight when yanking (copying) text',
  group = vim.api.nvim_create_augroup('highlight-yank', { clear = true }),
  callback = function()
    vim.hl.on_yank()
  end,
})

-- Return to last edit position when opening files
vim.api.nvim_create_autocmd('BufReadPost', {
  desc = '-- Return to last edit position when opening files',
  group = vim.api.nvim_create_augroup('return-last-cursor-position', { clear = true }),
  callback = function()
    local mark = vim.api.nvim_buf_get_mark(0, '"')
    local lcount = vim.api.nvim_buf_line_count(0)
    if mark[1] > 0 and mark[1] <= lcount then
      pcall(vim.api.nvim_win_set_cursor, 0, mark)
    end
  end,
})

-- Create directories when saving files
vim.api.nvim_create_autocmd('BufWritePre', {
  desc = 'Create directories when saving files',
  group = vim.api.nvim_create_augroup('create-dir-when-saving', { clear = true }),
  callback = function()
    local dir = vim.fn.expand '<afile>:p:h'
    if vim.fn.isdirectory(dir) == 0 then
      vim.fn.mkdir(dir, 'p')
    end
  end,
})

-- Disable automatic comment wrapping
vim.api.nvim_create_autocmd('BufEnter', {
  desc = 'Disable automatic comment wrapping',
  pattern = '*',
  callback = function()
    vim.opt.formatoptions:remove { 'c', 'r', 'o' }
  end,
})

-- This should be added to your Neovim configuration (likely init.lua or a plugin config file)
-- Add this to your session post-load hook if you're getting arrow-related errors
vim.api.nvim_create_autocmd('User', {
  pattern = 'SessionLoadPost',
  callback = function()
    -- Only needed if you have separated_by_branch = true in your arrow config
    require('arrow.git').refresh_git_branch()

    -- Always good to reload the cache file after session load
    require('arrow.persist').load_cache_file()
  end,
})
