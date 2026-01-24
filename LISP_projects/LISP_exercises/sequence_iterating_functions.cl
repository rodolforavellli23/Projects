#!/usr/bin/ecl -shell

;; Variable Definition

(defvar *my-vector* (vector 1 2 1 2 3 1 2 3 4))
;(defvar *my-text* "foobarbaz")
(defconstant +escape+ #\Escape)

;; Function Definition

(defun print-orange (text)
  (let ( (escape (code-char 27)) ) ; ecl will recognize 27 as the ASCII character for ESCAPE
    (format t "~%~4T~C\[1;38;5;208m~A~C\[0m~%"
          escape 
	  text 
	  escape
    )
  )
)

; \033[1;38;5;208m\] Bright Orange
; \033[0m\] Default Text Color (White)

(defun my-count(n i e) 
  (format t "~%~4TNumber of items equal to ~d in ~C[1;38;5;208m*my-vector*~C[0m = ~a~%" 
	  i
	  +escape+
	  +escape+
	  (count i n)
	  )
  (values)
)

;; TODO
;;	IMPLEMENT THE FOLLOWING FUNCTIONS:
;;	my-remove
;;      my-subtitute
;;	my-find
;;	my-position


;; Text Output

(print-orange *my-vector*)
(my-count *my-vector* 1 +escape+)
