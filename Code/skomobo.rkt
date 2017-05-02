#lang racket

;(define targets?)
;(define server)
;(define arduino)
;(define raspi)

(define (compile code) (call-with-output-file "test.txt" (lambda (out) (display code out)) "text" "truncate/replace") )

compile "yes yes yes"

;the code needs to be able to specify what each fragment is targeting