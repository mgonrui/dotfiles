;; Place your private configuration here! Remember, you do not need to run 'doom
;; sync' after modifying this file!


;; Some functionality uses this to identify you, e.g. GPG configuration, email
;; clients, file templates and snippets. It is optional.
;; (setq user-full-name "John Doe"
;;       user-mail-address "john@doe.com")

;; Doom exposes five (optional) variables for controlling fonts in Doom:
;;
;; - `doom-font' -- the primary font to use
;; - `doom-variable-pitch-font' -- a non-monospace font (where applicable)
;; - `doom-big-font' -- used for `doom-big-font-mode'; use this for
;;   presentations or streaming.
;; - `doom-symbol-font' -- for symbols
;; - `doom-serif-font' -- for the `fixed-pitch-serif' face
(setq doom-font (font-spec :family "Agave Nerd Font" :size 20)
      doom-variable-pitch-font (font-spec :family "Agave Nerd Font" :size 15)
      doom-big-font (font-spec :family "Agave Nerd Font" :size 24))

;;


;; See 'C-h v doom-font' for documentation and more examples of what they
;; accept. For example:
;;
;;(setq doom-font (font-spec :family "Fira Code" :size 12 :weight 'semi-light)
;;      doom-variable-pitch-font (font-spec :family "Fira Sans" :size 13))
;;
;; If you or Emacs can't find your font, use 'M-x describe-font' to look them
;; up, `M-x eval-region' to execute elisp code, and 'M-x doom/reload-font' to
;; refresh your font settings. If Emacs still can't find your font, it likely
;; wasn't installed correctly. Font issues are rarely Doom issues!

;; There are two ways to load a theme. Both assume the theme is installed and
;; available. You can either set `doom-theme' or manually load a theme with the
;; `load-theme' function. This is the default:
(setq doom-theme 'doom-gruvbox)



;; home screen configuration
(setq fancy-splash-image (concat doom-user-dir "/images/gnu_cropped.png"))
(remove-hook '+doom-dashboard-functions #'doom-dashboard-widget-shortmenu)
(remove-hook '+doom-dashboard-functions #'doom-dashboard-widget-footer)
(remove-hook '+doom-dashboard-functions #'doom-dashboard-widget-loaded)
(add-hook! '+doom-dashboard-functions :append
  (insert  (+doom-dashboard--center +doom-dashboard--width "Welcome back, lisp sorcerer!" ) "\n\n\n\n\n\n\n\n\n\n\n\n\n"))
(assoc-delete-all "Open project" +doom-dashboard-menu-sections)

;; System locale to use for formatting time values.
(setq system-time-locale "C")         ; Make sure that the weekdays in the time stamps of
                                      ; your Org mode files and in the agenda appear in English.

;; set calendar to start weeks on monday
(setq calendar-week-start-day 1)
(setq electric-pair-mode 1)
 
(setq c-default-style "linux"
      c-basic-offset 4)

;; display lines with relative numbers
(after! doom-ui
  (setq display-line-numbers-type 'relative))


;; If you use `org' and don't want your org files in the default location below,
;; change `org-directory'. It must be set before org loads!
;; set private config path
(setq doom-user-dir "/home/mgr/.dotfiles/.config/doom/")

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

;; prioritize snippet autocompletion over lsp
(setq +lsp-company-backends '(company-capf :with company-yasnippet))

;; compile c source code and run it
(defun execute-c ()
  (interactive)
  (defvar compile-command)
  (setq compile-command(concat "make  && ./a.out | cat -e" ))
  (compile compile-command))
(map! :leader
      "r r" #'execute-c)

;; column maker
(add-to-list 'load-path "~/.config/doom/libs/column-marker")
(load-file "~/.config/doom/libs/column-marker/column-marker.el")
(add-hook 'c-mode-hook (lambda () (interactive) (column-marker-1 80)))


;; split window horizontally and move cursor to the right
(map! :leader
      "s h" (lambda ()
              (interactive)
              (split-window-horizontally)
              (evil-window-right 1)))
(map! :leader
      "s v" (lambda ()
              (interactive)
              (split-window-vertically)
              (evil-window-down 1)))


;; golden ratio resizing
(require 'golden-ratio)
(golden-ratio-mode 1)
;; fix to work with evil mode
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

(defun generate-scratch-buffer ()
    "Create and switch to a temporary scratch buffer with a random
       name."
    (interactive)
    (switch-to-buffer (make-temp-name "scratch")))

;; show lsp definition handlers
(setq lsp-eldoc-render-all nil)
(setq lsp-ui-doc-enable nil)
(setq lsp-ui-sideline-enable nil)
(setq lsp-completion-provider 0.2)

;;START ORG MODE ___________________________________________________________________________________________________________;;

;; set org directory path
(setq org-directory "~/documents/org/")
;; enable optional org modules
(setq org-modules '(org-habit))
;; disable autocompletion in org files
(add-hook 'org-mode-hook 'disable-company-mode)
;; custom todo keywords
(with-eval-after-load 'org
  (setq org-todo-keywords
        '(
          ;; (sequence "TOBRING(z)" "|" "BRINGED(Z)")
          ;; (sequence "TOWATCH" "|" "WATCHED(W)")
          ;; (sequence "TOREAD(r)" "|" "READ(R)")
          (sequence "TOBUY(b)" "|" "BUYED(B)")
          (sequence "TOREAD(r)" "READING" "|" "READ(R)" "DNF")
          (sequence "DEBT" "|" "PAYED")
          (sequence "- [ ](x)" "|" "- [X]")
          (sequence "INBOX(i)"
                    "ACTION(a)"
                    ;; "ONGOING(o)"
                    "NEXT(n)"
                    "PROJECT(p)"
                    "FUTURE(f)"
                    "WAITING(w)"
                    "|"
                    "DONE(d)"
                    "CANCELLED(c)")
          )))

;; configure tags
;; all context based tags (not only location-specific) are marked with "@" prefix
(setq org-tag-alist '(
                      (:startgroup . nil)

                      ("@pc" . ?p)
                      ("@chore" . ?c)
                      ("@errand" . ?s)
                      ("@work" . ?w)
                      ("@anywhere" . ?a)

                      ("clothes")
                      ("supermarket")

                      (:endgroup . nil)
                     ))

;; automatically change parent TODO to DONE when all TODO children are DONE
(defun org-summary-todo (n-done n-not-done)
  "Switch entry to DONE when all subentries are done, to TODO otherwise."
  (let (org-log-done org-todo-log-states) ; turn off logging
(org-todo (if (= n-not-done 0) "DONE" "TODO"))))
(add-hook 'org-after-todo-statistics-hook #'org-summary-todo)

;; timestamp when a todo is set as done
;;(setq org-log-done 'time)

;; change colors for TODO keywords
(setq org-todo-keyword-faces
      '(("TODO" . (:foreground "red" :weight bold))))

;; if non-nil, dont show todos with date in global todo list
(setq org-agenda-todo-ignore-scheduled t)

(use-package! elfeed-org
  :ensure t
  :config
  (elfeed-org)
  (setq rmh-elfeed-org-files (list "~/documents/org/elfeed.org")))



(require 'elfeed-tube)
(elfeed-tube-setup)
(define-key elfeed-show-mode-map (kbd "F") 'elfeed-tube-fetch)
(define-key elfeed-show-mode-map [remap save-buffer] 'elfeed-tube-save)
(define-key elfeed-search-mode-map (kbd "F") 'elfeed-tube-fetch)
(define-key elfeed-search-mode-map [remap save-buffer] 'elfeed-tube-save)

;; play video with mpv
(define-key elfeed-show-mode-map (kbd "C-c C-d") 'elfeed-tube-mpv)


;; Automatically get the files in "~/Documents/org"
;; with fullpath
;;

(setq org-agenda-start-on-weekday 1)

(setq org-agenda-files '(
                         "~/documents/org/projects.org"
                         "~/documents/org/agenda.org"
                         ))
(map! :leader
      "o a" #'org-agenda)
;; set org capture templates
(after! org
(setq org-capture-templates
      `(("i" "Inbox" entry  (file+headline "gtd.org" "MY INBOX")
         "**** INBOX %?"))))

;; edit agenda view format
(setq org-agenda-prefix-format
      '((agenda . " %i %-12:c%?-12t% s")
        (todo   . " ")
        (tags   . " %i %-12:c")
        (search . " %i %-12:c")))

;; hotkey for opening inbox capture
(map! :leader
      "c i" (lambda () (interactive) (org-capture nil "i")))

(map! :leader
      "r f" (lambda () (interactive) (magit-refresh)))

;; save all org files after changing a todo state
(advice-add 'org-todo :after
	    (lambda (&rest _)
	      (org-save-all-org-buffers)))

;; save all org files after changing a todo priority
(advice-add 'org-priority :after
	    (lambda (&rest _)
	      (org-save-all-org-buffers)))

;; remove mouse from agenda
(add-hook 'org-agenda-finalize-hook
      (lambda () (remove-text-properties
         (point-min) (point-max) '(mouse-face t))))

;; select files for org timeblock
;; (setq org-timeblock-files '(
;;                          "~/documents/org/org-timeblock-inbox-file.org"
;;                          ))
;;enable org-edna
(setq org-edna-use-inheritance t)
(org-edna-mode 1)

(setq org-gtd-directory "~/documents/org/gtd/")
(setq org-gtd-next "NEXT")
(setq org-gtd-todo "TODO")
(setq org-gtd-wait "WAIT")
(setq org-gtd-done "DONE")
(setq org-gtd-canceled "CANCELED")
(setq org-reverse-note-order nil)


;; Create hook to auto-refile when todo is changing state
(add-hook 'org-after-todo-state-change-hook 'dk/refile-todo 'append)
(defun dk/refile-todo()
(if (equal org-state "DONE")
	  (if (equal org-state "PROJECT")
		  (dk/refile-to "~/documents/org/projects.org" "PROJECTS"))))

(defun dk/refile-to (file headline)
"Move current headline to specified location"
(let ((pos (save-excursion
			 (find-file file)
			 (org-find-exact-headline-in-buffer headline))))
  (org-refile nil nil (list headline file nil pos)))
(switch-to-buffer (current-buffer))
)

(setq org-capture-templates
      '(("t" "Todo" entry (file+headline "~/org/gtd.org" "Tasks")
         "* TODO %?\n  %i\n  %a")
        ("j" "Journal" entry (file+datetree "~/org/journal.org")
         "* %?\nEntered on %U\n  %i\n  %a")))



;;ORG MODE ENDS___________________________________________________________________________________________________________;;

;; 42 insert header plugin
(add-to-list 'load-path "~/.config/doom/libs")
(add-to-list 'load-path "~/.config/doom/libs/42header_emacs")
(load-file "~/.config/doom/libs/42header_emacs/comments.el")
(load-file "~/.config/doom/libs/42header_emacs/header.el")
(load-file "~/.config/doom/libs/42header_emacs/init.el")
(load-file "~/.config/doom/libs/42header_emacs/list.el")
(load-file "~/.config/doom/libs/42header_emacs/string.el")
