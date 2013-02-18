; Gambit v4.6.6

;1.1

;  10 12 8 3 -3/2 19 #f 4 16 6 16

;1.2

  (/ (+ 5 4 
      (- 2 
       (- 3 
        (+ 6 
         (/ 4 5)))))
     (* 3 (- 6 2) (- 2 7)))

;1.3

  (define (sum-of-large-two x y z)
    (cond ((and (< x y) (< x z))
           (+ y z))
          ((and (< y x) (< y z))
           (+ x z))
          (else (+ x y))))

;1.4

;  a+|b|

;1.5

;  如果是应用序则是无限循环；否则返回0.
;  经验证，发现 Gambit v4.6.6 是应用序.

;1.6

;  会进入死循环；因为新定义的new-if是一个procedure，所以按照应用序，会先求实参的值；如果使用if那么会先求<predicate>，然后根据返回值只求解<consequent>和<alternative>之一。

;1.7

  (define (abs x) (if (< x 0) (- x) x))

  (define (square x) (* x x))

  (define (sqrt-iter guess x)
    (if (good-enough? guess x)
      guess
      (sqrt-iter (improve guess x) x)))

  (define (improve guess x)
    (average guess (/ x guess)))

  (define (average x y)
    (/ (+ x y) 2))

  (define (good-enough? guess x)
    (< (abs (- (square guess) x))
      0.001))

  (define (sqrt x)
    (sqrt-iter 1.0 x))

  ;得到错误答案；例如，(sqrt 0.001)
  ;死循环；例如，(sqrt 9999999999998)

  ;改进检测相邻两次猜测值的差值
  (define (good-enough? guess previous-guess)
    (< (abs (- previous-guess guess))
      0.001))

  (define (sqrt-iter guess previous-guess x)
    (if (good-enough? guess previous-guess)
      guess
      (sqrt-iter (improve guess x)
        guess
        x)))

  (define (sqrt x)
    (sqrt-iter 1.0 0 x))

  ;正常工作

  ;使用块结构重构程序
  (define (sqrt x)
    (define (good-enough? guess previous-guess)
      (< (abs (- previous-guess guess))
         0.001))
    (define (sqrt-iter guess previous-guess)
      (if (good-enough? guess previous-guess)
        guess
        (sqrt-iter (improve guess)
                   guess)))
    (define (improve guess)
      (average guess (/ x guess)))
    (sqrt-iter 1.0 0))

;1.8

(define (improve guess x)
  (/ (+ (/ x (* guess guess))
        (* 2 guess))
     3))

(define (cbrt-iter guess previous-guess x)
  (if (good-enough? guess previous-guess)
    guess
    (cbrt-iter (improve guess x)
               guess
               x)))

(define (cbrt x)
  (cbrt-iter 1.0 0 x))


;1.9

  ;recursive process
  ;
  ; (a-plus-b 4 5)
  ; (inc (a-plus-b (dec 4) 5))
  ; (inc (a-plus-b 3 5))
  ; (inc (inc (a-plus-b (dec 3) 5)))
  ; (inc (inc (a-plus-b 2 5)))
  ; (inc (inc (inc (a-plus-b (dec 2) 5))))
  ; (inc (inc (inc (a-plus-b 1 5))))
  ; (inc (inc (inc (inc (a-plus-b (dec 1) 5)))))
  ; (inc (inc (inc (inc (a-plus-b 0 5)))))
  ; (inc (inc (inc (inc 5))))
  ; (inc (inc (inc 6)))
  ; (inc (inc 7))
  ; (inc 8)
  ; 9

  (define (a-plus-b a b)
    (define (inc x)
      (+ x 1))
    (define (dec x)
      (- x 1))
    (if (= a 0)
      b
      (inc (a-plus-b (dec a) b))))

  ;iterative process
  ;
  ; (a-plus-b 4 5)
  ; (a-plus-b (dec 4) (inc 5))
  ; (a-plus-b 3 6)
  ; (a-plus-b (dec 3) (inc 6))
  ; (a-plus-b 2 7)
  ; (a-plus-b (dec 2) (inc 7))
  ; (a-plus-b 1 8)
  ; (a-plus-b (dec 1) (inc 8))
  ; (a-plus-b 0 9)
  ; 9

  ;递归procedure表示迭代的计算过程，称为尾递归

  (define (a-plus-b a b)
    (define (inc x)
      (+ x 1))
    (define (dec x)
      (- x 1))
    (if (= a 0)
      b
      (a-plus-b (dec a) (inc b))))

;1.10

  (define (A x y)
    (cond ((= y 0) 0)
      ((= x 0) (* 2 y))
      ((= y 1) 2)
      (else (A
             (- x 1)
             (A x (- y 1))))))

  ;(A 1 10) => 1024
  ;(A 2 4)  => 65536
  ;(A 3 3)  => 65536

  ;(f n)    => 2*n
  ;(g n)    => 2^n
  ;(h n)    => 2^(h n-1), h(0) = 0, h(1) = 2
  ;归纳法求得公式

;1.11

  ;recursive
  (define (f n)
    (if (< n 3)
      n
      (+ (f (- n 1))
        (* 2 (f (- n 2)))
          (* 3 (f (- n 3))))))

  ;iterative
  (define (f n)
    (define (f-iter a b c count)
      (cond ((= count 0) c)
        ((= count 1) b)
        ((= count 2) a)
        (else (f-iter (+ a (* 2 b) (* 3 c)) a b (- count 1)))))
    (f-iter 2 1 0 n))

;1.12

  (define (pascal row col)
    (if (or (= col 1) (= col row)) 1
      (+ (pascal (- row 1) (- col 1)) (pascal (- row 1) col))))

;1.13

  ; Assume a = (1+√5)/2, b = (1-√5)/2
  ; Prove Fib(n) is the closest integer to a^n/√5
  ;
  ; Fib(0) = (1 - 1)/√5 = 0
  ; Fib(1) = (a - b)/√5 = √5/√5 = 1
  ;
  ; Assume Fib(n-2) = (a^(n-2) - b^(n-2))/√5
  ; Fib(n-1) = (a^(n-1) -b^(n-1))/√5
  ;
  ; Fib(n) = Fib(n-1)+Fib(n-2)
  ;        = (a^(n-2) * (a+1) - b^(n-2) * (b+1))/√5
  ;        = (a^(n-2) & a^2 - b^(n-2) * b^2)/√5
  ;        = (a^n - b^n)/√5
  ; -1 < b=(1-√5)/2 < 0
  ; => -0.5 < -1/√5 < b^n/√5 < 1/√5 < 0.5
  ;
  ; => a^n/√5 = Fib(n)+b^n/√5
  ; => | a^n/√5 - Fib(n) | = b^n/√5 < 0.5
  ;
  ; Because Fib(n) is an integer, so Fib(n) is the closest integer to a^n/√5

;1.14

  ; 略

;1.15

  ; 12.15/(3^5) = 0.05 < 0.1
  ; time & space: O(lg a)

;1.16

  ; 使用(b^(n/2))^2 = (b^2)^(n/2)
  ; 除了使用指数n和基数b之外，还应维持一个附加的状态变量a，并定义一个状态转换之间的不变量a*b^n；在计算开始时a=1，并且在计算结束时返回a作为结果。
  ;
  ; 一般说，定义一个不变量，要求它在状态之间保持不变，
  ; 这一技术是思考迭代算法设计问题时的一种非常强有力的方法。

  (define (fast-expt b n)
    (define (even? n)
      (= (remainder n 2) 0))
    (define (fast-expt-iter b n a)
      (cond ((= n 0) a)
        ((even? n) (fast-expt-iter (* b b) (/ n 2) a))
        (else (fast-expt-iter b (- n 1) (* a b)))))
    (fast-expt-iter b n 1))

;1.17

  ; recursive
  (define (fast-multiple a b)
    (define (double x)
      (+ x x))
    (define (halve x)
      (/ x 2))
    (define (even? x)
      (= (remainder x 2) 0))
    (cond ((= b 0) 0)
      ((even? b) (double (fast-multiple a (halve b))))
      (else (+ a (fast-multiple a (- b 1))))))

;1.18

  ; iterative
  (define (fast-multiple a b)
    (define (double x)
      (+ x x))
    (define (halve x)
      (/ x 2))
    (define (even? x)
      (= (remainder x 2) 0))
    (define (fast-multiple-iter a b c)
      (cond ((= b 0) c)
        ((even? b) (fast-multiple-iter (double a) (halve b) c))
        (else (fast-multiple-iter a (- b 1) (+ a c)))))
    (fast-multiple-iter a b 0))

  ; if we choose the smaller as b, more efficient
  (define (fast-multiple a b)
    (define (double x)
      (+ x x))
    (define (halve x)
      (/ x 2))
    (define (even? x)
      (= (remainder x 2) 0))
    (define (fast-multiple-iter a b c)
      (cond ((= b 0) c)
        ((even? b) (fast-multiple-iter (double a) (halve b) c))
        (else (fast-multiple-iter a (- b 1) (+ a c)))))
    (if (< a b)
      (fast-multiple-iter b a 0)
      (fast-multiple-iter a b 0)))

;1.19

  ; O(lg n)
  ; T(pq):(a,b)=>(bq+aq+ap, bp+aq)
  ; T(pq):(bq+aq+ap, bp+aq)
  ;   => ((bp+aq)q + (bq+aq+ap)q + (bq+aq+ap)p,
  ;        (bp+aq)p + (bq+aq+ap)q)
  ;   => (2bpq+2aqq+bqq+2apq+app, bpp+2apq+bqq+aqq)
  ;   => (b(2pq+qq)+a(2pq+qq)+a(qq+pp), b(qq+pp)+a(2pq+qq))
  ;
  ; q' = 2pq+qq
  ; p' = qq+pp

  (define (fib n)
    (define (even? x)
      (= (remainder x 2) 0))
    (define (fib-iter a b p q count)
      (cond ((= count 0) b)
        ((even? count)
          (fib-iter a
                    b
                    (+ (* p p) (* q q))
                    (+ (* 2 p q) (* q q))
                    (/ count 2)))
        (else (fib-iter  (+ (* b q) (* a q) (* a p))
                         (+ (* b p) (* a q))
                         p
                         q
                         (- count 1)))))
    (fib-iter 1 0 0 1 n))

;1.20

  ; GCD
  ; iterative, 步数是对数增长
  ; 假设n是较小的数，那么算法步数为O(lg n)
  (define (gcd a b)
    (if (= b 0)
      a
      (gcd b (remainder a b))))

  ; 正则序
  ; (gcd 206 40)
  ;
  ; (gcd 40 (% 206 40)) [1]
  ;
  ; (gcd (% 206 40) (% 40 (% 206 40))) [2]
  ;
  ; (gcd (% 40 (% 206 40))
  ;     (% (% 206 40) (% 40 (% 206 40)))) [4]
  ;
  ; (gcd (% (% 206 40) (% 40 (% 206 40)))
  ;     (% (% 40 (% 206 40)) (% (% 206 40) (% 40 (% 206 40))))) [7+4]
  ;
  ; (gcd 2 0)
  ;
  ; 2
  ;
  ; 1+2+4+7+4 = 18

  ; 应用序
  ;
  ; gcd(206 40)
  ;
  ; gcd(40 (% 206 40)) [1]
  ; gcd(40 6)
  ;
  ; gcd(6 (% 40 6)) [1]
  ; gcd(6 4)
  ;
  ; gcd(4 (% 6 4)) [1]
  ; gcd(4 2)
  ;
  ; gcd(2 (% 4 2)) [1]
  ; gcd(2 0)
  ;
  ; 2
  ;
  ; 1+1+1+1 = 4

;1.21
;
;  检查整数n是否为素数?
;  两种方法：
;  1. 如果n不是素数，它必有一个小于等于√n的因子
;     也就是说该算法只需要在1和√n之间检查因子。
;     time: O(√n)

  (define (smallest-divisor n)
    (find-divisor n 2))

  (define (find-divisor n test-divisor)
    (cond ((> (square test-divisor) n) n)
      ((divides? test-divisor n) test-divisor)
      (else (find-divisor n (+ test-divisor 1)))))

  (define (divides? a b)
    (= (remainder b a) 0))

  (define (prime? n)
    (= n (smallest-divisor n)))

  (define (square n)
    (* n n))

;  2. 费马检查, 概率方法
;     time: O(lg n)

  (define (square n)
    (* n n))

  (define (expmod base exp m)
    (cond ((= exp 0) 1)
      ((even? exp)
        (remainder (square (expmod base (/ exp 2) m)) m))
      (else
        (remainder (* base (expmod base (- exp 1) m)) m))))

  (define (fermat-test n)
    (define (try-it a)
      (= (expmod a n n) a))
    (try-it (+ 1 (random-integer (- n 1)))))

  (define (fast-prime? n times)
    (cond ((= times 0) #t)
      ((fermat-test n) (fast-prime? n (- times 1)))
      (else #f)))

;   199, 1999, 7

;1.22

  (define (even? x)
    (= (remainder x 2) 0))

  (define (start-prime-test n start-time)
    (and (prime? n) ; (print n) (print " ")
      (println (- (time->seconds (current-time)) start-time))))

  (define (search-for-primes start count)
    (cond
      ((= count 0) (newline))
      ((even? start) (search-for-primes (+ start 1) count))
      ((start-prime-test start (time->seconds (current-time)))
        (search-for-primes (+ start 2) (- count 1)))
      (else
        (search-for-primes (+ start 2) count))))

; 1000
; 1.1301040649414062e-4
; 1.690387725830078e-4
; 8.180141448974609e-4
;
; 10000
; 2.911090850830078e-4
; 3.211498260498047e-4
; 4.520416259765625e-4
;
; 100000
; .0013661384582519531
; .0013370513916015625
; .0010950565338134766
;
; 1000000
; .0036530494689941406
; .00251007080078125
; .002357959747314453
;
; 不符合... FIXME

;1.23

  (define (next test-divisor)
    (if (= test-divisor 2) 3
      (+ test-divisor 2)))

  (define (find-divisor n test-divisor)
    (cond ((> (square test-divisor) n) n)
      ((divides? test-divisor n) test-divisor)
      (else (find-divisor n (next test-divisor)))))

; 1000
; 5.602836608886719e-5
; 8.082389831542969e-5
; 6.794929504394531e-5

; 10000
; 2.319812774658203e-4
; 2.7298927307128906e-4
; 2.758502960205078e-4

; 100000
; 9.090900421142578e-4
; 8.242130279541016e-4
; .0013120174407958984

; 1000000
; .0019578933715820312
; .0024051666259765625
; .0019190311431884766
;
; 比例也不对... FIXME

;1.24

  (define (prime? n)
    (fast-prime? n 10))

; 不符合2倍的关系... FIXME

;1.25

; 不好，因为base^exp太大而需要软件模拟精度，计算速度减慢

;1.26

; 因为这个改变把求幂变成了连乘，所以成了O(n)
; b^(2*n) = (b^n)^2
; 改写后成为 b^(2*n) = (b^n)*(b^n) = (b*b*..*b)*(b*b*...*b)
; 因为是应用序才有这种区别! (待验证 FIXME)

;1.27

  (define (square n)
    (* n n))

  (define (expmod base exp m)
    (cond ((= exp 0) 1)
      ((even? exp)
        (remainder (square (expmod base (/ exp 2) m)) m))
      (else
        (remainder (* base (expmod base (- exp 1) m)) m))))

  (define (fermat-test n k)
    (define (try-it a)
      (= (expmod a n n) a))
    (try-it k))

  (define (carmichael-test n)
    (define (recur n k)
      (if (= k 0) #t
        (and (fermat-test n k)
             (recur n (- k 1)))))
    (recur n (- n 1)))

;1.28

  (define (square n)
    (* n n))

  (define (expmod base exp m)
    (cond ((= exp 0) 1)
      ((even? exp)
        (let ((root (expmod base (/ exp 2) m)))
          (if (and (not (or (= root 1)
                            (= root (- m 1))))
                   (= (remainder (square root) m) 1))
            0
            (remainder (square root) m))))
      (else
        (remainder (* base (expmod base (- exp 1) m)) m))))

  (define (miller-rabin-test n)
    (define (try-it a)
      (= (expmod a (- n 1) n) 1))
    (try-it (+ 1 (random-integer (- n 1)))))

  (define (fast-prime? n times)
    (cond ((= times 0) #t)
      ((miller-rabin-test n) (fast-prime? n (- times 1)))
      (else #f)))

;1.29

  ;simpson rule求定积分

  (define (cube x) (* x x x))
  (define (sum term a next b)
    (if (> a b)
      0
      (+ (term a)
        (sum term (next a) next b))))
  (define (simpson f a b n)
    (define (simpson-h) (/ (- b a) n))
    (define (simpson-y x)
      (cond ((or (= x a) (= x (+ a (* n (simpson-h))))) (f x))
        ((even? (/ (- x a) (simpson-h))) (* 2 (f x)))
        (else (* 4 (f x)))))
    (define (simpson-next x)
      (+ x (simpson-h)))
    (* (sum simpson-y a simpson-next b) (/ (simpson-h) 3)))

  ; n=100, 1/4
  ; n=1000, 1/4
  ; 比积分更精确

;1.30

  (define (sum term a next b)
    (define (iter a result)
      (if (> a b)
        result
        (iter (next a) (+ (term a) result))))
    (iter a 0))

;1.31

  ; a. iterative
  (define (product term a next b)
    (define (iter a result)
      (if (> a b)
        result
        (iter (next a) (* (term a) result))))
    (iter a 1))

  (define (factorial n)
    (define (factorial-term x) x)
    (define (factorial-next x) (+ x 1))
    (product factorial-term 1 factorial-next n))

  ; calculate pi

  (define (pi)
    (define (pi-term x) (* (/ (- x 1) x) (/ (+ x 1) x)))
    (define (pi-next x) (+ x 2))
    (* 4.0 (product pi-term 3 pi-next 500001)))

  ; b. recursive
  (define (product term a next b)
    (if (> a b)
      1
      (* (term a) (product term (next a) next b))))

;1.32

  ; recursive
  (define (accumulate combiner null-value term a next b)
    (if (> a b)
      null-value
      (combiner (term a)
        (accumulate combiner null-value term (next a) next b))))

  ; iterative
  (define (accumulate combiner null-value term a next b)
    (define (iter a result)
      (if (> a b)
        result
        (iter (next a) (combiner (term a) result))))
    (iter a null-value))

  (define (product term a next b)
    (accumulate * 1 term a next b))

  (define (sum term a next b)
    (accumulate + 0 term a next b))

;1.33

  ; a.
  ; recursive
  (define (filtered-accumulate combiner null-value term a next b filter?)
    (if (> a b)
      null-value
      (combiner (if (filter? (term a)) (term a) 0)
        (filtered-accumulate combiner null-value term (next a) next b filter?))))

  ; iterative
  (define (filtered-accumulate combiner null-value term a next b filter?)
    (define (iter a result)
      (if (> a b)
        result
        (iter (next a)
          (if (filter? (term a)) (combiner result (term a)) result))))
    (iter a null-value))

  (define (filtered-sum term a next b filter?)
    (filtered-accumulate + 0 term a next b filter?))

  (define (filtered-product term a next b filter?)
    (filtered-accumulate * 1 term a next b filter?))

  (define (sum-prime a b)
    (define (prime-term x) x)
    (define (prime-next x) (if (even? x) (+ x 1) (+ x 2)))
    (filtered-sum prime-term a prime-next b prime?))

  ; b.
  (define (gcd a b)
    (if (= b 0)
      a
      (gcd b (remainder a b))))

  (define (product-relative-prime n)
    (define (relative-prime-term x) x)
    (define (relative-prime-next x) (+ x 1))
    (define (relative-prime-filter? x) (= (gcd x n) 1))
    (filtered-product relative-prime-term 1 relative-prime-next n relative-prime-filter?))

;1.34

  ; 将2作为procedure得到(2 2)
  ; 报错: Operator is not a PROCEDURE

;1.35

  ; 不动点计算
  (define tolerance 0.00001)

  (define (fixed-point f first-guess)
    (define (close-enough? v1 v2)
      (< (abs (- v1 v2)) tolerance))
    (define (try guess)
      (let ((next (f guess)))
        (if (close-enough? guess next)
          next
          (try next))))
    (try first-guess))

  ; 黄金分割
  (define (golden-ratio)
    (fixed-point (lambda (x) (+ 1 (/ 1 x))) 1.0))

;1.36

  ; 显示过程的不动点求解过程
  (define tolerance 0.00001)

  (define (fixed-point f first-guess)
    (define (close-enough? v1 v2)
      (< (abs (- v1 v2)) tolerance))
    (define (try guess)
      (let ((next (f guess)))
        (println next)
        (if (close-enough? guess next)
          next
          (try next))))
    (println first-guess)
    (try first-guess))

  ; 没用平均阻尼
  (fixed-point (lambda (x) (/ (log 1000) (log x))) 4.0)

  ; 4.
  ; 4.9828921423310435
  ; 4.301189432497896
  ; 4.734933901055578
  ; 4.442378437719526
  ; 4.632377941509958
  ; 4.505830646780212
  ; 4.588735606875766
  ; 4.533824356566501
  ; 4.56993352418142
  ; 4.546075272637246
  ; 4.561789745175654
  ; 4.55141783665413
  ; 4.5582542120702625
  ; 4.553744140202578
  ; 4.556717747893265
  ; 4.554756404545319
  ; 4.5560497413912975
  ; 4.5551967522618035
  ; 4.555759257615811
  ; 4.555388284933278
  ; 4.555632929754932
  ; 4.555471588998784
  ; 4.555577989320218
  ; 4.555507819903776
  ; 4.555554095154945
  ; 4.555523577416557
  ; 4.555543703263474
  ; 4.555530430629037
  ; 4.555539183677709
  ; 4.555539183677709

  ; 使用平均阻尼
  (fixed-point (lambda (x) (/ (+ x (/ (log 1000) (log x))) 2)) 4.0)
  ; 4.
  ; 4.491446071165521
  ; 4.544974650975552
  ; 4.553746974742814
  ; 4.555231425802502
  ; 4.555483906560562
  ; 4.5555268862194875
  ; 4.5555342036887705
  ; 4.5555342036887705

;1.37

  ; iterative
  (define (cont-frac n d k)
    (define (cont-frac-iter count result)
      (if (= count 0)
        result
        (cont-frac-iter (- count 1) (/ (n count) (+ (d count) result)))))
    (cont-frac-iter k 0))

  ; recursive
  (define (cont-frac n d k)
    (define (cont-frac-recur count)
      (if (> count k)
        0
        (/ (n count) (+ (d count) (cont-frac-recur (+ count 1))))))
    (cont-frac-recur 1))

  (cont-frac (lambda (i) 1.0) (lambda (i) 1.0) 11)

  ; k = 11 满足4位十进制精度

;1.38

  (define (natural k)
    (+ 2 (cont-frac
           (lambda (i) 1.0)
           (lambda (i)
             (let ((base (+ 1 (floor (/ (- i 1) 3))))
                   (offset (remainder (- i 1) 3)))
               (if (= offset 1) (* 2 base) 1)))
           k)))

;1.39

  (define (tan-cf x k)
    (cont-frac
      (lambda (i) (if (= i 1) x (- (* x x))))
      (lambda (i) (- (* 2 i) 1))
      k))

;1.40

  ; 三种思想结合的例子

  (define (average x y)
    (/ (+ x y) 2))

  (define (average-damp f)
    (lambda (x) (average x (f x))))

  (define (sqrt x)
    (fixed-point (average-damp (lambda (y) (/ x y))) 1.0))

  (define (cube-root x)
    (fixed-point (average-damp (lambda (y) (/ x (square y)))) 1.0))

  ; 可微函数是指那些在定义域中所有点都存在导数的函数。
  ; 牛顿法

  ; 求导公式
  (define dx 0.00001)

  (define (deriv g)
    (lambda (x)
      (/ (- (g (+ x dx)) (g x))
         dx)))

  (define (newton-transform g)
    (lambda (x)
      (- x (/ (g x) ((deriv g) x)))))

  (define (newton-method g guess)
    (fixed-point (newton-transform g) guess))

  (define (sqrt x)
    (newton-method (lambda (y) (- (square y) x))
                   1.0))

  ;找出一个函数在某种变换下的不动点
  (define (fixed-point-of-transform g transform guess)
    (fixed-point (transform g) guess))

  ;不动点搜索方法的重写
  (define (sqrt x)
    (fixed-point-of-transform (lambda (y) (/ x y))
                              average-damp
                              1.0))

  ;牛顿法改写
  (define (sqrt x)
    (fixed-point-of-transform (lambda (y) (- (square y) x))
                              newton-transform
                              1.0))

  ;1.40题解部分

  (define (cubic a b c)
    (lambda (x) (+ (cube x) (* a (square x)) (* b x) c)))

  (newton-method (cubic a b c) 1)

;1.41

  (define (double f) (lambda (x) (f (f x))))

  ; (((double (double double)) inc) 5) = 5+16 =21

;1.42

  (define (compose f g)
    (lambda (x) (f (g x))))

;1.43

  (define (repeated f n)
    (if (= n 1) f
      (lambda (x) (f ((repeated f (- n 1)) x)))))

  ;使用compose版本
  (define (repeated f n)
    (if (= n 1) f
      (compose f (repeated f (- n 1)))))

;1.44

  (define dx 0.00001)

  (define (smooth f)
    (lambda (x) (/ (+ (f (- x dx)) (f x) (f (+ x dx))) 3)))

  (define (n-smooth f n)
    ((repeated smooth n) f))

;1.45

  (define (fixed-point-of-transform g transform guess)
    (fixed-point (transform g) guess))

  (define (power-of-n x n)
    (if (= n 0) 1
      (* x (power-of-n x (- n 1)))))

  ; 改进版power-of-n
  (define (power-of-n x n)
    (cond ((= n 0) 1)
      ((even? n) (square (power-of-n x (/ n 2))))
      (else (* x (power-of-n x (- n 1))))))

  (define (power-of-n-root x n k)
    (fixed-point-of-transform
      (lambda (y) (/ x (power-of-n y (- n 1))))
      (repeated average-damp k)
      1.0))

;1.46

  ; 迭代式改进：为了计算出某些东西，我们对答案的某个初始猜测开始，检查这一猜测是否足够好，如果不行就改进这一猜测，将改进后的猜测作为新的猜测继续这一计算过程。

  (define (iterative-improve good-enough? next-guess)
    (define (recur guess)
      (if (good-enough? guess)
        guess
        (recur (next-guess guess))))
    (lambda (guess) (recur guess)))

  ; sqrt
  (define (sqrt x)
    ((iterative-improve
      (lambda (guess)
        (< (abs (- (square guess) x)) 0.001))
      (lambda (guess)
        (average guess (/ x guess))))
     1.0))

  ; fixed-point
  (define tolerance 0.00001)

  (define (fixed-point f first-guess)
    ((iterative-improve
      (lambda (guess)
        (< (abs (- guess (f guess))) tolerance))
      (lambda (guess) (f guess)))
     first-guess))
