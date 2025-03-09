;; KEY MAPPING
(map! :leader
      "w w" #'ace-window)
(map! :leader
      "r r" #'execute-c)
(map! :leader
      "h l" #'evil-lookup)
(map! :leader
      "w o" #'golden-ratio-toggle-widescreen)
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
(define-prefix-command 'my-window-map)


;; USER INTERFACE
;; See 'C-h v doom-font' for documentation and more examples of what they accept
(setq doom-font (font-spec :family "Agave Nerd Font" :size 25 :weight 'semi-light);; the primary font to use
      doom-variable-pitch-font (font-spec :family "Agave Nerd Font" :size 15) ;; a non-monospace font (where applicable)
      doom-big-font (font-spec :family "Agave Nerd Font" :size 24) ;; used for `doom-big-font-mode' use this for presentations or streaming.
      doom-serif-font (font-spec :family "Agave Nerd Font" :size 24) ;; for the `fixed-pitch-serif' face
      doom-symbol-font (font-spec :family "Agave Nerd Font" :size 24)) ;; for symbols
;; set default theme
(setq doom-theme 'doom-gruvbox)

;; Must be used *after* the theme is loaded
;; home screen configuration
(setq fancy-splash-image (concat doom-user-dir "/images/gruvbox_emacs_logo_cropped.png"))
(remove-hook '+doom-dashboard-functions #'doom-dashboard-widget-shortmenu)
(remove-hook '+doom-dashboard-functions #'doom-dashboard-widget-footer)
(remove-hook '+doom-dashboard-functions #'doom-dashboard-widget-loaded)
;; (add-hook! '+doom-dashboard-functions :append
;;   (insert  (+doom-dashboard--center +doom-dashboard--width "Welcome back, lisp sorcerer!" )))
(assoc-delete-all "Open project" +doom-dashboard-menu-sections)
;; display lines with relative numbers
(after! doom-ui
  (setq display-line-numbers-type 'relative))
;; golden ratio resizing
(require 'golden-ratio)
(golden-ratio-mode 1)
(golden-ratio-adjust 0) ;; turned off by default
;; hook golden ratio to movement commands
(setq golden-ratio-extra-commands
(append golden-ratio-extra-commands
'(
ace-window
evil-window-left
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
;; disable quit emacs prompt
(setq confirm-kill-emacs nil)


;; LSP
;; prioritize snippet autocompletion over lsp completion
(setq +lsp-company-backends '(company-capf :with company-yasnippet))
(setq lsp-completion-provider 0.2)


;; SYSTEM SETTINGS
;; set doom dir
;; (setq doom-user-dir "~/.dotfiles/.config/doom/")
;; load org configuration
(load! (concat doom-user-dir "org.el"))
;; load libraries folder
(add-load-path! "libs")
(setq electric-pair-mode 1)


;; C PROGRAMMING ENVIRONMENT
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
(load! (concat doom-user-dir "libs/column-marker/column-marker.el"))
(add-hook 'c-mode-hook (lambda () (interactive) (column-marker-1 80))) ;; mark a line if its more than 80 col long
;; insert 42  header plugin
;; (add-load-path! "libs/42header_emacs")
;; (load! "~/.config/doom/libs/42header_emacs/comments.el")
;; (load! "~/.config/doom/libs/42header_emacs/header.el")
;; (load! "~/.config/doom/libs/42header_emacs/init.el")
;; (load! "~/.config/doom/libs/42header_emacs/list.el")
;; (load! "~/.config/doom/libs/42header_emacs/string.el")
