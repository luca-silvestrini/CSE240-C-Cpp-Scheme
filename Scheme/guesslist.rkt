(#%require (lib "27.ss" "srfi"))
(random-source-randomize! default-random-source)

(define players '()) ; List for players

; Print out leaderboard
(define print_list
  (lambda ()
    (let print_player ((curPlayer (reverse players)))
      (cond
        ((null? curPlayer) '()) ; Ends print when base case is met: Empty list
        (else
         (let ((name (car (car curPlayer))) ; name of player
               (guess_count (cadr (car curPlayer)))) ; guess count for player
           (begin ; print Leaderboard
             (display "------------------\n")
             (display (string-append name " " (number->string guess_count) "\n")))
           (print_player (cdr curPlayer)))))))) ; loop



(define play_guess
  (lambda ()
    (display "Guess a number from 1 to 100: ")
    (let ((num_to_guess (+ (random-integer 100) 1))
          (guess 0)
          (guess_count 0))
      (let loop () ; Loops until correct guess is made
        (set! guess (read))
        (cond
          ((> num_to_guess guess)
           (display "Higher...Enter guess ")
           (set! guess_count (+ guess_count 1)) ; Guess_count++
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
             (display (string-append "Good game, " name "\n"))
             (set! players (cons (list name guess_count) players)))))))))

(define play
  (lambda ()
    (display "Enter q to quit or any other key to continue: ")
    (let ((input (read)))
      (cond ; Plays game until "q" is inputed
        ((not (equal? input "q"))
         (play_guess)
         (play))
        (else
         (print_list))))))

(play)