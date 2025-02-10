;; open org agenda
(map! :leader
      "o a" #'org-agenda)
;; hotkey for opening inbox capture
(map! :leader
      "c i" (lambda () (interactive) (org-capture nil "i")))

;; Make sure that the weekdays in the time stamps of your Org mode files and in the agenda appear in English.
(setq system-time-locale "C")
;; set calendar to start weeks on monday
(setq calendar-week-start-day 1)
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


(setq org-agenda-start-on-weekday 1)

(setq org-agenda-files '(
                         "~/documents/org/projects.org"
                         "~/documents/org/agenda.org"
                         ))
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
