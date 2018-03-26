.name  	 "zork"  #.comment "just a basic living prog"



.comment     "Lorem ipsum dolor sit amet."

l2:	sti	r1,%2,%0
and	r1,%0,r1
live:	live	%1
zjmp	%2
