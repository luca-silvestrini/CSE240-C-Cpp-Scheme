(define L '(3 5 2 8 6 1 4 9 7))
(display "---- original list \n")
(display L) (newline)

; leftlist and rightlist
;----------------------------------------------------------
(define center (quotient (length L) 2))

(define (leftlist lst n)
  (if (zero? n)
      '()
      (cons (car lst) (leftlist (cdr lst) (- n 1)))))
  
(define (rightlist lst n)
  (if (zero? n)
      lst
      (rightlist (cdr lst) (- n 1))))

(display "---- left and right lists\n")
(leftlist L center)
(rightlist L center)
  
; lefthalf and righthalf
;----------------------------------------------------------
(define (lefthalf lst)
  (leftlist lst (quotient (length lst) 2))); Recalculates center

(define (righthalf lst)
  (rightlist lst (quotient (length lst) 2)))

(display "---- left and right half\n")
  
(display "left halves\n")
(lefthalf L)
(lefthalf (lefthalf L))

  
(display "right halves\n")
(righthalf L)
(righthalf (righthalf L))

; merge
;----------------------------------------------------------
(define (merge lst1 lst2)
  (cond ((null? lst1) lst2)
        ((null? lst2) lst1)
        (else (if (< (car lst1) (car lst2))
                  (cons (car lst1) (merge (cdr lst1) lst2))
                  (cons (car lst2) (merge lst1 (cdr lst2)))))))

                  
(display "---- merge test 1\n")
(merge '(2 7 9) '(3 6 8))
(display "---- merge test 2\n")
(merge (leftlist L center) (rightlist L center))

; mergesort
;----------------------------------------------------------
(define (mergesort lst)
  (if (> (length lst) 1)
      (merge (mergesort (lefthalf lst))
             (mergesort (righthalf lst)))
      lst))

(display "---- mergesort test\n")
(mergesort L)
