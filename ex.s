
	.name  "zork"  #.comment justa basic 	living prog "

	.comment     "just a basic 	living prog"

l2:	sti	r1,%:live,%2
	and	r1,%0,r1
live:	live	%1
	zjmp	%:live
