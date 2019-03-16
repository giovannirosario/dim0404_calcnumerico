set xrange[-10:10]
set yrange[-10:10]
plot x*cos(x) title "xcos(x)", (1*x)/1 - (3*x**3)/6 + (5*x**5)/120 - (7*x**7)/5040 + (9*x**9)/362880 - (11*x**11)/39916800 + (13*x**13)/6227020800 title "aproximacao serie de taylor"