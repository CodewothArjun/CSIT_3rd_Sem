#D1: I	I	D	I	D	I	I	D	I
#D2: D	D	I	D	I	D	D	I	I
#D3: I	D	I	D	D	I	I	D	D
#D4: I	I	I	D	D	I	I	D	I

D1=c("I",	"I",	"D",	"I",	"D",	"I","I",	"D",	"I")
D2=c("D",	"D",	"I",	"D",	"I",	"D",	"D",	"I", "I")
D3=c("I",	"D",	"I",	"D",	"D",	"I",	"I",	"D", "D")
D4=c("I",	"I",	"D",	"D",	"D",	"I",	"I",	"D", "I")
table(D1)
table(D2)
table(D3)
table(D4)
prop.test(c(6,4,4,5),c(9,9,9,9))
