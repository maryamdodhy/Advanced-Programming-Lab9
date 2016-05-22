(define Add (lambda (m n s z) (m s (n s z))))

(define Subtract (lambda (m n) (n pred m)))

(define And (lambda (m n a b) (n (m a b) b)))
		
(define Or (lambda (m n a b) (n a (m a b))))

(define Not (lambda (m a b) (m a b)))

(define LEQ (lambda (m n) (isZero (Subtract m n))))
		
(define GEQ (lambda(m n) (Or (EQ(m n) NOT(LEQ(n m))))))