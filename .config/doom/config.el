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
;;set fonts
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
(load-file "~/.config/doom/org.el")
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
(add-to-list 'load-path "~/.config/doom/libs/column-marker")
(load-file "~/.config/doom/libs/column-marker/column-marker.el")
(add-hook 'c-mode-hook (lambda () (interactive) (column-marker-1 80))) ;; mark a line if its more than 80 col long
;; insert 42  header plugin
(add-to-list 'load-path "~/.config/doom/libs")
(add-to-list 'load-path "~/.config/doom/libs/42header_emacs")
(load-file "~/.config/doom/libs/42header_emacs/comments.el")
(load-file "~/.config/doom/libs/42header_emacs/header.el")
(load-file "~/.config/doom/libs/42header_emacs/init.el")
(load-file "~/.config/doom/libs/42header_emacs/list.el")
(load-file "~/.config/doom/libs/42header_emacs/string.el")
;; C PROGRAMMING ENDS

;; Whenever you reconfigure a package, make sure to wrap your config in an
;; `after!' block, otherwise Doom's defaults may override your settings. E.g.
;;
;;   (after! PACKAGE
;;     (setq x y))
;;
;; The exceptions to this rule:
;;
;;   - Setting file/directory variables (like `org-directory')
;;   - Setting variables which explicitly tell you to set them before their
;;     package is loaded (see 'C-h v VARIABLE' to look up their documentation).
;;   - Setting doom variables (which start with 'doom-' or '+').
;;
;; Here are some additional functions/macros that will help you configure Doom.
;;
;; - `load!' for loading external *.el files relative to this one
;; - `use-package!' for configuring packages
;; - `after!' for running code after a package has loaded
;; - `add-load-path!' for adding directories to the `load-path', relative to
;;   this file. Emacs searches the `load-path' when you load packages with
;;   `require' or `use-package'.
;; - `map!' for binding new keys
;;
;; To get information about any of these functions/macros, move the cursor over
;; the highlighted symbol at press 'K' (non-evil users must press 'C-c c k').
;; This will open documentation for it, including demos of how they are used.
;; Alternatively, use `C-h o' to look up a symbol (functions, variables, faces,
;; etc).
;;
;; You can also try 'gd' (or 'C-c c d') to jump to their definition and see how
;; they are implemented.
;;
;; disable autocompletion in .org, .txt, .md
(defun disable-company-mode ()
  (company-mode -1))
(add-hook 'markdown-mode-hook 'disable-company-mode)
(add-hook 'org-mode-hook 'disable-company-mode)
(add-hook 'text-mode-hook 'disable-company-mode)
(add-hook 'c-mode-hook 'disable-company-mode)


(setq vterm-use-vterm-prompt-detection-method t)
