return {
  'jay-babu/mason-nvim-dap.nvim', -- Makes a best effort to setup the various debuggers with reasonable debug configurations
  dependencies = {
    'mason-org/mason.nvim',
    'mfussenegger/nvim-dap',
  },
  opts = {
    automatic_installation = true,
    handlers = {},
    ensure_installed = { -- Update this to ensure that you have the debuggers for the langs you want
      'delve',
    },
  },
}
