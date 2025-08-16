return {
  'EdenEast/nightfox.nvim',
  dependencies = {
    {
      'nvim-treesitter/nvim-treesitter',
      opts = {
        highlight = {
          enable = true,

          -- Custom syntax highlighting for C
          -- vim.api.nvim_set_hl(0, '@function.call.c', { link = 'Fg', underline = false, sp = '' }),
          -- vim.api.nvim_set_hl(0, '@operator.c', { link = 'Fg', underline = false, sp = '' }),
          -- vim.api.nvim_set_hl(0, '@variable.parameter.c', { link = 'Blue', underline = false, sp = '' }),
          -- vim.api.nvim_set_hl(0, '@variable.declaration.c', { link = 'Blue', underline = false, sp = '' }),
          -- vim.api.nvim_set_hl(0, '@punctuation.delimiter.c', { link = 'Fg', underline = false, sp = '' }),
          -- vim.api.nvim_set_hl(0, '@property.c', { link = 'Fg', underline = false, sp = '' }),
          -- vim.api.nvim_set_hl(0, '@number.c', { link = 'Fg', underline = false, sp = '' }),
          -- vim.api.nvim_set_hl(0, '@constant.c', { link = 'Purple', underline = false, sp = '' }),
          -- vim.api.nvim_set_hl(0, '@ibl.scope.underline.1', { link = 'Fg', underline = false, sp = '' }),
          -- vim.api.nvim_set_hl(0, '@function.c', { link = 'Aqua', underline = false, sp = '' }),
          -- vim.api.nvim_set_hl(0, '@string.c', { link = 'Green', underline = false, sp = '' }),

          -- -- Custom syntax highlighting for C++
          vim.api.nvim_set_hl(0, '@function.cpp', { link = 'Keyword', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@variable.declaration.cpp', { link = '@variable.parameter', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@function.method.cpp', { link = 'Keyword', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@function.call.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@function.method.call.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@number.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@operator.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@constructor.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@property.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@keyword.repeat.cpp', { link = '@keyword.return', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@keyword.conditional.cpp', { link = '@keyword.return', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@type.builtin.cpp', { link = '@type', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@variable.member.cpp', { link = '@parameter', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@module.cpp', { link = '@type', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@keyword.modifier.cpp', { link = '@constant.builtin', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@keyword.type.cpp', { link = '@constant.builtin', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@keyword.cpp', { link = '@constant.builtin', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.type.operator.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.typemod.variable.defaultLibrary.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.typemod.property.classScope.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.typemod.parameter.readonly.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.type.method.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.typemod.function.defaultLibrary.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.typemod.method.defaultLibrary.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.typemod.class.defaultLibrary.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.typemod.method.readonly.cpp', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.type.namespace.cpp', { link = '@variable', underline = false, sp = '' }),

          -- Custom syntax highlighting for Lua
          vim.api.nvim_set_hl(0, '@function.lua', { link = 'Keyword', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@local.variable.declaration.lua', { link = '@parameter', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.mod.declaration.lua', { link = 'PreProc', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@variable.member.lua', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@variable.parameter.lua', { link = '@parameter', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@function.call.lua', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@number.lua', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@property.lua', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@function.builtin.lua', { link = 'PreProc', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@function.method.call.lua', { link = '@variable', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@keyword.operator.lua', { link = '@keyword.return', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@string.regexp.lua', { link = 'String', underline = false, sp = '' }),
        },
      },
    },
  },
  options = {
    -- Compiled file's destination location
    compile_path = vim.fn.stdpath 'cache' .. '/nightfox',
    compile_file_suffix = '_compiled', -- Compiled file suffix
    transparent = false, -- Disable setting background
    terminal_colors = true, -- Set terminal colors (vim.g.terminal_color_*) used in `:terminal`
    dim_inactive = false, -- Non focused panes set to alternative background
    module_default = true, -- Default enable value for modules
    colorblind = {
      enable = false, -- Enable colorblind support
      simulate_only = false, -- Only show simulated colorblind colors and not diff shifted
      severity = {
        protan = 0, -- Severity [0,1] for protan (red)
        deutan = 0, -- Severity [0,1] for deutan (green)
        tritan = 0, -- Severity [0,1] for tritan (blue)
      },
    },
    styles = { -- Style to be applied to different syntax groups
      comments = 'NONE', -- Value is any valid attr-list value `:help attr-list`
      conditionals = 'NONE',
      constants = 'NONE',
      functions = 'NONE',
      keywords = 'NONE',
      numbers = 'NONE',
      operators = 'NONE',
      strings = 'NONE',
      types = 'NONE',
      variables = 'NONE',
    },
    inverse = { -- Inverse highlight for different types
      match_paren = false,
      visual = false,
      search = false,
    },
    modules = { -- List of various plugins and additional options
      -- ...
    },
  },
  palettes = {},
  specs = {},
  groups = {},
}
