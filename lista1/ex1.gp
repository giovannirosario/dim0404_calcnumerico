set xrange[-1.5:2.5]
set yrange[-5:5]
set output "ex1.jpg"
plot x**3 - 2*x**2 - x + 2 title "funcao cubica", -2*x + 2 title"reta tangente em x = 1", (((2 + sqrt(7))/3)**3 - 2 * ((2 + sqrt(7))/3)**2 - ((2 + sqrt(7))/3) + 2) title "reta tangente ponto critico 1", (((2 - sqrt(7))/3)**3 - 2 * ((2 - sqrt(7))/3)**2 - ((2 - sqrt(7))/3) + 2) title "reta tangente ponto critico 2"
set label at 1, 0 "" point pointtype 3 ps 1
set label at 1, 0 "" point pointtype 3 ps 1
set label at ((2 - sqrt(7))/3), (((2 - sqrt(7))/3)**3 - 2 * ((2 - sqrt(7))/3)**2 - ((2 - sqrt(7))/3) + 2) "" point pointtype 3 ps 1
set label at ((2 + sqrt(7))/3), (((2 + sqrt(7))/3)**3 - 2 * ((2 + sqrt(7))/3)**2 - ((2 + sqrt(7))/3) + 2) "" point pointtype 3 ps 1
set grid
set xzeroaxis
set yzeroaxis