return {
  'mfussenegger/nvim-dap',
  dependencies = {
    'rcarriga/nvim-dap-ui', -- Creates a beautiful debugger UI
    'theHamsta/nvim-dap-virtual-text', -- Add virtual text support
    'nvim-neotest/nvim-nio', -- Required dependency for nvim-dap-ui
    'mason-org/mason.nvim', -- Installs the debug adapters for you
    'jay-babu/mason-nvim-dap.nvim', -- Makes a best effort to setup the various debuggers with reasonable debug configurations
    -- Add your own debuggers here
    'leoluz/nvim-dap-go', -- An extension for nvim-dap providing configurations for launching go debugger (delve)
  },
  keys = { -- Basic debugging keymaps
    {
      '<F5>',
      function()
        require('dap').continue()
      end,
      desc = 'Debug: Start/Continue',
    },
    {
      '<F1>',
      function()
        require('dap').step_into()
      end,
      desc = 'Debug: Step Into',
    },
    {
      '<F2>',
      function()
        require('dap').step_over()
      end,
      desc = 'Debug: Step Over',
    },
    {
      '<F3>',
      function()
        require('dap').step_out()
      end,
      desc = 'Debug: Step Out',
    },
    {
      '<leader>b',
      function()
        require('dap').toggle_breakpoint()
      end,
      desc = 'Debug: Toggle Breakpoint',
    },
    {
      '<leader>R',
      function()
        require('dap').restart_frame()
      end,
      desc = 'Debug: Set Breakpoint',
    },
    {
      '<leader>B',
      function()
        require('dap').set_breakpoint(vim.fn.input 'Breakpoint condition: ')
      end,
      desc = 'Debug: Set Breakpoint',
    },

    {
      '<F7>',
      function()
        require('dapui').toggle() -- Toggle to see last session result. Without this, you can't see session output in case of unhandled exception.
      end,
      desc = 'Debug: See last session result.',
    },
    {
      '<F8>',
      function()
        require('dap').down()
      end,
      desc = 'Debug: See last session result.',
    },
    {
      '<F9>',
      function()
        require('dap').up()
      end,
      desc = 'Debug: See last session result.',
    },
  },
  config = function()
    local dap = require 'dap'
    local dapui = require 'dapui'

    -- Dap UI setup
    -- For more information, see |:help nvim-dap-ui|
    dapui.setup {
      -- Set icons to characters that are more likely to work in every terminal.
      --    Feel free to remove or use ones that you like more! :)
      --    Don't feel like these are good choices.
      icons = { expanded = '▾', collapsed = '▸', current_frame = '*' },
      controls = {
        icons = {
          pause = '⏸',
          play = '▶',
          step_into = '⏎',
          step_over = '⏭',
          step_out = '⏮',
          step_back = 'b',
          run_last = '▶▶',
          terminate = '⏹',
          disconnect = '⏏',
        },
      },
    }

    -- Change breakpoint icons
    vim.api.nvim_set_hl(0, 'DapBreak', { fg = '#e67e80' })
    vim.api.nvim_set_hl(0, 'DapStop', { fg = '#dbbc7f' })
    local breakpoint_icons = { Breakpoint = 'B', BreakpointCondition = 'C', BreakpointRejected = 'R', LogPoint = 'L', Stopped = 'S' }
    for type, icon in pairs(breakpoint_icons) do
      local tp = 'Dap' .. type
      local hl = (type == 'Stopped') and 'DapStop' or 'DapBreak'
      vim.fn.sign_define(tp, { text = icon, texthl = hl, numhl = hl })
    end

    dap.listeners.after.event_initialized['dapui_config'] = dapui.open
    dap.listeners.before.event_terminated['dapui_config'] = dapui.close
    dap.listeners.before.event_exited['dapui_config'] = dapui.close

    require('dap-go').setup { -- Install golang specific config
      delve = {
        detached = vim.fn.has 'win32' == 0, -- On Windows delve must be run attached or it crashes.
      },
    }
  end,
}
