#!/usr/bin/ecl -shell


;; Define 'i', initialize to 0, increment by 1 each step
;; Exit condition: stop when i equals 3. Return 'done.

(defun spacer()
  (format t "~%")
  (values)
  )

(spacer)

(do ( (i 0 (1+ i)) ) 
  ((= i 3) 'done)
  (format t "~4Ti = ~A~%" i)
  )

(spacer)
