#!/usr/bin/gnuplot

reset

Nx= 600
Ny= 600
Nf= 100
Ng= 2000

############## plot selection_risks #################
set term png size 560,370 crop enhanced font 'Verdana, 9'

set xl'time'
set yl'Selection (Predation) Risk'

set xr[0:Ng] 
#set yr[0.075:0.425]

# define axis
set style line 11 lc rgb '#2f4f4f' lt 1
set border 3 back ls 11
set tics nomirror

# define grid
set style line 12 lc rgb '#2f4f4f' lt 0 lw 1
set grid back ls 12

# color line definitions
set style line 1 lc rgb '#FFE91F' pt 6 lw 4.5 #  green      (species 1)
set style line 2 lc rgb '#0B080C pt 6 lw 4.5#  red	     (species 2)
set style line 3 lc rgb '#F12B04 pt 6 lw 4.5#  orange     (species 3)
set style line 4 lc rgb '#2266BF' pt 6 lw 4.5#  dark blue  (species 4)
set style line 5 lc rgb '#16A240' pt 6 lw 4.5#  cyan	     (species 5)



set out'selection_risk.png'

plot for[i=7:10] 'database/densities.dat' u 1:i  with lines ls (i-6) t' Species '.(i-6)


############## plot densities #################
set term png size 560,370 crop enhanced font 'Verdana, 9'

set xl'time'
set yl'Species Densities (Populations)'

#set xr[1000:1500] 
#set yr[0.0:1.0]

# define axis
set style line 11 lc rgb '#2f4f4f' lt 1
set border 3 back ls 11
set tics nomirror

# define grid
set style line 12 lc rgb '#2f4f4f' lt 0 lw 1
set grid back ls 12

# color line definitions
set style line 1 lc rgb '#16A240' pt 6 lw 4.5 #  green	(species 5)
set style line 2 lc rgb '#FFE91F' pt 6 lw 4.5 #  amarelo      (species 1)
set style line 3 lc rgb '#0B080C' pt 6 lw 4.5#  preto	(species 2)
set style line 4 lc rgb '#F12B04' pt 6 lw 4.5#  vermelho    	(species 3)
set style line 5 lc rgb '#2266BF' pt 6 lw 4.5#  azul		(species 4)
set style line 6 lc rgb '#16A240' pt 6 lw 4.5#  green         (species 5)


set style line 6 lc rgb '#16A240' pt 6 # green	     (species 5)
set out'densities.png'

plot for[i=3:7] 'database/densities.dat' u 1:i with lines ls (i-1) t'Species '.(i-2)
# plot 'database/densities.dat' u (($1)):3 with lines ls 1 t '1',\
#    'database/densities.dat' u (($1)):4 with lines ls 6 t '2',\
#     'database/densities.dat' u (($1)):5 with lines ls 3 t '3',\
#    'database/densities.dat' u (($1)):6 with lines ls 5 t '4',\
#     'database/densities.dat' u (($1)):7 with lines ls 2 t '5' 



################ plot grid #####################
#set size ratio -1
set term png size 416,401 crop 

unset xtics
unset ytics
unset key
unset colorbox
unset border
unset grid
unset xl
unset yl

set xr[0:Nx]
set yr[0:Ny]

set cbrange[0:5]


#set palette defined ( 0 '#ffffff',\
 #                     1 '#CE2D4F',\
  #                    2 '#F4B860',\
   #                   3 '#303633' ,\
#		      4 '#4056F4' ,\
#		      5	'#51E5FF')

		

set palette defined ( 0 '#ffffff',\
                      1 '#FFE91F',\
                      2 '#0B080C',\
                      3 '#F12B04',\
                      4 '#2266BF',\
					5 '#16A240')

#set palette defined ( 0 '#ffffff',\
 #                     1 '#7ee0a6',\
  #                    2 '#0c341d',\
   #                   3 '#ed7117')

#set palette defined ( 0 '#ffffff',\
 #                     1 '#0a5d00',\
  #                    2 'cyan',\
   #                   3 '#DC143C')

do for[i=0:Nf]{ 

	dataname = sprintf("database/data%d.dat",i)
	imagename = sprintf("plots/grid%d.png",i)

	set out imagename

	plot dataname u 1:2:3 matrix with image notitle 
}
