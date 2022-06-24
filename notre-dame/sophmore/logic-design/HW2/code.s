.text
ldi r1, 0x3 //assign 0x3 to r1
ldi r2, 0x5 //assign 0x5 to r2
not r3, r2 // ~r2 into the r3 bucket
and r4, r1, r3
not r3, r1 // ~r1 into the r3 bucket
and r6, r3, r2
or r0, r4,r6
quit