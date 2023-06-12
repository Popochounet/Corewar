	.name "Popo"
	.comment "g fait caca"


    st r1, 16
	ld %167706624, r2
    fork %:launch
hi:	live %123
    st r2, -21
	zjmp %:hi
launch: fork %:atk
    zjmp %:launch
atk:
