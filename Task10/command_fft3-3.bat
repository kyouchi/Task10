set encoding utf8
set xl "f[Hz]"
set yl "Amplitude"
set xrange [0:8190]
set yrange [0:650.965]
set grid
set title "Apply FFT"
set term pngcairo enhanced size 1920,1080
set output "spectrum3-3.png" 
plot "spectrum3-3.plt" with lp
set output
