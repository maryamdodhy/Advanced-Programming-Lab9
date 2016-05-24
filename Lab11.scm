(define Add (lambda (m n s z) (m s (n s z))))
(define Or (lambda (m n a b) (n a (m a b))))
(define Y (lambda (f) (lambda (x) (f (x x))) (lambda (x) (f(x x)))))
(define Not (lambda (m a b) (m a b)))
(define Rec (lambda (f n) (isZero n 0) 0 (Add (f n-1) n )))
(define LT (lambda(m n) (Not(Or (EQ(m n) Not(LEQ(n m)))))))

(define Func (lambda (m n) (Or (isZero)(m) (LT n m)) f (Y Rec) (Add m n)))

