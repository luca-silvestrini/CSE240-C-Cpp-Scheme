(#%require (lib "27.ss" "srfi"))
(random-source-randomize! default-random-source)

(define play_guess
  (lambda ()
    (display "Guess a number from 1 to 100: ")
    (let ((num_to_guess (+ (random-integer 100) 1))
          (guess 0)
          (guess_count 0))
      (let loop () ; loops until correct guess is made
        (set! guess (read))
        (cond
          ((> num_to_guess guess)
           (display "Higher...Enter guess ")
           (set! guess_count (+ guess_count 1)) ; guess_count++
           (loop))
          ((< num_to_guess guess)
           (display "Lower...Enter guess ")
           (set! guess_count (+ guess_count 1))
           (loop))
          (else
           (set! guess_count (+ guess_count 1))
           (begin ; End of game statements
             (display (string-append "Correct! " (number->string guess_count) " guesses... "))
             (display "Please enter your name: "))
           (let ((name (read)))
             (display (string-append "Good game, " name)))))))))

(play_guess)