(load-theme 'wheatgrass t) 
(xterm-mouse-mode 1)

(use-package eglot
  :ensure t
  :config
  ;; Tell Eglot to use cl-lsp for Common Lisp files
  (add-to-list 'eglot-server-programs
               '(lisp-mode . ("cl-lsp"))))

;; Automatically start Eglot whenever you open a Common Lisp file
(add-hook 'lisp-mode-hook 'eglot-ensure)
