.name "Morgan Freeman"
.comment "May the force be with you Harry - Gandalf
-- El Psy Kongroo --"

ld %1, r3
and r2, %0, r2
sti r1, %:live_loop, %1
sti r1, %:live1, %1
sti r1, %:live2, %1
sti r1, %:live3, %1
sti r1, %:live4, %1
fork %:live_loop
sti r1, %:live5, %1
sti r1, %:live6, %1
sti r1, %:live7, %1
sti r1, %:step2, %1
zjmp %:step2
live_loop: live %1
live1: live %1
live2: live %1
live3: live %1
live4: live %1
live5: live %1
live6: live %1
live7: live %1
zjmp %:live_loop

step2: live %1
add r3, r2, r2
and %2048, r2, r4
fork %:step2
zjmp %:step2
and r2, %0, r2
zjmp %:live_loop
