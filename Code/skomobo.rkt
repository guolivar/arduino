#lang racket

;(define targets?)
;(define server)
;(define arduino)
;(define raspi)

(define (create code) (call-with-output-file "test.cpp" #:mode-flag 'text #:exists-flag 'truncate/replace (lambda (out) (write code)) ) )

create "yes yes yes"

;the code needs to be able to specify what each fragment is targeting