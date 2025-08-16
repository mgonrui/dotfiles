local function custom_parsers()
  local parser_config = require('nvim-treesitter.parsers').get_parser_configs()
  parser_config.kanata = { -- Kanata config
    install_info = {
      url = '~/.local/share/nvim/tree-sitter-kanata',
      files = { 'src/parser.c' },
      branch = 'main',
      filetype = 'kbd',
    },
  }
  -- Add other custom parsers here...
end

return {
  'nvim-treesitter/nvim-treesitter', -- Highlight, edit, and navigate code
  build = ':TSUpdate',
  main = 'nvim-treesitter.configs', -- Sets main module to use for opts
  -- [[ Configure Treesitter ]]
  opts = {
    ensure_installed = { 'bash', 'c', 'diff', 'html', 'lua', 'luadoc', 'markdown', 'markdown_inline', 'query', 'vim', 'vimdoc', 'kanata' },
    auto_install = true, -- Autoinstall languages that are not installed

    -- indent = { enable = true, disable = { 'ruby' } },
  },
  config = function(_, opts)
    custom_parsers() -- Load custom parsers first
    require('nvim-treesitter.configs').setup(opts)
  end,
}
