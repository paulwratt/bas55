5   REM SIEVE OF ERATOSTHENES, BY ERATOSTHENES OF CYERENE, 276 BC - 194 BC
10  PRINT "FIND PRIMES FROM 2 TO N (N <= 1000). ENTER N: "
20  INPUT N
30  IF N<2 THEN 10
40  IF N>1000 THEN 10
50  DIM A(1000)
60  LET S=SQR(N)
70  FOR I=2 TO S
80    IF A(I)=1 THEN 130
90    LET D=N/I
100   FOR J=I TO D
110     LET A(I*J)=1
120   NEXT J
130 NEXT I
140 FOR I=2 TO N
150   IF A(I)=1 THEN 170
160   PRINT I
170 NEXT I
180 END
