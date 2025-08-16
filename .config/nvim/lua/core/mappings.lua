-- [[ Basic Keymaps ]]
vim.keymap.set('n', '<Esc>', '<cmd>nohlsearch<CR>', { desc = 'Clear highlights on search' })
vim.keymap.set('n', 'Y', 'y$', { desc = 'Yank to end of line' })
vim.keymap.set('n', '<leader>q', vim.diagnostic.setloclist, { desc = 'Open diagnostic [Q]uickfix list' })
vim.keymap.set('n', 'n', 'nzzzv', { desc = 'Next search result (centered)' })
vim.keymap.set('n', 'N', 'Nzzzv', { desc = 'Previous search result (centered)' })

-- Disable mouse clicks except left click
vim.keymap.set('', '<RightMouse>', '<Nop>')
vim.keymap.set('', '<MiddleMouse>', '<Nop>')
vim.keymap.set('', '<2-LeftMouse>', '<Nop>')
vim.keymap.set('', '<3-LeftMouse>', '<Nop>')
vim.keymap.set('', '<4-LeftMouse>', '<Nop>')

-- Buffer navigation
vim.keymap.set('n', '<leader>bn', ':bnext<CR>', { desc = 'Next buffer' })
vim.keymap.set('n', '<leader>bp', ':bprevious<CR>', { desc = 'Previous buffer' })

-- Keybinds to make split navigation easier.
vim.keymap.set('n', '<C-h>', '<C-w><C-h>', { desc = 'Move focus to the left window' })
vim.keymap.set('n', '<C-l>', '<C-w><C-l>', { desc = 'Move focus to the right window' })
vim.keymap.set('n', '<C-j>', '<C-w><C-j>', { desc = 'Move focus to the lower window' })
vim.keymap.set('n', '<C-k>', '<C-w><C-k>', { desc = 'Move focus to the upper window' })

-- Cut and paste without yanking
vim.keymap.set('x', '<leader>p', '"_dP', { desc = 'Paste without yanking' })
vim.keymap.set({ 'n', 'v' }, '<leader>d', '"_d', { desc = 'Delete without yanking' })

-- Move lines up/down
vim.keymap.set('n', '<A-j>', ':m .+1<CR>==', { desc = 'Move line down' })
vim.keymap.set('n', '<A-k>', ':m .-2<CR>==', { desc = 'Move line up' })
vim.keymap.set('v', '<A-j>', ":m '>+1<CR>gv=gv", { desc = 'Move selection down' })
vim.keymap.set('v', '<A-k>', ":m '<-2<CR>gv=gv", { desc = 'Move selection up' })

-- Better indenting in visual mode
vim.keymap.set('v', '<', '<gv', { desc = 'Indent left and reselect' })
vim.keymap.set('v', '>', '>gv', { desc = 'Indent right and reselect' })

vim.keymap.set('n', '<leader>e', ':Explore<CR>', { desc = 'Open file explorer' })

-- Splitting & Resizing
vim.keymap.set('n', '<leader>/', ':vsplit<CR>', { desc = 'Split window vertically' })
vim.keymap.set('n', '<leader>-', ':split<CR>', { desc = 'Split window horizontally' })
vim.keymap.set('n', '<C-Up>', ':resize +2<CR>', { desc = 'Increase window height' })
vim.keymap.set('n', '<C-Down>', ':resize -2<CR>', { desc = 'Decrease window height' })
vim.keymap.set('n', '<C-Left>', ':vertical resize -2<CR>', { desc = 'Decrease window width' })
vim.keymap.set('n', '<C-Right>', ':vertical resize +2<CR>', { desc = 'Increase window width' })
vim.keymap.set('n', '<leader>w', ':wq<CR>', { desc = 'Quit window' })

vim.keymap.set('n', '<leader>.', ':OilFB<CR>', { desc = 'Open file browser' })

-- Horizontal scrolling with shift+scrollwheel
vim.keymap.set('n', '<S-ScrollWheelUp>', '<ScrollWheelLeft>', { desc = 'Scroll left' })
vim.keymap.set('n', '<S-ScrollWheelDown>', '<ScrollWheelRight>', { desc = 'Scroll right' })

-- Eval lua code
vim.keymap.set('n', '<space><space>x', '<cmd>source %<CR>', { desc = 'Evaluate entire file' })
vim.keymap.set('n', '<space>x', ':.lua<CR>', { desc = 'Evaluate single line' })
vim.keymap.set('v', '<space>x', ':lua<CR>', { desc = 'Evaluate selection' })

-- vim.keymap.set('n', '<space>i', ':Inspect<CR>', { desc = 'Evaluate selection' })
vim.api.nvim_set_keymap('n', '<space>i', ':Inspect<CR>', { noremap = true, silent = false })

-- Quickfix
vim.keymap.set('n', '<M-j>', '<cmd>cnext<CR>', { desc = 'Quickfix next' })
vim.keymap.set('n', '<M-k>', '<cmd>cprev<CR>', { desc = 'Quickfix prev' })
