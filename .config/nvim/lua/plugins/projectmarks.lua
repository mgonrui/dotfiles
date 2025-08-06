local function cwd_name() -- Get the name of the current working directory.
  return vim.fn.fnamemodify(vim.fn.getcwd(), ':t')
end

return {
  'BartSte/nvim-project-marks',
  lazy = false,
  config = function()
    require('projectmarks').setup {

      shadafile = '~/.dotfiles/.config/nvim/shadas/' .. cwd_name() .. '.shada',
      mappings = true,
      abbreviations = false,
      message = 'Waiting for mark...',
      message_opts = { timeout = 2000 },
    }
  end,
}
