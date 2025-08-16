return {
  'neanias/everforest-nvim', -- Theme
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
          vim.api.nvim_set_hl(0, '@function.cpp', { link = 'Aqua', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@variable.declaration.cpp', { link = 'Blue', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@function.method.cpp', { link = 'Aqua', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@string.cpp', { link = 'Green', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@variable.parameter.cpp', { link = 'Blue', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@module.cpp', { link = 'Yellow', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@function.call.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@function.method.call.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@number.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@operator.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@constructor.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@property.cpp', { link = 'Fg', underline = false, sp = '' }),

          vim.api.nvim_set_hl(0, '@lsp.typemod.variable.definition.cpp', { link = 'Blue', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.typemod.variable.defaultLibrary.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.type.parameter.cpp', { link = 'Blue', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.type.property.cpp', { link = 'Blue', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.type.operator.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.typemod.property.classScope.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.typemod.parameter.readonly.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.type.method.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.typemod.function.defaultLibrary.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.typemod.method.defaultLibrary.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.typemod.class.defaultLibrary.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.type.class.cpp', { link = 'Yellow', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.typemod.method.readonly.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.type.namespace.cpp', { link = 'Fg', underline = false, sp = '' }),
          vim.api.nvim_set_hl(0, '@lsp.type.function.cpp', { link = 'Aqua', underline = false, sp = '' }),
        },
      },

      priority = 1000, -- Make sure to load this before all the other start plugins.
      config = function() -- test hello
        ---@diagnostic disable-next-line: missing-fields
        require('everforest').setup {
          italics = false,
          background = 'hard',
          ui_contrast = 'low',
          disable_italic_comments = true,
          styles = {
            comments = { italic = false }, -- Disable italics in comments
          },
          colours_override = function(palette)
            palette.aqua = '#83C092'
            -- palette.blue = '#7FBBFF'
          end,
        }
      end,
    },
  },
}
