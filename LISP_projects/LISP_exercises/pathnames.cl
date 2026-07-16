#!/bin/ecl -shell

#|

Pathnames in LISP

|#

; Variables

(defparameter *my-pad*
  (format NIL "~2T")
); pad

(defparameter *my-str*
  (format NIL "-")
); str

(defparameter *my-num* 97); num

(defparameter *chunk-len* 90)

(defconstant +escape+ #\Escape); e

(defvar *HOME* (user-homedir-pathname))

(defvar *pathname* 
  (make-pathname 
    :directory (append 
		 (pathname-directory *HOME*)
		 '("Documentos"
		   "GitHub"
		   "Projects"
		   "LISP_projects"
		   "LISP_exercises")
		 ) 
    :name "test" 
    :type "txt"
  )
); Pathname object

; Function Declaration

; Functions
; Naming Notes:
;       * is put as placeholder for a given
;         value in an argument name.
; Argument Notes:
;       s-*   = string containing the name
;               of the variable to be
;               displayed.

(defun my-spacer(str num)
  (format t "~%~1T")
  (loop for i from 0 to num do
    (format t "~a" str)
  )
  (format t "~%")
  (values)
)

(defun end-space() 
  (format t "~%")
  (values)
  )

; Splits a string into a list of substrings of maximum length 'limit'
(defun chunk-string (str limit)
  (loop for i from 0 by limit while (< i (length str))
        collect (subseq str i (min (length str) (+ i limit)))
	)
  )

;; Slice the pathname string into chunks of chunk-len characters
;; Print each chunk on a new line, aligned with the padding
(defun my-display-chunk(pad n e s-n chunk-len)
  (let* ( (path-str (namestring n)) (chunks (chunk-string path-str chunk-len)) )
    (if (< chunk-len 80) 
      (progn
       (format t "~%~a~C\[1;38;5;208m~a~C\[0m is ~%" 
	    pad 
	    e 
	    s-n 
	    e) 
       (dolist (chunk chunks)
	 (format t "~a~a~%" pad chunk)
	 )
      )
      (progn
       (format t "~%~a~C\[1;38;5;208m~a~C\[0m is "
	    pad 
	    e 
	    s-n 
	    e) 
       (dolist (chunk chunks)
	 (format t "~a~%" chunk)
	 )
      )
    )
    (values)
  )
 )

(defun my-file-printer (pad path)
  (format t "~%")
  (if (probe-file path)
    (with-open-file (in path :direction :input)
      (loop for line = (read-line in NIL NIL) while line do
            (format t "~a~a~%" 
		    pad 
		    line)
	    )
      )
    (format t
            "~aError: File not found at ~a~%" 
	    pad
            path)
    )
  (values)
)

; Text Output
(my-spacer *my-str* *my-num*)
(my-display-chunk 
  *my-pad* 
  *pathname*
  +escape+
  "Pathname"
  *chunk-len*)
(my-spacer *my-str* *my-num*)
(my-file-printer 
  *my-pad* 
  *pathname*)
(my-spacer *my-str* *my-num*)
(end-space)
