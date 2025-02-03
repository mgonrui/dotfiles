;; KEY MAPPING STARTS
;; make and run c programs
(map! :leader
      "r r" #'execute-c)
;; split window horizontally and move cursor to the right
(map! :leader
      "s h" (lambda ()
              (interactive)
              (split-window-horizontally)
              (evil-window-right 1)))
;; split window vertically and move cursor to the bottom
(map! :leader
      "s v" (lambda ()
              (interactive)
              (split-window-vertically)
              (evil-window-down 1)))
;; refresh magit
(map! :leader
      "r f" (lambda () (interactive) (magit-refresh)))
;; KEY MAPPING ENDS

;; USER INTERFACE STARTS
;; set fonts
;; See 'C-h v doom-font' for documentation and more examples of what they accept
(setq doom-font (font-spec :family "Agave Nerd Font" :size 20 :weight 'semi-light);; the primary font to use
      doom-variable-pitch-font (font-spec :family "Agave Nerd Font" :size 15) ;; a non-monospace font (where applicable)
      doom-big-font (font-spec :family "Agave Nerd Font" :size 24) ;; used for `doom-big-font-mode' use this for presentations or streaming.
      doom-serif-font (font-spec :family "Agave Nerd Font" :size 24) ;; for the `fixed-pitch-serif' face
      doom-symbol-font (font-spec :family "Agave Nerd Font" :size 24)) ;; for symbols
;; set default theme
(setq doom-theme 'doom-gruvbox)
;; home screen configuration
(setq fancy-splash-image (concat doom-user-dir "/images/gnu_cropped.png"))
(remove-hook '+doom-dashboard-functions #'doom-dashboard-widget-shortmenu)
(remove-hook '+doom-dashboard-functions #'doom-dashboard-widget-footer)
(remove-hook '+doom-dashboard-functions #'doom-dashboard-widget-loaded)
(add-hook! '+doom-dashboard-functions :append
  (insert  (+doom-dashboard--center +doom-dashboard--width "Welcome back, lisp sorcerer!" ) "\n\n\n\n\n\n\n\n\n\n\n\n\n"))
(assoc-delete-all "Open project" +doom-dashboard-menu-sections)
;; display lines with relative numbers
(after! doom-ui
  (setq display-line-numbers-type 'relative))
;; golden ratio resizing
(require 'golden-ratio)
(golden-ratio-mode 1)
;; fix golden ratio to work with evil mode
(setq golden-ratio-extra-commands
(append golden-ratio-extra-commands
'(evil-window-left
evil-window-right
evil-window-up
evil-window-down
buf-move-left
buf-move-right
buf-move-up
buf-move-down
window-number-select
select-window
select-window-1
select-window-2
select-window-3
select-window-4
select-window-5
select-window-6
select-window-7
select-window-8
select-window-9)))
;; disable autocompletion in .org, .txt, .md
(defun disable-company-mode ()
  (company-mode -1))
(add-hook 'markdown-mode-hook 'disable-company-mode)
(add-hook 'org-mode-hook 'disable-company-mode)
(add-hook 'text-mode-hook 'disable-company-mode)
(add-hook 'c-mode-hook 'disable-company-mode)
;; USER INTERFACE ENDS

;; LSP STARTS
;; prioritize snippet autocompletion over lsp completion
(setq +lsp-company-backends '(company-capf :with company-yasnippet))
;; show lsp definition handlers
(setq lsp-eldoc-render-all nil)
(setq lsp-ui-doc-enable nil)
(setq lsp-ui-sideline-enable nil)
(setq lsp-completion-provider 0.2)
;; LSP ENDS


;; SYSTEM SETTINGS STARTS
;; set doom dir
(setq doom-user-dir "/home/mgr/.dotfiles/.config/doom/")
;; load org configuration
(load! "~/.config/doom/org.el")
;; load libraries folder
(add-load-path! "libs")
;; System locale to use for formatting time values.
(setq system-time-locale "C")         ; Make sure that the weekdays in the time stamps of
                                      ; your Org mode files and in the agenda appear in English.

;; set calendar to start weeks on monday
(setq calendar-week-start-day 1)
(setq electric-pair-mode 1)
;; SYSTEM SETTINGS ENDS

;; C PROGRAMMING STARTS
;; set c default formatting style
(setq c-default-style "linux"
      c-basic-offset 4)
;; compile c source code and run it
(defun execute-c ()
  (interactive)
  (defvar compile-command)
  (setq compile-command(concat "make  && ./a.out | cat -e" ))
  (compile compile-command))
;; column marker
(add-load-path! "libs/column-marker")
(load! "~/.config/doom/libs/column-marker/column-marker.el")
(add-hook 'c-mode-hook (lambda () (interactive) (column-marker-1 80))) ;; mark a line if its more than 80 col long
;; insert 42  header plugin
(add-load-path! "libs/42header_emacs")
(load! "libs/42header_emacs/comments.el")
(load! "libs/42header_emacs/header.el")
(load! "libs/42header_emacs/init.el")
(load! "libs/42header_emacs/list.el")
(load! "libs/42header_emacs/string.el")
