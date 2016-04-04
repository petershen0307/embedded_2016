reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.100]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0-0.06):($2+0.001):2 with labels title ' ', \
'' using 3:xtic(1) with histogram title 'mini structure'  , \
'' using ($0+0.3):($3+0.0015):3 with labels title ' ', \
'' using 4:xtic(1) with histogram title 'hash 8527'  , \
'' using ($0+0.3):($4+0.0015):4 with labels title ' '
