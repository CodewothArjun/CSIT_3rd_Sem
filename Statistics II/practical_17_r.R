initialweight=c(39,	52,	49,	46,	61,	36,	28,	57)
initialage=c(8, 7,	6,	11,	8,	7, 9,	5)
weightgain=c(8,	7,	6,	9,	10,	6,	4,	5)
summary(lm(weightgain~initialweight+initialage))
R=sqrt(0.6865)
R
data=data.frame(weightgain,initialweight,initialage)
data
install.packages("ppcor")
library("ppcor")
pcor(data,"pearson")
