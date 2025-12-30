#!/usr/bin/ecl -shell

;; Learning about lists in Commom Lisp

;; Variables

(defvar my_list_1 '( :a 1 :b 2 :c 3))

(defvar my_list_2 (list 4 5 6))

;; Functions

(defun p_list (my_list) 
  (format t "~%~4TMy_list = ~a~%" 
	  my_list
	  )
  (values)
)

(defun p_list_n (my_list n) 
  (format t "~%~4TMy_list(~a) = ~a~%" 
	  n
	  (elt my_list n)
	  )
  (values)
)

(defun p_list_key (my_list key) 
  (format t "~%~4TMy_list(~a) = ~a~%" 
	  key
	  (getf my_list key)
	  )
  (values)
)

;; Output

(p_list my_list_2)
(p_list_n my_list_2 0)
(p_list_key my_list_1 :b)
