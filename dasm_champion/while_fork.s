.name           "while_loop"
.comment        "When a process becomes a Backward great grandpa"

	sti	r1, %41, %1
	sti	r1, %55, %1
	ld	%6, r1
	ld	%1, r2
	add	r1, r2, r1
	or	%15, r1, r3
	live	%1
	zjmp	%16
	fork	%-21
	ld	%0, r3
	zjmp	%-31
	live	%1
	zjmp	%-26
