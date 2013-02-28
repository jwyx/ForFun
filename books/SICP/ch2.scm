; Gambit v4.6.6

;2.1

  ; 有理数的构造函数
  (define (make-rat n d)
    (let ((g (gcd n d)))
      (let ((nn (/ n g)) (nd (/ d g)))
          (if (> (* nn nd) 0)
            (cons nn nd)
            (cons (- (abs nn)) (abs nd))))))
;2.2

  (define (make-segment start end) (cons start end))

  (define (start-segment s) (car s))

  (define (end-segment s) (cdr s))

  (define (make-point x y) (cons x y))

  (define (x-point p) (car p))

  (define (y-point p) (cdr p))

  (define (midpoint-segment s)
    (let ((start (start-segment s))
          (end (end-segment s)))
      (make-point
        (/ (+ (x-point start) (x-point end)) 2)
        (/ (+ (y-point start) (y-point end)) 2))))

  (define (print-point p)
    (newline)
    (display "(")
    (display (x-point p))
    (display ",")
    (display (y-point p))
    (display ")"))

;2.3

  ;略

;2.4

  ;使用过程作为对象使用
  (define (cons x y)
    (lambda (m) (m x y)))

  (define (car z)
    (z (lambda (p q) p)))

  (define (cdr z)
    (z (lambda (p q) q)))

;2.5

  ; 如何证明? TODO

  (define (cons a b)
    (cond ((and (= a 0) (= b 0)) 1)
          ((and (= a 0) (> b 0))
            (* 3 (cons a (- b 1))))
          ((and (> a 0) (= b 0))
            (* 2 (cons (- a 1) b)))
          (else
            (* 2 3 (cons (- a 1) (- b 1))))))

  (define (car z)
    (if (= (remainder z 2) 0) (+ 1 (car (/ z 2))) 0))

  (define (cdr z)
    (if (= (remainder z 3) 0) (+ 1 (cdr (/ z 3))) 0))

;2.6

  (define zero (lambda (f) (lambda (x) x)))

  (define (add-1 n)
    (lambda (f) (lambda (x) (f ((n f) x)))))

  ; 考察代换模型的使用
  ; one = (add-1 zero)
  (define one (lambda (f) (lambda (x) (f x))))

  ; two = (add-1 one)
  (define two (lambda (f) (lambda (x) (f (f x)))))

  ; +的定义? TODO

;2.7

  (define (make-interval a b) (cons a b))

  (define (upper-bound z) (max (car z) (cdr z)))
  (define (lower-bound z) (min (car z) (cdr z)))

;2.8

  (define (sub-interval x y)
    (make-interval (- (lower-bound x) (upper-bound y))
                   (- (upper-bound x) (lower-bound y))))

;2.9

  ; add
  ; z = (x.lower + y.lower, x.upper + y.upper)
  ; z.width = (x.upper + y.upper - x.lower - y.lower)/2
  ;         = (x.upper - x.lower)/2 + (y.upper - x.upper)/2
  ;         = x.width + y.width

  ; sub
  ; z = (x.lower - y.upper, x.upper - y.lower)
  ; z.width = (x.upper - y.lower - x.lower + y.upper)/2
  ;         = (x.upper - x.lower)/2 + (y.upper - y.lower)/2
  ;         = x.width + y.width


;2.10

  (define (add-interval x y)
    (make-interval (+ (lower-bound x) (lower-bound y))
                   (+ (upper-bound x) (upper-bound y))))

  (define (mul-interval x y)
    (let ((p1 (* (lower-bound x) (lower-bound y)))
          (p2 (* (lower-bound x) (upper-bound y)))
          (p3 (* (upper-bound x) (lower-bound y)))
          (p4 (* (upper-bound x) (upper-bound y))))
     (make-interval (min p1 p2 p3 p4)
                    (max p1 p2 p3 p4))))

  (define (div-interval x y)
    (let ((y-upper (upper-bound y))
          (y-lower (lower-bound y)))
      (if (> (* y-upper y-lower) 0)
        (mul-interval x
          (make-interval (/ 1.0 y-upper)
                         (/ 1.0 y-lower)))
        (error "include 0"))))

;2.11

  ;略

;2.12

  (define (make-center-width c w)
    (make-interval (- c w) (+ c w)))

  (define (center i)
    (/ (+ (lower-bound i) (upper-bound i)) 2))

  (define (width i)
    (/ (- (upper-bound i) (lower-bound i)) 2))

  (define (make-center-percent c p)
    (make-interval (- c (* c p)) (+ c (* c p))))

  (define (percent i)
    (/ (width i) (center i)))

;2.13

  ;TODO

;2.14

  ;TODO

;2.15

  ;TODO

;2.16

  ;TODO

;2.17

  ;从0开始,找出list items中的下标为n的元素
  (define (list-ref items n)
    (if (= n 0)
      (car items)
      (list-ref (cdr items) (- n 1))))

  ; recursive
  (define (length items)
    (if (null? items)
      0
      (+ 1 (length (cdr items)))))

  ; iterative
  (define (length items)
    (define (length-iter a count)
      (if (null? a)
        count
        (length-iter (cdr a) (+ 1 count))))
    (length-iter items 0))

  ; 将list2 append list1
  (define (append list1 list2)
    (if (null? list1)
      list2
      (cons (car list1) (append (cdr list1) list2))))

  ; 最后一个元素
  ; 答案
  ; iterative
  (define (last-pair items)
    (define (last-pair-iter items count)
      (if (= count 1)
        items
        (last-pair-iter (cdr items) (- count 1))))
    (last-pair-iter items (length items)))

  ; recursive
  (define (last-pair items)
    (if (null? (cdr items))
      items
      (last-pair (cdr items))))

;2.18

  ; recursive
  (define (reverse items)
    (if (null? (cdr items))
      items
      (append (reverse (cdr items)) (cons (car items) '()))))

  ; iterative
  (define (reverse items)
    (define (reverse-iter items result)
      (if (null? items)
        result
        (reverse-iter (cdr items) (cons (car items) result))))
    (reverse-iter items '()))

;2.19

  (define us-coins (list 50 25 10 5 1))

  (define uk-coins (list 100 50 20 10 5 2 1 0.5))

  (define (count-change amount)
    (cc amount us-coins))

  ; 简化版本
  (define (cc amount coins)
    (cond ((= amount 0) 1)
      ((or (< amount 0) (null? coins)) 0)
      (else (+ (cc amount (cdr coins))
               (cc (- amount (car coins)) coins)))))

  ; 题目答案
  (define (cc amount coin-values)
    (cond ((= amount 0) 1)
          ((or (< amount 0) (no-more? coin-values)) 0)
          (else
            (+ (cc amount (except-first-denomination coin-values))
               (cc (- amount (first-denomination coin-values))
                  coin-values)))))

  (define (first-denomination coin-values) (car coin-values))

  (define (except-first-denomination coin-values) (cdr coin-values))

  (define (no-more? coin-values) (null? coin-values))

  ; 对结果没有影响 (Correct?)

;2.20

  (define (same-parity x . y)
    (define (recur items)
      (if (null? items)
        '()
        (if (= (remainder x 2) (remainder (car items) 2))
          (cons (car items) (recur (cdr items)))
          (recur (cdr items)))))
    (recur (cons x y)))

;2.21

  (define (square-list items)
    (if (null? items)
      '()
      (cons (square (car items)) (square-list (cdr items)))))

  (define (square-list items)
    (map (lambda (x) (square x)) items))

;2.22

  ; 第一种方式得到的list是反的
  ; 第二种方式无法得到list；
  ;   因为cons的第一个参数作为一个元素，不是作为一个list

;2.23

  ; 技巧：使用lambda可以组合多条语句
  (define (for-each proc items)
    (if (not (null? items))
      ((lambda () (proc (car items))
                  (for-each proc (cdr items))))))

;2.24

  ;认识这种元素本身也是序列的序列的另一种方式，是把它们看作树。序列里的元素就是树的分支，而那些本身也是序列的元素就形成了树中的子树。

  (define (count-leaves x)
    (cond ((null? x) 0)
          ((not (pair? x)) 1)
          (else (+ (count-leaves (car x))
                   (count-leaves (cdr x))))))
  ; 略

;2.25

  (car (cdr (car (cdr (cdr (list 1 3 (list 5 7) 9))))))

  (car (car (list (list 7))))

  (car (cdr
    (car (cdr
      (car (cdr
        (car (cdr
          (car (cdr
            (car (cdr
              (list 1
                (list 2
                  (list 3
                    (list 4
                      (list 5
                        (list 6 7))))))))))))))))))

;2.26

  (define x (list 1 2 3))
  (define y (list 4 5 6))

  (append x y)
  ; (1 2 3 4 5 6)
  (cons x y)
  ; ((1 2 3) 4 5 6)
  (list x y)
  ; ((1 2 3) (4 5 6))

;2.27

  (define (deep-reverse items)
    (define (iter items result)
      (if (null? items)
        result
        (let ((current (car items)))
          (if (pair? current)
            (iter (cdr items) (cons (iter current '()) result))
            (iter (cdr items) (cons current result))))))
    (iter items '()))

;2.28

  (define (fringe items)
    (if (null? items)
      '()
      (if (pair? (car items))
        (append (fringe (car items)) (fringe (cdr items)))
        (cons (car items) (fringe (cdr items))))))

;2.29

  
