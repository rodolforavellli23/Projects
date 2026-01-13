#!/usr/bin/ecl --shell

; Hexadecimal Representation
(defun this_hex() 
  (
   format t "~%~4T10 in hex(~a) = ~X~%" 
	  "#xA"
	  10
  )
  (values)
)

; Octal Representation
(defun this_oct() 
  (
   format t "~%~4T10 in oct(~a) = ~O~%" 
   	    "#o12"
	    10
  )
  (values)
)

; Binary Representation
(defun this_bin() 
  (format t "~%~4T10 in bin(~a) = ~B~%"
            "#b1010"
	    10
  )
  (values)
)

; Base 36 - Custom Bases Representation
(defun this_36() 
  (format t "~%~4T72 in base 36(~a) ~
             = ~36R~%"
            "#36r20"
	    72
  )
  (values)
)

; Decimal Floating Point Representation
(defun this_decimal()
  (format t "~%~4T0.123 in ~a = ~f~%"
            ".123 or 123e-3"
	    .123
  )
  (values)
)

; Text output to the terminal 
(this_hex)
(this_oct)
(this_bin)
(this_36)
(this_decimal)
