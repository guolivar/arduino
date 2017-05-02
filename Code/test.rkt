#lang racket

( define upper 100 )
( define lower 1 )

(define (guess) (quotient(+ lower upper)) 2)

upper
lower
